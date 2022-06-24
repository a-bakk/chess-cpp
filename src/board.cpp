#include "board.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "figure.h"

field board[BOARD_SIZE][BOARD_SIZE];

field::field(const std::string& content, bool occupied) : content(content), occupied(occupied) {}

const std::string& field::get_content() const { return content; }

bool field::is_occupied() const { return occupied; }

const figure* field::get_field_figure() const { return this->field_figure; }

void field::set_content(const std::string& content) { this->content = content; }

void field::set_occupied(bool occupied) { this->occupied = occupied; }

void field::set_field_figure(figure *field_figure) { this->field_figure = field_figure; }

void field::board_init() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            figure *tmp_f; bool set = false;
            switch (i) {
                case 0: {
                    switch (j) {
                        case 0:
                        case 7: {
                            tmp_f = new rook {false}; set = true; break;
                        }
                        case 1:
                        case 6: {
                            tmp_f = new knight {false}; set = true; break;
                        }
                        case 2:
                        case 5: {
                            tmp_f = new bishop {false}; set = true; break;
                        }
                        case 3: {
                            tmp_f = new queen {false}; set = true; break;
                        }
                        case 4: {
                            tmp_f = new king {false}; set = true; break;
                        }
                    }
                    break;
                }
                case 1: {
                    tmp_f = new pawn {false}; set = true; break;
                }
                case 6: {
                    tmp_f = new pawn {true}; set = true; break;
                }
                case 7: {
                    switch (j) {
                        case 0:
                        case 7: {
                            tmp_f = new rook {true}; set = true; break;
                        }
                        case 1:
                        case 6: {
                            tmp_f = new knight {true}; set = true; break;
                        }
                        case 2:
                        case 5: {
                            tmp_f = new bishop {true}; set = true; break;
                        }
                        case 3: {
                            tmp_f = new queen {true}; set = true; break;
                        }
                        case 4: {
                            tmp_f = new king {true}; set = true; break;
                        }
                    }
                }
                default: board[i][j].set_content(EMPTY_FIELD);
            }
            if (set) {
                std::stringstream sstmp;
                sstmp << FIELD_PREFIX << tmp_f->get_symbol() << FIELD_POSTFIX;
                board[i][j].set_content(sstmp.str());
                board[i][j].set_field_figure(tmp_f);
                board[i][j].set_occupied(true);
                delete tmp_f;
            }
        }
    }
}

void field::board_print() {
    std::cout << "   ";
    for (int i = 'A'; i < 'A' + BOARD_SIZE; i++) {
        std::cout << " " << (char) i << " ";
    }
    std::cout << std::endl;
    int row_i = 8;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE + 1; j++) {
            if (j == 0) {
                std::cout << " " << row_i << " ";
            }
            else {
                std::cout << board[i][j - 1].get_content();
            }
            if (j == 8) {
                std::cout << " " << row_i << " "; row_i--;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "   ";
    for (int i = 'A'; i < 'A' + BOARD_SIZE; i++) {
        std::cout << " " << (char) i << " ";
    }
    std::cout << std::endl;
}

bool pawn::validate_move(int from_r, int from_c, int to_r, int to_c, bool owner) {
    if (owner) {
        if (to_r >= from_r) return false;
        if (!board[to_r][to_c].is_occupied() && from_c == to_c && to_r == (from_r - 1)) return true;
        if (board[to_r][to_c].is_occupied() && to_r == (from_r - 1) && (to_c == (from_c - 1) || to_c == (from_c + 1))) return true;
    }
    else {
        if (to_r <= from_r) return false;
        if (!board[to_r][to_c].is_occupied() && from_c == to_c && to_r == (from_r + 1)) return true;
        if (board[to_r][to_c].is_occupied() && to_r == (from_r + 1) && (to_c == (from_c - 1) || to_c == (from_c + 1))) return true;
    }
    return false;
}
