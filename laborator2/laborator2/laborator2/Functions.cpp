#include "Functions.h"
#include "Movie.h"

int movie_compare_name(Movie first, Movie second) {
    if (first.get_name() == second.get_name())
        return 0;
    else if (first.get_name() < second.get_name())
        return -1;
    else
        return 1;
}

int movie_compare_year(Movie first, Movie second) {
    if ((double)first.get_year() == (double)second.get_year())
        return 0;
    else if ((double)first.get_year() < (double)second.get_year())
        return -1;
    else
        return 1;
}

int movie_compare_score(Movie first, Movie second) {
    if (first.get_score() == second.get_score())
        return 0;
    else if (first.get_score() < second.get_score())
        return -1;
    else
        return 1;
}

int movie_compare_length(Movie first, Movie second) {
    if (first.get_length() == second.get_length())
        return 0;
    else if (first.get_length() < second.get_length())
        return -1;
    else
        return 1;
}

int movie_compare_passed_years(Movie first, Movie second) {
    if (first.get_passed_years() == second.get_passed_years())
        return 0;
    else if (first.get_passed_years() < second.get_passed_years())
        return -1;
    else
        return 1;
}