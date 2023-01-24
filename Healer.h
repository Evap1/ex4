//
// Created by Eva Poluliakhov on 21/01/2023.
//

#ifndef EX4_HEALER_H
#define EX4_HEALER_H
#include "Player.h"

class Healer : public Player {
public:
    explicit Healer(const std::string &name);
    ~Healer() override = default;
    std::string getType() const override;
    Player *clone(const std::string &name) override;
    void heal (const int add);
};


#endif //BESTEX4_HEALER_H
