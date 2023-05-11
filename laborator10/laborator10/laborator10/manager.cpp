#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <functional>
#include "manager.h"
#include "exception.h"

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

void CommandManager::run() {
    string tmp;
    vector<string> args;

    while (true) {
        printf("\n");

        std::getline(std::cin, tmp);
        args.clear();

        auto ptr = strtok(&tmp[0], " ");
        while (ptr) {
            args.push_back(ptr);
            ptr = strtok(nullptr, " ");
        }

        if (args.empty()) {
            // empty command, doing nothing
            continue;
        }

        auto& command = args[0];
        if (command == "stop") {
            return;
        }
        auto it = commands.find(command);
        if (it == commands.end()) {
            printf("No command with that name: %s\n", command.c_str());
            continue;
        }

        // remove the command name
        args.erase(args.begin());

        try {
            it->second(args);
        } catch (const FileException& e) {
            printf("Command failed: %s\n", e.what());
        } catch (const std::exception& e) {
            printf( "Command failed with an exception: %s\n", e.what());
        } catch (...) {
            printf( "Command failed with an unknown exception.\n");
        }
    }
}