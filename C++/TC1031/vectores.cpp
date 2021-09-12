#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int>vect;
	int myints;
	
	cout<<"Escriba numeros enteros (escriba 0 para finalizar captura): \n";
	
	do{
		cin>> myints;
		vect.push_back(myints);
	}while(myints);
	
	cout<<"vect stores "<<int(vect.size())<<" numbers.\n";

}
