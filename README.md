# C++ Library Management System (OOP Lab Project)

## Project Overview
This project is a console-based Library Management System built in C++ to demonstrate core Object-Oriented Programming principles. The system allows users to add books, view the library inventory, search for items, and persist data using file handling.

## OOP Concepts Implemented
* **Encapsulation:** Class variables (like `id` and `title`) are hidden and accessed via public getter methods.
* **Abstraction:** The `LibraryItem` class uses a pure virtual function (`displayInfo()`), acting as an abstract blueprint.
* **Inheritance:** The `Book` class inherits attributes and methods from the base `LibraryItem` class.
* **Static Polymorphism:** The `searchBook()` method is overloaded to accept either an integer ID or a string Title.
* **Dynamic Polymorphism:** The `displayInfo()` method is overridden in the `Book` class to provide specific implementation details.
* **File Handling:** The inventory is automatically saved to and loaded from `library_data.txt`.

## Group Members & Contributions
* **Muhammad Abdullah Shoukat [2025-AI-399]:** Designed the class architecture (Library.h) and implemented the Abstract base class.
* **Ihab Ali [2025-AI-415]:** Implemented File Handling (loading and saving from .txt) and the main interface.
* **Muhammad Ahmad [2025-AI-398]:** Developed Static and Dynamic Polymorphism logic (overloaded search functions and overriding).
* **Zain Fiaz [2025-AI-393]:** Handled VS Code compilation, GitHub repository management, and debugging.


