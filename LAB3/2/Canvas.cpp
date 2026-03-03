#include "Canvas.h"
#include <stdio.h>

Canvas::Canvas(int width, int height) {
    w = width;
    h = height;
    matrix = new char*[height];
    for (int i = 0; i < height; i++)
        matrix[i] = new char[width];

    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++)
            matrix[i][j] = ' ';
}

Canvas::~Canvas() {
    for (int i = 0; i < h; i++)
        delete[] matrix[i];

    delete[] matrix;
}

void Canvas::Print() {
    for (int i = 0; i < h; i++, printf("\n"))
        for (int j = 0; j < w; j++)
            printf("%c", matrix[i][j]);
}

void Canvas::Clear() {
   for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++)
            matrix[i][j] = ' '; 
}

void Canvas::SetPoint(int x, int y, char ch) {
    matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    // distanta
    int dx = (x2 > x1) ? (x2 - x1) : (x1 - x2);
    int dy = (y2 > y1) ? (y2 - y1) : (y1 - y2);

    // directia pasului
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    // marja de eroare
    int err = dx - dy;

    while (true) {
        // verific sa fie in bounds
        if (x1 >= 0 && x1 < w && y1 >= 0 && y1 < h)
            matrix[y1][x1] = ch;

        // am ajuns cu linia in punctul 2
        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(left, bottom, right, bottom, ch);
    DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++) {
        DrawLine(left, i, right, i, ch);
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            int dx = j - x;
            int dy = i - y;
            int dSq = dx * dx + dy * dy;

            if (dSq >= (ray-1)*(ray-1) && dSq <= ray * ray)
                matrix[i][j] = ch;
        }              
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            int dx = j - x;
            int dy = i - y;

            if (dx * dx + dy * dy <= ray * ray)
                matrix[i][j] = ch;
        }               
}