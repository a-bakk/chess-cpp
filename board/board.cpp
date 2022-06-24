#include "board.h"

field board[BOARD_SIZE][BOARD_SIZE];

field::field(const std::string& content, bool occupied) : content(content), occupied(occupied) {}

figure::figure(char symbol, bool owner) : symbol(symbol), owner(owner) {}

figure::~figure() {}

field::~field() { if (field_figure != nullptr) free(field_figure); field_figure = nullptr; }

char figure::get_symbol() const { return symbol; }

bool figure::get_owner() const { return owner; }

void figure::set_symbol(char symbol) { this->symbol = symbol; }

void figure::set_owner(bool owner) { this->owner = owner; }

king::king(bool owner) : figure((owner ? 'K' : 'k'), owner) {}

queen::queen(bool owner) : figure((owner ? 'Q' : 'q'), owner) {}

rook::rook(bool owner) : figure ((owner ? 'R' : 'r'), owner) {}

bishop::bishop(bool owner) : figure ((owner ? 'B' : 'b'), owner) {}

knight::knight(bool owner) : figure ((owner ? 'N' : 'n'), owner) {}

pawn::pawn(bool owner) : figure ((owner ? 'P' : 'p'), owner) {}

const std::string& field::get_content() const { return content; }

bool field::is_occupied() const { return occupied; }

figure* field::get_field_figure() const { return this->field_figure; }

void field::set_content(const std::string& content) { this->content = content; }

void field::set_occupied(bool occupied) { this->occupied = occupied; }

void field::set_field_figure(figure *field_figure) { this->field_figure = field_figure; }

void field::board_init() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            figure *tmp_f = nullptr; bool set = false;
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

bool figure::move(const move_coord& c) {
    if (!board[c.from_r][c.from_c].is_occupied()) return false;
    if (!(board[c.from_r][c.from_c].field_figure->validate_move(c, board[c.from_r][c.from_c].field_figure->get_owner()))) return false;
    board[c.to_r][c.to_c].set_content(board[c.from_r][c.from_c].get_content()); board[c.to_r][c.to_c].set_occupied(true); board[c.to_r][c.to_c].set_field_figure(board[c.from_r][c.from_c].get_field_figure());
    board[c.from_r][c.from_c].set_occupied(false); board[c.from_r][c.from_c].set_content(EMPTY_FIELD);
    return true;
}

bool king::validate_move(const move_coord& c, bool owner) {
    for (unsigned i = c.from_r - 1; i <= c.from_r + 1; i++) {
        for (unsigned j = c.from_c - 1; j <= c.from_c + 1; j++) {
            if (c.to_r == i && c.to_c == j) return true;
        }
    }
    return false;
}

bool queen::validate_move(const move_coord& c, bool owner) {
    king k(true); bishop b(true); // now this is ugly
    return k.validate_move(c, owner) || b.validate_move(c, owner);
}

bool rook::validate_move(const move_coord& c, bool owner) {
    return ((c.from_r == c.to_r) || (c.from_c == c.to_c));
}

bool bishop::validate_move(const move_coord& c, bool owner) {
    return (((c.from_r + c.from_c) == (c.to_r + c.to_c)) || ((c.from_c - c.from_r) == (c.to_c - c.to_r)));
}

bool knight::validate_move(const move_coord& c, bool owner) {
    return (((c.to_r == (c.from_r - 2) || c.to_r == (c.from_r + 2)) && (c.to_c == (c.from_c - 1) || c.to_c == (c.from_c + 1))) ||
    ((c.to_c == (c.from_c - 2) || c.to_c == (c.from_c + 2)) && (c.to_r == (c.from_r + 1) || c.to_r == (c.from_r - 1))));
}

bool pawn::validate_move(const move_coord& c, bool owner) {
    if (owner) {
        if (c.to_r >= c.from_r) return false;
        if (!board[c.to_r][c.to_c].is_occupied() && !board[c.to_r - 1][c.to_c].is_occupied() && c.from_r == 6 && c.to_c == c.from_c && c.to_r == (c.from_r - 2)) return true;
        if (!board[c.to_r][c.to_c].is_occupied() && c.from_c == c.to_c && c.to_r == (c.from_r - 1)) return true;
        if (board[c.to_r][c.to_c].is_occupied() && c.to_r == (c.from_r - 1) && (c.to_c == (c.from_c - 1) || c.to_c == (c.from_c + 1))) return true;
    }
    else {
        if (c.to_r <= c.from_r) return false;
        if (!board[c.to_r][c.to_c].is_occupied() && !board[c.to_r + 1][c.to_c].is_occupied() && c.from_r == 1 && c.to_c == c.from_c && c.to_r == (c.from_r + 2)) return true;
        if (!board[c.to_r][c.to_c].is_occupied() && c.from_c == c.to_c && c.to_r == (c.from_r + 1)) return true;
        if (board[c.to_r][c.to_c].is_occupied() && c.to_r == (c.from_r + 1) && (c.to_c == (c.from_c - 1) || c.to_c == (c.from_c + 1))) return true;
    }
    return false;
}
