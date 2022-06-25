#include "board.h"
#include "user-interaction.h"

int main(int argc, char **argv) {

    field::board_init();
    field::board_print();

    move_coord t;
    get_coords(t);
    std::cout << t.from_c << t.from_r << std::endl;

    return 0;

}
