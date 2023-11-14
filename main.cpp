#include <iostream>
#include <vector>
#include <string>
#include <set> // Ajout de la bibliothèque set pour gérer les couleurs déjà choisies

// Fonction pour afficher les choix de couleurs
void displayColorChoices()
{
    std::cout << "Color Choices:" << std::endl;
    std::cout << "1. Red" << std::endl;
    std::cout << "2. Green" << std::endl;
    std::cout << "3. Blue" << std::endl;
    std::cout << "4. Yellow" << std::endl;
    std::cout << "5. Magenta" << std::endl;
    std::cout << "6. Cyan" << std::endl;
    std::cout << "7. White" << std::endl;
    std::cout << "8. Black" << std::endl;
    std::cout << "9. Orange" << std::endl;
}

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

    // Demander aux joueurs leur nom et couleur
    std::vector<std::string> playerNames;
    std::vector<std::string> playerColors;

    // Utiliser un ensemble (set) pour suivre les couleurs déjà choisies
    std::set<int> chosenColors;

    for (int i = 0; i < nbPlayers; ++i)
    {
        std::string playerName;
        std::cout << "Enter name for Player " << i + 1 << ": ";
        std::cin >> playerName;
        playerNames.push_back(playerName);

        while (true)
        {
            displayColorChoices();
            int colorChoice;
            std::cout << "Select color for " << playerName << " (1 to 9): ";
            std::cin >> colorChoice;

            // Vérifier si la couleur est déjà choisie
            if (chosenColors.find(colorChoice) != chosenColors.end())
            {
                std::cout << "Color already chosen. Please choose a different color." << std::endl;
            }
            else
            {
                // Ajouter la couleur choisie à l'ensemble
                chosenColors.insert(colorChoice);

                // Associer le choix de couleur à une couleur réelle
                std::string color;
                switch (colorChoice)
                {
                case 1:
                    color = "Red";
                    break;
                case 2:
                    color = "Green";
                    break;
                case 3:
                    color = "Blue";
                    break;
                case 4:
                    color = "Yellow";
                    break;
                case 5:
                    color = "Magenta";
                    break;
                case 6:
                    color = "Cyan";
                    break;
                case 7:
                    color = "White";
                    break;
                case 8:
                    color = "Black";
                    break;
                case 9:
                    color = "Orange";
                    break;
                default:
                    std::cout << "Invalid color choice. Defaulting to Black." << std::endl;
                    color = "Black";
                    break;
                }

                playerColors.push_back(color);
                break;
            }
        }
    }

    // Initialiser et afficher le tableau
    char array[ARRAY_SIZE][ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = 0; j < ARRAY_SIZE; j++)
        {
            array[i][j] = '.';
        }
    }

    // Afficher les noms et couleurs des joueurs
    for (int i = 0; i < nbPlayers; ++i)
    {
        std::cout << "Player " << i + 1 << ": " << playerNames[i] << " (Color: " << playerColors[i] << ")" << std::endl;
    }

    // Afficher le tableau
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
