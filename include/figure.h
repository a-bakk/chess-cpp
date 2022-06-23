#pragma once

#ifndef FIGURE_H
#define FIGURE_H

class figure {
protected:
    char symbol;
    bool owner; // true if owner is light
public:
    figure(char symbol, bool owner);
    figure() = default;
    virtual ~figure();
    char get_symbol() const;
    bool get_owner() const;
    void set_symbol(char symbol);
    void set_owner(bool owner);
    void move(int from_r, int from_c, int to_r, int to_c);
    virtual bool validate_move(int from_r, int from_c, int to_r, int to_c, bool owner) = 0;
};

class king : public figure {
public:
    king(bool owner);
    bool validate_move(int from_r, int from_c, int to_r, int to_c, bool owner);
};

class queen : public figure {
public:
    queen(bool owner);
    bool validate_move(int from_r, int from_c, int to_r, int to_c, bool owner);
};

class rook : public figure {
public:
    rook(bool owner);
    bool validate_move(int from_r, int from_c, int to_r, int to_c, bool owner);
};

class bishop : public figure {
public:
    bishop(bool owner);
    bool validate_move(int from_r, int from_c, int to_r, int to_c, bool owner);
};

class knight : public figure {
public:
    knight(bool owner);
    bool validate_move(int from_r, int from_c, int to_r, int to_c, bool owner);
};

class pawn : public figure {
public:
    pawn(bool owner);
    bool validate_move(int from_r, int from_c, int to_r, int to_c, bool owner);
};

#endif // FIGURE_H