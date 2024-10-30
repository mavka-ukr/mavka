function showHelloCode() {
  document.querySelector(`[data-hello-code="true"]`).dataset.codeActive = "true";
  document.querySelector(`[data-rocket-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-server-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-request-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-button-show-hello-code="true"]`).classList.add("active");
  document.querySelector(`[data-button-show-rocket-code="true"]`).classList.remove("active");
  document.querySelector(`[data-button-show-server-code="true"]`).classList.remove("active");
  document.querySelector(`[data-button-show-request-code="true"]`).classList.remove("active");
}

function showRocketCode() {
  document.querySelector(`[data-hello-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-rocket-code="true"]`).dataset.codeActive = "true";
  document.querySelector(`[data-server-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-request-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-button-show-hello-code="true"]`).classList.remove("active");
  document.querySelector(`[data-button-show-rocket-code="true"]`).classList.add("active");
  document.querySelector(`[data-button-show-server-code="true"]`).classList.remove("active");
  document.querySelector(`[data-button-show-request-code="true"]`).classList.remove("active");
}

function showServerCode() {
  document.querySelector(`[data-hello-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-rocket-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-server-code="true"]`).dataset.codeActive = "true";
  document.querySelector(`[data-request-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-button-show-hello-code="true"]`).classList.remove("active");
  document.querySelector(`[data-button-show-rocket-code="true"]`).classList.remove("active");
  document.querySelector(`[data-button-show-server-code="true"]`).classList.add("active");
  document.querySelector(`[data-button-show-request-code="true"]`).classList.remove("active");
}

function showRequestCode() {
  document.querySelector(`[data-hello-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-rocket-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-server-code="true"]`).dataset.codeActive = "false";
  document.querySelector(`[data-request-code="true"]`).dataset.codeActive = "true";
  document.querySelector(`[data-button-show-hello-code="true"]`).classList.remove("active");
  document.querySelector(`[data-button-show-rocket-code="true"]`).classList.remove("active");
  document.querySelector(`[data-button-show-server-code="true"]`).classList.remove("active");
  document.querySelector(`[data-button-show-request-code="true"]`).classList.add("active");
}

document.querySelector(`[data-button-show-hello-code="true"]`).addEventListener("click", () => {
  showHelloCode();
});

document.querySelector(`[data-button-show-rocket-code="true"]`).addEventListener("click", () => {
  showRocketCode();
});

document.querySelector(`[data-button-show-server-code="true"]`).addEventListener("click", () => {
  showServerCode();
});

document.querySelector(`[data-button-show-request-code="true"]`).addEventListener("click", () => {
  showRequestCode();
});

showRocketCode();

function showMenu() {
  const menuButton = document.querySelector("[data-navigation-menu-toggle=true]");
  menuButton.classList.add("active");
  const buttonLeft = menuButton.getBoundingClientRect().left;
  const buttonTop = menuButton.getBoundingClientRect().top;
  document.documentElement.style.setProperty("--menu-left", `${buttonLeft}px`);
  document.documentElement.style.setProperty("--menu-top", `${buttonTop}px`);
  const menu = document.querySelector(".MavkaNavigationMenu");
  menu.dataset.hidden = "false";
}

function hideMenu() {
  const menuButton = document.querySelector("[data-navigation-menu-toggle=true]");
  menuButton.classList.remove("active");
  const menu = document.querySelector(".MavkaNavigationMenu");
  menu.dataset.hidden = "true";
}

document.querySelector("[data-navigation-menu-toggle=true]").addEventListener("click", () => {
  const menu = document.querySelector(".MavkaNavigationMenu");
  const isHidden = menu.dataset.hidden === "true";
  if (isHidden) {
    showMenu();
  } else {
    hideMenu();
  }
});

window.addEventListener("resize", () => {
  hideMenu();
});

window.addEventListener("scroll", () => {
  hideMenu();
});

window.addEventListener("click", (event) => {
  if (!event.target.closest(".MavkaNavigationMenu") && !event.target.closest("[data-navigation-menu-toggle=true]")) {
    hideMenu();
  }
});

