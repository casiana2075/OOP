#include <map>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>

bool cmp(const std::pair<std::string, int>& left, const std::pair<std::string, int>& right) {
    if (left.second != right.second) {
        return left.second < right.second;
    } else {
        return left.first > right.first;
    }
}

int main() {

    std::ifstream file("TextFile.txt"); // open the input file
    std::string s;
    getline(file, s); 
    file.close();
    std::cout << "Input phrase is: \"" << s << "\"" << std::endl;

    //vector
    std::vector<std::string> words; // vector of words
    std::string word;               // an word as a string
    int wordsCount = 0;
    for (auto it = s.begin(); it != s.end(); ++it)
        {
        if (*it != ' ' && *it != '.' && *it != '!' && *it != '?' && *it != ',')
            { 
                word += tolower(*it);
            }
        else if(!word.empty()){
                words.push_back(word);  
                wordsCount++;
                word.clear();
            }
        }
    if (!word.empty()) {
        words.push_back(word);
        word.clear();
    }
    //for (const auto& w : words) {  
    //        std::cout << w <<std::endl;
    //    }

    //map
    std::map<std::string, int> m;

    for (const auto& w : words) {
            if (m.find(w) == m.end())
                m[w] = 1;
            else
                m[w]++;
    }
    //for (auto it = m.begin(); it != m.end(); ++it)
    //        std::cout << it->first << ":" << it->second <<std::endl;

    //priority queue
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(&cmp)> p(&cmp);

    for (const auto& w : m) {
            p.push(w);
    }

    // output sorted words
    while (!p.empty()) {
            auto w = p.top();
            std::cout << w.first << " => " << w.second << std::endl;
            p.pop();
    }
    return 0;
}