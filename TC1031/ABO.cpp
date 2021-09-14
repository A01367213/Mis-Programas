#include <iostream>
#include <vector>

using namespace std;

class Ordenamiento{
	vector<int>datos;
	
	
	public:
	
		int buscSecuencial(int k){
			for(int i=0;i<datos.size();i++){
				if (datos[i]==k){
					return i;
				}
			}
			return -1;
			
		}
		
		int buscBinaria(){
			
		}
		
		int ordenaInsercion(){
			
		}
		
		int ordenaBurbuja(){
			
		}
		
		int ordenaMerge(){
			
		}
		
		int insertar(int n){
			datos.push_back(n);
		}
		
		void imprime(){
			for (int i=0 ; i<datos.size(); i++){
			cout<<datos[i]<<" ";
			}
			cout<<endl;
		}
	
};

int main(){
	Ordenamiento ord;
	int n,numLee,a;
	cout<<"Ingresa el tamaño del vector: ";
	cin>>n;
	
	for (int i=0; i<n; i++){
		cin>>numLee;
		ord.insertar(numLee);
	}
	ord.imprime();
	cout<<ord.buscSecuencial(5);

}


//Añadir método (imprimeVector)
//Añadir método (leeArchivo)
