#pragma once
#include "sqlite3.h"
#include <iostream>
#include "book.hpp"

class Library{
private:
    sqlite3* db;
public:
    Library();
    ~Library();

    Book addpromBook(); // добавляет в промежуточное
    bool addBookindatabase(Book*); // добавяляет в бд
    bool chowBook(Book*); //выводит в консоль данный из класса
    bool showBookFromTable(int regime = 1, int nach = 0); // вывод всей таблицы с указанным параметром сортировки
    int getTotalBooksCount();
    bool deleteBookById(int);
    bool getFindBookFromTable(int, std::string, int nach = 0);
};