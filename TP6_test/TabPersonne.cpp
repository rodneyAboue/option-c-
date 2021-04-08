                   // Fichier genere avec ./genere TabPersonne
#include "TabPersonne.h"

//--
TabPersonne::TabPersonne( /* ### */ )
{
	tab= new Personne* [MAX];
	this->_nbElm=0;
}

//--
TabPersonne::TabPersonne(const TabPersonne& aT)
{
 _copy(aT);
}

//--
TabPersonne& TabPersonne::operator=(const TabPersonne& aT)
{
 if (this != &aT)
 {
  _destroy();
  _copy(aT);
 }
 return *this;
}

//--
TabPersonne::~TabPersonne(void)
{
 _destroy();
}

//--
bool operator==(const TabPersonne& aT1, const TabPersonne& aT2)
{
 return aT1.isEqualTo(aT2);
}

//--
bool operator!=(const TabPersonne& aT1, const TabPersonne& aT2)
{
 return !(aT1==aT2);
}

//--
ostream& operator<<(ostream& os, const TabPersonne& aT)
{
 aT.display(os);
 return os;
}

//--
void TabPersonne::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 // ### : Affichage des attributs de la classe TabPersonne
 // Exemple : os << _at;
 	os<<"La table contient : "<<_nbElm<<" element(s)"<<endl; 
 	for (int i = 0; i < _nbElm; ++i)
 	{
 		os<<"["<<*tab[i]<<"]";
 	}
 	os<<endl;
}

//--
bool TabPersonne::isEqualTo(const TabPersonne& aT) const
{
 (void)aT; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe TabPersonne
 // Exemple : if (_at != aT._at) return false;
 for (int i = 0; i < aT._nbElm; ++i)
 {
 	if(tab[i]!=aT.tab[i])
 		return false;
 }
 return true;
}

//--
void TabPersonne::_copy(const TabPersonne& aT)
{
 (void)aT; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe TabPersonne
 // Exemple : _at = aT._at;
 	_nbElm=aT._nbElm;
 	for (int i = 0; i < aT._nbElm; ++i)
 	{
 		tab[i]=aT.tab[i];	
 	}
}

//--
void TabPersonne::_destroy(void)
{
 // ### : Destruction des attributs de la classe TabPersonne
 // Exemple : delete _at;
	delete[] tab;
}

/*-------------------------------------------------------*/
void TabPersonne::ajout(Personne *p)
{
	if (_nbElm < MAX)
	{
		tab[_nbElm]=p;
		_nbElm++;
	}
	else
		cout<<"Error : tab est plein "<<endl;
	
}
Personne* TabPersonne::operator[](const int i)
{
	if (i<_nbElm)
	{
		return tab[i];
	}
	else
	{
		cout<<"Error : the element " << i <<"does not exist"<<endl;
	}
}
int TabPersonne::getNbelement()
{
	return _nbElm;
}