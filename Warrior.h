//
// Created by Eva Poluliakhov on 22/01/2023.
//

#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H
#include "Player.h"

class Warrior : public Player{

public:
        explicit Warrior(const std::string &name);
        ~Warrior() override = default;
        std::string getType() const override;
        Player *clone(const std::string &name) override;
        int getAttackStrength() const override;
};





#endif //EX4_WARRIOR_H
