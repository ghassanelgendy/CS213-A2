// File: Problem12.cpp
// Purpose: Scans a file for some terms.
// Author: Jana Ramadan
// Section: S21
// ID: 20220470
// TA: Rana Abdelkader
// Date: 12 Oct 2023
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector<int> points; // ely haysheel el point assigned tab heya leh global? so2al helw ma3rfsh egabto
void Phishing_Scanner(string filename, vector<string> words) {   // elfunction betlef 3ala kelma kelma teshofha fel file wala
    ifstream file(filename); // efta7 el file awl haga
    if (file.is_open()) {  // fata7 wala hayt3ebna ma3ah?
        string line; // string yesheel el lines ely fel file
        int total = 0;  // han7ot el total points bas ehtart ba tet7at fel function wala fy anhy moseba takhodny
        for (int i = 0; i < words.size(); i++) {  // hanlef 3ala vector el words kelma kelma
            int count = 0;  // mabda2eyan el kelma be zero leh fel loop? la2n ana kol kelma 3ayza abd2aha men el awl
            while (getline(file, line)) {  // tool ma fy lines
                if (line.find(words[i]) != string::npos) {   // dawary 3al kelma fy kol line law mawgooda
                    count ++;
                    total += points[i];
                }
            }
            if (count != 0){
                cout <<"The word:  "<< words[i] << " was found " << count << " times and its total number of points equals: " << (count*points[i]) << endl;
            }
        }
        file.close();  // Close the file
        cout << "Total of points: " << total << endl;
    }
    else {   // el file mafatahsh asasan
        cout << "el file mesh motah" << endl;
    }
}
int main()
{
    vector<string> words = {"suspicious", "expire", "important", "install", "bank", "locked", "PIN", "password", "personal","update", "action", "required", "invoice", "hello", "credit", "card", "verification ", "account", "security", "confirm", "link", "online", "transactions", "previous", "activity", "click", "download", "alert", "username", "perform"};
    points = {1,2,2,2,3,1,3,3,2,2,1,1,3,1,3,3,2,2,1,2,2,1,3,1,2,3,2,2,3,1};
    string filename;
    cin>>filename;
    filename = filename + ".txt";
    Phishing_Scanner(filename, words);
    return 0;
}

