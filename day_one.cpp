#include <iostream>

int main() {
    int maxElfCals = 0;
    int currentElfCals = 0;
    std::string calcsStr{};
    while (std::getline(std::cin, calcsStr)) {
        if (calcsStr == "") {
            maxElfCals = std::max<int>(currentElfCals, maxElfCals);
            std::cout << maxElfCals << std::endl;
            currentElfCals = 0;
            continue;
        }
        currentElfCals += std::stoi(calcsStr);
    }

    return 0;
}
