#include <vector>

class Game
{
private:
    int numPlayers;
    int numRounds;
    int rounds = 9;
    std::vector<std::string> players;
    std::vector<std::string> playerOrder;

public:
    Game(int nbPlayers);
    void getPlayers();
};

Game::Game(int nbPlayers) {}

void Game::getPlayers()
{
    
}
