//
// Created by Eva Poluliakhov on 23/01/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H


#include "BattleCard.h"

class Witch : public BattleCard {
public:
    Witch();
    std::string getType() const override;
    void applyEncounter(Player& player) const override;
    Card *clone() override;

    ~Witch() override = default;
    Witch(const Witch &) = default;
    Witch &operator=(const Witch & other) = default;

private:
    static const int DEFAULT_FORCE = 11;
    static const int DEFAULT_LOOT = 2;
    static const int DEFAULT_HP = 10;
    static const int DEFAULT_FORCE_LOSS = -1;
};


#endif //EX4_WITCH_H
