                   // Fichier genere avec ./genere Etudiant
#ifndef _ETUDIANT_H_
#define _ETUDIANT_H_

#include <iostream>

#include "Personne.h"

using namespace std;

class Etudiant : public Personne
{
   friend ostream& operator<<(ostream& os, const Etudiant& anE);
   friend istream& operator>>(istream& is, Etudiant&);

 public :

   // Allocateurs/Desallocateurs

            Etudiant( /* ### */ );
	    Etudiant(const string, const string, const int, const double,const double);
            Etudiant(const string, const string, const int);
            Etudiant(const Personne&);
            Etudiant(const Personne&, const double, const double);
            Etudiant(const Etudiant& anE);
            Etudiant& operator=(const Etudiant& anE);
   virtual ~Etudiant(void);

   // Comparaisons

   friend  bool operator==(const Etudiant& anE1, const Etudiant& anE2);
   friend  bool operator!=(const Etudiant& anE1, const Etudiant& anE2);

   // Inspecteurs/modificateurs
   double getNote1() const;
   double getNote2() const;
   void setNote1(const double);
   void setNote2(const double);

   // moyenne
   double moyenne() const;

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<
   virtual void input(istream&);

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const Etudiant& anE) const;

 protected :

             // ###

 private :

             // ###
     double _note1, _note2;

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const Etudiant& anE);
   void _destroy(void);
};

#endif // _ETUDIANT_H_
