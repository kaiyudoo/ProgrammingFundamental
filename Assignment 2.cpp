#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAXBOOKS = 100;
const int MAXSALES = 100;

struct Book {
    string isbn;
    string title;
    string author;
    double price;
    int stock;
};

struct SaleRecord {
    string isbn;
    string title;
    int quantity;
    double totalPrice;
};

Book inventory[MAXBOOKS];
SaleRecord sales[MAXSALES];
int bookCount = 0;
int saleCount = 0;

void mainMenu() {

    cout << "\n----- BOOKSTORE INVENTORY & SALES SYSTEM -----\n";
	cout << "1. Add New Book\n";
    cout << "2. Display All Books\n";
	cout << "3. Search Book (by ISBN or Title)\n";
    cout << "4. Buy Book\n";
    cout << "5. Show Sales Summary\n";
    cout << "6. Exit\n";

    cout << endl;

}
    
void addBook() {
	
	if (bookCount >= MAXBOOKS) {
   		cout << "\nInventory full! Cannot add more books.\n";
    	return;
    }
    
    Book b;
    
    inventory[bookCount++] = b;
    
    cout << "\n--- Add New Book ---\n";
    cout << "Enter ISBN: ";
    cin >> b.isbn;
    cout << "Enter Title: ";
    getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    cout << "Enter Price (RM): ";
    cin >> b.price;
    cout << "Enter Stock Quantity: ";
    cin >> b.stock;
	cin.ignore();
	
	
    cout << "Book added successfully!\n";
}

void displayBooks() {
    cout << "\n--- Book List ---\n";
    
    if (bookCount == 0) {
        cout << "\nNo books available.\n";
        return;
    }

  	cout << "\n\nBook Details : " << endl;
	cout << left << setw(15) << "ISBN" << setw(30) << "Title" << setw(20) << "Author" << setw(10) << "Price" << setw(10) << "Stock" << endl;

	cout << fixed << setprecision(2);

	for (int i = 0; i < bookCount; i++) {
        cout << left << setw(15) << inventory[i].isbn
             << setw(30) << inventory[i].title
             << setw(20) << inventory[i].author
             << setw(10) << fixed << setprecision(2) << inventory[i].price
             << setw(10) << inventory[i].stock << endl;
	}
}

void searchBook() {
    cout << "\n--- Search Book ---\n";
    if (bookCount == 0) {
        cout << "\nNo books to search.\n";
        return;
    }

  	int choice;
    cout << "\nSearch by: 1. ISBN  2. Title\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    string input;
    bool found = false;

        if (choice == 1) {
        cout << "Enter ISBN: ";
        getline(cin, input);
        for (int i = 0; i < bookCount; i++) {
            if (inventory[i].isbn == input) {
                cout << "\nBook Found!\n";
            	cout << "ISBN: " << inventory[i].isbn << endl;
            	cout << "Title: " << inventory[i].title << endl;
            	cout << "Author: " << inventory[i].author << endl;
            	cout << "Price: RM" << inventory[i].price << endl;
            	cout << "Stock: " << inventory[i].stock << endl;
                found = true;
                break;
            }
        }
    } else if (choice == 2) {
        cout << "Enter Title: ";
        getline(cin, input);
        for (int i = 0; i < bookCount; i++) {
            if (inventory[i].title == input) {
                cout << "\nBook Found!\n";
            	cout << "ISBN: " << inventory[i].isbn << endl;
            	cout << "Title: " << inventory[i].title << endl;
            	cout << "Author: " << inventory[i].author << endl;
            	cout << "Price: RM" << inventory[i].price << endl;
            	cout << "Stock: " << inventory[i].stock << endl;
                found = true;
                break;
            }
        }
    } else {
        cout << "\nInvalid option.\n";
        return;
    }

    if (!found)
        cout << "\nBook not found.\n";
}
    
void buyBook() {
    if (bookCount == 0) {
        cout << "\nNo books in inventory.\n";
        return;
    }

    string isbn;
    cout << "\nEnter ISBN of the book to buy: ";
    cin.ignore();
    getline(cin, isbn);

    for (int i = 0; i < bookCount; i++) {
        if (inventory[i].isbn == isbn) {
            cout << "Book: " << inventory[i].title << " (Stock: " << inventory[i].stock << ")\n";
            cout << "Enter quantity to buy: ";
            int qty;
            cin >> qty;

            if (qty <= 0) {
                cout << "Invalid quantity.\n";
                return;
            }

            if (qty > inventory[i].stock) {
                cout << "Insufficient stock!\n";
                return;
            }

            double total = qty * inventory[i].price;
            inventory[i].stock = inventory[i].stock - qty;

    
            sales[saleCount++] = {inventory[i].isbn, inventory[i].title, qty, total};

            cout << "\nPurchase successful! Total Price: RM" << fixed << setprecision(2) << total << endl;
            return;
        }
    }

    cout << "\nBook not found.\n";
}

void showSalesSummary() {
    if (saleCount == 0) {
        cout << "\nNo sales made yet.\n";
        return;
    }

    double totalSales = 0;
    cout << "\n=== SALES SUMMARY ===\n";
    cout << left << setw(15) << "ISBN" << setw(30) << "Title"
         << setw(10) << "Qty" << setw(15) << "Total (RM)" << endl;
    cout << string(70, '-') << endl;

    for (int i = 0; i < saleCount; i++) {
        cout << left << setw(15) << sales[i].isbn
             << setw(30) << sales[i].title
             << setw(10) << sales[i].quantity
             << setw(15) << fixed << setprecision(2) << sales[i].totalPrice << endl;
        totalSales += sales[i].totalPrice;
    }

    cout << "\nTotal Sales for the Day: RM" << fixed << setprecision(2) << totalSales << endl;

    cout << "\nRemaining Stock:\n";
    displayBooks();
}


int main() {
	int choice;
	
	do{
		mainMenu();
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
                buyBook();
                break;

            case 5:
                showSalesSummary();
                break;

            case 6:
                cout << "Exiting program... Thank you!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
		
		
		
	}while (choice != 6);
	
	return 0;
}
