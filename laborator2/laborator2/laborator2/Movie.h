#pragma once
#include <string>

class Movie {
  private:
    std::string name;
    int year;
    double score;
    int length;
    int passed_years;
    int current_year=2023;

  public:
    // constructor

    Movie() {
        }
        // setters
        void set_name(const std::string& name);
        void set_year(int year);
        void set_score(double score);
        void set_length(int lenght);
        // getters
        const std::string get_name();
        int get_year();
        int get_score();
        int get_length();
        int get_passed_years();
    
};