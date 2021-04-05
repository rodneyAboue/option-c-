                   // Fichier genere avec ./genere Etudiant
#include "Etudiant.h"

//--
Etudiant::Etudiant( /* ### */ ) : Personne( /* ### */ )
{
   _note1=0;
   _note2=0;
}

//--
Etudiant::Etudiant(const string nom, const string prenom, const int annee, const double n1, const double n2 ) : Personne(nom,prenom,annee)
{
   _note1=n1;
   _note2=n2;
}

//--
Etudiant::Etudiant(const string nom, const string prenom, const int annee) : Personne(nom,prenom,annee)
{
   _note1=0;
   _note2=0;
}

//--
Etudiant::Etudiant(const Personne &p ) : Personne(p)
{
   _note1=0;
   _note2=0;
}

//--
Etudiant::Etudiant(const Personne &p,const double n1, const double n2 ) : Personne(p)
{
   _note1=n1;
   _note2=n2;
}

//--
Etudiant::Etudiant(const Etudiant& anE) : Personne(anE)
{
 _copy(anE);
}

//--
Etudiant& Etudiant::operator=(const Etudiant& anE)
{
 if (this != &anE)
 {
  Personne::operator=(anE);
  _destroy();
  _copy(anE);
 }
 return *this;
}

//--
Etudiant::~Etudiant(void)
{
 _destroy();
}

//--
bool operator==(const Etudiant& anE1, const Etudiant& anE2)
{
 return anE1.isEqualTo(anE2);
}

//--
bool operator!=(const Etudiant& anE1, const Etudiant& anE2)
{
 return !(anE1==anE2);
}

//--
ostream& operator<<(ostream& os, const Etudiant& anE)
{
 anE.display(os);
 return os;
}

//--
void Etudiant::display(ostream& os) const
{
 //(void)os; // Pour eviter un warning si pas utilise

 Personne::display(os);

 // ### : Affichage des attributs de la classe Etudiant
 // Exemple : os << _at;
 os << " a pour moyenne " << moyenne();
}

//--
istream& operator>>(istream& is, Etudiant& anE)
{
 anE.input(is);
 return is;
}

//--
void Etudiant::input(istream& is) 
{
 cout << "lecture d'un etudiant"<< endl;
 Personne::input(is);
 cout << "Quelle est la premiere note ? ";
 is >> _note1;
 cout << "Quelle est la deuxième note ? ";
 is >> _note2;
}

//--
bool Etudiant::isEqualTo(const Etudiant& anE) const
{
  // deux etudiants sont egaux si les personnes sont egales (on suppose pas d'homonymes)

 if (!(Personne::isEqualTo(anE))) return false;
 return true;
}

//--
void Etudiant::_copy(const Etudiant& anE)
{
 _note1=anE._note1;
 _note2=anE._note2;
}

//--
void Etudiant::_destroy(void)
{
 // ### : Destruction des attributs de la classe Etudiant
 // Exemple : delete _at;
}


   
double Etudiant::getNote1() const
{
  return _note1;
}

   
double Etudiant::getNote2() const
{
  return _note2;
}

   
void Etudiant::setNote1(const double n)
{
  _note1=n;
}

   
void Etudiant::setNote2(const double n)
{
  _note2=n;
}

double Etudiant::moyenne() const
{
   return (_note1+_note2)/2;
}




