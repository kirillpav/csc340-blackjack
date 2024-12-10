#include "LinkedList.h"
#include "Movie.h"
#include "Book.h"

#include <string>
#include <iostream>
using namespace std;

// H-What in chernobyl happened here
void displayMenu()
{
    cout << "=========================================\n";
    cout << "           📚 Library Menu               \n";
    cout << "=========================================\n";
    cout << "1. Add a New Book\n";
    cout << "2. Search for a Book\n";
    cout << "3. Borrow a Book\n";
    cout << "4. Return a Book\n";
    cout << "5. List All Books\n";
    cout << "6. Exit\n";
    cout << "=========================================\n";
    cout << "Please choose an option (1-6): ";
}

int main()
{
    LinkedList library; // A collection of books
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            // addBook(library);
            break;
        case 2:
            // searchBook(library);
            break;
        case 3:
            // cout << "\nBorrowing a book is under development...\n";
            break;
        case 4:
            // cout << "\nReturning a book is under development...\n";
            break;
        case 5:
            // listBooks(library);
            break;
        case 6:
            cout << "\nThank you for using the library system! Goodbye.\n";
            break;
        default:
            cout << "\nInvalid option! Please choose a number between 1 and 6.\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 6);

    return 0;
}