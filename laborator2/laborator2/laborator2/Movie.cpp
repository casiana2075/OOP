#include "Movie.h"
#include <cstring>
#include <string.h>

void Movie::set_name(const std::string& name) {
    this-> name = name;
}
void Movie::set_year(int year) {
    this-> year = year;
}

void Movie::set_score(double score) {
    this-> score= score;
}

void Movie::set_length(int length) {
    this-> length= length;
}

const std::string Movie::get_name() {
    return name;
}

int Movie::get_year() {
    return year;
}

int Movie::get_score() {
    if (score > 1.0 && score < 10.0)
        return score;
    else
        return;
}

int Movie::get_length() {
    return length;
}

int Movie::get_passed_years() {
    return current_year-year;
}