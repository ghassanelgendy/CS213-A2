#include <iostream>
#include <vector>
using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

bool FormsDominoChain(vector<dominoT> & dominos, vector<dominoT> & chain){
    if (dominos.empty()) { //recursion base case , if we have no dominos left to check and none of them returned false
        return true;
    }
    for (int i = 0; i < dominos.size(); ++i) {
        if(chain.empty() || chain.back().rightDots == dominos[i].leftDots) {
            chain.push_back(dominos[i]);
            dominoT current = dominos[i]; //save the current domino temporarily in case we need to backtrack
            dominos.erase(dominos.begin() + i);
            if (FormsDominoChain(dominos, chain)) { //calls functon recursively to check rest of the dominos
                return true;
            }
            dominos.insert(dominos.begin() + i, current);//backtracks if we cant form a chain this way
            chain.pop_back();
        }
    }

    return false;
}

void printsol(const vector<dominoT> & chain) {
    for (const auto & domino : chain) {
        cout << domino.leftDots << "|" << domino.rightDots << " - ";
    }
}

int main() {
    vector<dominoT> dominoSet1 = { {6, 1},{2, 6}, {1, 4}, {4, 4}, {4, 3}};
    vector<dominoT> chain;
    if (FormsDominoChain(dominoSet1, chain)) {
        cout<<"true\n";
        printsol(chain);
    } else {
        cout<<"false\n";
    }
}
