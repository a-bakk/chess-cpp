#include "user-interaction.h"

invalid_coord::invalid_coord(const std::string& message) : message(message) {}

const char* invalid_coord::what() const noexcept { return message.c_str(); }

bool get_coords(move_coord &c) {
    std::cout << " move from: "; std::string input; std::cin >> input;
    try {
        c.from_c = toupper(input[0]) - 'A';
        if (c.from_c < 0 || c.from_c > 7) throw invalid_coord("invalid column");
        input = input.erase(0, 1); int tmp = std::stoi(input); if (tmp < 0 || tmp > 8) throw invalid_coord("invalid row");
        c.from_r = abs(tmp - BOARD_SIZE);
        if (c.from_r < 0 || c.from_r > 7) throw invalid_coord("invalid row");
        std::cout<< "Move to: "; std::cin >> input;
        c.to_c = toupper(input[0]) - 'A';
        if (c.to_c < 0 || c.to_c > 7) throw invalid_coord("invalid column");
        input = input.erase(0, 1); tmp = std::stoi(input); if (tmp < 0 || tmp > 8) throw invalid_coord("invalid row");
        c.to_r = abs(tmp - BOARD_SIZE);
        if (c.to_r < 0 || c.to_r > 7) throw invalid_coord("invalid row");
        return true;
    }
   catch (const invalid_coord& exc) {
        std::cout << "Invalid arguments given!" << std::endl; return false;
   }
   catch (const std::exception& exc) {
        std::cout << "Error while reading input!" << std::endl; return false;
   }
   return false; 
}