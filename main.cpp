#include "LinkedList.h"
#include "Movie.h"
#include "Book.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
    LinkedList books;
    books.push_back(new Book("1984", "George Orwell", "Fiction", 200, 1960));

    books.printToScreen();

    return 0;
}