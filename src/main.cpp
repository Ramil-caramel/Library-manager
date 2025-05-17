#include "book.hpp"
#include "sqlite3.h"
#include "menu.hpp"
#include "library.hpp"

const char* SQL_TABLE = 
        "CREATE TABLE IF NOT EXISTS books ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "title TEXT NOT NULL,"
        "author TEXT NOT NULL,"
        "description TEXT,"
        "rating REAL,"
        "review TEXT,"
        "coverPhotoPath TEXT,"
        "bookFilePath TEXT"
        ");";

int main(){

    sqlite3* db;
    char*  errMsg = nullptr;
    Library Lib;

    if (sqlite3_open("test.db", &db) != SQLITE_OK){
        std::cerr << "база не открылась";
        sqlite3_close(db);
        return 0;
    }


    if (sqlite3_exec(db, SQL_TABLE, 0 , 0, &errMsg) != SQLITE_OK){
        std::cerr << "error";
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 0;
    }
    





    std::string input;
    int choice;

    do{
        printMenu();
        std::getline(std::cin, input);
        choice = std::stoi(input); //ТЫ НЕХОРОШИЙ ЧЕЛОВЕК ВВЕЛ НЕ ЦИФЕРКИ А ГРЯЗНУЮ БУКВУ!!!!!!!!
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            newBookMenu(db, &Lib);
            break;

        case 2:
            showallBookMenu(db, &Lib);
            break;

        case 3:
            break;

        case 4:
            deleteBookMenu(db, &Lib);
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
    sqlite3_close(db);
}