                   // Fichier genere avec ./genere Fraction
#include "Fraction.h"




//--
Fraction::Fraction( /* ### */ )
{
    this->num=0;
    this->den=1;

}
Fraction::Fraction( const int numero )
{
    this->num=numero;
}

Fraction::Fraction( const int numero ,const int denominateur)
{
    this->num=numero;
    if(denominateur != 0){
        this->den=denominateur;
    }else{
            cout << "denominateur égale a 0"<<endl;
    }

}


//--
Fraction::Fraction(const Fraction& aF)
{
 _copy(aF);
}

//--
Fraction& Fraction::operator=(const Fraction& aF)
{
 if (this != &aF)
 {
  _destroy();
  _copy(aF);
 }
 return *this;
}

//--
Fraction::~Fraction(void)
{
 _destroy();
}
//------------------------------------------------------
int Fraction::get_numerator()
{
    return this->num;
}
   
int Fraction::get_denominator()
{
    return this->den;
}
void Fraction::set_denominator(const int i )
{
    this->den=i;
}
   
void Fraction::set_numerator(const int i ){
    this->num=i;
}
//--
bool operator==(const Fraction& aF1, const Fraction& aF2)
{
 return aF1.isEqualTo(aF2);
}

//--
bool operator!=(const Fraction& aF1, const Fraction& aF2)
{
 return !(aF1==aF2);
}

//--
ostream& operator<<(ostream& os, const Fraction& aF)
{
 aF.display(os);
 return os;
}

istream& operator>>(istream& os, Fraction& aF)
{
    aF.input(os);
    return os;

}
//--
void Fraction::display(ostream& os) const
{
 (void)os; // Pour eviter un warning si pas utilise

 // ### : Affichage des attributs de la classe Fraction
 // Exemple : os << _at;
    os<<"fraction : ";   
    os<<num;
    if ( this->den!=1)
    {
        os<<"/";
        os<<den;
    }
}


//*---------------------
void Fraction::input(istream& os)
{
 (void)os; // Pour eviter un warning si pas utilise

 // ### : Affichage des attributs de la classe Fraction
 // Exemple : os << _at;
    os>>num;
    os>>den;
}
//--
bool Fraction::isEqualTo(const Fraction& aF) const
{
 (void)aF; // Pour eviter un warning si pas utilise

 // ### : Test des attributs de la classe Fraction
 // Exemple : if (_at != aF._at) return false;
    if(num*aF.den==aF.num*den)
        return true;
    else
        return false;
}

//--
void Fraction::_copy(const Fraction& aF)
{
 (void)aF; // Pour eviter un warning si pas utilise

 // ### : Affectation des attributs de la classe Fraction
 // Exemple : _at = aF._at;
    num=aF.num;
    den=aF.den;
}

//--
void Fraction::_destroy(void)
{
 // ### : Destruction des attributs de la classe Fraction
 // Exemple : delete _at;
}
/*-----------------------------------------------*/
Fraction operator+(const Fraction& aF1, const Fraction& aF2)
{
    Fraction f;
    f.num=(aF1.num*aF2.den)+(aF2.num*aF1.den);
    f.den=aF1.den*aF2.den;
    return f;
}
Fraction operator+(const int i, const Fraction& aF)
{
    Fraction f;
    f.num=(i*aF.den)+(aF.num);
    f.den=aF.den;
    return f;
}
Fraction operator+(const Fraction& aF, const int i)
{
    Fraction f;
    f.num=(aF.num)+(aF.den*i);
    f.den=aF.den;
    return f;
}
/*----------------------------------------------------------------------*/
Fraction operator*(const Fraction& aF1, const Fraction& aF2)
{
    Fraction f;
    f.num=aF1.num*aF2.num;
    f.den=aF1.den*aF2.den;
    return f;
}
Fraction operator*(const int i, const Fraction& aF)
{
    Fraction f;
    f.num=i*aF.num;
    f.den=aF.den;
    return f;
}
Fraction operator*(const Fraction& aF, const int i)
{
    Fraction f;
    f.num=(aF.num*i);
    f.den=aF.den;
    return f;
}
