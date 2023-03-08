#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstring>
#include "Math.h"
#include <cstdarg>

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return (double) (a + b);
}

int Math::Add(double a, double b, double c){
    return (double) (a + b + c);
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math::Mul(int a, int b, int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return (double) (a * b);
}

int Math::Mul(double a, double b, double c) {
    return (double) (a * b * c);
}

int Math::Add(int count, ...) {
    va_list args;
    va_start(args, count);

    int sum = 0;
    for (int i = 0; i < count ; i++) {
        sum += va_arg(args, int);
    }

    va_end(args);
    return sum;
}

char* Math::Add(const char* p1, const char* p2) {
    if (p1 == nullptr || p2 == nullptr)
        return nullptr;
    int length1 = strlen(p1);
    int length2 = strlen(p2);
    char* p = new char[length1 + length2 + 1];
    strcpy(p, p1);
    strcat(p, p2);
    return p;
}
