#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <random>
#include <limits>

#include "board.hpp"
#include "player.hpp"
#include "../helpers/displayColorChoices.hpp"
#include "../helpers/getColorName.hpp"

class Game
{
private:
    //Add array size
    int numPlayers;
    int numRounds = 9;
    std::vector<std::string> players;
    std::vector<std::string> playerOrder;

    int getNumberOfPlayers(int &ARRAY_SIZE);
    void getPlayerInfo(std::vector<std::string> &playerNames, std::vector<std::string> &playerColors);
    void displayPlayerInfo(const std::vector<std::string> &playerNames, const std::vector<std::string> &playerColors);
    void initializePlayers();
    void shufflePlayerOrder();

public:
    void run(); // Run the game
};

void Game::run() //Handle the game logic
{
    int ARRAY_SIZE;
    numPlayers = getNumberOfPlayers(ARRAY_SIZE);

    initializePlayers();

    //Ransomize the order of players
    shufflePlayerOrder();

    Board newBoard(ARRAY_SIZE);
    TilesManager newTilesManager;

    newTilesManager.readTilesFromFile("game_tiles.txt");

    for (int round = 1; round <= numRounds; ++round)
    {
        std::cout << "\nRound " << round << ":\n";

        for (auto playerIt = playerOrder.begin(); playerIt != playerOrder.end(); ++playerIt)
        {
            const std::string &player = *playerIt;

            // Ask the player to enter a letter
            std::cout << player << "'s turn: \n";

            // Perform some game logic
            newBoard.displayBoard();
            newTilesManager.displayCurrentTile();
            newTilesManager.displayQueue();

            // Let the user choose which cell to fill
            char userInput;
            int fillRow, fillCol;

            std::cout << "Enter the coordinates (e.g., A1): ";
            std::cin >> userInput >> fillRow;
            fillCol = static_cast<int>(userInput) - 'A'; // Convert letter to column index

            // Example of filling a cell with '#' at user-specified coordinates
            newBoard.fillCell(fillRow - 1, fillCol, newTilesManager);
            newTilesManager.deleteLastTile();
        }
    }
}

int Game::getNumberOfPlayers(int &ARRAY_SIZE)
{
    int nbPlayers;
    while (true)
    {
        std::cout << "Players (2 to 9): ";
        std::cin >> nbPlayers;

        if (nbPlayers >= 2 && nbPlayers <= 5)
        {
            ARRAY_SIZE = 20;
        }
        else if (nbPlayers >= 6 && nbPlayers <= 9)
        {
            ARRAY_SIZE = 30;
        }
        else
        {
            std::cout << "Invalid input. Please enter an integer between 2 and 9." << std::endl;
            continue;
        }

        break;
    }

    return nbPlayers;
}

void Game::getPlayerInfo(std::vector<std::string> &playerNames, std::vector<std::string> &playerColors)
{
    std::set<int> chosenColors;

    for (int i = 0; i < numPlayers; ++i)
    {
        std::string playerName;
        std::cout << "Enter name for Player " << i + 1 << ": ";
        std::cin >> playerName;
        playerNames.push_back(playerName);

        while (true)
        {
            displayColorChoices();
            int colorChoice;
            std::cout << "Select color for " << playerName << " (1 to 9): ";
            std::cin >> colorChoice;

            if (chosenColors.find(colorChoice) != chosenColors.end())
            {
                std::cout << "Color already chosen. Please choose a different color." << std::endl;
            }
            else
            {
                chosenColors.insert(colorChoice);
                playerColors.push_back(getColorName(colorChoice));
                break;
            }
        }
    }
}

void Game::displayPlayerInfo(const std::vector<std::string> &playerNames, const std::vector<std::string> &playerColors)
{
    for (int i = 0; i < numPlayers; ++i)
    {
        std::cout << "Player " << i + 1 << ": " << playerNames[i] << " (Color: " << playerColors[i] << ")" << std::endl;
    }
}

void Game::initializePlayers()
{
    std::vector<std::string> playerNames;
    std::vector<std::string> playerColors;

    getPlayerInfo(playerNames, playerColors);
    displayPlayerInfo(playerNames, playerColors);

    playerOrder = playerNames;
}

void Game::shufflePlayerOrder()
{
    // Use a random number generator to shuffle the order of players
    std::random_device rd;
    std::mt19937 g(rd());

    // Shuffle the playerOrder vector
    std::shuffle(playerOrder.begin(), playerOrder.end(), g);
}
