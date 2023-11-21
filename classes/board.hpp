#include <iostream>

class Board
{
private:
    int boardSize;
    char **board;

public:
    Board(int size);
    ~Board();
    void initBoard();
    void displayBoard() const;
    void fillCell(int row, int col);
};

// constructor to initialize the board size and allocate memory for the 2D array
Board::Board(int size) : boardSize(size)
{
    // Allocate memory for the 2D array
    board = new char *[size];
    for (int i = 0; i < size; ++i)
    {
        board[i] = new char[size];
    }

    // Initialize the board
    initBoard();
}

// Destructor to free the allocated memory
Board::~Board()
{
    for (int i = 0; i < boardSize; ++i)
    {
        delete[] board[i];
    }
    delete[] board;
}

// Function to initialize the board with '.' in each cell
void Board::initBoard()
{
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; ++j)
        {
            board[i][j] = '.';
        }
    }
}

void Board::displayBoard() const
{
    // Print column coordinates with letters
    std::cout << "   ";
    for (int i = 0; i < boardSize; ++i)
    {
        std::cout << char('A' + i) << " ";
    }
    std::cout << std::endl;

    // Print rows with row coordinates, letters, and array elements
    for (int i = 0; i < boardSize; ++i)
    {
        std::cout << char('A' + i) << "  ";
        for (int j = 0; j < boardSize; ++j)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to fill a cell with 'X' at the specified coordinates (int row, int col).
void Board::fillCell(int row, int col)
{
    if (row >= 0 && row < boardSize && col >= 0 && col < boardSize) // Check if coordinates are valid (within the board)
    {
        board[row][col] = 'X';
    }
    else
    {
        std::cout << "Invalid coordinates. Cell not filled." << std::endl;
    }
}
