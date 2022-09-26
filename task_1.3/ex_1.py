import time
import json
import requests as req
import tqdm
from bs4 import BeautifulSoup


class Vacancy:
    """
    Информация о вакансии
    """
    title: str
    work_experience: str
    salary: str
    region: str


class Vacancies:
    """
    Набор вакансий
    """

    def __init__(self):
        self.data = list[Vacancy]()

    data: list[Vacancy]


class VacanciesCustomEncoder(json.JSONEncoder):
    def default(self, o: Vacancies):
        return {"data": [v.__dict__ for v in o.data]}


def get_request(link: str) -> BeautifulSoup:
    """
    Получение структуры страницы по ссылке
    :param link: адрес сраницы
    :return: структура страницы
    """

    headers = req.utils.default_headers()
    headers.update({
        'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0',
    })

    resp = req.get(link, headers=headers)
    return BeautifulSoup(resp.text, "lxml")


def find_total_pages(soup: BeautifulSoup) -> int:
    """
    Определение числа страниц поиска
    :param soup: структура страницы поиска
    :return: число страниц поиска
    """

    total_pages = 0
    page_tags = soup.find(class_="pager").find_all(attrs={"class": "bloko-button"})
    for tag in page_tags:
        current_page = (int(tag.next.text) if tag.next.text.isdigit() else 0) - 1
        if current_page > total_pages:
            total_pages = current_page
    return total_pages


def get_vacancy(link: str) -> Vacancy:
    """
    Получение информации по вакансии на hh.ru
    :param link: ссылка на страницу вакансии
    :return: информация по вакансии
    """

    result = Vacancy()
    soup = get_request(link)
    title = soup.find(class_="bloko-header-section-1")
    if title is None:
        title = soup.find(attrs={"data-qa": "vacancy-title"})
    if title is not None:
        result.title = title.text

    salary = soup.find(attrs={"data-qa": "vacancy-salary"})
    if salary is not None:
        result.salary = salary.text

    work_experience = soup.find(attrs={"data-qa": "vacancy-experience"})
    if work_experience is not None:
        result.work_experience = work_experience.text

    region = soup.find(attrs={"data-qa": "vacancy-view-raw-address"})
    if region is None:
        region = soup.find(attrs={"data-qa": "vacancy-view-location"})
    if region is not None:
        result.region = region.text.split(",")[0]

    return result


def get_vacancies(text: str, function) -> Vacancies:
    """
    Получение информации по вакансиям на hh.ru
    :param function: функция, выполняемая после каждой просмотренной страницы поиска
    :param text: параметры поиска вакансии, (пример: python+разработчик)
    :return: Набор вакансий
    """

    pages = 0
    page = 0

    result = Vacancies()

    while page <= pages:
        soup = get_request(f"https://hh.ru/search/vacancy?text={text}&area=1&page={page}")

        if pages == 0:
            pages = find_total_pages(soup)
            print(f"Total pages: {pages + 1}")

        print(f"Page: {page + 1}")
        tags = soup.find_all(class_="serp-item__title")
        for item in tqdm.tqdm(tags):
            link = item.attrs["href"].split("?")[0]
            result.data.append(get_vacancy(link))

        time.sleep(1)
        function(result)
        page += 1

    return result


def save_to_file(result: Vacancies, file_path: str):
    """
    Сохранение данных в файл
    :param result: данные
    :param file_path: файл
    :return: void
    """
    with open(file_path, "w") as file:
        json.dump(result, file, cls=VacanciesCustomEncoder, ensure_ascii=False)


def get_vacancies_to_file(file_path: str = "data.json", text: str = "python+разработчик"):
    """
    Получение информации по вакансиям на hh.ru c сохранением в файл
    :param file_path: путь к файлу
    :param text: параметры поиска вакансии, (пример: python+разработчик)
    :return: void
    """

    get_vacancies(text, lambda result: save_to_file(result, file_path))

