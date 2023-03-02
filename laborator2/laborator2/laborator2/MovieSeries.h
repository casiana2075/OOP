#pragma once
#include "Movie.h"

class MovieSeries {
  private:
    static const int MAX_MOVIES = 16;
    Movie* movies[MAX_MOVIES];
    int count;

  public:
    void init();
    void add(Movie* movie);
    void print() const;
    void sort();
};