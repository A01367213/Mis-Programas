#include <iostream>
#include "classHolaMundo.h"

using namespace std;

float pi,r,a,p;


int main(){
	HolaMundo hush;
	hush.	escribe();

	cout<<"Dame el radio del círculo"<<"\n";
	cin>>r;
	pi=3.14;
	a=pi*r*r;
	cout <<"Área del círculo: "<<a<<"\n";
	p=2*pi*r;
	cout<<"Perimetro del circulo: "<<p<<"\n";
	
}
