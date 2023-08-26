// https://en.cppreference.com/w/cpp/container/map

#include "printmap.cpp"

void mapExample() {
    // Create a map of three (string, int) pairs
    std::map<std::string, int> m;
    m["CPU"] = 10;
    m["GPU"] = 15;
    m["RAM"] = 20;
    printMap("1) Initial map: ", m);
 
    m["CPU"] = 25; // update an existing value
    m["SSD"] = 30; // insert a new value
    printMap("2) Updated map: ", m);
 
    // using operator[] with non-existent key always performs an insert
    std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    printMap("4) Updated map: ", m);
 
    m.erase("GPU");
    printMap("5) After erase: ", m);

// C++20 alternative:
// std::erase_if(m, [](const auto& pair){ return pair.second > 25; });
// print_map("6) After erase: ", m);
// std::cout << "7) m.size() = " << m.size() << '\n';
//
// C++11 alternative:
    for (auto it = m.begin(); it != m.end();) {
        if (it->second > 25)
            it = m.erase(it);
        else
            it++;
    }
 
    m.clear();
    std::cout << std::boolalpha << "8) Map is empty: " << m.empty() << "\n\n";
}