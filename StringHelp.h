#pragma once
#include <string>
#include <vector>
#include <sstream>
std::vector<std::string> split(const std::string& text, const char& delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(text);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}