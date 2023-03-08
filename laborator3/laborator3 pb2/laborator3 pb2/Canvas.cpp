#include "Canvas.h"
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <iostream>

void Canvas::clear() {
    for (int i = 0; i < lines; ++i)
        for (int j = 0; j < columns; ++j)
            v[i][j] = ' ';
}

void Canvas::print() const {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j)
            printf("%c", v[i][j]);
        printf("\n");
    }
}

Canvas::Canvas(int lines, int columns) {
    this->lines = lines;
    this->columns = columns;
    clear();
}

void Canvas::set_pixel(int x, int y, char value) {
    if (x >= 0 && x < lines && y >= 0 && y < columns)
        v[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 1; i <= count; i++) {
        {
            int x = va_arg(args, int);
            int y = va_arg(args, int);
            char value = va_arg(args, char);
            set_pixel(x, y, value);
        }
    }

    va_end(args);
}
