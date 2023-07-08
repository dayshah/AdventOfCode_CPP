#include <iostream>
#include <set>
#include <vector>

int main()
{
    std::vector<char> commons{};
    std::string line;
    while (std::getline(std::cin, line))
    {
        const size_t mid = line.size() / 2;
        const std::string firstHalfStr = line.substr(0, mid);
        const std::string secondHalfStr = line.substr(mid, mid);
        std::set<char> firstHalf{};
        std::set<char> secondHalf{};
        strToSet(firstHalfStr, firstHalf);
        strToSet(secondHalfStr, secondHalf);
    }
    std::set<int> firstHalf{};
}

void strToSet(const std::string& halfStr, const std::set<char>& halfSet) {
    for (int i = 0; i < halfStr.size(); ++i) {
        halfStr.at(i);
    }

}
