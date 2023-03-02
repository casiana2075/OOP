#include "MovieSeries.h"
#include <iostream>
#include <algorithm>

MovieSeries::MovieSeries() {
    count = 0;
    for (int i = 0; i < MAX_MOVIES; i++) {
        movies[i] = nullptr;
    }
}

void MovieSeries::init() {
    for (int i = 0; i < count; i++) {
        delete movies[i];
    }
}

void MovieSeries::add(Movie* movie) {
    if (count < MAX_MOVIES) {
        movies[count] = movie;
        count++;
    } else {
        std::cerr << "Maximum number of movies reached!" << std::endl;
    }
}

void MovieSeries::print() const {
    for (int i = 0; i < count; i++) {
        std::cout << movies[i]->get_name() << " (" << movies[i]->get_year() << ")" << std::endl;
    }
}

void MovieSeries::sort() {
    std::sort(movies, movies + count, [](Movie* a, Movie* b) { return a->get_passed_years() > b->get_passed_years(); });
}
