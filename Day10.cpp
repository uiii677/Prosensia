#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

const char* FILENAME = "inventory.txt";

// Add new item
void addItem() {
    Item newItem;
    cout << "Enter Item ID: ";
    cin >> newItem.id;

    // Check for duplicate
    ifstream inFile(FILENAME, ios::binary);
    Item temp;
    while (inFile.read((char*)&temp, sizeof(Item))) {
        if (temp.id == newItem.id) {
            cout << "ID already exists!\n";
            inFile.close();
            return;
        }
    }
    inFile.close();

    cin.ignore();
    cout << "Enter Item Name: ";
    cin.getline(newItem.name, 50);
    cout << "Enter Quantity: ";
    cin >> newItem.quantity;
    cout << "Enter Price: ";
    cin >> newItem.price;

    ofstream outFile(FILENAME, ios::binary | ios::app);
    outFile.write((char*)&newItem, sizeof(Item));
    outFile.close();

    cout << "Item added successfully.\n";
}

// View all items
void viewAllItems() {
    ifstream inFile(FILENAME, ios::binary);
    Item item;
    cout << "\nID\tName\t\tQty\tPrice\n";
    while (inFile.read((char*)&item, sizeof(Item))) {
        cout << item.id << "\t" << item.name << "\t" << item.quantity << "\t" << item.price << endl;
    }
    inFile.close();
}

// Search item by ID
void searchItemByID() {
    int searchID;
    cout << "Enter ID to search: ";
    cin >> searchID;

    ifstream inFile(FILENAME, ios::binary);
    Item item;
    bool found = false;

    while (inFile.read((char*)&item, sizeof(Item))) {
        if (item.id == searchID) {
            cout << "\nItem Found:\n";
            cout << item.id << "\t" << item.name << "\t" << item.quantity << "\t" << item.price << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Item not found.\n";
    inFile.close();
}

// Update item quantity
void updateQuantity() {
    int id, change;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Quantity Change (+/-): ";
    cin >> change;

    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    Item item;
    bool found = false;

    while (file.read((char*)&item, sizeof(Item))) {
        if (item.id == id) {
            item.quantity += change;
            if (item.quantity < 0) item.quantity = 0;

            int pos = file.tellg();
            file.seekp(pos - sizeof(Item));
            file.write((char*)&item, sizeof(Item));
            cout << "Quantity updated.\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Item not found.\n";
    file.close();
}

// Delete item
void deleteItem() {
    int deleteID;
    cout << "Enter ID to delete: ";
    cin >> deleteID;

    ifstream inFile(FILENAME, ios::binary);
    ofstream outFile("temp.txt", ios::binary);

    Item item;
    bool deleted = false;

    while (inFile.read((char*)&item, sizeof(Item))) {
        if (item.id != deleteID) {
            outFile.write((char*)&item, sizeof(Item));
        } else {
            deleted = true;
        }
    }

    inFile.close();
    outFile.close();

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (deleted)
        cout << "Item deleted.\n";
    else
        cout << "Item not found.\n";
}

// Menu
void menu() {
    int choice;
    do {
        cout << "\n===== Inventory Menu =====\n";
        cout << "1. Add Item\n2. View All Items\n3. Search by ID\n";
        cout << "4. Update Quantity\n5. Delete Item\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) addItem();
        else if (choice == 2) viewAllItems();
        else if (choice == 3) searchItemByID();
        else if (choice == 4) updateQuantity();
        else if (choice == 5) deleteItem();
        else if (choice == 6) cout << "Exiting...\n";
        else cout << "Invalid choice.\n";

    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}

