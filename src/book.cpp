#include "book.hpp"

std::string Book::gettitle(){
    return this->title;
}
bool Book::settitle(std::string str){
    this->title = str;
    return 1;
}
std::string Book::getauthor(){
    return this->author;
}
bool Book::setauthor(std::string str){
    this->author = str;
    return 1;
}
std::string Book::getdescription(){
    return this->description;
}
bool Book::setdescription(std::string str){
    this->description = str;
    return 1;
}
double Book::getrating(){
    return this->rating;
}
bool Book::setrating(double r){
    this->rating = r;
    return 1;
}
std::string Book::getreview(){
    return this->review;
}
bool Book::setreview(std::string& str){
    this -> review = str;
    return 1;
}
std::string Book::getcoverPhotoPath(){
    return this->coverPhotoPath;
}
bool Book::setcoverPhotoPath(std::string str){
    this->coverPhotoPath = str;
    return 1;
}
std::string Book::getbookFilePath(){
    return this->bookFilePath;
}
bool Book::setbookFilePath(std::string str){
    this -> bookFilePath = str;
    return 1;
}
