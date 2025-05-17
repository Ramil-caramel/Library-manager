#pragma once
#include <iostream>
#include "sqlite3.h"
#include "book.hpp"
#include "library.hpp"
class Menu
{
private:
    Library& lib;

public:
    Menu(Library& ref) : lib{ref} {}
    void printMenu();
    bool newBookMenu(); 
    bool showallBookMenu();
    bool deleteBookMenu();
    bool findBookMenu();

};

