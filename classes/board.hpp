#include <iostream>
#include <vector>

class Board
{
private:
    int boardSize;
    std::vector<std::vector<char> > board;

public:
    Board(int size);
    ~Board();
    void initBoard();
    void displayBoard() const;
    void fillCell(int row, int col);
};

// constructor
Board::Board(int size) : boardSize(size), board(size, std::vector<char>(size, '.')) {}

// Default destructor
Board::~Board() = default;

void Board::displayBoard() const
{
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
}

void Board::fillCell(int row, int col)
{
    if (row >= 0 && row < boardSize && col >= 0 && col < boardSize)
    {
        board[row][col] = 'X';
    }
    else
    {
        std::cout << "Invalid coordinates. Cell not filled." << std::endl;
    }
}
