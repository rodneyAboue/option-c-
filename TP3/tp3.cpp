#include <iostream>
#include "Personne.h"
#include "Etudiant.h"
#include "Enseignant.h"

using namespace std;

int main() {
  Personne p1("Ramel","Jessica",1975);
  Personne p2("Golo","Thierry",1998);
  Etudiant e1;
  Etudiant e2("Bon","Jean",2000,15,13);
  Etudiant e3(p2,17,10.5);
  Enseignant s("Dusud","Caroline",1970,120,25);
  Enseignant s2;

  // lecture et affichage
  cout << p1 << endl << p2 << endl << e1 << endl << e2 << endl << e3 << endl << s << endl;
  cin >> e1;
  cout << e1 << " defini" << endl;
  cin >> s2;
  cout << s2 << " defini" << endl;

  // set et get
  s2.setAnnee(1950);
  s2.setCM(300);
  cout << s2 << endl;

  // 
  affectation indépendante
  Etudiant e4=e3;
  e3.setNom("Aaaaaah");
  cout << e3 << endl << e4 << endl;
  
  
}