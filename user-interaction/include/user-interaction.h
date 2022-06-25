#pragma once

#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#include "../../board/include/board.h"
#include <iostream>
#include <cstdlib>

bool get_coords(move_coord &c);

class invalid_coord : public std::exception {
    std::string message;
public:
    invalid_coord(const std::string& message);
    const char* what() const noexcept override;
};

#endif // USER_INTERACTION_H