#include <iostream>
#include <vector>

using namespace std;

class Dinamica{
	private:

	public:

		void obtenerDatos(){
            int n, p, q; //p=precio; q=pago
			cin >> n;
			int valores[n]; //Valores de moonedas

			for (int i = 0; i < n; i++){
				cin >> valores[i];
			}

			//imprimir(valores, n);
			cin >> p;
			cin >> q;
		}

		void imprimir(int lista[], int tam){
			for (int i = 0; i < tam; i++){
				cout << lista[i] << " ";
			}
			cout << endl;
		}

};

int main(){
	Dinamica din;
	din.obtenerDatos();
}
