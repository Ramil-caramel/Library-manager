# Цель и задача:

Создание консольного  приложения реализующее функции картотеки для домашней библиотеки. 

# Функционал:

- Добавление новой книги
- Поиск книг по названию, автору, ключевым словам
- Вывод полного списка книг и возможность их сортировки
- Удаление книги из списка
- Вывод полной информации (по id книги из базы данных)

# Реализация:

Для реализации используется функционал SQLite 
Book - промежуточная структура используемая для реализации ввода данных
```
struct Book{
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
}
```

Library - класс используемый для реализации взаимодействия с базой данных.
Здесь полем является указатель на базу данных для сокрытия доступа от остальной программы.
```
class Library{
    
private:
    sqlite3* db;
public:
    Library();
    ~Library();

    Book addpromBook(); // добавляет в промежуточное
    bool addBookindatabase(Book*); // добавяляет в бд
    bool showBookFromTable(int regime = 1, int nach = 0); // вывод всей таблицы с указанным параметром сортировки
    int getTotalBooksCount();
    bool deleteBookById(int);
    bool getFindBookFromTable(int, std::string, int nach = 0);
    Book returnBook(int id); // возвращаем книгу по id
};
```
Menu - класс для реализации самого взаимодействия с приложеним
Класс реализован с патерном singltone для невозможности повторного создания Menu
```
class Menu
{
private:
    Library& lib;
    Menu(Library& ref) : lib{ref} {}
    static Menu* _instance;

public:
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    
    static Menu* Instence(Library&);


    void printMenu(); // начальное меню
    bool newBookMenu(); //меню добавления книги
    bool showallBookMenu(); // меню вывод всех книг
    bool outputBookMenu(); // меню вывод книги по id
    bool showBook(Book&); // меню вывод структуры 
    bool deleteBookMenu(); // меню удаления книги
    bool findBookMenu(); // меню поиска книги

    static void Destroy();

    ~Menu() {};
};
```