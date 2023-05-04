#include <fstream>
#include <iostream>
#include <vector>
#include "csv_reader.h"
#include "episode.h"

int main() {
    std::ifstream input_file("episodes.csv");
    if (!input_file.is_open()) {
        printf("File couldn't be opened\n");
        return 1;
    }
    CsvReader reader(input_file);

    std::vector<Episode> episodes;
    for (std::vector<std::string> columns : reader) {
        episodes.emplace_back(columns);
    }

    printf("number of episodes: %zu\n\n", episodes.size());

    std::ofstream output_file("output.txt");
    for (auto& episode : episodes) {
        output_file << "Title: " << episode.title << std::endl;
        output_file << "Date: " << episode.date << std::endl;
        output_file << "Length: " << episode.length << " minutes" << std::endl;
        output_file << "Viewers (in millions): " << episode.viewersmm << std::endl;
        output_file << "Score: " << episode.score << std::endl << std::endl;
    }
}