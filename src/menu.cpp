#include "menu.hpp"

void printMenu() {
    std::cout << "=== Домашняя библиотека ===" << std::endl; // не забыть добавить вывод книги по id
    std::cout << "1. Добавить книгу" << std::endl;
    std::cout << "2. Показать все книги" << std::endl; // сортировка имя, автор, оценка
    std::cout << "3. Найти книгу" << std::endl; // по названию, автору, тегу
    std::cout << "4. Удалить книгу" << std::endl;
    std::cout << "5. Изменить книгу" << std::endl;
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
        choice = std::stoi(input); //ТЫ НЕХОРОШИЙ ЧЕЛОВЕК ВВЕЛ НЕ ЦИФЕРКИ А ГРЯЗНУЮ БУКВУ!!!!!!!!
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

bool showallBookMenu(sqlite3* db, Library* lib){
    int regime = 1;

    int nach = 0;
    int total = lib->getTotalBooksCount(db);

    lib->showBookFromTable(db, regime, nach);

    int CHISLO_PROLETOV = 5; // я поставил 10 но где менять не придумал
    // ОНО ЕСТЬ НО Я НИЧЕГО С ЭТИМ НЕ СДЕЛАЛ
    while (true)
    {
        std::string input;
        int choice;
        std::cout <<std::endl;
        std::cout << "если хотите сменить режим сортировки:" <<std::endl;
        std::cout << "1 - сортировка по названию" << std::endl;
        std::cout << "2 - сортировка по автору" <<std::endl;
        std::cout << "3 - перелестнуть назад , 4 - перелестнуть вперед" <<std::endl;
        std::cout << "0 - выход" << std::endl;
        std::cout << std::endl;
        std::getline(std::cin, input);
        choice = std::stoi(input);

        switch (choice)
        {
        case 1:
            regime = 1;
            lib->showBookFromTable(db, regime, nach);
            break;
        case 2:
            regime = 2;
            lib->showBookFromTable(db, regime, nach);
            break;
        case 3:
            if (nach - 5 >= 0){
                nach -= 5;
            }
            lib->showBookFromTable(db, regime, nach);
            break;
        case 4:
            if (nach + 5 < total){
                nach += 5;
            }
            lib->showBookFromTable(db, regime, nach);
            break;
        case 0:
            return 1;
            break;

        default:
            std::cout << "invalid argument"<< std::endl;
            return 0;
            break;
        }
    }
    
}