#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <iostream>
#include <fstream>
#include <deque>
#include <map>
#include <array>
#include <vector>
#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Barfight.h"
#include "Cards/Gremlin.h"
#include "Cards/Well.h"
#include "Cards/Witch.h"
#include "Cards/Mana.h"


#include "Exception.h"



#include "Players/Player.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Players/Ninja.h"
#include "utilities.h"

class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::deque<std::unique_ptr<Card> > m_deck;
    std::deque<std::unique_ptr<Player> > m_players;
    std::deque<std::unique_ptr<Player> > m_winners;
    std::deque<std::unique_ptr<Player> > m_losers;
    std::vector<std::unique_ptr<Player> > test;
    int m_rounds;

    int getNumOfPlayers();
    void setPlayers(int numOfPlayers, std::deque<std::unique_ptr<Player> > &players);
    void setDeck (const std::string &fileName, std::deque<std::unique_ptr<Card> > &deck);



    static const int MIN_NUM_OF_CARDS = 5;
    static const int WIN_LEVEL = 10;
    static const int MIN_NUM_OF_PLAYERS = 2;
    static const int MAX_NUM_OF_PLAYERS = 6;
    static const int MAX_NAME_LEN = 15;
    static const int NUM_OF_PLAYER_TYPES = 3;
    static const int NUM_OF_CARDS_TYPES = 8;


    class StringType
    {
        std::string m_condition;
    public:
        explicit StringType(std::string str) : m_condition(str){}
        bool operator()(std::string &str) const;
    };


    std::array<std::shared_ptr<Player>, NUM_OF_PLAYER_TYPES> playerTypes = {
            std::unique_ptr<Player>(new Warrior("")),
            std::unique_ptr<Player>(new Healer("")),
            std::unique_ptr<Player>(new Ninja(""))
    };

    std::array<std::shared_ptr<Card>, NUM_OF_CARDS_TYPES> cardTypes = {
            std::unique_ptr<Card>(new Witch()),
            std::unique_ptr<Card>(new Well()),
            std::unique_ptr<Card>(new Treasure()),
            std::unique_ptr<Card>(new Merchant()),
            std::unique_ptr<Card>(new Mana()),
            std::unique_ptr<Card>(new Gremlin()),
            std::unique_ptr<Card>(new Dragon()),
            std::unique_ptr<Card>(new Barfight()),
    };
};



#endif /* MTMCHKIN_H_ */
