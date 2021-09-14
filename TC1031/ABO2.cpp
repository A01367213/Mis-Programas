#include <iostream>
#include <vector>

using namespace std;

class Ordenamiento{

	
	
	public:
	
		int buscSecuencial(vector<int>datos,int k){
			for(int i=0;i<datos.size();i++){
				if (datos[i]==k){
					return i;
				}
			}
			return -1;
			
		}
		
		int buscBinaria(){
			
		}
		
		int ordenaInsercion(vector<int>datos){
			
		}
		
		int ordenaBurbuja(){
			
		}
		
		int ordenaMerge(){
			
		}
		
//		int insertar(int n){
//			datos.push_back(n);
//		}
		
		void imprime(vector<int>datos){
			for (int i=0 ; i<datos.size(); i++){
			cout<<datos[i]<<" ";
			}
			cout<<endl;
		}
	
};

int main(){
	Ordenamiento ord;
	
	vector<int>datos;
	
	datos.push_back(4);
	datos.push_back(46);
	datos.push_back(2);
	datos.push_back(5);
	datos.push_back(1);
	datos.push_back(-8);
	datos.push_back(-3);
	ord.imprime(datos);
	
	cout<<ord.buscSecuencial(datos,4);
}


//Añadir método (imprimeVector)
//Añadir método (leeArchivo)
