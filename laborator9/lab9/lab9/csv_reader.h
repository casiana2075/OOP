#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CsvReader {
  public:
    CsvReader(std::ifstream& file) : file_(file) {
    }

    CsvIterator begin() const;
    CsvIterator end() const;

  private:
    std::ifstream& const file_;
};

class CsvIterator {
  public:
    CsvIterator(std::ifstream& file) : file_(file) {
    }

    std::vector<std::string> operator*() const {
        return columns_;
    }

    CsvIterator& operator++() {
        if (file_.good()) {
            readLine();
        }
        return *this;
    }

    bool operator!=(CsvIterator const& other) const{
        return file_ != other.file_;
    }

  private: 
    void readLine() {
        std::string line;
        std::getline(file_, line);
        if (!file_.good()) {
            return;
        }

        std::stringstream ss(line);

        columns_.clear();
        std::string column;
        while (std::getline(ss, column, ',')) {
            if (column.front() == '"' && column.back() == '"') {
                column = column.substr(1, column.size() - 2);
            }
            columns_.push_back(column);
        }
    }

    std::ifstream& file_;
    std::vector<std::string> columns_;

    friend class CsvReader;
};

CsvIterator CsvReader::begin() const {
    CsvIterator it(file_);
    it.readLine();
    return it;
}

CsvIterator CsvReader::end() const {
    return CsvIterator(file_);
}
