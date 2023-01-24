//
// Created by Eva Poluliakhov on 22/01/2023.
//

#ifndef EX4_NINJA_H
#define EX4_NINJA_H

#include "Player.h"

class Ninja : public Player {
public:
    explicit Ninja(const std::string &name);
    ~Ninja() override = default;
    std::string getType() const override;
    Player *clone(const std::string &name) override;
    void addCoins(const int add);
};


#endif //EX4_NINJA_H


