                   // Fichier genere avec ./genere Personne
#include "Personne.h"

//--
Personne::Personne( /* ### */ )
{
   _nom="Doe";
   _prenom="John";
   _annee=_ANNEE_;
}

//--
Personne::Personne(const string nom, const string prenom, const int annee)
{
   _nom=nom;
   _prenom=prenom;
   _annee=annee;
}

//--
Personne::Personne(const Personne& aP)
{
 _copy(aP);
}

//--
Personne& Personne::operator=(const Personne& aP)
{
 if (this != &aP)
 {
  _destroy();
  _copy(aP);
 }
 return *this;
}

//--
Personne::~Personne(void)
{
 _destroy();
}

//--
bool operator==(const Personne& aP1, const Personne& aP2)
{
 return aP1.isEqualTo(aP2);
}

//--
bool operator!=(const Personne& aP1, const Personne& aP2)
{
 return !(aP1==aP2);
}

//--
ostream& operator<<(ostream& os, const Personne& aP)
{
 aP.display(os);
 return os;
}

//--
void Personne::display(ostream& os) const
{
   os << _prenom << " " << _nom << " (" << _ANNEE_ - _annee << " ans)";
}

//--
istream& operator>>(istream& is, Personne& aP)
{
 aP.input(is);
 return is;
}

//--
void Personne::input(istream& is) 
{
   cout << "quel nom ? ";
   //is >> _nom;
   getline(is,_nom);   // pour lire aussi si le nom comporte des espaces
   cout << "quel prenom ? ";
   //is >> _prenom;
   getline(is,_prenom);
   cout << "quelle annee de naissance ? ";
   is >> _annee;
}


//--
bool Personne::isEqualTo(const Personne& aP) const
{
 if (_nom!=aP._nom) return false;
 if (_prenom!=aP._prenom) return false;
 if (_annee!=aP._annee) return false;
 return true;
}

//--
void Personne::_copy(const Personne& aP)
{
   _nom=aP._nom;
   _prenom=aP._prenom;
   _annee=aP._annee;
}

//--
void Personne::_destroy(void)
{
 // ### : Destruction des attributs de la classe Personne
 // Exemple : delete _at;
}

void Personne::setNom(const string nom) 
{
   _nom=nom;
}

void Personne::setPrenom(const string prenom) 
{
   _prenom=prenom;
}
void Personne::setAnnee(const int annee) 
{
   _annee=annee;
}

string Personne::getNom() const
{
   return _nom;
}

string Personne::getPrenom() const
{
   return _prenom;
}

int Personne::getAnnee() const
{
   return _annee;
}



bool Personne::operator<(const Personne&p) const
{
   if (_nom<p._nom) return true;
   if (_nom>p._nom) return false;
   return (_prenom<p._prenom);
}






