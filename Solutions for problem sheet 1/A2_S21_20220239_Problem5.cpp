// File: A2_S21_20220239_Problem5.cpp
// Purpose: Solution for sheet 1
// Author: Ghassan Tarek Elgendy
// Section: S21
// ID: 20220239
// TA: Rana AbdelKader
// Date: 29 Oct 2023

#include <bits/stdc++.h>

using namespace std;
vector<pair<string, int>> leaderboard; //vector holding players and scores in pairs
unsigned short errors;

bool compareScore(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}

void addScore() {
    takeCount:
    unsigned short count = 0;
    cout << "How many scores you wanna add?\n";
    cin >> count;
    if (count > 10) {
        cout << "Maximum 10 scores.\n";

        goto takeCount;
    }
    for (int i = 0; i < count; ++i) {
        cout << "Enter player number " << i + 1 << "'s name and score: \n";
        string name;
        unsigned int score;
        cin >> name;
        cin >> score;
        leaderboard.emplace_back(name, score);
    }
}

void printPlayerBestScore() {
    bool isFound = false;
    cout << "Please enter player's name: ";
    string name;
    cin >> name;
    for (auto const &player: leaderboard) {
        if (player.first == name) {
            cout << name << "'s best score is: " << player.second << endl;
            isFound = true;
            break;
        }
    }
    if (!isFound) cout << "This player doesn't exist in the database.\n";
}

void checkSize() {
    while (leaderboard.size() > 10) {
        leaderboard.pop_back();
    }
}

void chooseOption() {
    choose:
    cout <<
         "What do you want to do? \n"
         "a. Add new scores\n"
         "b. Print the leaderboard's top 10\n"
         "c. Check a player's top score\n"
         "d. Exit\n->";
    unsigned char choice;
    unsigned short places{1};
    cin >> choice;
    choice = tolower(choice);
    switch (choice) {
        case 'a':
            addScore();
            break;
        case 'b':
            for (auto &player: leaderboard) {
                cout << places << "- " << player.first << ' ' << player.second << endl;
                places++;
            }
            break;
        case 'c':
            printPlayerBestScore();
            break;
        case 'd':
            abort();
        default:
            errors++;
            cout << "Wrong entry, please try again.";
            if (errors >= 4) cout << "4 errors? Terminating.\n";
    }
    sort(leaderboard.begin(), leaderboard.end(), compareScore);
    checkSize();
    cout << "===========================================\n";
    unsigned char loop;
    cout << "Wanna do something else? Y/N\n->";
    cin >> loop;
    loop = tolower(loop);
    if (loop == 'y') {
        goto choose;
    } else abort();
}

int main() {
    cout << "\t\t====================[ Welcome to the leaderboard ]====================\n";
    chooseOption();
    return 0;
}