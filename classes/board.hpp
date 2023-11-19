#include <iostream>

class Board
{
private:
    char **array;
    int size;

public:
    Board(int size);
    ~Board();
    void initializeBoard();
    void displayBoard();
    void placeElement(int row, int col, char element);
};

Board::Board(int size)
{
    // Initialiser la taille
    this->size = size;

    // Allouer de la mémoire pour le tableau
    array = new char *[size];
    for (int i = 0; i < size; ++i)
    {
        array[i] = new char[size];
    }
}

Board::~Board()
{
    for (int i = 0; i < size; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

void Board::initializeBoard()
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            array[i][j] = '.';
        }
    }
}

void Board::displayBoard()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
