#include "menu.hpp"

void Menu::printMenu() {
    std::cout << "=== Домашняя библиотека ===" << std::endl; // не забыть добавить вывод книги по id
    std::cout << "1. Добавить книгу" << std::endl;
    std::cout << "2. Показать все книги" << std::endl; // сортировка имя, автор, оценка
    std::cout << "3. Найти книгу" << std::endl; // по названию, автору, тегу
    std::cout << "4. Удалить книгу" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

bool Menu::newBookMenu(){
    
    Book prom_book = lib.addpromBook();

    while(true){
        std::string input;
        int choice;

        std::cout << "вот книга которую вы хотите добавить, вы уверены в введенных данных"<< std::endl;
        lib.chowBook(&prom_book);
        std::cout << "1 - да все верно" << std::endl;
        std::cout << "2 - нет я хочу заролнить все заново" << std::endl;//ТЫ НЕХОРОШИЙ ЧЕЛОВЕК ВВЕЛ НЕ ЦИФЕРКИ А ГРЯЗНУЮ БУКВУ!!!!!!!!

        try{
            std::getline(std::cin, input);
            choice = std::stoi(input);
        }
        catch(const std::exception& e){
            std::cerr << "invalid argument" << std::endl; 
            //std::cerr << e.what() << '\n';
            return 0;
        }

        switch (choice){
            case 1:
                std::cout << lib.addBookindatabase(&prom_book) <<std::endl; // не забудь добавить методы файл менеджера по переносу фотки или проверки
                return 1;
                break;
            case 2:
        
                break;
            default:
            return 0;
            break;
        }
        prom_book = lib.addpromBook();
    }
}

bool Menu::showallBookMenu(){
    int regime = 1;

    int nach = 0;
    int total = lib.getTotalBooksCount();

    lib.showBookFromTable(regime, nach);

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
        try{
            std::getline(std::cin, input);
            choice = std::stoi(input);
        }
        catch(const std::exception& e){
            std::cerr << "invalid argument" << std::endl; 
            //std::cerr << e.what() << '\n';
            return 0;
        }

        switch (choice)
        {
        case 1:
            regime = 1;
            lib.showBookFromTable(regime, nach);
            break;
        case 2:
            regime = 2;
            lib.showBookFromTable(regime, nach);
            break;
        case 3:
            if (nach - 5 >= 0){
                nach -= 5;
            }
            lib.showBookFromTable(regime, nach);
            break;
        case 4:
            if (nach + 5 < total){
                nach += 5;
            }
            lib.showBookFromTable(regime, nach);
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

bool Menu::deleteBookMenu(){
    std::string input;
    int id;
    std::cout << "Введите id книги для удаления: ";
    try
    {
        std::getline(std::cin, input);
        id = std::stoi(input);
        std::cout << lib.deleteBookById(id);
    }
    catch(const std::exception& e)
    {
        std::cerr << "это походу не индекс книги" << std::endl; 
        //std::cerr << e.what() << '\n';
        return 0;
    }
    

    return 1;
}

bool Menu::findBookMenu(){

    int regime = 1;
    int nach = 0;
    int total = lib.getTotalBooksCount();

    int CHISLO_PROLETOV = 5; // я поставил 10 но где менять не придумал
    // ОНО ЕСТЬ НО Я НИЧЕГО С ЭТИМ НЕ СДЕЛАЛ
    std::cout << "Введите объект поиска" <<std::endl;
    std::string search;
    std::getline(std::cin, search);

    while (true)
    {

        std::string input;
        int choice;
        std::cout << std::endl;
        std::cout << "режим поиска:" <<std::endl;
        std::cout << "1 - поиск по названию" << std::endl;
        std::cout << "2 - поиск по автору" << std::endl;
        std::cout << "3 - перелестнуть назад , 4 - перелестнуть вперед" <<std::endl;
        std::cout << "5 - сменить элемент поиска" << std::endl;
        std::cout << "0 - выход" << std::endl;
        std::cout << std::endl;

        try{
            std::cout << "Введите значение : ";
            std::getline(std::cin, input);
            choice = std::stoi(input);
        }
        catch(const std::exception& e){
            std::cerr << "invalid argument" << std::endl; 
            //std::cerr << e.what() << '\n';
            return 0;
        }
    
        switch (choice)
        {
        case 1:
            regime = 1;
            std::cout << "Включен режим поиска по названию" << std::endl;
            lib.getFindBookFromTable(regime, search, nach);
            break;
        case 2:
            regime = 2;
            std::cout << "Включен режим поиска по автору" <<std::endl;
            lib.getFindBookFromTable(regime, search, nach);
            break;
        case 3:
            if (nach - 5 >= 0){
                nach -= 5;
            }
            lib.getFindBookFromTable(regime, search, nach);
            break;
        case 4:
            if (nach + 5 < total){
                nach += 5;
            }
            lib.getFindBookFromTable(regime, search, nach);
            break;
        case 5:
            std::cout << "Введите новый элемент для поиска: ";
            std::getline(std::cin, search);
            nach = 0;
            lib.getFindBookFromTable(regime, search, nach);
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

    return 1;
}