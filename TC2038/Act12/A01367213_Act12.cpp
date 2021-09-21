#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Actividad12{
    private:
        //No. monedas, Valor monedas
        int num, valor, precio, pago;
        vector<int>monedas; //Lista de monedas
        vector<int>listMon;
        int na = 1000000; //No aplica
        int mem[10000]; //Lista de valores calculados


    public:

    void greedy(){
        int cambioTotal = pago - precio;
        int i = 0;
        vector<int> monedas2;
        sort(monedas.begin(), monedas.end(), greater<int>());

        while (cambioTotal > 0 && i < num){
            if (cambioTotal >= monedas[i]){
                cambioTotal = cambioTotal - monedas[i];
                monedas2.push_back(monedas[i]);
            }
            else{
                i++;
            }
        }
        //imprimir(monedas);
        cout << "-----Algoritmo Greedy-----" << endl;
        imprimir(monedas2);
        //cout << cambioGreed(cambioTotal) << endl;
    }


	void dinamica(){
        memset(mem, -1, sizeof(mem));
        int cambioTotal = pago - precio;
        cout << "-----Cambio Dinamico-----" <<endl;
        cout << cambioDin(cambioTotal) << endl;
        imprimir(listMon);
    }

    int cambioDin(int val){ //Valor del pago
        if (val < 0) return na; // No hay cambio disponible
        if (val == 0) return 0; //El cambio es de 0 monedas
        if (mem[val] != -1) return mem[val];
        int cantidad = na; //Cantidad de monedas a devolver
        for (int i = 0; i < num; i++){
            cantidad = min(cantidad, cambioDin(val - monedas[i]));
            listMon.push_back(monedas[i]);
        }

        return mem[val] = cantidad + 1;
    }


        //Obtiene los datos de las variablea a utilizar
        void obtenerDatos(){
            cin >> num;
            for (int i = 0; i < num; i++){
                cin >> valor;
                monedas.push_back(valor);
            }
            sort(monedas.begin(), monedas.end());
            cout << endl;
            cin >> precio;
            cin >> pago;

        }

        void imprimir(vector<int>v){
			for (int i = 0; i < v.size(); i++){
				cout << v[i] << " ";
			}
			cout << endl;
		}
};

int main(){
    Actividad12 act;
    act.obtenerDatos();
    act.dinamica();
    act.greedy();
}
