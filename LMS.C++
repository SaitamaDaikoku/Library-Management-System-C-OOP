#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  BOOK CLASS 
class Book {
protected:
    int bookID;
    string title;
    string author;
    bool issued;

public:
    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        issued = false;
    }

    int getBookID() {
        return bookID;
    }

    string getTitle() {
        return title;
    }

    bool isIssued() {
        return issued;
    }

    void issueBook() {
        issued = true;
    }

    void returnBook() {
        issued = false;
    }

    void displayBook() {
        cout << "\nBook ID : " << bookID;
        cout << "\nTitle   : " << title;
        cout << "\nAuthor  : " << author;
        cout << "\nStatus  : " << (issued ? "Issued" : "Available") << endl;
    }
};

//  USER CLASS 
class User {
private:
    int userID;
    string name;

public:
    User(int id, string n) {
        userID = id;
        name = n;
    }

    int getUserID() {
        return userID;
    }

    string getName() {
        return name;
    }

    void displayUser() {
        cout << "\nUser ID : " << userID;
        cout << "\nName    : " << name << endl;
    }
};

// LIBRARY CLASS 
class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    // Add Book
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "\nBook Added Successfully!\n";
    }

    // Display All Books
    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo books available.\n";
            return;
        }

        for (auto &book : books) {
            book.displayBook();
            cout << "------------------------\n";
        }
    }

    // Add User
    void addUser() {
        int id;
        string name;

        cout << "\nEnter User ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        users.push_back(User(id, name));

        cout << "\nUser Added Successfully!\n";
    }

    // Issue Book
    void issueBook() {
        int id;

        cout << "\nEnter Book ID to Issue: ";
        cin >> id;

        for (auto &book : books) {
            if (book.getBookID() == id) {
                if (!book.isIssued()) {
                    book.issueBook();
                    cout << "\nBook Issued Successfully!\n";
                } else {
                    cout << "\nBook Already Issued!\n";
                }
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }

    // Return Book
    void returnBook() {
        int id;

        cout << "\nEnter Book ID to Return: ";
        cin >> id;

        for (auto &book : books) {
            if (book.getBookID() == id) {
                if (book.isIssued()) {
                    book.returnBook();
                    cout << "\nBook Returned Successfully!\n";
                } else {
                    cout << "\nBook Was Not Issued!\n";
                }
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }

    // Search Book
    void searchBook() {
        string title;
        cin.ignore();

        cout << "\nEnter Book Title: ";
        getline(cin, title);

        for (auto &book : books) {
            if (book.getTitle() == title) {
                cout << "\nBook Found:\n";
                book.displayBook();
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }
};

// MAIN FUNCTION 
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Add User\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Search Book\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;

            case 2:
                lib.displayBooks();
                break;

            case 3:
                lib.addUser();
                break;

            case 4:
                lib.issueBook();
                break;

            case 5:
                lib.returnBook();
                break;

            case 6:
                lib.searchBook();
                break;

            case 7:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
