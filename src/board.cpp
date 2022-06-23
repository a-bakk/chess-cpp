#include "../include/board.h"

#include <iostream>

field::field(const std::string& content, bool occupied) : content(content), occupied(occupied) {}

const std::string& field::get_content() const { return content; }

bool field::get_occupied() const { return occupied; }

void field::set_content(const std::string& content) { this->content = content; }

void field::set_occupied(bool occupied) { this->occupied = occupied; }

void field::board_init() { // missing actual figures
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // init
        }
    }
}