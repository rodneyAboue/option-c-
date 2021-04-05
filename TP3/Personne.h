                   // Fichier genere avec ./genere Personne
#ifndef _PERSONNE_H_
#define _PERSONNE_H_

#include <iostream>

using namespace std;

#define _ANNEE_ 2021

class Personne
{
   friend ostream& operator<<(ostream& os, const Personne& aP);
   friend istream& operator>>(istream&,Personne&);

 public :

   // Allocateurs/Desallocateurs

            Personne( /* ### */ );
            Personne(const string, const string, const int);
            Personne(const Personne& aP);
            Personne& operator=(const Personne& aP);
   virtual ~Personne(void);

   // Comparaisons

   friend  bool operator==(const Personne& aP1, const Personne& aP2);
   friend  bool operator!=(const Personne& aP1, const Personne& aP2);

   // inferiorite alphabetique
   bool operator<(const Personne&) const;

   // Inspecteurs/modificateurs
   string getNom() const;
   string getPrenom() const;
   int getAnnee() const;
   void setNom(const string);
   void setPrenom(const string);
   void setAnnee(const int);

 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
                                                      // dans operator<<
   virtual void input(istream&);

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
   // n'est pas virtuelle car ce n'est pas ce prototype dans les classes dérivées
   // donc ce n'est pas la même méthode partout
           bool isEqualTo(const Personne& aP) const;

 protected :

             // ###

 private :

             // ###
    string _nom;
    string _prenom;
    int _annee;

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const Personne& aP);
   void _destroy(void);
};

#endif // _PERSONNE_H_
