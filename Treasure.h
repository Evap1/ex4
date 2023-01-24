//
// Created by Eva Poluliakhov on 21/01/2023.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H
#include "Card.h"


class Treasure : public Card{
public:
    Treasure() = default;
    std::string getType() const override;
    Card *clone() override;
    void applyEncounter(Player& player) const override;

    Treasure(const Treasure &) = default;
    ~Treasure() override = default;
    Treasure &operator=(const Treasure & other) = default;

private:

    static const int DEFAULT_COINS_TO_ADD = 10;


};



#endif //EX4_TREASURE_H
