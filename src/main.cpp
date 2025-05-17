#include "book.hpp"
#include "sqlite3.h"
#include "menu.hpp"
#include "library.hpp"


int main(){
    try{

    Library Lib;

    std::string input;
    int choice;

    do{
        printMenu();
        std::getline(std::cin, input);
        choice = std::stoi(input);          //ТЫ НЕХОРОШИЙ ЧЕЛОВЕК ВВЕЛ НЕ ЦИФЕРКИ А ГРЯЗНУЮ БУКВУ!!!!!!!!
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            newBookMenu(&Lib);
            break;

        case 2:
            showallBookMenu(&Lib);
            break;

        case 3:
            findBookMenu(&Lib);
            break;

        case 4:
            deleteBookMenu(&Lib);
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
        return 0;
    }
    }
    catch (const std::exception& e) {
        std::cerr << "Фатальная ошибка: " << e.what() << std::endl;
        return 0;
    }
    return 1;
}