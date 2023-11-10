#include <iostream>

int main()
{
    std::cout << "Players (2 to 9)" << std::endl;

    int nbPlayers;
    std::cin >> nbPlayers;

    int ARRAY_SIZE;
    if (nbPlayers >= 2 && nbPlayers <= 5)
    {
        ARRAY_SIZE = 20;
    }
    else if (nbPlayers >= 6 && nbPlayers <= 9)
    {
        ARRAY_SIZE = 30;
    }

    char array[ARRAY_SIZE][ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            array[i][j] = '.';
        }
    }

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}