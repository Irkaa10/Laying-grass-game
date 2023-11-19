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
    this->size = size + 1; // Augmentez la taille pour ajouter une ligne et une colonne pour les nombres
    array = new char *[this->size];
    for (int i = 0; i < this->size; ++i)
    {
        array[i] = new char[this->size];
        for (int j = 0; j < this->size; ++j)
        {
            if (i == 0) // Première ligne pour les nombres de colonnes
            {
                array[i][j] = j == 0 ? ' ' : char('0' + j);
            }
            else if (j == 0) // Première colonne pour les nombres de lignes
            {
                array[i][j] = char('0' + i);
            }
            else
            {
                array[i][j] = '.';
            }

            if (array[i][j] > '9')
            {
                // Si la valeur est supérieure à '9', remplacez-la par un entier
                array[i][j] = char('0' + i);
            }
        }
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
