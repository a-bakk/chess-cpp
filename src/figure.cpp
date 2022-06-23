#include "../include/figure.h"

figure::figure(char symbol, bool owner) : symbol(symbol), owner(owner) {}

char figure::get_symbol() const { return symbol; }

bool figure::get_owner() const { return owner; }

void figure::set_symbol(char symbol) { this->symbol = symbol; }

void figure::set_owner(bool owner) { this->owner = owner; }

