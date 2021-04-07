#include <iostream>
#include <vector>
#include "Personne.h"
#include "Etudiant.h"
#include "Enseignant.h"
#include "TabPersonne.h"
using namespace std;

int main() {
  TabPersonne tab ,tab2;
  tab.ajout(new Personne);
  tab.ajout(new Etudiant("Jason", "Thierry",2000,10,17));
  tab.ajout(new Enseignant);
  cout<<tab;
  cout<<tab2;
  bool a=(tab==tab2);
  cout<<a<<endl;
  tab2=tab;
  cout<<tab2;

}

