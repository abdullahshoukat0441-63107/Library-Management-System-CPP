#include "Library.h"
#include <iostream>
using namespace std;
int main()
{
    LibraryManager myLibrary;
    myLibrary.loadBooks();

    int choice;
    do
    {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add a Book\n2. View All Books\n3. Search by ID\n4. Search by Title\n";
        cout << "5. Issue a Book\n6. Return a Book (Calculate Fine)\n7. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1)
        {
            int id;
            string title, author;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            myLibrary.addBook(id, title, author);
        }
        else if (choice == 2)
        {
            myLibrary.displayAll();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            myLibrary.searchBook(id);
        }
        else if (choice == 4)
        {
            string title;
            cin.ignore();
            cout << "Enter Title to search: ";
            getline(cin, title);
            myLibrary.searchBook(title);
        }
        else if (choice == 5)
        {
            int id;
            cout << "Enter ID of the book to issue: ";
            cin >> id;
            myLibrary.issueBook(id);
        }
        else if (choice == 6)
        {
            int id, daysLate;
            cout << "Enter ID of the returned book: ";
            cin >> id;
            cout << "How many days late is it? (Enter 0 if on time): ";
            cin >> daysLate;
            myLibrary.returnBook(id, daysLate);
        }
    } while (choice != 7);
    cout << "     Thank you for using Library Management System";
    return 0;
}
