#include "LinkedList.h"
#include "Movie.h"
#include "Book.h"

#include <string>
#include <iostream>
using namespace std;

//H-What in chernobyl happened here

int main()
{
    LinkedList books;
    books.push_back(new Book("Deep Survival", "Available", 2004, "Laurence Gonzales", "Non-Fiction", 295));

    books.printToScreen();

    return 0;
}