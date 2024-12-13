#include "LinkedList.h"
#include "Movie.h"
#include "Book.h"

#include <string>
#include <iostream>
using namespace std;

void displayMenu()
{
    cout << "=========================================\n";
    cout << "           📚 Library Menu               \n";
    cout << "=========================================\n";
    cout << "1. Add a New Book\n";
    cout << "2. Add a New Movie\n";
    cout << "3. Search for a Book\n";
    cout << "4. Search for a Movie\n";
    cout << "5. Borrow a Media Item\n";
    cout << "6. Return a Media Item\n";
    cout << "7. List All Books\n";
    cout << "8. List All Movies\n";
    cout << "9. Exit\n";
    cout << "=========================================";
    cout << "Please choose an option (1-9): ";
}

void addBook(LinkedList &library)
{
    string name, status, author, genre;
    int yearReleased, pageNum;

    cout << "\nEnter the book's title: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the book's status (e.g., Available): ";
    getline(cin, status);
    cout << "Enter the author's name: ";
    getline(cin, author);
    cout << "Enter the genre: ";
    getline(cin, genre);
    cout << "Enter the year released: ";
    cin >> yearReleased;
    cout << "Enter the number of pages: ";
    cin >> pageNum;

    library.push_back(new Book(name, status, yearReleased, author, genre, pageNum));
    cout << "Book \"" << name << "\" added successfully!\n";
}

void addMovie(LinkedList &library)
{
    string name, status, director, genre;
    int yearReleased;
    double duration;

    cout << "\nEnter the movie's title: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the movie's status (e.g., Available): ";
    getline(cin, status);
    cout << "Enter the director's name: ";
    getline(cin, director);
    cout << "Enter the genre: ";
    getline(cin, genre);
    cout << "Enter the year released: ";
    cin >> yearReleased;
    cout << "Enter the duration (in minutes): ";
    cin >> duration;

    library.push_back(new Movie(name, status, yearReleased, director, genre, duration));
    cout << "Movie \"" << name << "\" added successfully!\n";
}

void searchMedia(const LinkedList &library, const string &type)
{
    string name;
    cout << "\nEnter the " << type << "'s title to search: ";
    cin.ignore();
    getline(cin, name);

    Node *current = library.getHead();
    while (current != nullptr)
    {
        Media *media = current->getData();
        if (media->getName() == name)
        {
            cout << type << " \"" << name << "\" is available in the library.\n";
            media->print();
            return;
        }
        current = current->getNext();
    }
    cout << type << " \"" << name << "\" not found in the library.\n";
}

void listMedia(const LinkedList &library)
{
    if (library.size() == 0)
    {
        cout << "\nNo media items available in the library.\n";
        return;
    }
    cout << "\nListing all media items in the library:\n";
    library.printToScreen();
}

int main()
{
    LinkedList library; // A collection of books and movies
    LinkedList books;
    LinkedList movies;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook(books);
            break;
        case 2:
            addMovie(movies);
            break;
        case 3:
            searchMedia(books, "Book");
            break;
        case 4:
            searchMedia(movies, "Movie");
            break;
        case 5:
            cout << "\nBorrowing a media item is under development...\n";
            break;
        case 6:
            cout << "\nReturning a media item is under development...\n";
            break;
        case 7:
            listMedia(books);
            break;
        case 8:
            listMedia(movies);
            break;
        case 9:
            cout << "\nThank you for using the library system! Goodbye.\n";
            break;
        default:
            cout << "\nInvalid option! Please choose a number between 1 and 8.\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 8);

    return 0;
}