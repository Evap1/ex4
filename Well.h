//
// Created by Eva Poluliakhov on 23/01/2023.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H

#include "Card.h"

class Well : public Card{
public:
    Well() = default;
    std::string getType() const override;
    Card *clone() override;
    void applyEncounter(Player& player) const override;

    Well(const Well &) = default;
    ~Well() override = default;
    Well &operator=(const Well & other) = default;

private:

    static const int DEFAULT_HP_DEMAGE = 10;


};

#endif //EX4_WELL_H
