#include "Library.h"

LibraryItem::LibraryItem(int id, string title) {
    this->id = id;
    this->title = title;
}
int LibraryItem::getId() { return id; }
string LibraryItem::getTitle() { return title; }

Book::Book(int id, string title, string author, bool issued) : LibraryItem(id, title) {
    this->author = author;
    this->isIssued = issued;
}

void Book::displayInfo() {
    cout << "ID: " << id << " | Title: " << title 
         << " | Author: " << author 
         << " | Status: " << (isIssued ? "Issued" : "Available") << endl;
}

void Book::setStatus(bool status) { isIssued = status; }
string Book::getAuthor() { return author; }
bool Book::getStatus() { return isIssued; }

void LibraryManager::loadBooks() {
    ifstream file(filename);
    if (!file) return; 

    string line, title, author, statusStr;

    while (getline(file, line)) {
        if (line.empty() || line.find_first_not_of(" \t\r\n") == string::npos) {
            continue; 
        }

        stringstream ss(line);
        string tempId;
        
        int id = 0; bool status = false;

        try {
            getline(ss, tempId, ','); id = stoi(tempId);
            getline(ss, title, ',');
            getline(ss, author, ',');
            
            if (getline(ss, statusStr, ',')) status = stoi(statusStr);
            
            books.push_back(Book(id, title, author, status));
        } catch (...) {
            continue;
        }
    }
    file.close();
}

void LibraryManager::saveBooks() {
    ofstream file(filename);
    for (Book& b : books) {
        file << b.getId() << "," << b.getTitle() << "," 
             << b.getAuthor() << "," << b.getStatus() << "\n";
    }
    file.close();
}

void LibraryManager::addBook(int id, string title, string author) {
    books.push_back(Book(id, title, author));
    saveBooks();
    cout << "Book added successfully!" << endl;
}

void LibraryManager::displayAll() {
    if (books.empty()) {
        cout << "Library is empty." << endl;
        return;
    }
    for (Book& b : books) {
        b.displayInfo();
    }
}

void LibraryManager::searchBook(int id) {
    for (Book& b : books) {
        if (b.getId() == id) {
            b.displayInfo();
            return;
        }
    }
    cout << "Book not found." << endl;
}

void LibraryManager::searchBook(string title) {
    for (Book& b : books) {
        if (b.getTitle() == title) {
            b.displayInfo();
            return;
        }
    }
    cout << "Book not found." << endl;
}

void LibraryManager::issueBook(int id) {
    for (Book& b : books) {
        if (b.getId() == id) {
            if (!b.getStatus()) {
                b.setStatus(true);
                saveBooks();
                cout << "Success: Book '" << b.getTitle() << "' has been issued." << endl;
            } else {
                cout << "Error: This book is already issued." << endl;
            }
            return;
        }
    }
    cout << "Error: Book ID not found." << endl;
}

void LibraryManager::returnBook(int id, int daysLate) {
    for (Book& b : books) {
        if (b.getId() == id) {
            if (b.getStatus()) {
                b.setStatus(false);
                saveBooks();
                cout << "\n--- Return Processed ---" << endl;
                cout << "Book: " << b.getTitle() << " returned successfully." << endl;
                
                if (daysLate > 0) {
                    int fine = daysLate * 50; 
                    cout << "Notice: Book is late by " << daysLate << " days." << endl;
                    cout << "TOTAL FINE DUE: Rs. " << fine << endl;
                } else {
                    cout << "Returned on time. No fine due." << endl;
                }
                cout << "------------------------\n" << endl;
            } else {
                cout << "Error: This book was not issued." << endl;
            }
            return;
        }
    }
    cout << "Error: Book ID not found." << endl;
}
