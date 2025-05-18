#include "book.hpp"
#include "sqlite3.h"
#include "menu.hpp"
#include "library.hpp"


int main(){
    try{
    Library Lib;
    Menu* menu = Menu::Instence(Lib);
    std::string input;
    int choice;

    do{
        menu->printMenu();
        std::getline(std::cin, input);
        choice = std::stoi(input);          //ТЫ НЕХОРОШИЙ ЧЕЛОВЕК ВВЕЛ НЕ ЦИФЕРКИ А ГРЯЗНУЮ БУКВУ!!!!!!!!
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            menu->newBookMenu();
            break;

        case 2:
            menu->showallBookMenu();
            break;

        case 3:
            menu->findBookMenu();
            break;

        case 4:
            menu->deleteBookMenu();
            break;

        case 5:
            menu->outputBookMenu();
            break;
        case 0:
            break;

        default:
            std::cout << "error argumaent" << std::endl;
            break;
        }

    }
    while (choice != 0);
    {
        Menu::Destroy();
        return 0;
    }
    }
    catch (const std::exception& e) {
        Menu::Destroy();
        std::cerr << "Фатальная ошибка: " << e.what() << std::endl;
        return 0;
    }
    
    return 1;
}