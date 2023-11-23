#include <iostream>
#include "tiles.hpp"

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
    void fillCell(int row, int col, TilesManager &tilesManager);
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
void Board::fillCell(int row, int col, TilesManager &tilesManager)
{
    // Get the last tile from the TilesManager
    std::vector<Tile> tiles = tilesManager.getTiles();
    if (tiles.empty())
    {
        std::cout << "No tiles available to place on the board." << std::endl;
        return;
    }

    const Tile &tile = tiles.back(); // Get the last tile from the vector

    // Check if any part of the tile is outside the board
    for (const auto &coord : tile.coordinates)
    {
        int newRow = row + coord.y;
        int newCol = col + coord.x;

        if (newRow < 0 || newRow >= boardSize || newCol < 0 || newCol >= boardSize)
        {
            std::cout << "Invalid tile placement, part of the tile is outside the board." << std::endl;
            return; // Exit the function if any part of the tile is outside the board
        }
    }

    // If all coordinates are within the board boundaries, place the tile on the board
    for (const auto &coord : tile.coordinates)
    {
        int newRow = row + coord.y;
        int newCol = col + coord.x;
        board[newRow][newCol] = '#';
    }
}
