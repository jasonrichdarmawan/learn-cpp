// https://en.cppreference.com/w/cpp/container/map

#include <string>
#include <map>
#include <iostream>

void printMap(std::string_view comment, const std::map<std::string, int>& m)
{
    std::cout << comment;
// C+17 alternative:
// for (const auto& [key, value] : m)
//     std::cout << '[' << key << "] = " << value << "; ";
//
// C++11 alternative:
    for (const auto& pair : m)
        std::cout << '[' << pair.first << "] = " << pair.second << "; ";

// C++11 alternative:
//  for (const auto& n : m)
//      std::cout << n.first << " = " << n.second << "; ";
//
// C++98 alternative
//  for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++)
//      std::cout << it->first << " = " << it->second << "; ";

    std::cout << '\n';
}