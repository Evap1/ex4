//
// Created by Eva Poluliakhov on 21/01/2023.
//
#include "Mtmchkin.h"
#include <array>


Mtmchkin::Mtmchkin(const std::string &fileName) :
        m_deck(),
        m_players(),
        m_winners(),
        m_losers(),
        m_rounds(0)
{
    printStartGameMessage();
    setDeck(fileName, m_deck);
    int numOfPlayers = getNumOfPlayers();
    setPlayers(numOfPlayers, m_players);
}


bool Mtmchkin::isGameOver() const {
    return m_players.empty();
}


int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds;
}


int Mtmchkin::getNumOfPlayers() {
    std::string input;
    Mtmchkin::StringType isNumbers("0123456789");
    while (true)
    {
        printEnterTeamSizeMessage();
        std::getline(std::cin, input);
        if (!isNumbers(input))
        {
            printInvalidInput();
        } else {
            int inputNum = std::stoi(input);
            if (inputNum >= MIN_NUM_OF_PLAYERS && inputNum <= MAX_NUM_OF_PLAYERS)
            {
                return inputNum;
            } else {
                printInvalidTeamSize();
            }
        }
    }
}

void Mtmchkin::setPlayers(int numOfPlayers, std::deque<std::unique_ptr<Player>> &players)
{
    std::string name, type, input;
    bool isSearching;
    Mtmchkin::StringType isAlpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    for (int i = 0 ; i < numOfPlayers; i++)
    {
        isSearching = true;
        while (isSearching)
        {
            printInsertPlayerMessage();
            std::getline(std::cin, input);
            name = input.substr(0, input.find(' '));
            type = input.substr(input.find(' ')+1, input.size());
         //   bool isNameUsed = std::find(players.begin(), players.end(), name) != players.end();
            if (!isAlpha(name) || MAX_NAME_LEN < name.size())
            {
                printInvalidName();
            }
            else
            {
                for(std::shared_ptr<Player> &playerType : playerTypes)
                {
                    if (playerType->getType() == type)
                    {
                        players.push_back(std::unique_ptr<Player>(playerType->clone(name))); //std move?
                        isSearching = false;
                    }
                    else printInvalidClass();
                }
            }
        }
    }
}

void Mtmchkin::setDeck(const std::string &fileName, std::deque<std::unique_ptr<Card> > &deck) {
    std::ifstream deckFile(fileName);

    if (!deckFile)
    {
        throw DeckFileNotFound();
    }

    std::string currentCard;
    int line = 1;
    bool isOk = false;
    while (std::getline(deckFile, currentCard))
    {
        for (std::shared_ptr<Card> &cardType : cardTypes){
            if (cardType->getType() == currentCard){
                deck.push_back(std::unique_ptr<Card>(cardType->clone()));
                ++line;
                isOk = true;
            }
        }
        if (!isOk){
            throw DeckFileFormatError(line);
        }
        isOk = false;
    }
    if (deck.size() < MIN_NUM_OF_CARDS)
    {
        throw DeckFileInvalidSize();
    }
}

bool Mtmchkin::StringType::operator()(std::string &str) const
{
    if (str.find_first_not_of(m_condition) == std::string::npos)
    {
        return true;
    }
    return false;
}

void Mtmchkin::playRound(){

    while (!isGameOver()){
        printRoundStartMessage(++m_rounds);
        std::unique_ptr<Player> currentPlayer = std::move(m_players.front());
        std::unique_ptr<Card> currentCard = std::move(m_deck.front()) ;

        printTurnStartMessage(currentPlayer->getName());

        m_players.pop_front();
        m_deck.pop_front();

        currentCard->applyEncounter(*currentPlayer);
        m_deck.push_back(std::move(currentCard));

        bool isWon = currentPlayer->getLevel() == WIN_LEVEL;
        bool isDead = currentPlayer->isKnockedOut();
        if (isWon)
        {
            m_winners.push_back(std::move(currentPlayer));
        }
        else if (isDead)
        {
            m_losers.push_front(std::move(currentPlayer));
        }
        else m_players.push_back(std::move(currentPlayer));
    }
        printGameEndMessage();
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int rank = 0;


}


