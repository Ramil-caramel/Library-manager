#include "book.hpp"

bool Book::addBook(sqlite3* db){
    const char* sql = "INSERT INTO books (title, author, description, rating, review, coverPhotoPath, bookFilePath) VALUES (?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement" << std::endl;
        return 0;
    }
    // id не дкргаем оно само закинет так как я в начале sql поставил PRIMARY KEY AUTOINCREMENT
    // Привязываем параметры
    //sqlite3_bind_int(stmt, 1, this->id);
    sqlite3_bind_text(stmt, 1, this->title.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, this->author.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, this->description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 4, this->rating); 
    sqlite3_bind_text(stmt, 5, this->review.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, this->coverPhotoPath.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, this->bookFilePath.c_str(), -1, SQLITE_TRANSIENT);
    
    
    // Выполняем запрос
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Execution failed: " << std::endl;
        sqlite3_finalize(stmt);
        return 0;
    }

    sqlite3_finalize(stmt);
    return 1;
}

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