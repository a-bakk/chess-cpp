#include "board.h"

#include <iostream>
#include <vector>

std::vector<std::vector<field>> field::board;

field::field(const std::string& content, bool occupied) : content(content), occupied(occupied) {}

field::~field() { if (this->field_figure != nullptr) delete field_figure; }

const std::string& field::get_content() const { return content; }

bool field::get_occupied() const { return occupied; }

const figure* field::get_field_figure() const { return this->field_figure; }

const std::vector<std::vector<field>>& field::get_board() {
    return field::board;
}

void field::set_content(const std::string& content) { this->content = content; }

void field::set_occupied(bool occupied) { this->occupied = occupied; }

void field::set_field_figure(figure *field_figure) { this->field_figure = field_figure; }

void field::board_init() { // missing actual figures
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].set_content(EMPTY_FIELD);
        }
    }
}