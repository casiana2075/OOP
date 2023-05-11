#pragma once
#include <string>

using namespace std;

class FileException : exception {
  private:
    string filename;
    string message;


  public:
    FileException(const string& filename, const string& message) 
        : filename(filename), message(message) {
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};