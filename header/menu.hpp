#pragma once
#include <iostream>
#include "sqlite3.h"
#include "book.hpp"
#include "library.hpp"

void printMenu();
bool newBookMenu(sqlite3*, Library*);