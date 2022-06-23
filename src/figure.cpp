#include "figure.h"
#include "board.h"

figure::figure(char symbol, bool owner) : symbol(symbol), owner(owner) {}

figure::~figure() {}

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

bool king::validate_move(int from_r, int from_c, int to_r, int to_c, bool owner) {
    for (int i = from_r - 1; i <= from_r + 1; i++) {
        for (int j = from_c - 1; j <= from_c + 1; j++) {
            if (to_r == i && to_c == j) return true;
        }
    }
    return false;
}

bool queen::validate_move(int from_r, int from_c, int to_r, int to_c, bool owner) {
    king k(true); bishop b(true); // now this is ugly
    return k.validate_move(from_r, from_c, to_r, to_c, owner) || b.validate_move(from_r, from_c, to_r, to_c, owner);
}

bool rook::validate_move(int from_r, int from_c, int to_r, int to_c, bool owner) {
    return ((from_r == to_r) || (from_c == to_c));
}

bool bishop::validate_move(int from_r, int from_c, int to_r, int to_c, bool owner) {
    return (((from_r + from_c) == (to_r + to_c)) || ((from_c - from_r) == (to_c - to_r)));
}

bool knight::validate_move(int from_r, int from_c, int to_r, int to_c, bool owner) {
    return (((to_r == (from_r - 2) || to_r == (from_r + 2)) && (to_c == (from_c - 1) || to_c == (from_c + 1))) ||
    ((to_c == (from_c - 2) || to_c == (from_c + 2)) && (to_r == (from_r + 1) || to_r == (from_r - 1))));
}

bool pawn::validate_move(int from_r, int from_c, int to_r, int to_c, bool owner) {
    if (owner) {
        if (to_r >= from_r) return false;
        if (!field::get_board()[to_r][to_c].get_occupied() && from_c == to_c && to_r == (from_r - 1)) return true;
        if (field::get_board()[to_r][to_c].get_occupied() && to_r == (from_r - 1) && (to_c == (from_c - 1) || to_c == (from_c + 1))) return true;
    }
    else {
        if (to_r <= from_r) return false;
        if (!field::get_board()[to_r][to_c].get_occupied() && from_c == to_c && to_r == (from_r + 1)) return true;
        if (field::get_board()[to_r][to_c].get_occupied() && to_r == (from_r + 1) && (to_c == (from_c - 1) || to_c == (from_c + 1))) return true;
    }
    return false;
}