#include "board.h"
#include "user-interaction.h"

int main(int argc, char **argv) {

    field::board_init();
    field::board_print();

    move_coord test = {1, 0, 3, 0};

    figure::move(test);

    field::board_print();

    return 0;

}
