#include "canvas.h"
#include <cstdarg>
#include <stdio.h>

Canvas::Canvas(int lines, int columns) {
    this->lines = lines;
    this->columns = columns;

    matrix = new char*[lines];
    for (int i = 0; i < lines; i++)
        matrix[i] = new char[columns];

    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = ' ';
}

void Canvas::set_pixel(int x, int y, char value) {
    matrix[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);

    int x, y, value;
    for (int i = 0; i < count; i++) {
        x = va_arg(args, int);
        y = va_arg(args, int);
        value = static_cast<char>(va_arg(args, int));
        set_pixel(x, y, value);
    }
    va_end (args);
}

void Canvas::clear() {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = ' ';
}

void Canvas::print() const {
    for (int i = 0; i < lines; i++, printf("\n"))
        for (int j = 0; j < columns; j++)
            printf("%c", matrix[i][j]);
}

Canvas::~Canvas() {
    for (int i = 0; i < lines; i++)
        delete[] matrix[i];
    delete[] matrix;
}