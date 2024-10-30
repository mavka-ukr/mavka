window.__randomize_color__ = function() {
  const randomColorName = () => {
    const colors = ["black", "blue", "yellow", "red"];
    return colors[Math.floor(Math.random() * colors.length)];
  };
  const colorName = randomColorName();
  document.documentElement.style.setProperty("--primary-rgb", `var(--${colorName}-rgb)`);
  document.documentElement.style.setProperty("--primary-hover-rgb", `var(--${colorName}-hover-rgb`);
  document.documentElement.style.setProperty("--primary-pressed-rgb", `var(--${colorName}-pressed-rgb`);
  document.documentElement.style.setProperty("--primary-text-rgb", `var(--${colorName}-text-rgb`);
  document.documentElement.style.setProperty("--primary-transparent-button-rgb", `var(--${colorName}-transparent-button-rgb`);
};
window.__randomize_color__();

function enableMobileMode() {
  document.documentElement.classList.add("mobile");
}

function disableMobileMode() {
  document.documentElement.classList.remove("mobile");
}

function checkMobileMode() {
  if (window.innerWidth < 950) {
    enableMobileMode();
  }
  if (window.innerWidth >= 950) {
    disableMobileMode();
  }
}

checkMobileMode();

window.addEventListener("resize", () => {
  checkMobileMode();
});

function enableDarkMode() {
  document.documentElement.classList.add("dark");
}

function disableDarkMode() {
  document.documentElement.classList.remove("dark");
}

function checkDarkMode() {
  const currentMode = localStorage.getItem("mavka_ukr_light_mode");
  if (currentMode === "auto") {
    if (window.matchMedia("(prefers-color-scheme: dark)").matches) {
      enableDarkMode();
    } else {
      disableDarkMode();
    }
    document.querySelectorAll(`[data-navigation-light-toggle-badge-auto=true]`).forEach((el) => {
      el.style.display = "block";
    });
    document.querySelectorAll(`[data-navigation-light-toggle-badge-yes=true]`).forEach((el) => {
      el.style.display = "none";
    });
    document.querySelectorAll(`[data-navigation-light-toggle-badge-no=true]`).forEach((el) => {
      el.style.display = "none";
    });
  } else if (currentMode === "light") {
    disableDarkMode();
    document.querySelectorAll(`[data-navigation-light-toggle-badge-auto=true]`).forEach((el) => {
      el.style.display = "none";
    });
    document.querySelectorAll(`[data-navigation-light-toggle-badge-yes=true]`).forEach((el) => {
      el.style.display = "block";
    });
    document.querySelectorAll(`[data-navigation-light-toggle-badge-no=true]`).forEach((el) => {
      el.style.display = "none";
    });
  } else if (currentMode === "dark") {
    enableDarkMode();
    document.querySelectorAll(`[data-navigation-light-toggle-badge-auto=true]`).forEach((el) => {
      el.style.display = "none";
    });
    document.querySelectorAll(`[data-navigation-light-toggle-badge-yes=true]`).forEach((el) => {
      el.style.display = "none";
    });
    document.querySelectorAll(`[data-navigation-light-toggle-badge-no=true]`).forEach((el) => {
      el.style.display = "block";
    });
  }
}

if (!localStorage.getItem("mavka_ukr_light_mode")) {
  localStorage.setItem("mavka_ukr_light_mode", "auto");
}

document.querySelector(".XDocsPageNavigationFooter").innerHTML += `<button class="XDocsPageNavigationFooterConfigButton">
  <svg class="no-dark-shadow" data-navigation-light-toggle-badge-auto="true" xmlns="http://www.w3.org/2000/svg" viewBox="0 -960 960 960" fill="currentColor"><path d="M440-200q52 0 99-21t81-60q-128-8-214-99.5T320-600q0-13 1-25.5t3-24.5q-57 32-90.5 88T200-440q0 100 70 170t170 70Zm0 80q-134 0-227-93t-93-227q0-134 93-227t227-93q5 0 10 .5t10 .5q-29 32-44.5 73T400-600q0 100 70 170t170 70q31 0 60.5-7.5T756-390q-18 118-108 194t-208 76Zm112-400 128-360h80l128 360h-76l-28-80H656l-28 80h-76Zm122-134h92l-46-146-46 146ZM407-381Z" /></svg>
  <svg class="no-dark-shadow" data-navigation-light-toggle-badge-yes="true" xmlns="http://www.w3.org/2000/svg" viewBox="0 -960 960 960" fill="currentColor"><path d="M480-360q50 0 85-35t35-85q0-50-35-85t-85-35q-50 0-85 35t-35 85q0 50 35 85t85 35Zm0 80q-83 0-141.5-58.5T280-480q0-83 58.5-141.5T480-680q83 0 141.5 58.5T680-480q0 83-58.5 141.5T480-280ZM200-440H40v-80h160v80Zm720 0H760v-80h160v80ZM440-760v-160h80v160h-80Zm0 720v-160h80v160h-80ZM256-650l-101-97 57-59 96 100-52 56Zm492 496-97-101 53-55 101 97-57 59Zm-98-550 97-101 59 57-100 96-56-52ZM154-212l101-97 55 53-97 101-59-57Zm326-268Z" /></svg>
  <svg class="no-dark-shadow" data-navigation-light-toggle-badge-no="true" xmlns="http://www.w3.org/2000/svg" viewBox="0 -960 960 960" fill="currentColor"><path d="M480-120q-150 0-255-105T120-480q0-150 105-255t255-105q14 0 27.5 1t26.5 3q-41 29-65.5 75.5T444-660q0 90 63 153t153 63q55 0 101-24.5t75-65.5q2 13 3 26.5t1 27.5q0 150-105 255T480-120Zm0-80q88 0 158-48.5T740-375q-20 5-40 8t-40 3q-123 0-209.5-86.5T364-660q0-20 3-40t8-40q-78 32-126.5 102T200-480q0 116 82 198t198 82Zm-10-270Z" /></svg>
</button>`;

