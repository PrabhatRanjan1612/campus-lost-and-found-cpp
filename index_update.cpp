#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. OOP CLASSES (Inheritance & Polymorphism)
// ==========================================

// Base Class (Parent)
class User {
protected:
    string username;
    string password;
    string role;

public:
    User(string u, string p, string r) {
        username = u;
        password = p;
        role = r;
    }
    virtual ~User() {} // Virtual destructor for inheritance

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getRole() const { return role; }

    // Virtual function for polymorphism
    virtual void showInfo() const {
        cout << "User: " << username << " (" << role << ")\n";
    }
};

// Derived Class 1: Student (Inherits from User)
class Student : public User {
private:
    string studentId;

public:
    Student(string u, string p, string id) : User(u, p, "Student") {
        studentId = id;
    }

    // Overriding showInfo function
    void showInfo() const override {
        cout << "Student: " << username << " [Student ID: " << studentId << "]\n";
    }
};

// Derived Class 2: Admin (Inherits from User)
class Admin : public User {
private:
    string department;

public:
    Admin(string u, string p, string dept) : User(u, p, "Admin") {
        department = dept;
    }

    // Overriding showInfo function
    void showInfo() const override {
        cout << "Admin: " << username << " [Department: " << department << "]\n";
    }
};

// Item Class
class Item {
public:
    int id;
    string type;      // "Lost" ya "Found"
    string name;      // Cheez ka naam
    string location;  // Kahan mili ya khoyi
    string reporter;  // Kisne report kiya

    Item(int i, string t, string n, string l, string r) {
        id = i; type = t; name = n; location = l; reporter = r;
    }

    void display() const {
        cout << "------------------------------------\n";
        cout << "ID       : " << id << "\n";
        cout << "Type     : " << type << "\n";
        cout << "Item     : " << name << "\n";
        cout << "Location : " << location << "\n";
        cout << "Reported : " << reporter << "\n";
    }
};

// ==========================================
// 2. MAIN FUNCTION
// ==========================================
int main() {
    // Polymorphic vector of User pointers
    vector<User*> users;
    users.push_back(new Student("rahul", "1234", "STU101"));
    users.push_back(new Admin("admin", "admin123", "Campus Security"));

    // Initial dummy items
    vector<Item> items = {
        Item(1, "Lost", "Water Bottle", "Library", "rahul"),
        Item(2, "Found", "Calculator", "Lab 3", "admin")
    };

    cout << "====================================\n";
    cout << "   CAMPUS LOST & FOUND PORTAL       \n";
    cout << "====================================\n";

    User* currentUser = nullptr;
    string u, p;

    // Login Loop
    while (currentUser == nullptr) {
        cout << "\n[ LOGIN ]\n";
        cout << "Student -> rahul / 1234\n";
        cout << "Admin   -> admin / admin123\n";
        cout << "Username: "; cin >> u;
        cout << "Password: "; cin >> p;

        for (User* user : users) {
            if (user->getUsername() == u && user->getPassword() == p) {
                currentUser = user;
                break;
            }
        }

        if (currentUser == nullptr) {
            cout << "Galat username ya password! Phir se koshish karein.\n";
        }
    }

    cout << "\nLogin Successful! Welcome -> ";
    currentUser->showInfo(); // Polymorphism in action!

    // Main Menu Loop
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. View All Items\n";
        cout << "2. Report Lost or Found Item\n";
        cout << "3. Logout & Exit\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n--- All Items List ---\n";
            if (items.empty()) {
                cout << "Koi item registered nahi hai.\n";
            } else {
                for (const auto& item : items) {
                    item.display();
                }
            }
        } 
        else if (choice == 2) {
            string type, name, loc;
            cout << "Enter Type (Lost / Found): "; cin >> type;
            cout << "Enter Item Name: "; cin.ignore(); getline(cin, name);
            cout << "Enter Location: "; getline(cin, loc);

            int newId = items.size() + 1;
            items.push_back(Item(newId, type, name, loc, currentUser->getUsername()));
            cout << "Success! Item added with ID: " << newId << "\n";
        } 
        else if (choice == 3) {
            cout << "Exiting program. Goodbye!\n";
        } 
        else {
            cout << "Invalid choice! 1, 2 ya 3 enter karein.\n";
        }

    } while (choice != 3);

    // Memory clean up (delete dynamic memory)
    for (User* user : users) {
        delete user;
    }
    users.clear();

    return 0;
}