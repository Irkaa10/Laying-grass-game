#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Coordinate
{
    int x, y; // x and y coordinates
};

struct Tile
{
    char id;                             // Tile ID
    std::vector<Coordinate> coordinates; // Coordinates of the tile
};

class TilesManager
{
private:
    std::vector<Tile> tiles; // Vector to store the tiles

public:
    // TilesManager(const std::string &filename);   // Constructor to read the tiles from a file
    std::vector<Tile> readTilesFromFile(const std::string &filename); // Function to return the vector of tiles
    void displayTile(const Tile &tile);                               // Function to display the tiles
    void handleRotation(Tile &tile);                                  // Function to rotate the tiles
    void displayQueue();                                              // Function to display the next 5 tiles
};

// Function to read tiles from a file and store them in a vector of Tile objects
std::vector<Tile> TilesManager::readTilesFromFile(const std::string &filename)
{
    std::vector<Tile> tiles;      // Vector to store the tiles read from the file
    std::ifstream file(filename); // Open the file

    if (file.is_open()) // Check if the file is open
    {
        std::string line;                // String to store each line read from the file
        while (std::getline(file, line)) // Read each line from the file
        {
            if (line.substr(0, 5) == "Tile:") // Check if the line starts with "Tile:" by comparing the first 5 characters of the line
            {
                Tile tile;         // Create a Tile object to store the tile
                tile.id = line[6]; // Get the tile ID from the line (the 7th character)

                while (std::getline(file, line) && !line.empty()) // Read the coordinates of the tile until an empty line is encountered or the end of the file is reached
                {
                    std::istringstream iss(line);      // Create an input string stream to read the coordinates from the line
                    Coordinate coord;                  // Create a Coordinate object to store the coordinates
                    iss >> coord.x >> coord.y;         // Read the coordinates from the string stream and store them in the Coordinate object
                    tile.coordinates.push_back(coord); // Add the coordinates to the vector of coordinates
                }

                tiles.push_back(tile); // Add the tile to the vector of tiles
            }
        }

        file.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return tiles; // Return the vector of tiles
}

// Function to rotate a tile 90 degrees clockwise
void TilesManager::handleRotation(Tile &tile) // Pass by reference to modify the original tile
{
    for (auto &coord : tile.coordinates) // Loop through each coordinate of the tile
    {
        // Rotate coordinates (x, y) to (y, -x)
        int temp = coord.x; // Store x in a temporary variable
        coord.x = coord.y;  // Set x to y
        coord.y = -temp;    // Set y to -x
    }
}

// Function to display the next 5 tiles in the queue (The last 5 tiles in the vector)
void TilesManager::displayQueue()
{
    int startIdx = std::max(0, static_cast<int>(tiles.size()) - 5); // Start index for the last 5 tiles

    std::cout << "Next tiles:" << std::endl;
    for (int i = startIdx; i < tiles.size(); ++i) // Loop through the last 5 tiles in the vector of tiles
    {
        displayTile(tiles[i]); // Display the tile
    }
}

// Function to display the graphical representation of a tile on a grid
void TilesManager::displayTile(const Tile &tile)
{
    // Find the dimensions of the tile to determine the grid size
    int minX = 0, minY = 0, maxX = 0, maxY = 0; // Initialize the min and max coordinates to the first coordinate of the tile
    for (const auto &coord : tile.coordinates)  // Loop through each coordinate of the tile
    {
        minX = std::min(minX, coord.x); // Update the min and max coordinates
        minY = std::min(minY, coord.y);
        maxX = std::max(maxX, coord.x);
        maxY = std::max(maxY, coord.y);
    }

    // Create an empty grid to display the tile
    std::vector<std::vector<char>> grid(maxY - minY + 1, std::vector<char>(maxX - minX + 1, ' '));

    // Mark the tile coordinates on the grid
    for (const auto &coord : tile.coordinates)
    {
        grid[coord.y - minY][coord.x - minX] = '#';
    }

    // Display the grid
    for (int y = 0; y <= maxY - minY; ++y)
    {
        for (int x = 0; x <= maxX - minX; ++x)
        {
            std::cout << grid[y][x] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}
