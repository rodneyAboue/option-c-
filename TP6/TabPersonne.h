                   // Fichier genere avec ./genere TabPersonne
#ifndef _TABPERSONNE_H_
#define _TABPERSONNE_H_
#include "Personne.h"
#include <iostream>
#define MAX 100
using namespace std;

class TabPersonne
{
   friend ostream& operator<<(ostream& os, const TabPersonne& aT);

 public :

   // Allocateurs/Desallocateurs

            TabPersonne( /* ### */ );
            TabPersonne(const TabPersonne& aT);
            TabPersonne& operator=(const TabPersonne& aT);
   virtual ~TabPersonne(void);

   // Comparaisons

   friend  bool operator==(const TabPersonne& aT1, const TabPersonne& aT2);
   friend  bool operator!=(const TabPersonne& aT1, const TabPersonne& aT2);
   Personne* operator[](const int i);

   // Inspecteurs/modificateurs
   int getNbelement();
   void ajout(Personne* p);

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const TabPersonne& aT) const;

 protected :

             // ###

 private :

             // ###
          int _nbElm;
          Personne **tab;
          //vector<Personne*> tab 
          /*for (Personne* element : tab )
          {
            
          }*/

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const TabPersonne& aT);
   void _destroy(void);
};

#endif // _TABPERSONNE_H_
