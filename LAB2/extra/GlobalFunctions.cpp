#include "GlobalFunctions.h"

int movie_compare_name(Movie movie1, Movie movie2) {
    char* name1 = movie1.get_name();
    char* name2 = movie2.get_name();
    int i = 0;
    while (name1[i] != '\0' && name2[i] != '\0') {
        if (name1[i] < name2[i])
            return -1;
        if (name1[i] > name2[i])
            return 1;
        i++;
    }
    if (name1[i] == '\0' && name2[i] == '\0')
        return 0;
    if (name1[i] == '\0')
        return -1;
    return 1;
}

int movie_compare_year(Movie movie1, Movie movie2) {
    int year1 = movie1.get_year();
    int year2 = movie2.get_year();
    if (year1 < year2)
        return -1;
    else if (year1 > year2)
        return 1;
    else
        return 0;
}

int movie_compare_score(Movie movie1, Movie movie2) {
    double score1 = movie1.get_score();
    double score2 = movie2.get_score();
    if (score1 < score2)
        return -1;
    else if (score1 > score2)
        return 1;
    else
        return 0;
}

int movie_compare_length(Movie movie1, Movie movie2) {
    int length1 = movie1.get_length();
    int length2 = movie2.get_length();
    if (length1 < length2)
        return -1;
    else if (length1 > length2)
        return 1;
    else
        return 0;
}

int movie_compare_passed_years(Movie movie1, Movie movie2) {
    int passed_years1 = movie1.get_passed_years(2026, movie1.get_year());
    int passed_years2 = movie2.get_passed_years(2026, movie2.get_year());
    if (passed_years1 < passed_years2)
        return -1;
    else if (passed_years1 > passed_years2)
        return 1;
    else
        return 0;
}
