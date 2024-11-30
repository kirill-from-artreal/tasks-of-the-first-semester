#include "Header.h"

int safe_input_int(const std::string & prompt) {
    int value;
    std::string str;

    while (true) {
        std::cout << prompt;
        std::cin >> value;
        std::cin >> str;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error\n";
        } else {
            std::cout << str << "\n";
            std::cout << value << "\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}
