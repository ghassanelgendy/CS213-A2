#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <sstream> //to separate words by comma

using namespace std;

vector<string> postwords() {
    ifstream file("problem10Post.txt");
    if (!file) {
        cout << "Unable to find/open file: problem10Post.txt , please check file directory and try again.";
        exit(0);
    }
    vector<string> words;
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    return words;
}

vector<string> words = postwords();

map<string, vector<string>> lookuptable() {
    ifstream file("problem10LookUPTable.txt");
    if (!file) {
        cout << "Unable to find/open file: problem10LookUPTable.txt , please check file directory and try again.";
        exit(0);
    }
    map<string, vector<string>> replacements;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string word;
        getline(ss, word, ':');

        vector<string> replaces;
        string replaced;
        while (getline(ss, replaced, ',')) {
            replaces.push_back(replaced);
        }
        replacements[word] = replaces;
    }

    return replacements;
}
map<string, vector<string>> table = lookuptable();
void censor(){
    srand(time(0));
    for (auto & word : words) {
        for (auto& pair : table) {
            if (word == pair.first) {
                const vector<string>& alternatives = pair.second;
                int random = rand() % alternatives.size();
                word = alternatives[random];
                break;
            }
        }
    }
}

void censoredpost() {
    ofstream file("problem10CensoredPost.txt");

    for ( auto& word : words) {
        file << word << ' ';
    }
}

int main() {
    censor();
    censoredpost();
    return 0;


}