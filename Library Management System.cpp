#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string name;
    string author;
    int quantity;
};

void addBook() {

    Book b;

    ofstream file("books.txt", ios::app);

    cout << "\nEnter Book ID: ";
    cin >> b.id;

    cin.ignore();

    cout << "Enter Book Name: ";
    getline(cin, b.name);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    cout << "Enter Quantity: ";
    cin >> b.quantity;

    file << b.id << endl;
    file << b.name << endl;
    file << b.author << endl;
    file << b.quantity << endl;

    file.close();

    cout << "\nBook added successfully\n";
}

void viewBooks() {

    Book b;

    ifstream file("books.txt");

    if (!file) {
        cout << "\nNo records found\n";
        return;
    }

    cout << "\n===== Book Records =====\n";

    while (file >> b.id) {

        file.ignore();
        getline(file, b.name);
        getline(file, b.author);
        file >> b.quantity;
        file.ignore();

        cout << "\nBook ID: " << b.id;
        cout << "\nName: " << b.name;
        cout << "\nAuthor: " << b.author;
        cout << "\nQuantity: " << b.quantity;
        cout << "\n-------------------------\n";
    }

    file.close();
}

void searchBook() {

    Book b;
    int id;
    bool found = false;

    ifstream file("books.txt");

    cout << "\nEnter Book ID to search: ";
    cin >> id;

    while (file >> b.id) {

        file.ignore();
        getline(file, b.name);
        getline(file, b.author);
        file >> b.quantity;
        file.ignore();

        if (b.id == id) {

            cout << "\nBook Found\n";
            cout << "Name: " << b.name << endl;
            cout << "Author: " << b.author << endl;
            cout << "Quantity: " << b.quantity << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nBook not found\n";

    file.close();
}

int main() {

    int choice;

    while (true) {

        cout << "\n===== Library Management System =====\n";
        cout << "1 Add Book\n";
        cout << "2 View Books\n";
        cout << "3 Search Book\n";
        cout << "4 Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addBook();
            break;

        case 2:
            viewBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}