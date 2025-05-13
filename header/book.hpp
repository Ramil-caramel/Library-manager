#pragma once
#include <string>
#include <iostream>
//#include <vector>
#include "sqlite3.h"
#include <cstring>

class Book{
    private:

    unsigned int id;
    std::string title;
    std::string author;
    std::string description; //описание
    double rating;
    std::string review; //мнение
    //std::vector<std::string> tags;
    //std::vector<std::string> quotes;
    std::string coverPhotoPath;
    //std::string contentPhotosPath;
    std::string bookFilePath;

    public:
    Book () : id{0}, title{"not found"}, author{"not found"}, description{"not found"}, rating{0}, review{"not found"},
        coverPhotoPath{"not found"},bookFilePath{"not found"} {};
    ~Book() {}
    bool addBook(sqlite3*);
    void showBook();
    bool outputBook();
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