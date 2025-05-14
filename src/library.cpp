#include "library.hpp"

bool Library::addBookindatabase(sqlite3* db, Book* book){
    const char* sql = "INSERT INTO books (title, author, description, rating, review, coverPhotoPath, bookFilePath) VALUES (?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement" << std::endl;
        return 0;
    }
    // id не дкргаем оно само закинет так как я в начале sql поставил PRIMARY KEY AUTOINCREMENT
    // Привязываем параметры
    //sqlite3_bind_int(stmt, 1, this->id);
    sqlite3_bind_text(stmt, 1, book->gettitle().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, book->getauthor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, book->getdescription().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 4, book->getrating()); 
    sqlite3_bind_text(stmt, 5, book->getreview().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, book->getcoverPhotoPath().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, book->getbookFilePath().c_str(), -1, SQLITE_TRANSIENT);
    
    
    // Выполняем запрос
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Execution failed: " << std::endl;
        sqlite3_finalize(stmt);
        return 0;
    }

    sqlite3_finalize(stmt);
    return 1;
}

bool Library::chowBook(Book* book){
    std::cout << book->title << std::endl;
    std::cout << book->author << std::endl;
    std::cout << book->description << std::endl;
    std::cout << book->rating << std::endl;
    std::cout << book->review << std::endl;
    std::cout << book->coverPhotoPath << std::endl;
    std::cout << book->bookFilePath << std::endl;
    return 1;
}

Book Library::addpromBook(){
    Book book;

    std::string rating;
    std::string full, line;
    //std::vector<std::string> tags;

    std::cout << "Добавление книги, если хотите оставить параметр пустым просто нажмите enther" << std::endl;

    std:: cout << "введите название книги: ";
    std::getline(std::cin, book.title);
    std::cout << std::endl;
    if (book.title == "") book.settitle("not find");

    std:: cout << "введите автора: ";
    std::getline(std::cin, book.author);
    std::cout << std::endl;
    if (book.author == "") book.setauthor("not find");

    std::cout << "Введите текст описания (введите END на новой строке для завершения):\n";
    while (std::getline(std::cin, line)) {
        if (line == "END") break;
            full += line + '\n'; // сохраняем с переносами
    }
    if (!full.empty()) book.setdescription(full);
    std::cout<<std::endl;

    std::cout << "введите рейтинг: ";
    std::getline(std::cin, rating);
    if (!rating.empty()) {
        double rate = std::stod(rating);
        book.setrating(rate);
    }
    std::cout<<std::endl;

    std:: cout << "введите свою рецензию (введите END на новой строке для завершения):\n";
    line = "";
    full = "";
    while (std::getline(std::cin, line)) {
        if (line == "END") break;
        full += line + '\n'; // сохраняем с переносами
    }
    if (!full.empty()) book.setreview(full);
    std::cout << std::endl;


    std:: cout << "введите путь к обложке книги: ";
    std::getline(std::cin, book.coverPhotoPath);
    std::cout << std::endl;
    if (book.coverPhotoPath == "") book.setcoverPhotoPath("not find");

    std:: cout << "введите путь к файлу книги: ";
    std::getline(std::cin, book.bookFilePath);
    std::cout << std::endl;
    if (book.bookFilePath == "") book.setbookFilePath("not find");

    return book;
}