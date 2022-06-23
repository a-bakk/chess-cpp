#pragma once

#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#define FIELD_PREFIX "["
#define FIELD_POSTFIX "]"
#define EMPTY_FIELD "[_]"
#define BOARD_SIZE 8

class field {
    std::string content;
    bool occupied;
public:
    field(const std::string& content, bool occupied);
    field() = default;
    const std::string& get_content() const;
    bool get_occupied() const;
    void set_content(const std::string& content);
    void set_occupied(bool occupied);
    void board_init();
    void board_print();
};

#endif // BOARD_H