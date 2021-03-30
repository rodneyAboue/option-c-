                   // Fichier genere avec ./genere Fraction
#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>

using namespace std;



class Fraction
{
   friend ostream& operator<<(ostream& os, const Fraction& aF);
   friend istream& operator>>(istream& os, Fraction& aF);

 public :

   // Allocateurs/Desallocateurs

            Fraction( /* ### */ );
            Fraction( const int numero );
            Fraction( const int numero ,const int denominateur);
            
            Fraction(const Fraction& aF);
            Fraction& operator=(const Fraction& aF);
           
   virtual ~Fraction(void);

   // Comparaisons

   friend  bool operator==(const Fraction& aF1, const Fraction& aF2);
   friend  bool operator!=(const Fraction& aF1, const Fraction& aF2);
   friend  Fraction operator+(const Fraction& aF1, const Fraction& aF2);
   friend  Fraction operator+(const Fraction& aF, const int i);
   friend  Fraction operator+(const int i,const Fraction& aF);
   friend  Fraction operator*(const Fraction& aF1, const Fraction& aF2);
   friend  Fraction operator*(const Fraction& aF, const int i);
   friend  Fraction operator*(const int i,const Fraction& aF);
   // Inspecteurs/modificateurs
   int get_numerator();
   int get_denominator();
   void set_denominator(const int i );
   void set_numerator(const int i );
 protected :

   // Methodes a appeler par une classe derivee

   // display: a appeler dans une classe derivee      // display est une
   virtual void display(ostream& os) const;           // methode appelee
   virtual void input(istream& os);
                                              // dans operator<<

   // isEqualTo: a appeler dans une classe derivee (dans operator==)
           bool isEqualTo(const Fraction& aF) const;

 protected :

             // ###

 private :

             int num;
			 int den;

 private :

   // Methodes privees d'allocation/desallocation

   void _copy(const Fraction& aF);
   void _destroy(void);
};

#endif // _FRACTION_H_
