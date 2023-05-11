#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <functional>
#include <fstream>
#include "manager.h"
#include "exception.h"

using namespace std;


int main() {
    CommandManager manager;

    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    auto count = [](vector<string> args) { printf("Counted %d argumets.\n", args.size());};
    manager.add("count", count);

    int counter = 0;
    auto times = [](vector<string> args) mutable {
        static int counter = 0;
        counter++;
        printf("Times called: %d", counter);
    };
    manager.add("times", times);

    auto copy = [](vector<string> args) {
        if (args.size() < 2)
            throw FileException("", "Source and destination files are required.");
        const string& sourceFile = args[0];
        const string& destinationFile = args[1];

        ifstream src(sourceFile, ios::binary);
        ofstream dst(destinationFile, ios::binary);

        if (!src) {
            throw FileException(sourceFile, "Failed to open source file.");
        }

        if (!dst) {
            throw FileException(destinationFile, "Failed to create destination file.");
        }

        dst << src.rdbuf();

        if (src.fail()) {
            throw FileException(sourceFile, "Failed to read source file.");
        }

        if (dst.fail()) {
            throw FileException(destinationFile, "Failed to write to destination file.");
        }


        printf("File copied successfully.\n");
    };
    manager.add("copy", copy);

    // add one more command of anything you'd like
    auto allocate = [](vector<string> args) {
        if (args.size() < 1) {
            throw FileException("", "Memory allocation command requires arguments.");
        }

        int size = stoi(args[0]);
        vector<int> memory(size); // alloc mem

        printf("Memory allocated successfully.");
    };
    manager.add("allocate", allocate);

    manager.run();

    printf("Goodbye.\n");
}
