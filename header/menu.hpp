#pragma once
#include <iostream>
#include "sqlite3.h"
#include "book.hpp"
#include "library.hpp"

void printMenu();
bool newBookMenu(Library*); 
bool showallBookMenu(Library*);
bool deleteBookMenu(Library*);
bool findBookMenu(Library*);