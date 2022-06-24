#pragma once

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <sstream>
#include <string>

#define FIELD_PREFIX "["
#define FIELD_POSTFIX "]"
#define EMPTY_FIELD "[_]"
#define BOARD_SIZE 8

typedef struct {
    unsigned from_r, from_c, to_r, to_c;
} move_coord;

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
    static bool move(const move_coord& c);
    virtual bool validate_move(const move_coord& c, bool owner) = 0;
};

class field {
    std::string content;
    bool occupied;
    figure *field_figure = nullptr;
public:
    field(const std::string& content = "[_]", bool occupied = false);
    ~field();
    const std::string& get_content() const;
    bool is_occupied() const;
    figure* get_field_figure() const;
    void set_content(const std::string& content);
    void set_occupied(bool occupied);
    void set_field_figure(figure *field_figure);
    static void board_init();
    static void board_print();
    friend bool figure::move(const move_coord& c);
};

class king : public figure {
public:
    king(bool owner);
    bool validate_move(const move_coord& c, bool owner);
};

class queen : public figure {
public:
    queen(bool owner);
    bool validate_move(const move_coord& c, bool owner);
};

class rook : public figure {
public:
    rook(bool owner);
    bool validate_move(const move_coord& c, bool owner);
};

class bishop : public figure {
public:
    bishop(bool owner);
    bool validate_move(const move_coord& c, bool owner);
};

class knight : public figure {
public:
    knight(bool owner);
    bool validate_move(const move_coord& c, bool owner);
};

class pawn : public figure {
public:
    pawn(bool owner);
    bool validate_move(const move_coord& c, bool owner);
};

#endif // BOARD_H