#include <iostream>
#include <vector>

class Player
{
private:
    std::string name;
    int color;

public:
    // Constructeur prenant le nom et la couleur en paramètres
    Player(const std::string &playerName, const int playerColor);
    // Méthode pour afficher les informations du joueur
    void displayInfo() const;
};

// Implémentation du constructeur
Player::Player(const std::string &playerName, const int playerColor) : name(playerName), color(playerColor) {}

void Player::displayInfo() const
{
    std::cout << "Player " << name << " (Color: " << color << ")" << std::endl;
}
