#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Ordenamiento{
	
	public:
		vector<int>data;
		
		
//		void leerArchivo(string archivo){
//			int n, numero;
//		    ifstream myfile(archivo);
//		    if (myfile.is_open() == true){
//		        myfile >> n;
//		        cout << "Nums: " << endl;
//		        for (int i=0; i<n; i++){
//		            myfile >> numero;
//		            data.push_back(numero);
//		            cout << data[i] << endl;
//		        }
//		    myfile.close();
//		    } 
//			else{
//		        cout << "No se pudo abrir\n";
//			}
//		}
	
	
	
		int buscSecuencial(int k){
			for(int i=0;i<data.size();i++){
				if (data[i]==k){
					return i;
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
				if(k==data[medio]){
					indice = medio;
				}
				else if (k<data[medio]){
					indice=busquedaBinaria(primero,medio-1,k);//Busca en parte izquierda
				}
				else{
					indice=busquedaBinaria(medio+1,ultimo,k);//Busca en parte derecha
				}
			}
			return indice;
		}
			

		
		int ordenaInsercion(){
			
			
		}
		
		int ordenaBurbuja(){
			for(int i=1; i<data.size(); i++){
				for (int j=0;j<data.size()-i;j++){
					if (data[j]>data[j+1]){
						int aux=data[j];
						data[j]=data[j+1];
						data[j+1]=aux;
					}
				}
			}			
		}
//----------------------------------------------------------------		
		void merge(int lo, int mid, int hi) {
		    int n1 = mid - lo + 1;
		    int n2 = hi - mid;
		
		    int a1[n1], a2[n2];
		
		    for (int i = 0; i < n1; i++){
			
		        a1[i] = data[lo + i];
			}
			
			for (int j = 0; j < n2; j++){
		        a2[j] = data[mid + 1 + j];
			}
			
		    int i, j, k;
		    i = 0;
		    j = 0;
		    k = lo;
		
		    while (i < n1 && j < n2) {
		        if (a1[i] <= a2[j]) {
		            data[k] = a1[i];
		            i++;
		        } 
				else {
		            data[k] = a2[j];
		            j++;
		        }
		        k++;
		    }
		
		    while (i < n1) {
		        data[k] = a1[i];
		        i++;
		        k++;
		    }
		
		    while (j < n2) {
		        data[k] = a2[j];
		        j++;
		        k++;
		    }
		}
		
		
		void ordenaMerge( int lo, int hi){
			if (lo >= hi){
        		return;
    		}
    		
			int mid;
    		mid = ( lo + hi )/2;
    		ordenaMerge(lo, mid);
    		ordenaMerge(mid +1,hi);
    		merge( lo, mid, hi);
		}
//---------------------------------------------------------------------------------		
		int insertar(){
			int n,numLee;
			cout<<"Ingresa el tamaño del vector: ";
			cin>>n;
			for (int i=0; i<n; i++){
				cin>>numLee;
				data.push_back(numLee);
			}
		}
		
		void imprime(){
			for (int i=0 ; i<data.size(); i++){
			cout<<data[i]<<" ";
			}
			cout<<endl;
		}
	
};

int main(){
	Ordenamiento ord;
//	vector<int>datos;
//  datos=ord.leerArchivo("datos.txt")



	
//	vector<int>datos;
	
//	ord.insertar(datos);
//	ord.imprime(datos);

	
//	cout<<ord.buscSecuencial(datos,6)<<endl;
	cout<<endl;
////	ord.buscBinaria(datos);
//    ord.ordenaMerge(datos,0,datos.size()-1);
//	
//	ord.imprime(datos);
//	cout<<endl;
//	cout<<ord.busquedaBinaria(datos,0,datos.size()-1,6);
	
	
}


//Añadir método (imprimeVector)
//Añadir método (leeArchivo)
