#include <iostream>
#include "classHolaMundo.h"

using namespace std;

float pi,r,a,p;


int main(){
	HolaMundo hush;
	hush.	escribe();

	cout<<"Dame el radio del c�rculo"<<"\n";
	cin>>r;
	pi=3.14;
	a=pi*r*r;
	cout <<"�rea del c�rculo: "<<a<<"\n";
	p=2*pi*r;
	cout<<"Perimetro del circulo: "<<p<<"\n";
	
}
