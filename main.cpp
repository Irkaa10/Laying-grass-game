#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "helpers/displayColorChoices.hpp"
#include "classes/board.hpp"

int getNumberOfPlayers(int &ARRAY_SIZE)
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

std::string getColorName(int colorChoice)
{
    std::string color;
    switch (colorChoice)
    {
    case 1:
        color = "Red";
        break;
    case 2:
        color = "Green";
        break;
    case 3:
        color = "Blue";
        break;
    case 4:
        color = "Yellow";
        break;
    case 5:
        color = "Magenta";
        break;
    case 6:
        color = "Cyan";
        break;
    case 7:
        color = "White";
        break;
    case 8:
        color = "Black";
        break;
    case 9:
        color = "Orange";
        break;
    default:
        std::cout << "Invalid color choice. Defaulting to Black." << std::endl;
        color = "Black";
        break;
    }
    return color;
}

void getPlayerInfo(int nbPlayers, std::vector<std::string> &playerNames, std::vector<std::string> &playerColors)
{
    std::set<int> chosenColors;

    for (int i = 0; i < nbPlayers; ++i)
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

void displayPlayerInfo(int nbPlayers, const std::vector<std::string> &playerNames, const std::vector<std::string> &playerColors)
{
    for (int i = 0; i < nbPlayers; ++i)
    {
        std::cout << "Player " << i + 1 << ": " << playerNames[i] << " (Color: " << playerColors[i] << ")" << std::endl;
    }
}

int main()
{
    int nbPlayers;
    int ARRAY_SIZE;

    nbPlayers = getNumberOfPlayers(ARRAY_SIZE);

    std::vector<std::string> playerNames;
    std::vector<std::string> playerColors;

    getPlayerInfo(nbPlayers, playerNames, playerColors);

    displayPlayerInfo(nbPlayers, playerNames, playerColors);

    Board newBoard(ARRAY_SIZE);
    newBoard.displayBoard();

    return 0;
}
