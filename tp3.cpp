#include "carte.h"
#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: ./tp3 carte.txt" << endl;
        return 1;
    }

    ifstream fichier(argv[1]);
    if (!fichier.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    unique_ptr<Carte> carte = make_unique<Carte>();
    fichier >> *carte;
    carte->Afficher();

    // The file will be automatically closed when 'fichier' goes out of scope.
    return 0;
}