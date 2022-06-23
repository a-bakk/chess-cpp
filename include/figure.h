#pragma once

#ifndef FIGURE_H
#define FIGURE_H

class figure {
protected:
    char symbol;
    bool owner; // true if owner is light
public:
    figure(char symbol, bool owner);
    char get_symbol() const;
    bool get_owner() const;
    void set_symbol(char symbol);
    void set_owner(bool owner);
    virtual void move(int from_r, int from_c, int to_r, int to_c) = 0;
};

#endif // FIGURE_H