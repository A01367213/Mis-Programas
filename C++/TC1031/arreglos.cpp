#include <iostream>
#define MAX 10

using namespace std;

class Arreglo{
	int tam=0;
	int datos[MAX];
	
	public:
		
		//Acciones
		//Inserta un elemento n al final del arreglo
		void insertar(int n){
			datos[tam]=n;
			tam++;
		}
		
		//Elimina un elemento al final del arreglo
		void eliminar(){
			tam--;
		}
		
		//Elimina un elemento al inicio del arreglo
		void eliminarInicio(){
			for (int i=0 ; i<tam-1 ; i++){
				datos[i]=datos[i+1];
			}
			tam--;
		}
		
		void imprimir(){
			for (int i=0 ; i<tam ; i++){
				cout<<datos[i]<<" ";
			}
			cout<<endl;
		}
		
		int busquedaSecuencial(int k){ //k=Elemento a buscar
			int pos=-1;
			for(int i=0 ; i<tam ; i++){
				if (datos[i]==k){
					return datos[i];
				}
			}
			return -1;	
		}
		
		
		int busquedaBinaria(int primero, int ultimo, int k){
			int indice,medio;
			
			if (ultimo<primero){
				indice=-1;
			}
			else{
				medio=(primero+ultimo)/2; //Division entera si int/int
				if(k==datos[medio]){
					indice = medio;
				}
				else if (k<datos[medio]){
					indice=busquedaBinaria(primero,medio-1,k);//Busca en parte izquierda
				}
				else{
					indice=busquedaBinaria(medio+1,ultimo,k);//Busca en parte derecha
				}
			}
			return indice;
		}
		
		
		
};

int main(){
	Arreglo miArreglo;
	
	int n; //numero de elementos en el arreglo
	cout<<"Numero de elementos en el arreglo: ";
	cin>>n;
	
	int numLee;
	for(int i=0; i<n; i++){
		cin>>numLee;
		miArreglo.insertar(numLee);
	}
	cout<<n-1<<endl;
	cout<<miArreglo.busquedaBinaria(0,n-1,13)<<endl;
	cout<<miArreglo.busquedaBinaria(0,n-1,8)<<endl;
	
	
	
//	Arreglo miArreglo;
//	miArreglo.	imprimir();
//	miArreglo.insertar(8);
//	miArreglo.imprimir();
//	miArreglo.insertar(2);
//	miArreglo.imprimir();
//	miArreglo.insertar(9);
//	miArreglo.imprimir();
//	miArreglo.insertar(4);
//	miArreglo.imprimir();
//	miArreglo.insertar(1);
//	miArreglo.imprimir();
//	miArreglo.eliminarInicio();
//	miArreglo.imprimir();
//	miArreglo.eliminar();
//	miArreglo.imprimir();
//	a=miArreglo.busquedaSecuencial(2);
//	cout<<a;
}
