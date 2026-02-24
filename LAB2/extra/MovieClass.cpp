#include "MovieClass.h"

void Movie::set_name(char* str) {
    int i = 0;
    while (i < 255 && str[i] != '\0') {
        name[i] = str[i];
        i++;
    }
    name[i] = '\0';
}

void Movie::set_year(int y) {
    year = y;
}

void Movie::set_score(double x) {
    if (x >= 1 && x <= 10) {
        score = x;
    }
}

void Movie::set_length(int x) {
    length = x;
}

char* Movie::get_name() {
    return this->name;
}

int Movie::get_year() {
    return this->year;
}

double Movie::get_score() {
    return this->score;
}

int Movie::get_length() {
    return this->length;
}

int Movie::get_passed_years(int current_year, int release_year) {
    return current_year - release_year;
}