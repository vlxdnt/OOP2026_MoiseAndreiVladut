#include "MovieClass.h"

void Movie::set_name(std::string str) {
    name = str;
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

std::string Movie::get_name() {
    return name;
}

int Movie::get_year() {
    return year;
}

double Movie::get_score() {
    return score;
}

int Movie::get_length() {
    return length;
}

int Movie::get_passed_years(int current_year, int release_year) {
    return current_year - release_year;
}