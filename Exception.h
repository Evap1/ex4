//
// Created by Eva Poluliakhov on 21/01/2023.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <stdexcept>
#include <string>


class DeckFileNotFound : public std::logic_error {

public:
    DeckFileNotFound() : logic_error("Deck File Error: File not found") {}
};

class DeckFileFormatError : public std::logic_error {

public:
    DeckFileFormatError(int line) : logic_error("Deck File Error: File format error in line " + std::to_string(line)) {}
};

class DeckFileInvalidSize : public std::logic_error {

public:

    DeckFileInvalidSize() : logic_error("Deck File Error: Deck size is invalid") {}
};



#endif //EX4_EXCEPTION_H
