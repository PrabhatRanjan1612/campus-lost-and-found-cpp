# 🏫 Campus Lost and Found Portal (C++ Console Edition)

A simple, beginner-friendly console-based C++ application designed for college mini-projects. This project demonstrates core **Object-Oriented Programming (OOP)** principles such as **Inheritance**, **Polymorphism**, and dynamic memory management.

---

## 🚀 Features
- **Role-Based Access:** Support for both **Students** and **Admins**.
- **OOP Principles:** Implements a base `User` class with derived `Student` and `Admin` classes using virtual functions for polymorphism (`showInfo()`).
- **Item Management:** Users can view all registered items and report new **Lost** or **Found** belongings.
- **Interactive Console Menu:** Easy-to-use text menu for navigation.

---

## 🔑 Demo Credentials

| Role | Username | Password | Additional Info |
| :--- | :--- | :--- | :--- |
| **Student** | `rahul` | `1234` | Roll/ID: STU101 |
| **Admin** | `admin` | `admin123` | Department: Campus Security |

---

## 🛠️ How to Compile and Run

You can run this code using any standard C++ compiler (like g++, Dev-C++, Code::Blocks, or VS Code):

### Using Terminal / GCC (`g++`):
```bash
# Compile the code
g++ -std=c++11 main.cpp -o lost_and_found

# Run the executable
# On Linux/macOS:
./lost_and_found
# On Windows:
lost_and_found.exe
