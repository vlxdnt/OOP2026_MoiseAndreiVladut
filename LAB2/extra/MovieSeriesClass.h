#include "MovieClass.h"
#include <stdio.h>

class MovieSeries {
    private:
        Movie* movies[16];
        int count = 0;
    public:
        void init();
        void add(Movie* movie);
        void print();
        void sort();
};