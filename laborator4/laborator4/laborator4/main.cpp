#include "MyLibrary.h"
#include <iostream>

int main(int argc, char* argv[]) {

    MyLibrary l1 = { std::cout };

    //// printeaza: "found -1 books" si id-urile
    //// -1 daca nu avem nimic
    l1.print_books();

    int l2_ids[] = { 3356, 2213, 5723, 1246, 12573, 6424, 85573, 2235113, 2241 };
    MyLibrary l2{ std::cout, 9, l2_ids };
    // printeaza: "Found 9 books" si id-urile
    l2.print_books();

    MyLibrary l3 = { std::cout, 20, 15, 200 };
    // 20 carti
    l3.print_books(); 
    
    MyLibrary l4 = { std::cout, "12;13;15;16" };
     //4 carti
    l4.print_books();

    

     MyLibrary l5 = { std::cout, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // 10 carti
    l5.print_books();

    MyLibrary& l = l5;
    // 🤔
    std::cout << "found book number: " << l.get_books_count() << std::endl;
    std::cout << "found book id: " << l.get_book_id_by_index(3) << std::endl;
    std::cout << "found book id: " << l.get_book_id_by_index(10) << std::endl;

    // modifica clasa ca sa mearga asta
    l.print_books();
    
    
    MyLibrary l6{ 0, 5, 10, 15 };
    l6.print_books();


    {
        MyLibrary l2_copy = l2;
        std::cout << "before update" << std::endl;
        // printeaza: 3356
        std::cout << "library l2: book index 0 " << l2.get_book_id_by_index(0) << std::endl;
        // printeaza: 3356
        std::cout << "library l2_copy: book index 0 " << l2_copy.get_book_id_by_index(0) << std::endl;

        l2_copy.update_book_id_by_index(0, 20);

        // printeaza: 3356
        std::cout << "library l2: book index 0 " << l2.get_book_id_by_index(0) << std::endl;
        // printeaza: 20
        std::cout << "library l2_copy: book index 0 " << l2_copy.get_book_id_by_index(0) << std::endl;

    }
}