#include <iostream>
#include <vector>

enum Color {
    Red = 1,
    Green,
    Blue,
    Yellow,
    Magenta,
    Cyan,
    White,
    Black,
    Orange
};

class Player
{
private:
    std::string name;
    Color color;
    std::vector<std::pair<int, int> > territory;

public:
    // Constructeur prenant le nom et la couleur en paramètres
    Player(const std::string &playerName, const Color playerColor);
    // Méthode pour afficher les informations du joueur
    void displayInfo() const;
    std::string getName() const;
    Color getColor() const; // Getter for the color
    void addTerritory(int x, int y, int boardsSize);
};

// Implémentation du constructeur
Player::Player(const std::string &playerName, const Color playerColor) : name(playerName), color(playerColor) {}

std::string Player::getName() const
{
    return name;
}

Color Player::getColor() const
{
    return color;
}

void Player::displayInfo() const
{
    std::cout << "Player " << name << " (Color: " << color << ")" << std::endl;
}

void Player::addTerritory(int x, int y, int boardSize)
{
    // Add the given cell if it is within bounds
    if (x >= 0 && x < boardSize && y >= 0 && y < boardSize)
    {
        territory.emplace_back(x, y);

        // Add neighboring cells if they are within bounds
        if (x + 1 >= 0 && x + 1 < boardSize && y >= 0 && y < boardSize)
            territory.emplace_back(x + 1, y);
        if (x - 1 >= 0 && x - 1 < boardSize && y >= 0 && y < boardSize)
            territory.emplace_back(x - 1, y);
        if (x >= 0 && x < boardSize && y + 1 >= 0 && y + 1 < boardSize)
            territory.emplace_back(x, y + 1);
        if (x >= 0 && x < boardSize && y - 1 >= 0 && y - 1 < boardSize)
            territory.emplace_back(x, y - 1);
        if (x + 1 >= 0 && x + 1 < boardSize && y + 1 >= 0 && y + 1 < boardSize)
            territory.emplace_back(x + 1, y + 1);
        if (x - 1 >= 0 && x - 1 < boardSize && y - 1 >= 0 && y - 1 < boardSize)
            territory.emplace_back(x - 1, y - 1);
        if (x + 1 >= 0 && x + 1 < boardSize && y - 1 >= 0 && y - 1 < boardSize)
            territory.emplace_back(x + 1, y - 1);
        if (x - 1 >= 0 && x - 1 < boardSize && y + 1 >= 0 && y + 1 < boardSize)
            territory.emplace_back(x - 1, y + 1);
    }
}
