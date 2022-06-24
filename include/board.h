#pragma once

#ifndef BOARD_H
#define BOARD_H

#include "figure.h"
#include <iostream>
#include <vector>

#define FIELD_PREFIX "["
#define FIELD_POSTFIX "]"
#define EMPTY_FIELD "[_]"
#define BOARD_SIZE 8

class field {
    std::string content;
    bool occupied;
    figure *field_figure = nullptr;
    //static std::vector<std::vector<field>> board;
public:
    field(const std::string& content = "[_]", bool occupied = false);
    ~field();
    const std::string& get_content() const;
    bool is_occupied() const;
    const figure* get_field_figure() const;
    const static std::vector<std::vector<field>>& get_board();
    void set_content(const std::string& content);
    void set_occupied(bool occupied);
    void set_field_figure(figure *field_figure);
    static void board_init();
    static void board_print();
};

#endif // BOARD_H