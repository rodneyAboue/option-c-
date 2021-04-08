                   // Fichier genere avec ./genere Enseignant
#include "Enseignant.h"

//--
Enseignant::Enseignant( /* ### */ ) : Personne( /* ### */ )
{
  _CM=0;
  _TD=0;
}

//--
Enseignant::Enseignant(const string nom,const string prenom,const int annee,const int cm,const int td ) : Personne(nom,prenom,annee)
{
  _CM=cm;
  _TD=td;
}

//--
Enseignant::Enseignant(const string nom,const string prenom,const int annee) : Personne(nom,prenom,annee)
{
  _CM=0;
  _TD=0;
}

//--
Enseignant::Enseignant(const Personne&p ) : Personne( p )
{
  _CM=0;
  _TD=0;
}

//--
Enseignant::Enseignant(const Personne&p ,const int cm,const int td) : Personne( p )
{
  _CM=cm;
  _TD=td;
}

//--
Enseignant::Enseignant(const Enseignant& anE) : Personne(anE)
{
 _copy(anE);
}

//--
Enseignant& Enseignant::operator=(const Enseignant& anE)
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
Enseignant::~Enseignant(void)
{
 _destroy();
}

//--
bool operator==(const Enseignant& anE1, const Enseignant& anE2)
{
 return anE1.isEqualTo(anE2);
}

//--
bool operator!=(const Enseignant& anE1, const Enseignant& anE2)
{
 return !(anE1==anE2);
}

//--
ostream& operator<<(ostream& os, const Enseignant& anE)
{
 anE.display(os);
 return os;
}

//--
void Enseignant::display(ostream& os) const
{
 //(void)os; // Pour eviter un warning si pas utilise

 Personne::display(os);

 // ### : Affichage des attributs de la classe Enseignant
 // Exemple : os << _at;
 os << " qui fait " << hetd() << " HETD";
}

//--
istream& operator>>(istream& is, Enseignant& anE)
{
 anE.input(is);
 return is;
}

//--
void Enseignant::input(istream& is) 
{
 //(void)os; // Pour eviter un warning si pas utilise

 //cout << "lecture d'un enseignant" << endl;
 Personne::input(is);
 cout << "Nombre d'heures de CM ? ";
 is >> _CM;
 cout << "Nombre d'heures de TD ? ";
 is >> _TD;

}

//--
bool Enseignant::isEqualTo(const Enseignant& anE) const
{
 //(void)anE; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe Enseignant
 // Exemple : if (_at != anE._at) return false;

 if (!(Personne::isEqualTo(anE))) return false;
 return true;
}

//--
void Enseignant::_copy(const Enseignant& anE)
{
 //(void)anE; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe Enseignant
 // Exemple : _at = anE._at;

  _CM=anE._CM;
  _TD=anE._TD;
}

//--
void Enseignant::_destroy(void)
{
 // ### : Destruction des attributs de la classe Enseignant
 // Exemple : delete _at;
}
   
void Enseignant::setCM(const int cm) 
{
  _CM=cm;
}
   
void Enseignant::setTD(const int td)
{
  _TD=td;
}
   
int Enseignant::getCM() const
{
  return _CM;
}

   
int Enseignant::getTD() const
{
  return _TD;
}

   
   
double Enseignant::hetd() const
{
   return 1.5*_CM+_TD;
}


