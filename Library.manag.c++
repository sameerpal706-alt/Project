#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        issued = false;
    }
};

vector<Book> library;

// Add Book
void addBook() {
    int id;
    string title, author;

    cout << "\nEnter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    library.push_back(Book(id, title, author));

    cout << "Book added successfully.\n";
}

// Display Books
void displayBooks() {
    if (library.empty()) {
        cout << "\nNo books available.\n";
        return;
    }

    cout << "\n------ Book List ------\n";

    for (auto &book : library) {
        cout << "ID: " << book.id << endl;
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Status: " << (book.issued ? "Issued" : "Available") << endl;
        cout << "------------------------\n";
    }
}

// Search Book
void searchBook() {
    int id;
    cout << "\nEnter Book ID to search: ";
    cin >> id;

    for (auto &book : library) {
        if (book.id == id) {
            cout << "\nBook Found\n";
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Status: " << (book.issued ? "Issued" : "Available") << endl;
            return;
        }
    }

    cout << "Book not found.\n";
}

// Issue Book
void issueBook() {
    int id;
    cout << "\nEnter Book ID to issue: ";
    cin >> id;

    for (auto &book : library) {
        if (book.id == id) {
            if (!book.issued) {
                book.issued = true;
                cout << "Book issued successfully.\n";
            } else {
                cout << "Book is already issued.\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

// Return Book
void returnBook() {
    int id;
    cout << "\nEnter Book ID to return: ";
    cin >> id;

    for (auto &book : library) {
        if (book.id == id) {
            if (book.issued) {
                book.issued = false;
                cout << "Book returned successfully.\n";
            } else {
                cout << "Book was not issued.\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

// Delete Book
void deleteBook() {
    int id;
    cout << "\nEnter Book ID to delete: ";
    cin >> id;

    for (int i = 0; i < library.size(); i++) {
        if (library[i].id == id) {
            library.erase(library.begin() + i);
            cout << "Book deleted successfully.\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                cout << "Thank you for using Library Management System.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}