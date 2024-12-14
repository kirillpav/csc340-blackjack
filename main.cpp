#include "LinkedList.h"
#include "Movie.h"
#include "Book.h"
#include "Member.h"
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
    cout << "7. Merge Libraries\n";
    cout << "8. Sort Media\n";
    cout << "9. List All Media\n";
    cout << "10. Exit\n";
    cout << "=========================================";
    cout << "Please choose an option (1-10): ";
}

void addBook(LinkedList &library, LinkedList &secondLibrary)
{
    string name, status, author, genre;
    int yearReleased, pageNum, libraryChoice;

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
    cout << "Enter the library to add the book to (1 or 2): ";
    cin >> libraryChoice;
    if (libraryChoice == 1)
    {
        library.push_back(new Book(name, status, yearReleased, author, genre, pageNum));
    }
    else
    {
        secondLibrary.push_back(new Book(name, status, yearReleased, author, genre, pageNum));
    }
    cout << "Book \"" << name << "\" added successfully!\n";
}

void addMovie(LinkedList &library, LinkedList &secondLibrary)
{
    string name, status, director, genre;
    int yearReleased, libraryChoice;
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
    cout << "Enter the library to add the movie to (1 or 2): ";
    cin >> libraryChoice;
    if (libraryChoice == 1)
    {
        library.push_back(new Movie(name, status, yearReleased, director, genre, duration));
    }
    else
    {
        secondLibrary.push_back(new Movie(name, status, yearReleased, director, genre, duration));
    }
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
    LinkedList secondLibrary;

    int choice, libraryChoice;
    Member *member = new Member();
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook(library, secondLibrary);
            break;
        case 2:
            addMovie(library, secondLibrary);
            break;
        case 3:
            searchMedia(library, "Book");
            break;
        case 4:
            searchMedia(library, "Movie");
            break;
        case 5:
        {
            string title;
            cout << "Enter the title of the media item to borrow: ";
            cin.ignore();
            getline(cin, title);

            // Search for the item in the LinkedList
            Media *mediaItem = library.linearSearch(title);

            if (mediaItem)
            {
                member->addMedia(*mediaItem); // Borrow the item
                cout << "Media item '" << mediaItem->getMediaType() << ": " << title << "' borrowed successfully.\n";
            }
            else
            {
                cout << "Media item '" << title << "' not found.\n";
            }
        }

        break;
        case 6:
        {
            // Return media case
            string mediaName;
            cout << "Enter the name of the media item to return: ";
            cin.ignore();            // Clear input buffer
            getline(cin, mediaName); // Get full media name
            member->returnMedia(mediaName);
        }
        break;
        case 7:
            library.mergeDicts(&secondLibrary);
            break;
        case 8:
            cout << "Enter the library to sort (1 or 2): ";
            cin >> libraryChoice;
            if (libraryChoice == 1)
            {
                cout << "sorting..." << endl;
                library.mergeSort();
                cout << "           ...Done!" << endl;
            }
            else
            {
                cout << "sorting..." << endl;
                secondLibrary.mergeSort();
                cout << "           ...Done!" << endl;
            }
            break;
        case 9:
            cout << "Enter the library to list (1 or 2): ";
            cin >> libraryChoice;
            if (libraryChoice == 1)
            {
                listMedia(library);
            }
            else
            {
                listMedia(secondLibrary);
            }
            break;
        case 10:
            cout << "\nThank you for using the library system! Goodbye.\n";
            break;
        default:
            cout << "\nInvalid option! Please choose a number between 1 and 11.\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 11);

    return 0;
}