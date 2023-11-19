#include <iostream>

class Board
{
private:
    char **array; // Utilisation d'un double pointeur pour créer un tableau dynamique
    int size;     // Ajout d'une variable pour stocker la taille du tableau

public:
    Board(int size);        // Ajout d'un constructeur avec la taille du tableau comme argument
    ~Board();               // Ajout d'un destructeur pour libérer la mémoire allouée dynamiquement
    void initializeBoard(); // Ajout d'une fonction pour initialiser le tableau
    void displayBoard();    // Ajout d'une fonction pour afficher le tableau
};

// Définition du constructeur
Board::Board(int size)
{
    this->size = size;

    // Allocation dynamique du tableau 2D
    array = new char *[size];
    for (int i = 0; i < size; ++i)
    {
        array[i] = new char[size];
        for (int j = 0; j < size; ++j)
        {
            array[i][j] = '.';
        }
    }
}

// Définition du destructeur
Board::~Board()
{
    // Libération de la mémoire allouée dynamiquement
    for (int i = 0; i < size; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

// Définition de la fonction initializeBoard
void Board::initializeBoard()
{
    // Vous pouvez réinitialiser le tableau ici si nécessaire
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = '.';
        }
    }
}

// Définition de la fonction displayBoard
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
