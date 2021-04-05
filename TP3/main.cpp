#include <iostream>
#include <vector>
#include "Personne.h"
#include "Etudiant.h"
#include "Enseignant.h"

using namespace std;

int main() {
  Personne tab[3];
  tab[0]=Personne();
  tab[1]=Etudiant("Jason", "Thierry",2000,10,17);
  tab[2]=Enseignant();

  for (int i = 0; i < 3; ++i)
  {
    cout<<tab[i]<<endl;
  }  
  vector<Personne> tab2;
  cout<<"il y a :"<<tab2.size()<<endl;
  tab2.push_back(Personne("Terieur", " Alain ",1965));
  for (Personne element :tab2)
      cout << element << endl ; 
}

