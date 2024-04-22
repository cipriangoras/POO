#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>


void splitString(const std::string& str, std::map<std::string, int>& wordCount) {
    std::stringstream ss(str);
    std::string word;
    while (ss >> word) {
        
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        wordCount[word]++;
    }
}


struct CompareWords {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second == b.second)
            return a.first > b.first; 
        return a.second < b.second; 
    }
};

int main() {
    std::string filename = "input.txt"; 
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Eroare: " << filename << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string line;
    while (std::getline(file, line)) {
        splitString(line, wordCount);
    }

    
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, CompareWords> pq;
    for (const auto& pair : wordCount) {
        pq.push(pair);
    }

    
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        std::cout << top.first << ": " << top.second << std::endl;
    }

    return 0;
}
