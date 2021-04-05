#include <iostream>
#include "Personne.h"

using namespace std;

int main() {
  Personne p;
  Personne p1("Ramel","Jessica",1995);
  Personne p2("Golo","Thierry",1998);
  Personne p3,p4;

  // affichage
  cout << "p :" << p << endl << "p1 : " << p1 << endl << "p2 : " << p2 << endl;

  // lecture
  cin >> p3;
  cout << p3 << " definie" << endl;

  // copie, set et get
  p4=p3;
  p3.setAnnee(1950);
  cout << p4.getAnnee() << " " << p3.getAnnee() << endl;

  // inferiorite alphabetique
  if (p1<p3) cout << p1 << " est avant " << p3 << endl;
  else cout << p1 << " n'est pas avant " << p3 << endl;
  
}

