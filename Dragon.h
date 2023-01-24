//
// Created by Eva Poluliakhov on 23/01/2023.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#include "BattleCard.h"

class Dragon : public BattleCard {
public:
    Dragon();
    std::string getType() const override;
    Card *clone() override;
    void applyEncounter(Player& player) const override;

    ~Dragon() override = default;
    Dragon(const Dragon &) = default;
    Dragon &operator=(const Dragon & other) = default;

private:
    static const int DEFAULT_FORCE = 25;
    static const int DEFAULT_LOOT = 1000;
    static const int DEFAULT_HP = 100;
};



#endif //EX4_DRAGON_H
