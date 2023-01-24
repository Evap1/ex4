//
// Created by Eva Poluliakhov on 23/01/2023.
//

#include "Merchant.h"


Merchant::Merchant() :
    m_addHP(DEFAULT_ADD_HP),
    m_costHP(DEFAULT_HP_COST),
    m_addForce(DEFAULT_ADD_FORCE),
    m_costForce(DEFAULT_FORCE_COST)
    {}

std::string Merchant::getType()const{
    return "Merchant";
}

Card *Merchant::clone(){
    return new Merchant();
}

void Merchant::applyEncounter(Player &player) const {
    bool isChoosing = true;
    std::string choice;
    int converted;
    while (isChoosing) {
        printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
        std::getline(std::cin, choice);
        try {
            converted = std::stoi(choice);
            if (converted >= Choose::COUNT) {
                printInvalidInput();
            }
            if (converted == Choose::LEAVE) {
                isChoosing = false;
                break;
            }
            if (converted == Choose::ADD_HEALTH) {
                if (player.pay(DEFAULT_HP_COST)) {
                    printMerchantSummary(std::cout, player.getName(), converted, DEFAULT_HP_COST);
                    isChoosing = false;
                }
            }
            if (converted == Choose::ADD_FORCE) {
                if (player.pay(DEFAULT_FORCE_COST)) {
                    printMerchantSummary(std::cout, player.getName(), converted, DEFAULT_FORCE_COST);
                    isChoosing = false;
                }
            } else printMerchantInsufficientCoins(std::cout);
        }
        catch (std::invalid_argument &err) {
            printInvalidInput();
            continue;
        }
    }
}