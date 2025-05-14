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

bool newBookMenu(sqlite3* db, Library* lib){
    
    Book prom_book = lib->addpromBook();

    while(true){
        std::string input;
        int choice;

        std::cout << "вот книга которую вы хотите добавить, вы уверены в введенных данных"<< std::endl;
        lib->chowBook(&prom_book);
        std::cout << "1 - да все верно" << std::endl;
        std::cout << "2 - нет я хочу заролнить все заново" << std::endl;
        std::getline(std::cin, input);
        choice = std::stoi(input);
        switch (choice){
            case 1:
                std::cout << lib->addBookindatabase(db, &prom_book) <<std::endl; // не забудь добавить методы файл менеджера по переносу фотки или проверки
                return 1;
                break;
            case 2:
        
                break;
            default:
            return 0;
            break;
        }
        prom_book = lib->addpromBook();
    }
}