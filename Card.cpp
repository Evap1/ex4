//
// Created by Eva Poluliakhov on 21/01/2023.
//

#include "Card.h"


void Card::printInfo(std::ostream &os) const
{
    printCardDetails(os, getType());
    printEndOfCardDetails(os);
}

std::ostream &operator<<(std::ostream &os, const Card &card)
{
    card.printInfo(os);
    return os;
}