#include <iostream>
#include <fstream> //on utilise fstream afin de lire dans un fichier texte directement les dimensions des différentes tuiles

class Tile
{
private:
    //la taille sur laquelle s'étant la tile (par exemple, si la tile fait 3x4 x=3 donc si posé en x=10 sur plateau alors la tile recouvrera x=10, 11 et 12).
    //de même pour y qui représente donc l'axe Y du plateau.
    int x;
    int y;
public:
    Tile(int x, int y) : x(x); y(y) {}

    //On définir getX et getY, afin d'accéder aux valeurs de la Tile dans la classe qui permettra de les définir
    //Par mesure de sécurité, ces fonctions sont crées pour que les joueurs ne puissent définir les dimensions de leur Tile
    //Elles sont donc uniquement accessible via des fonctions et non directement en public via leur valeur

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

//permet de définir les dimensions d'une tuile par rapport a sa taille

class CustomTile :: public Tile
{
public:
    CustomTile(int x, int y) : Tile(x, y) {}
};

//fonction qui permet de créer par rapport aux nombres de joueurs le nombre parfait de custom tile qu'il faut
// l'argument N°2 : le nombre de joueur sert a définir le nombre maximum de tuiles présent dans le vecteur afin de ne pas surchagé le nombre d'objets a l'intérieur
// l'argument N°3 : argument fixe qui permettrait de définir que chaque joueur a maximum 10.67 tuiles a ramené par sa présence

std::vector<CustomTile> ReadCustomTilesDimensions(const std::string& filename, int NbPlayers, int const TilesMAX)
{
    std::vector<CustomTile> CustomTiles;
    std::ifstream file(filename);

    //bien définir des tuiles 1x1 présent au début du vecteur par rapport aux nombres de joueurs, afin que chaque premier round de chaque joueur soit bien des tiles 1x1

    int defaultNbPlayers = NbPlayers;

    while (defaultNbPlayers > 0)
    {
        CustomTile customtile(1,1);
        Customtiles.push_back(customtile);
        --defaultNbPlayers;
    }

    if (file.is_open())
    {
        int x, y;
        int TilesToRead = TilesMAX * NbPlayers;
        //Par rapport aux nombres de joueurs, le vecteur contiendra le nombre de tuiles nécessaire
        while (TilesToRead > 0 && file >> x >> y)
        {
            CustomTile customTile(x,y);
            CustomTiles.push_back(customTile);
            --TilesToRead;
        }
        file.close();
    }
    else
    {
        std::cout << "Impossible d'ouvrir le fichier: " << filename << std::endl;
    }

    return CustomTiles;
}
