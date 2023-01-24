//
// Created by Eva Poluliakhov on 21/01/2023.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H
#include "../Players/Player.h"

class Card {
public:

    Card() = default;
    virtual void applyEncounter(Player& player) const = 0;
    virtual std::string getType() const= 0;
    virtual void printInfo(std::ostream &os) const;
    virtual Card *clone() = 0;
    virtual ~Card() = default;
    Card(const Card &) = default;
    Card &operator=(const Card &other) = default;

};

std::ostream &operator<<(std::ostream &os, const Card &card);




#endif //BESTEX4_CARD_H
