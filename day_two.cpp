#include <iostream>

using namespace std;

unordered_map<char, int> scoreMap {
    {'X', 1},
    {'Y', 2},
    {'Z', 3}
};

int secretStrategy() {
    string line{};
    unordered_map<char, char> winMap {
        {'X', 'C'},
        {'Y', 'A'},
        {'Z', 'B'}
    };
    unordered_map<char, char> drawMap {
        {'X', 'A'},
        {'Y', 'B'},
        {'Z', 'C'}
    };
    int totalScore {};
    while (getline(cin, line)) {
        if (line[0] == 'Q') break;
        char oppposing = line[0];
        char you = line[2];
        totalScore += scoreMap[you];
        if (winMap[you] == oppposing)
            totalScore += 6;
        else if (drawMap[you] == oppposing)
            totalScore += 3;
    }
    return totalScore;
}

int ultraSecretStrategy() {
    string line{};
    unordered_map<char, char> loseMap {
        {'A', 'Z'}, // Z loses to A
        {'B', 'X'},
        {'C', 'Y'}
    };
    unordered_map<char, char> drawMap {
        {'A', 'X'}, // X draws with A
        {'B', 'Y'},
        {'C', 'Z'}
    };
    unordered_map<char, char> winMap {
        {'A', 'Y'}, // Y wins against A
        {'B', 'Z'},
        {'C', 'X'}
    };
    int totalScore {};
    while (getline(cin, line)) {
        if (line[0] == 'Q') break;
        char oppposing = line[0];
        char result = line[2];
        if (result == 'X') {
            totalScore += scoreMap[loseMap[oppposing]];
        }
        if (result == 'Y') {
            totalScore += scoreMap[drawMap[oppposing]];
            totalScore += 3;
        }
        if (result == 'Z') {
            totalScore += scoreMap[winMap[oppposing]];
            totalScore += 6;
        }
    }
    return totalScore;
}

int main() {
    //secretStrategy();
    cout << ultraSecretStrategy() << endl;
    return 0;
}
