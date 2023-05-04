#pragma once
#include <string>
#include <vector>

struct Episode {
    std::string title;
    std::string date;
    int length;
    int viewersmm;
    double score;

    Episode(const std::vector<std::string>& columns) {
        title = columns[0];
        date = columns[1];
        length = std::stoi(columns[2]);
        viewersmm = std::stoi(columns[3]);
        score = std::stod(columns[4]);
    }
};
