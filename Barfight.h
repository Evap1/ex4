//
// Created by Eva Poluliakhov on 23/01/2023.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card{
public:
    Barfight() = default;
    std::string getType() const override;
    Card *clone() override;
    void applyEncounter(Player& player) const override;

    Barfight(const Barfight &) = default;
    ~Barfight() override = default;
    Barfight &operator=(const Barfight & other) = default;

private:
    static const int DEFAULT_HP_DEMAGE = 10;


};

#endif //EX4_BARFIGHT_H
