#pragma once
#include <iostream>
#include "sqlite3.h"
#include "book.hpp"

void printMenu();
bool newBookMenu(sqlite3*);