#pragma once
#include <string>
#include <iostream>
//#include <vector>
#include "sqlite3.h"
#include <cstring>

class Book{
    public:

    unsigned int id;
    std::string title;
    std::string author;
    std::string description; //описание
    double rating;
    std::string review; //мнение
    //std::vector<std::string> tags;
    std::string coverPhotoPath;
    std::string bookFilePath;

    Book () : id{0}, title{"not find"}, author{"not find"}, description{"not find"}, rating{0}, review{"not find"},
        coverPhotoPath{"not find"},bookFilePath{"not find"} {};
    ~Book() {}
    //std::string outputBook();
    bool redacterBook();
    bool deleteBook();

    //гетеры сетеры
    std::string gettitle();
    bool settitle(std::string);
    std::string getauthor();
    bool setauthor(std::string);
    std::string getdescription();
    bool setdescription(std::string);
    double getrating();
    bool setrating(double);
    std::string getreview();
    bool setreview(std::string&);
    std::string getcoverPhotoPath();
    bool setcoverPhotoPath(std::string);
    std::string getbookFilePath();
    bool setbookFilePath(std::string);
};