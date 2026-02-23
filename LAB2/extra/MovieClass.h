#pragma once
#include <string>

class Movie {
    private:
        std::string name;
        int year;
        double score;
        int length;
    public:
        void set_name(std::string str);
        void set_year(int y);
        void set_score(double x);
        void set_length(int x);

        std::string get_name();
        int get_year();
        double get_score();
        int get_length();
        int get_passed_years(int current_year, int release_year);
    };