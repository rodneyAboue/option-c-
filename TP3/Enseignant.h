                   // Fichier genere avec ./genere Enseignant
#ifndef _ENSEIGNANT_H_
#define _ENSEIGNANT_H_

#include <iostream>

#include "Personne.h"

using namespace std;

class Enseignant : public Personne
{
   friend ostream& operator<<(ostream& os, const Enseignant& anE);
   friend istream& operator>>(istream& is, Enseignant&);

 public :

   // Allocateurs/Desallocateurs

            Enseignant( /* ### */ );
            Enseignant(const string,const string,const int,const int,const int);
            Enseignant(const Personne&,const int,const int);
            Enseignant(const string,const string,const int);
            Enseignant(const Personne&);
            Enseignant(const Enseignant& anE);
            Enseignant& operator=(const Enseignant& anE);
   virtual ~Enseignant(void);

   // Comparaisons

   friend  bool operator==(const Enseignant& anE1, const Enseignant& anE2);
   friend  bool operator!=(const Enseignant& anE1, const Enseignant& anE2);

   // Inspecteurs/modificateurs
   void setCM(const int);
   void setTD(const int);
   int getCM() const;
   int getTD() const;

   // calcul des HETD
   double hetd() const;

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<
   virtual void input(istream&);

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const Enseignant& anE) const;

 protected :

             // ###

 private :

             // ###
   int _CM,_TD;

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const Enseignant& anE);
   void _destroy(void);
};

#endif // _ENSEIGNANT_H_
