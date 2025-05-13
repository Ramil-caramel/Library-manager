#include "book.hpp"
#include "sqlite3.h"
#include "menu.hpp"

int main(){
    Book book_prom;

    sqlite3* db;
    char*  errMsg = nullptr;
    sqlite3_stmt* stmt;

    if (sqlite3_open("test.db", &db) != SQLITE_OK){
        std::cerr << "база не открылась";
        sqlite3_close(db);
        return 0;
    }
    const char* sql = 
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

    if (sqlite3_exec(db, sql, 0 , 0, &errMsg) != SQLITE_OK){
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
        choice = std::stoi(input);
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            newBookMenu(db);
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