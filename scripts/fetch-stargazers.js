const fs = require("fs");

// --- CONFIGURATION ---
const OWNER = "mavka-ukr"; // Replace with the repository owner (e.g., 'facebook')
const REPO = "mavka"; // Replace with the repository name (e.g., 'react')
const TOKEN = process.env.GITHUB_TOKEN || ""; // Optional: Highly recommended to avoid rate limits (60/hr vs 5000/hr)
// ---------------------

async function fetchAllStargazers() {
  let stargazers = [];
  let page = 1;
  let hasMore = true;

  console.log(`Fetching stargazers for ${OWNER}/${REPO}...`);

  while (hasMore) {
    // Requesting max allowed 100 items per page
    const url = `https://api.github.com/repos/${OWNER}/${REPO}/stargazers?per_page=100&page=${page}`;
    const headers = {
      Accept: "application/vnd.github.star+json", // Custom header required to get timestamps
      "User-Agent": "node-fetch-stargazers",
    };

    if (TOKEN && TOKEN !== "YOUR_GITHUB_TOKEN") {
      headers["Authorization"] = `Bearer ${TOKEN}`;
    }

    try {
      const response = await fetch(url, { headers });

      if (!response.ok) {
        throw new Error(
          `GitHub API error: ${response.status} ${response.statusText}`,
        );
      }

      const data = await response.json();

      if (data.length === 0) {
        hasMore = false; // No more stargazers left
      } else {
        stargazers.push(...data);
        console.log(
          `Fetched page ${page} (${stargazers.length} total users loaded)`,
        );
        page++;
      }
    } catch (error) {
      console.error("Error fetching data:", error.message);
      break;
    }
  }

  return stargazers.reverse();
}

function generateMarkdown(stargazers) {
  let md = `# Stargazers for ${OWNER}/${REPO}\n\n`;
  md += `Total Stars: **${stargazers.length}**\n\n`;
  md += `| Avatar | Username | Starred At |\n`;
  md += `| --- | --- | --- |\n`;

  for (const item of stargazers) {
    const user = item.user;
    const starredAt = new Date(item.starred_at).toUTCString();
    md += `| <img src="${user.avatar_url}" width="30" height="30" style="border-radius:50%"> | [${user.login}](${user.html_url}) | ${starredAt} |\n`;
  }

  return md;
}

async function main() {
  const stargazers = await fetchAllStargazers();

  if (stargazers.length === 0) {
    console.log("No stargazers found or an error occurred.");
    return;
  }

  const markdownContent = generateMarkdown(stargazers);
  const fileName = `STARGAZERS.md`;

  fs.writeFileSync(fileName, markdownContent, "utf8");
  console.log(
    `\nSuccess! Exported ${stargazers.length} stargazers to ${fileName}`,
  );
}

main();
