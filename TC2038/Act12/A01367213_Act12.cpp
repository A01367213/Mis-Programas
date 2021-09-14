#include <iostream>
#include <vector>

using namespace std;

class Actividad12{
    private:
        int num, valor, precio, pago;
        vector<int>monedas;

    public:
	
	void dinamica(){

	}


        void obtenerDatos(){
            cin >> num;
            for (int i = 0; i < num; i++){
                cin >> valor;
                monedas.push_back(valor);
            }
            cout << endl;
            cin >> precio;
            cin >> pago;

        }

        void imprimir(){
			for (int i = 0; i < num; i++){
				cout << monedas[i] << " ";
			}
			cout << endl;
		}
};

int main(){
    Actividad12 act;
    act.obtenerDatos();
    act.imprimir();
}
