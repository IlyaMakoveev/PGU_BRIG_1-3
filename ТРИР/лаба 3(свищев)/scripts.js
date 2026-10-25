// Текущий год
const currentYear = new Date().getFullYear();

document.getElementById("year").textContent = currentYear;

// Эффект печатной машинки в заголовке
const titleText = 'Цель моих произведений — не разрушать, а возводить мосты, так как мы все должны питать надежду, что люди сблизятся друг с другом. И это сближение будет происходить тем быстрее и проще, чем больше люди узнают друг о друге';
const titleElement = document.getElementById("citata");

let titleIndex = 0;
const typingSpeed = 23;

function typeTitle() {
    if (titleIndex < titleText.length){
        titleElement.innerHTML += titleText.charAt(titleIndex);
        titleIndex++;
        setTimeout(typeTitle, typingSpeed);
    }
}

window.addEventListener('DOMContentLoaded', typeTitle);

// Полоса прогресса прокрутки

window.addEventListener('scroll', updateScrollProgress);

function updateScrollProgress() {
    const scrollTop = document.documentElement.scrollTop;
    const scrollHeight = document.documentElement.scrollHeight - document.documentElement.clientHeight;

    const scrollPercent = (scrollTop / scrollHeight) * 100;

    document.getElementById('progressBar').style.width = scrollPercent + '%';
}

// Кнопка наверх
const btnUp = document.getElementById('btnUp');

window.addEventListener('scroll', () => {
    if (window.scrollY > 400){
        btnUp.classList.add("show");
    }
    else {
        btnUp.classList.remove("show");
    }
});

btnUp.addEventListener("click", () => {
    window.scrollTo({
        top: 0,
        behavior: "smooth"
    });
});

// Приветствие & попап
const popup = document.getElementById("welcomePopup");
const greetingText = document.getElementById("greetingText");
const closePopup = document.getElementById("closePopup");

function greetingByTime() {
    const now = new Date();
    const hour = now.getHours();

    if (hour >= 5 && hour < 12) {
    return "Доброе утро!";
  } else if (hour >= 12 && hour < 18) {
    return "Добрый день!";
  } else if (hour >= 18 && hour < 24) {
    return "Добрый вечер!";
  } else {
    return "Доброй ночи!";
  }
}
  greetingText.textContent = greetingByTime();

  popup.classList.add("show");

  closePopup.addEventListener("click", () => {
    popup.classList.remove("show");
  });

// Подсветка пункта меню
const sections = document.querySelectorAll("section")
const links = document.querySelectorAll("nav a")

window.addEventListener("scroll", () => {
    const topScreen = window.scrollY + 80;

    sections.forEach(section => {
        const sectionTop = section.offsetTop;
        const sectionHeight = section.offsetHeight;

        if (topScreen > sectionTop && topScreen < sectionTop + sectionHeight) {
            const id = section.id;

            links.forEach(link => {
            if (link.getAttribute('href') === `#${id}`) {
              link.classList.add('active');
            } else {
              link.classList.remove('active');
            }
          });
        }
    })
})