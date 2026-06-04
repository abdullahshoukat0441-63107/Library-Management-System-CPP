#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Abstract Base Class
class LibraryItem {
protected: 
    int id;
    string title;
public:
    LibraryItem(int id, string title);
    virtual void displayInfo() = 0; 
    virtual ~LibraryItem() {}
    
    int getId();
    string getTitle();
};

// Derived Class
class Book : public LibraryItem {
private:
    string author;
    bool isIssued;
public:
    Book(int id, string title, string author, bool issued = false);
    
    void displayInfo() override; 
    
    void setStatus(bool status); 
    string getAuthor();
    bool getStatus();
};

class LibraryManager {
private:
    vector<Book> books;
    const string filename = "library_data.txt";

public:
    void loadBooks();
    void saveBooks();
    
    void addBook(int id, string title, string author);
    void displayAll();
    
    void searchBook(int id);
    void searchBook(string title);

    void issueBook(int id);
    void returnBook(int id, int daysLate);
};

#endif