#pragma once
#include "sqlite3.h"
#include <iostream>
#include "book.hpp"

class Library{
public:
    Book addpromBook(); // добавляет в промежуточное
    bool addBookindatabase(sqlite3*, Book*); // добавяляет в бд
    bool chowBook(Book*); //выводит в консоль данный из класса
    bool showBookFromTable(sqlite3*, int regime = 1, int nach = 1); // вывод всей таблицы с указанным параметром сортировки
    int getTotalBooksCount(sqlite3* db);
};