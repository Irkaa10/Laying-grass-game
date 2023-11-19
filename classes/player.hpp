#include <iostream>
#include <string>

class Player
{
private:
    std::string name;
    int color;

public:
    // Constructeur prenant le nom et la couleur en paramètres
    Player(const std::string &playerName, const int playerColor);

    // Méthode pour poser une pièce sur le plateau
    void placePieceOnBoard();
};

// Implémentation du constructeur
Player::Player(const std::string &playerName, const int playerColor) : name(playerName), color(playerColor)
{
}

// Implémentation de la méthode pour poser une pièce sur le plateau
void Player::placePieceOnBoard()
{
    // Logique pour poser une pièce sur le plateau
    std::cout << name << " is placing a piece on the board." << std::endl;
}
