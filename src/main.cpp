#include "board.h"
#include "user-interaction.h"

int main(int argc, char **argv) {

    std::cout << "[N]ew game :: [E]xit: ";
    char input;
    while (1) {
        bool success = false;
        while (!success) {
           try {
                std::cin >> input; std::cout << input << std::endl;
                if (tolower(input) != 'e' && tolower(input) != 'n') throw std::invalid_argument("invalid option");
                success = true;
            }
            catch (const std::invalid_argument& exc) {
                std::cout << "Nonexistent option!" << std::endl;
            }
        }
        switch (tolower(input)) {
            case 'e': {
                std::cout << "Exiting..." << std::endl; return 0; break;
            }
            case 'n': {
                field::board_init();
                field::board_print();
                while (!field::win_condition()) {
                    success = false; move_coord move; std::cout << "Light";
                    while (!success) {
                        while (!get_coords(move)) { std::cout << "Light";};
                        if (figure::move(move, true)) success = true;
                    }
                    field::board_print(); success = false; std::cout << "Dark";
                    while (!success) {
                        while (!get_coords(move)) { std::cout << "Dark"; }
                        if (figure::move(move, false)) success = true;
                    }
                    field::board_print();
                }
                std::cout << "Exiting..." << std::endl; return 0;
            }
        }
    }

    return 0;

}
