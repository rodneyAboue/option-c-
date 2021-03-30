#include "Fraction.h"
#include <iostream>

using namespace std;


int main(){

Fraction f1(1,1);
cout<<f1<<endl;
cout<<f1.get_numerator()<<endl;

Fraction f2(2,4);
cout<<f2<<endl;

cout<<f2<<endl;
Fraction f3;
cin >>f3;
cout<<f3<<endl;
cout <<"on teste f1== f2"<<endl;
bool b1=false;
b1=(f1==f3);
cout <<b1<<endl;

cout <<"on teste le plus "<<endl;
Fraction f4;
f2=(f1+f2);
f4=(f1+f2);
cout <<f2<<endl<<f4<<endl;

return 0; 
}
