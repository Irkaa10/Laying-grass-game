#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <random>
#include <limits>
#include <cstdlib> // for system()

#include "board.hpp"
#include "player.hpp"

class Game
{
private:
    int numRounds = 9;
    int ARRAY_SIZE;
    int numPlayers;
    std::vector<Player> players;           // Now using vector of Player objects instead of strings
    std::vector<std::string> playerColors; // Vector to store the colors of the players
    std::vector<std::string> playerOrder;
    void displayPlayerInfo() const;
    void displayAvailableColors() const;
    void displayTerritory() const;
    void initializePlayers();
    void shufflePlayerOrder();

public:
    void run(); // Run the game
};

void Game::run() // Handle the game logic
{
    initializePlayers();
    displayPlayerInfo();
    // int ARRAY_SIZE;
    // numPlayers = getNumberOfPlayers(ARRAY_SIZE);

    // Ransomize the order of players
    shufflePlayerOrder();

    Board newBoard(ARRAY_SIZE);
    TilesManager newTilesManager;

    newTilesManager.readTilesFromFile("game_tiles.txt");

    for (int round = 1; round <= numRounds; ++round)
    {
        std::cout << "\nRound " << round << ":\n";

        for (const std::string &playerName : playerOrder)
        {
            auto playerIt = std::find_if(players.begin(), players.end(), [&](const Player &player)
                                         { return player.getName() == playerName; });

            if (playerIt == players.end())
            {
                // Handle error, player not found
                continue;
            }

            Player &currentPlayer = *playerIt;

            // Ask the player to enter a letter
            std::cout << currentPlayer.getName() << "'s turn: \n";

            // Display player's territory
            std::cout << "Territory Content:" << std::endl;

            // Get the territory vector from the player
            std::vector<std::pair<int, int>> playerTerritory = currentPlayer.getTerritory();

            // Display the content of the territory vector
            for (const auto &cell : playerTerritory)
            {
                std::cout << "(" << cell.first << ", " << cell.second << ") ";
            }

            std::cout << std::endl;

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

            // Add the filled cell to the player's territory
            currentPlayer.addTerritory(fillRow - 1, fillCol, ARRAY_SIZE);

            newTilesManager.deleteLastTile();
        }
        
    }
}

void Game::displayPlayerInfo() const
{
    for (const auto &player : players)
    {
        player.displayInfo();
    }
}

void Game::displayAvailableColors() const
{
    std::cout << "Available Colors:" << std::endl;
    for (int i = 1; i <= 9; ++i)
    {
        std::cout << i << " - " << playerColors[i - 1] << std::endl;
    }
}

void Game::initializePlayers()
{
    do
    {
        std::cout << "Enter the number of players (between 2 and 9): ";
        std::cin >> numPlayers;

        if (std::cin.fail() || numPlayers < 2 || numPlayers > 9)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Please enter a valid integer between 2 and 9." << std::endl;
        }
        else
        {
            break;
        }
    } while (true);

    if (numPlayers >= 2 && numPlayers <= 4)
    {
        ARRAY_SIZE = 20;
    }
    else if (numPlayers >= 5 && numPlayers <= 9)
    {
        ARRAY_SIZE = 30;
    }

    playerColors = {"Red", "Green", "Blue", "Yellow", "Magenta", "Cyan", "White", "Black", "Orange"};

    displayAvailableColors(); // Show available colors

    for (int i = 0; i < numPlayers; ++i)
    {
        std::string playerName;
        int colorChoice;

        std::cout << "Enter the name for Player " << (i + 1) << ": ";
        std::cin >> playerName;

        do
        {
            std::cout << "Choose color for Player " << (i + 1) << " (1-9): ";
            std::cin >> colorChoice;

            if (std::cin.fail() || colorChoice < 1 || colorChoice > 9)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid color choice. Please enter an integer between 1 and 9." << std::endl;
            }
            else
            {
                // Check if the color is already chosen by another player
                bool colorTaken = false;
                for (const auto &player : players)
                {
                    if (player.getColor() == static_cast<Color>(colorChoice))
                    {
                        colorTaken = true;
                        break;
                    }
                }

                if (!colorTaken)
                {
                    break; // Exit the loop if the color choice is valid and not taken
                }
                else
                {
                    std::cout << "Color already chosen by another player. Choose a different color." << std::endl;
                }
            }

        } while (true);

        Color playerColor = static_cast<Color>(colorChoice);
        Player player(playerName, playerColor);
        players.push_back(player);
    }
}

void Game::shufflePlayerOrder()
{
    // Populate playerOrder with player names before shuffling
    for (const auto &player : players)
    {
        playerOrder.push_back(player.getName());
    }

    // Use a random number generator to shuffle the order of players
    std::random_device rd;
    std::mt19937 g(rd());

    // Shuffle the playerOrder vector
    std::shuffle(playerOrder.begin(), playerOrder.end(), g);
}

void Game::displayTerritory() const
{
    for (const auto &player : players)
    {
        std::cout << player.getName() << "'s Territory Content:" << std::endl;

        // Get the territory vector from the player
        std::vector<std::pair<int, int>> playerTerritory = player.getTerritory();

        // Display the content of the territory vector
        for (const auto &cell : playerTerritory)
        {
            std::cout << "(" << cell.first << ", " << cell.second << ") ";
        }

        std::cout << std::endl;
    }
}