window.addEventListener("keydown", (event) => {
  if (event.key === "Escape") {
    hideMenu();
  }
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
      el.style.display = "flex";
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
      el.style.display = "flex";
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
      el.style.display = "flex";
    });
  }
}

if (!localStorage.getItem("mavka_ukr_light_mode")) {
  localStorage.setItem("mavka_ukr_light_mode", "auto");
}

checkDarkMode();

document.querySelectorAll("[data-navigation-light-toggle=true]").forEach((el) => {
  el.addEventListener("click", () => {
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
});

let ctrlPressed = false;

window.addEventListener("keydown", (event) => {
  if (event.key === "Control") {
    ctrlPressed = true;
  }
});

window.addEventListener("keyup", (event) => {
  if (event.key === "Control") {
    ctrlPressed = false;
  }
});

const isTouchscreen = "ontouchstart" in window || navigator.maxTouchPoints > 0 || navigator.msMaxTouchPoints > 0;

window.addEventListener("wheel", (event) => {
  if (ctrlPressed) {
    document.documentElement.style.setProperty("--atom-base-size", `${Math.max(1, parseFloat(getComputedStyle(document.documentElement).getPropertyValue("--atom-base-size")) - event.deltaY * 0.05)}%`);
    document.documentElement.style.setProperty("--atom-base-degree", `${Math.max(1, parseFloat(getComputedStyle(document.documentElement).getPropertyValue("--atom-base-size")) - event.deltaY)}deg`);
    event.preventDefault();
    event.stopPropagation();
  }
}, { passive: false });

window.addEventListener("scroll", (event) => {
  document.documentElement.style.setProperty("--scroll-y-percentage", `${window.scrollY / (document.body.scrollHeight - window.innerHeight) * 100}%`);
  document.documentElement.style.setProperty("--scroll-y-degree", `${window.scrollY / (document.body.scrollHeight - window.innerHeight) * 360}deg`);
});

window.addEventListener("mousemove", (event) => {
  if (!isTouchscreen) {
    document.documentElement.style.setProperty("--mouse-x-percentage", `${event.clientX / window.innerWidth * 100}%`);
    document.documentElement.style.setProperty("--mouse-y-percentage", `${event.clientY / window.innerHeight * 100}%`);
    document.documentElement.style.setProperty("--mouse-x-degree", `${event.clientX / window.innerWidth * 360}deg`);
    document.documentElement.style.setProperty("--mouse-y-degree", `${event.clientY / window.innerHeight * 360}deg`);
  }
});

document.querySelector(".MavkaHomeAtomContainer").addEventListener("dblclick", () => {
  if (!isTouchscreen) {
    document.documentElement.style.setProperty("--atom-base-size", "350%");
    document.documentElement.style.setProperty("--atom-base-degree", "0deg");
  }
});

document.documentElement.classList.add("transitions");

if (window.matchMedia("(prefers-reduced-motion: reduce)").matches) {
  document.documentElement.classList.remove("transitions");
}

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

function showMobileMenu() {
  const menuButton = document.querySelector(".MavkaNavigationMobileToggle");
  menuButton.classList.add("active");
  const menu = document.querySelector(".MavkaNavigationMobileMenu");
  menu.dataset.hidden = "false";
}

function hideMobileMenu() {
  const menuButton = document.querySelector(".MavkaNavigationMobileToggle");
  menuButton.classList.remove("active");
  const menu = document.querySelector(".MavkaNavigationMobileMenu");
  menu.dataset.hidden = "true";
}

document.querySelector(".MavkaNavigationMobileToggle").addEventListener("click", () => {
  const menu = document.querySelector(".MavkaNavigationMobileMenu");
  const isHidden = menu.dataset.hidden === "true";
  if (isHidden) {
    showMobileMenu();
  } else {
    hideMobileMenu();
  }
});

window.addEventListener("resize", () => {
  hideMenu();
});
