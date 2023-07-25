#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int maxElfCals = 0;
    int currentElfCals = 0;
    string calcsStr{};
    vector<int> tripleMax(3, 0);
    while (getline(std::cin, calcsStr)) {
        if (calcsStr == "answer") {
            int result = accumulate(tripleMax.begin(), tripleMax.end(), 0);
            cout << result << endl;
        } else if (calcsStr == "") {
            if (currentElfCals > tripleMax[2]){
                tripleMax.pop_back();
                tripleMax.push_back(currentElfCals);
                sort(tripleMax.begin(), tripleMax.end(), greater<int>());
            }
            currentElfCals = 0;
        } else {
            currentElfCals += stoi(calcsStr);
        }
    }

    return 0;
}
