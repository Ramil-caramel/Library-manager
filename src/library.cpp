#include "library.hpp"

Library::Library(){
    char*  errMsg = nullptr;

    const char* SQL_TABLE = 
        "CREATE TABLE IF NOT EXISTS books ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "title TEXT NOT NULL,"
        "author TEXT NOT NULL,"
        "description TEXT,"
        "rating REAL,"
        "review TEXT,"
        "coverPhotoPath TEXT,"
        "bookFilePath TEXT"
        ");";

    if (sqlite3_open("test.db", &db) != SQLITE_OK){
        std::cerr << "база не открылась";
        sqlite3_close(db);
    }

    if (sqlite3_exec(db, SQL_TABLE, 0 , 0, &errMsg) != SQLITE_OK){
        std::cerr << "error";
        sqlite3_free(errMsg);
    }

    
}

Library::~Library(){
    sqlite3_close(db);
}

bool Library::addBookindatabase(Book* book){
    const char* sql = "INSERT INTO books (title, author, description, rating, review, coverPhotoPath, bookFilePath) VALUES (?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement" << std::endl;
        return 0;
    }
    // id не дкргаем оно само закинет так как я в начале sql поставил PRIMARY KEY AUTOINCREMENT
    // Привязываем параметры
    //sqlite3_bind_int(stmt, 1, this->id);
    sqlite3_bind_text(stmt, 1, book->title.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, book->author.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, book->description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 4, book->rating); 
    sqlite3_bind_text(stmt, 5, book->review.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, book->coverPhotoPath.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, book->bookFilePath.c_str(), -1, SQLITE_TRANSIENT);
    
    
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
    if (book.title == "") book.title = "not find";

    std:: cout << "введите автора: ";
    std::getline(std::cin, book.author);
    std::cout << std::endl;
    if (book.author == "") book.author = "not find";

    std::cout << "Введите текст описания (введите END на новой строке для завершения):\n";
    while (std::getline(std::cin, line)) {
        if (line == "END") break;
            full += line + '\n'; // сохраняем с переносами
    }
    if (!full.empty()) book.description = full;
    std::cout<<std::endl;

    std::cout << "введите рейтинг: ";
    try
    {
        std::getline(std::cin, rating);
        if (!rating.empty()) {
            double rate = std::stod(rating);
            book.rating = rate;
        }
        std::cout<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "ТЫ НЕХОРОШИЙ ЧЕЛОВЕК ВВЕЛ НЕ ЦИФЕРКИ А ГРЯЗНУЮ БУКВУ!!!!!!!!" << std::endl;
        book.rating = 0;

    }

    std:: cout << "введите свою рецензию (введите END на новой строке для завершения):\n";
    line = "";
    full = "";
    while (std::getline(std::cin, line)) {
        if (line == "END") break;
        full += line + '\n'; // сохраняем с переносами
    }
    if (!full.empty()) book.review = full;
    std::cout << std::endl;


    std:: cout << "введите путь к обложке книги: ";
    std::getline(std::cin, book.coverPhotoPath);
    std::cout << std::endl;
    if (book.coverPhotoPath == "") book.coverPhotoPath = "not find";

    std:: cout << "введите путь к файлу книги: ";
    std::getline(std::cin, book.bookFilePath);
    std::cout << std::endl;
    if (book.bookFilePath == "") book.bookFilePath = "not find";

    return book;
}


bool Library::showBookFromTable(int regim, int nach){
    std::string sql = "SELECT id, title, author FROM books";
    std::string reg1 = " ORDER BY title ";
    std::string reg2 = " ORDER BY author ";
    std::string lim = "LIMIT ? OFFSET ?";
    

    Book a;
    sqlite3_stmt* stmt;
    if (regim == 1){
        sql += reg1 + lim;
    }
    if (regim == 2){
        sql += reg2 +lim;
    }
    sql += ";";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, 5);
        sqlite3_bind_int(stmt, 2, nach); //ЗДЕСЬ МЕНЯЕТСЯ ЧИСЛО ВЫВОДЩИХСЯ В КОНСОЛЬ ПОЗИЦИЙ

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Book book;
            a.id = sqlite3_column_int(stmt, 0);
            a.title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            a.author = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            
            std::cout << "id: " << a.id << " title: " << a.title << " author: " << a.author << std::endl;   
        }
        sqlite3_finalize(stmt);
    } 
    else {
        std::cerr << "ошибка подготовки запроса" << std::endl;
    }
  

    return 1;
}

int Library::getTotalBooksCount() {
    const char* sql = "SELECT COUNT(*) FROM books;";
    sqlite3_stmt* stmt; 
    int count = 0;
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            count = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);

    }
    else{
        std::cout << "подгатовка запроса для просчета всей таблицы не удалась" << std::endl;
    }
    return count;
}


bool Library::deleteBookById(int id) {
    const char* sql = "DELETE FROM books WHERE id = ?;";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Ошибка подготовки запроса: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    }
    
    sqlite3_bind_int(stmt, 1, id);
    
    if (sqlite3_step(stmt) == SQLITE_DONE) {
        // Проверяем, была ли действительно строка вообще?
        if (sqlite3_changes(db) > 0) {
            std::cout << "Книга " << id << " удалена" << std::endl;
        } 
        else 
        {
            std::cout << "Книга " << id << " не найдена" << std::endl;
        }
    } 
    else {
        std::cerr << "Ошибка при удалении: " << sqlite3_errmsg(db) << std::endl;

    }
    
    sqlite3_finalize(stmt);
    
    return 1;
}

bool Library::getFindBookFromTable(int regim, std::string searchTerm, int nach){
    std::string sql = "SELECT id, title, author FROM books WHERE ";
    std::string reg1 = " title LIKE ? ";
    std::string reg2 = " author LIKE ? ";
    std::string lim = "LIMIT ? OFFSET ?";

    Book a;
    sqlite3_stmt* stmt;
    if (regim == 1){
        sql += reg1 + lim;
    }
    if (regim == 2){
        sql += reg2 +lim;
    }
    sql += ";";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        std::string searchPattern = "%" + searchTerm + "%";
        sqlite3_bind_text(stmt, 1, searchPattern.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 2, 5);
        sqlite3_bind_int(stmt, 3, nach); //ЗДЕСЬ МЕНЯЕТСЯ ЧИСЛО ВЫВОДЩИХСЯ В КОНСОЛЬ ПОЗИЦИЙ

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Book book;
            a.id = sqlite3_column_int(stmt, 0);
            a.title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            a.author = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            
            std::cout << "id: " << a.id << " title: " << a.title << " author: " << a.author << std::endl;   
        }
        sqlite3_finalize(stmt);
    } 
    else {
        std::cerr << "ошибка подготовки запроса" << std::endl;
    }
  

    return 1;
}