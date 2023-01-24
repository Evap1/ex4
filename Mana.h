//
// Created by Eva Poluliakhov on 23/01/2023.
//

#ifndef EX4_MANA_H
#define EX4_MANA_H

#include "Card.h"

class Mana : public Card{
public:
    Mana() = default;
    std::string getType() const override;
    Card *clone() override;
    void applyEncounter(Player& player) const override;

    Mana(const Mana &) = default;
    ~Mana() override = default;
    Mana &operator=(const Mana & other) = default;

private:

    static const int DEFAULT_HP_DEMAGE = 10;


};


#endif //EX4_MANA_H
