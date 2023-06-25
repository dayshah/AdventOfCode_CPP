#include <iostream>
#include <algorithm>
#include <numeric>

int main() {
    int maxElfCals = 0;
    int currentElfCals = 0;
    std::string calcsStr{};
    std::vector<int> tripleMax(3, 0);
    while (std::getline(std::cin, calcsStr)) {
        if (calcsStr == "answer") {
            int result = std::accumulate(
                tripleMax.begin(),
                tripleMax.end(),
                0,
                [](const int& a, const int& b){
                    return a + b;
                }
            );
            std::cout << result << std::endl;
        } else if (calcsStr == "") {
            if (currentElfCals > tripleMax[2]){
                tripleMax.pop_back();
                tripleMax.push_back(currentElfCals);
                std::sort(tripleMax.begin(), tripleMax.end(), std::greater<int>());
            }
            currentElfCals = 0;
        } else {
            currentElfCals += std::stoi(calcsStr);
        }
    }

    return 0;
}
