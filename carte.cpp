#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Carte {
public:
    friend istream &operator>>(istream &is, Carte &carte);
    void Afficher() const;

private:
    struct Noeud {
        string rue, debut, fin;
        int cout;
        Noeud(string r, string d, string f, int c) : rue(r), debut(d), fin(f), cout(c) {}
    };

    vector<string> sites;
    vector<Noeud> noeuds;

    static bool CompareNoeuds(const Noeud& a, const Noeud& b);
};

istream &operator>>(istream &is, Carte &carte) {
    string ligne;

    // Clear existing data
    carte.sites.clear();
    carte.noeuds.clear();

    // Read sites until "---"
    while (getline(is, ligne) && ligne != "---") {
        carte.sites.push_back(ligne);
    }

    // Read nodes until "---" or end of stream
    while (getline(is, ligne) && ligne != "---") {
        stringstream ss(ligne);
        string rue, debut, fin;
        int cout;
        getline(ss, rue, ':');
        ss >> debut >> fin >> cout;
        carte.noeuds.emplace_back(rue, debut, fin, cout);
    }

    return is;
}

void Carte::Afficher() const {
    // Afficher les sites
    for (const auto& site : sites) {
        cout << site << endl;
    }

    // Afficher noeuds et calculer le cout total
    int cout_total = 0;
    for (const auto& noeud : noeuds) {
        cout << noeud.rue << " " << noeud.debut << " " << noeud.fin << " " << noeud.cout << endl;
        cout_total += noeud.cout;
    }

    cout << "---" << endl << cout_total << endl;
}

bool Carte::CompareNoeuds(const Noeud& a, const Noeud& b) {
    if (a.debut == b.debut) {
        return a.fin == b.fin ? a.cout < b.cout : a.fin < b.fin;
    }
    return a.debut < b.debut;
}