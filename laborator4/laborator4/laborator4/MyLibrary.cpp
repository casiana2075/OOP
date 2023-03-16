#define _CRT_SECURE_NO_WARNINGS 
#include "MyLibrary.h"
#include <iostream>
#include <cstdarg>
#include <initializer_list>
#include <string>


MyLibrary::MyLibrary(std::ostream& output_stream): output_stream(output_stream){
    books_count = -1;
    books = nullptr;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books)
    : output_stream(output_stream), books_count(books_count), books(new int [books_count]){
    for (int i = 0; i < books_count; i++) {
        this -> books[i]= books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max)
    : output_stream(output_stream), books_count(books_count){
    srand(time(nullptr));
    int cnt = 0;
    books = new int[books_count];
    while (cnt < books_count) {
        int x = rand();
        if (x > min && x < max) {
            books[cnt] = x;
            cnt++;
        }
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values): output_stream(output_stream){
    books_count = 0;
    books = new int[100];
    int number = 0;

    while (*(books_values) != '\0') {
        if (*(books_values) == ';') {
            books[books_count] = number;
            books_count++;
            number = 0;
        } 
        else {
            number *= 10;
            number += *(books_values) - '0';
        }
        books_values++;
    }
    books[books_count] = number;
    books_count++;

   /* char* sep= strtok((char *)books_values, ";");
    while (sep) {
        books[books_count] = std::stoi(sep);
        books_count++;
        sep = strtok(nullptr, ";");
    }
    sep = strtok(nullptr, "\n");
    books[books_count] = std::stoi(sep);*/
    
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...)
    :output_stream(output_stream), books_count(books_count), books(new int[books_count]){
    va_list args;
    va_start(args, books_count);
    for (unsigned int i = 0; i < books_count; i++)
        books[i] = va_arg(args, int);
    va_end(args);
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(std::cout) {
    books_count = 0;
    books = new int[100];
    for (const int* i = v.begin(); i != v.end(); ++i) {
        *(books + books_count) = *i;
        books_count++;
    }
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

MyLibrary::MyLibrary(const MyLibrary& other)
    : output_stream(other.output_stream), books_count(other.books_count), books(new int[other.books_count]) {
    std::copy(other.books, other.books + other.books_count, books);
}

void MyLibrary::print_books() {
    if (books_count == -1)
        output_stream << "Numarul de carti e -1"<< "\n";
    else {
        output_stream << "Id-urile cartilor : ";
        for (unsigned int i = 0; i < books_count; ++i)
            output_stream << books[i] << " ";
        output_stream << "\n";
        output_stream << books_count << " carti" << "\n"; 
    }   
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (0 <= book_index && book_index < books_count)
        books[book_index]=book_id;
}

int MyLibrary::get_books_count() {
    return books_count;
}

int MyLibrary::get_book_id_by_index(int index) {
    if (0 <= index && index < books_count)
        return books[index];
    else
        return -1;
}
