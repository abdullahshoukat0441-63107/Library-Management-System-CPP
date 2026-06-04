# C++ Library Management System (OOP Lab Project)

## Project Overview
This project is a console-based Library Management System built in C++ to demonstrate core Object-Oriented Programming (OOP) principles. The system allows users to seamlessly add books, view the library inventory, search for specific items, issue books, and process returns with automated fine calculations. All data is persistently stored using file handling.

## Core Features
* **Inventory Management:** Add new books and view the complete library catalog.
* **Smart Search:** Search for books by either their unique ID or Title.
* **Transaction Handling:** Issue books to users and process returns.
* **Automated Fines:** Automatically calculates late fees (Rs. 50/day) upon book return.
* **Data Persistence:** Automatically loads and saves all library data to a local text file (`library_data.txt`), ensuring no data is lost between sessions.

## OOP Concepts Implemented
* **Encapsulation:** Class variables (like `id`, `title`, and `isIssued`) are hidden and strictly accessed via public getter and setter methods.
* **Abstraction:** The `LibraryItem` class acts as an abstract blueprint utilizing a pure virtual function (`virtual void displayInfo() = 0;`).
* **Inheritance:** The `Book` class securely inherits core attributes and methods from the base `LibraryItem` class.
* **Static Polymorphism:** The `searchBook()` method is overloaded to accept either an integer (ID) or a string (Title).
* **Dynamic Polymorphism:** The `displayInfo()` method is overridden in the derived `Book` class to provide specific implementation details.

---

## Group Members & Work Breakdown

This project was developed collaboratively. The responsibilities and core module developments were divided as follows:

1. **[Abdullah Shoukat] - [2025-AI-399]
   * **Role:** GitHub Repository Management & Main Program Integration.
   * **Details:** Handled version control, repository setup, and merging. Developed the central `main.cpp` execution flow, implementing the interactive user menu and ensuring all external library components compiled and integrated flawlessly.

2. **[simra raza] - [2025-AI-377]**
   * **Role:** Class Architecture & Base Abstraction.
   * **Details:** Designed the header file (`Library.h`) and implemented the Abstract Base Class (`LibraryItem`), setting up the pure virtual functions and protected attributes.

3. **[Hafsa Shafiq] - [2025-AI-376]**
   * **Role:** Data Persistence & File Handling.
   * **Details:** Engineered the `loadBooks()` and `saveBooks()` functions in `Library.cpp`. Implemented robust stringstream parsing to safely read and write comma-separated values to the database file.

4. **[Zain Fiaz] - [2025-AI-393]**
   * **Role:** Core Book Mechanics & Dynamic Polymorphism.
   * **Details:** Implemented the derived `Book` class. Handled constructors, encapsulation (getters/setters), and successfully overrode the `displayInfo()` method for accurate data output.

5. **[Muhammad Ahmad] - [2025-AI-398]**
   * **Role:** Search Modules & Static Polymorphism.
   * **Details:** Developed the `displayAll()` function and engineered the overloaded `searchBook()` methods, allowing the system to process both integer and string search queries efficiently.

6. **[Ihab Ali] - [2025-AI_415]**
   * **Role:** Transaction Logic & Fine Calculation.
   * **Details:** Developed the logical state checks for the `issueBook()` and `returnBook()` functions. Implemented the mathematical logic to calculate and display financial penalties for overdue returns.

---

## How to Compile and Run

To run this project locally on your machine, you need a C++ compiler (like GCC) installed.

1. **Clone the repository:**
   ```bash
   git clone [YOUR_GITHUB_REPO_LINK_HERE]
   cd [YOUR_REPO_FOLDER_NAME]
