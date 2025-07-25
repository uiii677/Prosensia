#include <iostream>
#include <fstream>
using namespace std;

class Book {
protected:
    int id;
    string title;
    string author;

public:
    Book(int i = 0, string t = "", string a = "") : id(i), title(t), author(a) {}

    void input() {
        cout << "Enter Book ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Book Title: "; getline(cin, title);
        cout << "Enter Author Name: "; getline(cin, author);
    }

    void display() {
        cout << "\nBook ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }

    int getID() {
        return id;
    }

    string toString() {
        return to_string(id) + "|" + title + "|" + author + "\n";
    }
};

class Library : public Book {
public:
    void addBook() {
        Book b;
        b.input();
        ofstream file("books.txt", ios::app);
        file << b.toString();
        file.close();
        cout << "Book added successfully.\n";
    }

    void viewBooks() {
        ifstream file("books.txt");
        string line;
        bool found = false;
        cout << "\n--- All Books ---\n";
        while (getline(file, line)) {
            found = true;
            int idPos = line.find('|');
            int titlePos = line.find('|', idPos + 1);

            int id = stoi(line.substr(0, idPos));
            string title = line.substr(idPos + 1, titlePos - idPos - 1);
            string author = line.substr(titlePos + 1);

            cout << "\nBook ID: " << id << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
        }
        if (!found) cout << "No books found.\n";
        file.close();
    }

    void searchBook(int searchID) {
        ifstream file("books.txt");
        string line;
        bool found = false;
        while (getline(file, line)) {
            int idPos = line.find('|');
            int titlePos = line.find('|', idPos + 1);

            int id = stoi(line.substr(0, idPos));
            if (id == searchID) {
                string title = line.substr(idPos + 1, titlePos - idPos - 1);
                string author = line.substr(titlePos + 1);

                cout << "\nBook Found:\n";
                cout << "Book ID: " << id << endl;
                cout << "Title: " << title << endl;
                cout << "Author: " << author << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "Book not found.\n";
        file.close();
    }
};

int main() {
    Library lib;
    int choice;
    while (true) {
        cout << "\n1. Add Book\n2. View All Books\n3. Search Book by ID\n4. Exit\nChoose: ";
        cin >> choice;
        if (choice == 1)
            lib.addBook();
        else if (choice == 2)
            lib.viewBooks();
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;
            lib.searchBook(id);
        }
        else if (choice == 4)
            break;
        else
            cout << "Invalid choice.\n";
    }
    return 0;
}

