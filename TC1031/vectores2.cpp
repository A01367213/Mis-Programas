#include <iostream>
#include <vector>

using namespace std;

void imprime(vector<int> v){
	for (int i=0 ; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
}


int main (){
	vector<int> arreglo; 	
	
	arreglo.push_back(-1);
	imprime(arreglo);
	arreglo.push_back(1);
	imprime(arreglo);
	arreglo.push_back(4);
	imprime(arreglo);
	arreglo.pop_back();
	imprime(arreglo);
	arreglo.push_back(10);
	imprime(arreglo);
}