checkDarkMode();

document.querySelector(".XDocsPageNavigationFooterConfigButton").addEventListener("click", () => {
  const currentMode = localStorage.getItem("mavka_ukr_light_mode");
  if (currentMode === "auto") {
    localStorage.setItem("mavka_ukr_light_mode", "light");
  } else if (currentMode === "light") {
    localStorage.setItem("mavka_ukr_light_mode", "dark");
  } else {
    localStorage.setItem("mavka_ukr_light_mode", "auto");
  }
  checkDarkMode();
});

document.querySelector(".XDocsPageNavigationSearch button").addEventListener("click", () => {
  const $searchInput = document.createElement("input");
  $searchInput.classList.add("XDocsSearchInput");
  $searchInput.setAttribute("type", "text");
  $searchInput.setAttribute("placeholder", "Пошук");
  $searchInput.addEventListener("input", () => {
    const searchValue = $searchInput.value.trim();
    window.searchDocs(searchValue).then((result) => {
      if (result.length === 0) {
        renderEmpty();
      } else {
        renderResult(result);
      }
    });
  });
  $searchInput.addEventListener("keydown", (e) => {
    if (e.key === "ArrowDown") {
      const $firstItem = $searchResults.firstElementChild;
      if ($firstItem) {
        $firstItem.focus();
        e.preventDefault();
        e.stopPropagation();
      } else {
        $searchInput.focus();
        e.preventDefault();
        e.stopPropagation();
      }
    }
    if (e.key === "ArrowUp") {
      const $lastItem = $searchResults.lastElementChild;
      if ($lastItem) {
        $lastItem.focus();
        e.preventDefault();
        e.stopPropagation();
      } else {
        $searchInput.focus();
        e.preventDefault();
        e.stopPropagation();
      }
    }
  }, false);

  const $searchResults = document.createElement("div");
  $searchResults.classList.add("XDocsSearchResults");
  $searchResults.classList.add("empty");
  $searchResults.innerHTML = "Введіть запит для пошуку";

  const pathPrefix = document.querySelector("meta[name=\"xdocs-url-prefix\"]").getAttribute("content");

  function renderResult(result) {
    $searchResults.classList.remove("empty");
    $searchResults.innerHTML = "";
    result.forEach((item) => {
      const $searchResultItem = document.createElement("a");
      $searchResultItem.classList.add("XDocsSearchResultItem");
      $searchResultItem.setAttribute("href", pathPrefix + item.path);
      $searchResultItem.innerHTML = item.title;
      $searchResults.appendChild($searchResultItem);

      $searchResultItem.addEventListener("keydown", (e) => {
        if (e.key === "ArrowDown") {
          const $nextItem = $searchResultItem.nextElementSibling;
          if ($nextItem) {
            $nextItem.focus();
            e.preventDefault();
            e.stopPropagation();
          } else {
            $searchInput.focus();
            e.preventDefault();
            e.stopPropagation();
          }
        }
        if (e.key === "ArrowUp") {
          const $prevItem = $searchResultItem.previousElementSibling;
          if ($prevItem) {
            $prevItem.focus();
            e.preventDefault();
            e.stopPropagation();
          } else {
            $searchInput.focus();
            e.preventDefault();
            e.stopPropagation();
          }
        }
      }, false);
    });
  }

  function renderEmpty() {
    $searchResults.classList.add("empty");
    $searchResults.innerHTML = "Нічого не знайдено";
  }

  const $searchContainer = document.createElement("div");
  $searchContainer.classList.add("XDocsSearchContainer");
  $searchContainer.appendChild($searchInput);
  $searchContainer.appendChild($searchResults);

  const $searchWrapper = document.createElement("div");
  $searchWrapper.classList.add("XDocsSearchWrapper");
  $searchWrapper.appendChild($searchContainer);

  $searchWrapper.addEventListener("click", (e) => {
    if (e.target === $searchWrapper) {
      $searchWrapper.remove();
    }
  });
  $searchWrapper.addEventListener("keydown", (e) => {
    if (e.key === "Escape") {
      $searchWrapper.remove();
      e.preventDefault();
      e.stopPropagation();
    }
  });

  document.body.appendChild($searchWrapper);

  $searchInput.focus();
});

const $spaceBeforeFooterWrapper = document.createElement("div");
$spaceBeforeFooterWrapper.classList.add("XDocsPageNavigationFooterWrapperSpaceBefore");

document.querySelector(".XDocsPageNavigationFooterWrapper").insertAdjacentElement("beforebegin", $spaceBeforeFooterWrapper);

const $activeMenuItem = document.querySelector(".XDocsPageNavigation .active");

if ($activeMenuItem && $activeMenuItem.scrollIntoView) {
  $activeMenuItem.scrollIntoView({
    block: "center"
  });
}