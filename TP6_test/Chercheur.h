                   // Fichier genere avec ./genere Chercheur
#ifndef _CHERCHEUR_H_
#define _CHERCHEUR_H_

#include <iostream>

#include "Personne.h"

using namespace std;

class Chercheur : public Personne
{
   friend ostream& operator<<(ostream& os, const Chercheur& aC);

 public :

   // Allocateurs/Desallocateurs

            Chercheur( /* ### */ );
            Chercheur(const Chercheur& aC);
            Chercheur& operator=(const Chercheur& aC);
   virtual ~Chercheur(void);

   // Comparaisons

   friend  bool operator==(const Chercheur& aC1, const Chercheur& aC2);
   friend  bool operator!=(const Chercheur& aC1, const Chercheur& aC2);

   // Inspecteurs/modificateurs
   string getDomaine();
   string setDomaine(const string dom);

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
    virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<
    virtual void input(istream& is);
   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const Chercheur& aC) const;

 protected :

             // ###

 private :

             // ###
  string domaine;

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const Chercheur& aC);
   void _destroy(void);
};

#endif // _CHERCHEUR_H_
