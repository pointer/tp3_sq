/*  INF3105 - Structures de données et algorithmes
 *  UQAM / Département d'informatique / TP3
 *
 *  Vos noms + codes permanents :
 */

#ifndef CARTE_H
#define CARTE_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Carte
{
public:
  friend istream &operator>>(istream &is, Carte &carte);
  void Afficher() const;

private:
  struct Noeud
  {
    string rue, debut, fin;
    int cout;
    Noeud(string r, string d, string f, int c) : rue(r), debut(d), fin(f), cout(c) {}
  };

  vector<string> sites;
  vector<Noeud> noeuds;

  static bool CompareNoeuds(const Noeud &a, const Noeud &b);
};

#endif // CARTE_H
