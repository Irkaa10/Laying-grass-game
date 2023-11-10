#include <iostream>

int main()
{
    int nbPlayers;
    int ARRAY_SIZE;

    while (true)
    {
        std::cout << "Players (2 to 9): ";
        std::cin >> nbPlayers;

        switch (nbPlayers)
        {
        case 2:
        case 3:
        case 4:
        case 5:
            ARRAY_SIZE = 20;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            ARRAY_SIZE = 30;
            break;
        default:
            std::cout << "Invalid input. Please enter an integer between 2 and 9." << std::endl;
            continue;
        }

        break;
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