#pragma once

class Movie {
    private:
        char name[255];
        int year;
        double score;
        int length;
        
    public:
        void set_name(char* str);
        void set_year(int y);
        void set_score(double x);
        void set_length(int x);

        char* get_name();
        int get_year();
        double get_score();
        int get_length();
        int get_passed_years(int current_year, int release_year);
    };