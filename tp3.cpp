#include "carte.h"
#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char *argv[]) 
{
    if (argc != 3)
    {
        cerr << "Usage: ./tp3 input_carte.txt output_file.txt" << endl;
        return 1;
    }

    ifstream fichier(argv[1]);
    if (!fichier.is_open())
    {
        cerr << "Erreur ouverture fichier entree" << endl;
        return 1;
    }
    std::ofstream out_file(argv[2]);
    if (!out_file.is_open())
    {
        cerr << "Erreur ouverture fichier sortie" << endl;
        return 1;
    }

    unique_ptr<Carte> carte = make_unique<Carte>();
    fichier >> *carte;
    carte->Afficher(out_file);
    out_file.close();

    // The file will be automatically closed when 'fichier' goes out of scope.
    return 0;
}