#include "MovieSeriesClass.h"

void MovieSeries::init() {
    count = 0;
}

void MovieSeries::add(Movie* movie) {
    if (count >= 16)
        return;

    movies[count++] = movie;
}

void MovieSeries::print() {
    for (int i = 0; i < count; i++) {
        printf("Movie #%d\n", i + 1);
        printf("Name: %s\n", movies[i]->get_name());
        printf("Year: %d\n", movies[i]->get_year());
        printf("Score: %.1f\n", movies[i]->get_score());
        printf("Length: %d minutes\n", movies[i]->get_length());
        printf("\n");
    }
}

void MovieSeries::sort() {
    int current_year = 2026;
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (movies[i]->get_passed_years(current_year, movies[i]->get_year()) >
                movies[j]->get_passed_years(current_year, movies[j]->get_year())) 
            {
                Movie* temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
}