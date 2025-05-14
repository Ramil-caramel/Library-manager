#pragma once
#include "sqlite3.h"
#include <iostream>
#include "book.hpp"

class Library{
public:
    Book addpromBook();
    bool addBookindatabase(sqlite3*, Book*);
    bool chowBook(Book*);
};