#pragma once
#include <iostream>
#include "sqlite3.h"
#include "book.hpp"
#include "library.hpp"
class Menu
{
private:
    Library& lib;
    Menu(Library& ref) : lib{ref} {}
    static Menu* _instance;

public:
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    
    static Menu* Instence(Library&);


    void printMenu(); // начальное меню
    bool newBookMenu(); //меню добавления книги
    bool showallBookMenu(); // меню вывод всех книг
    bool outputBookMenu(); // меню вывод книги по id
    bool showBook(Book&); // меню вывод структуры 
    bool deleteBookMenu(); // меню удаления книги
    bool findBookMenu(); // меню поиска книги

    static void Destroy();

    ~Menu() {};
};

