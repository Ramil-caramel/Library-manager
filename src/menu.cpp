#include "menu.hpp"

void printMenu() {
    std::cout << "=== Домашняя библиотека ===" << std::endl; // не забыть добавить вывод книги по id
    std::cout << "1. Добавить книгу" << std::endl;
    std::cout << "2. Показать все книги" << std::endl; // сортировка имя, автор, оценка
    std::cout << "3. Найти книгу" << std::endl; // по названию, автору, тегу
    std::cout << "4. Удалить книгу" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

bool newBookMenu(sqlite3* db){
    Book book;
    std::string title;
    std::string author;
    //std::string description; //описание
    std::string rating;
    std::string review; //мнение
    //std::vector<std::string> tags;
    //std::vector<std::string> quotes;
    std::string coverPhotoPath;
    //std::string contentPhotosPath;
    std::string bookFilePath;

    std::cout << "Добавление книги, если хотите оставить параметр пустым просто нажмите enther" << std::endl;

    std:: cout << "введите название книги: ";
    std::getline(std::cin, title);
    std::cout << std::endl;
    if (!title.empty()) book.settitle(title);

    std:: cout << "введите автора: ";
    std::getline(std::cin, author);
    std::cout << std::endl;
    if (!author.empty()) book.setauthor(author);

    std::string full, line;
    std::cout << "Введите текст описания (введите END на новой строке для завершения):\n";
    while (std::getline(std::cin, line)) {
        if (line == "END") break;
        full += line + '\n'; // сохраняем с переносами
    }
    if (!full.empty()) book.setdescription(full);
    std::cout<<std::endl;

    std::cout << "введите рейтинг: ";
    std::getline(std::cin, rating);
    if (!rating.empty()) {
        double rate = std::stod(rating);
        book.setrating(rate);
    }
    std::cout<<std::endl;

    std:: cout << "введите свою рецензию: ";
    line = "";
    full = "";
    while (std::getline(std::cin, line)) {
        if (line == "END") break;
        full += line + '\n'; // сохраняем с переносами
    }
    if (!full.empty()) book.setreview(full);
    std::cout << std::endl;


    std:: cout << "введите путь к обложке книги: ";
    std::getline(std::cin, coverPhotoPath);
    std::cout << std::endl;
    if (!coverPhotoPath.empty()) book.setcoverPhotoPath(coverPhotoPath);

    std:: cout << "введите путь к файлу книги: ";
    std::getline(std::cin, bookFilePath);
    std::cout << std::endl;
    if (!bookFilePath.empty()) book.setbookFilePath(bookFilePath);


    std::cout << book.addBook(db) <<std::endl; // не забудь добавить методы файл менеджера по переносу фотки или проверки

    return 1;
}