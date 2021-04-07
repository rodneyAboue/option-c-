                   // Fichier genere avec ./genere EnsChercheur
#ifndef _ENSCHERCHEUR_H_
#define _ENSCHERCHEUR_H_

#include <iostream>

#include "Enseignant.h"
#include "Chercheur.h"

using namespace std;

class EnsChercheur : public Enseignant,
                     public Chercheur
{
   friend ostream& operator<<(ostream& os, const EnsChercheur& anE);

 public :

   // Allocateurs/Desallocateurs

            EnsChercheur( /* ### */ );
            EnsChercheur(const EnsChercheur& anE);
            EnsChercheur& operator=(const EnsChercheur& anE);
   virtual ~EnsChercheur(void);

   // Comparaisons

   friend  bool operator==(const EnsChercheur& anE1, const EnsChercheur& anE2);
   friend  bool operator!=(const EnsChercheur& anE1, const EnsChercheur& anE2);

   // Inspecteurs/modificateurs

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const EnsChercheur& anE) const;

 protected :

             // ###

 private :

             // ###

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const EnsChercheur& anE);
   void _destroy(void);
};

#endif // _ENSCHERCHEUR_H_
