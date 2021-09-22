#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Actividad12{
    private:
        int num;// = 4; //No. Monedas
        int valor;//Valor de las monedas
        int precio;// = 7;//Precio producto
        int pago;// = 21; //Pago por producto
        vector<int>monedas;//{1,3,4,5}; //Lista de monedas
        vector<int>listMon;
        int na = 1000000; //No aplica
        //int mem[10000]; //Lista de valores calculados


    public:

    /*La complejidad de la función greedy es de O(n) debido a que el algoritmo siempre
      va a estar con un numero determinado hasta que este sea inferior al numero dado,
      factor que da paso al siguiente valor de la moneda, y asi sucesivamente hasta que
      termine de recorrer todas las monedas ingresadas*/
    void greedy(){
        int cambioTotal = pago - precio; //Lo que se tiene que regresar
        int i = 0;
        vector<int> monedas2; //Lista de monedas a regresar
        sort(monedas.begin(), monedas.end(), greater<int>());

        /*Si el cambio total es superior a 0, y el numero de iteraciones no excede la
          cantidad de monedas disponibles, se almacenaran las monedas que se entregaran*/
        while (cambioTotal > 0 && i < num){
            if (cambioTotal >= monedas[i]){
                cambioTotal = cambioTotal - monedas[i];
                monedas2.push_back(monedas[i]);
            }
            else{
                i++;
            }
        }
        cout << "-----Algoritmo Greedy-----" << endl;
        imprimir(monedas2);
    }
    /*La complejidad de la función dinámica es de O(mn), ya que siempre se va a estar revisando
      en base al cambio que se tiene que dar si la memoria sufre cambios o permanece igual, con
      el fin de dar con el minimo valor requerido de monedas*/
    void dinamica(){
        int cambioTotal = pago - precio; //Lo que se tiene que regresar
        int indice = cambioTotal;
        int cantMon;//Minimo de monedas por cada cantidad.
        vector<int>minimo{0}; //El minimo de monedas necesarias. Indice indica cantidad de cambio
        vector<vector<int>>memoria{{-1,-1}};//Guarda un índice y el ultimo valor de la moneda dada
        vector<int>despMon; //Se guardan las monedas que el usuario debera de recibir

        for (int i = 1; i <= cambioTotal; i++){
            //Se crea el vector que contendra los valores
            minimo.push_back(na);
            memoria.push_back(vector<int>());
            memoria[i].push_back(na);
            memoria[i].push_back(na);

            for (int j = 0; j < num; j++){
                // Se compara el indice con el valor de la moneda
                if (i >= monedas[j]){
                    cantMon = minimo[i - monedas[j]] + 1; //Se almacena la cantidad minima de monedas en el momento

                    //Compara si la cantidad minima temporal es menor que la cantidad minima almacenada.
                    //Cambia la memoria en caso de cumplir condición
                    if (cantMon < minimo[i]){
                        minimo[i] = cantMon;
                        memoria[i][0] = i - monedas[j];
                        memoria[i][1] = monedas[j];
                    }
                }
            }
        }

        //Siempre que el indice no sea 0, busca en la memoria los valores y los indices para poder almacenar las
        //monedas que se tienen que dar al usuario
        while (indice != 0){
            despMon.push_back(memoria[indice][1]);
            indice = memoria[indice][0];
        }

        sort(despMon.begin(),despMon.end(),greater<int>());
        cout << "----Algoritmo Dinamico----" << endl;
        imprimir(despMon);
    }

/*//Cuenta el minimo de monedas que se requieren para dar cambio
	void dinamica(){
        memset(mem, -1, sizeof(mem));
        int cambioTotal = pago - precio;
        cout << "----Algoritmo Dinamico----" <<endl;
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
    }*/


        //Obtiene los datos de las variablea a utilizar
        void obtenerDatos(){
            cin >> num;
            cout << endl;
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
				cout << v[i] << endl;
			}
			//cout << endl;
		}

		void imprimir2D(vector<vector<int>>v){
			for (int i = 0; i < v.size(); i++){
                for (int j = 0; j < v[i].size(); j++){
                    cout << v[i][j] << " ";
                }
                cout<< endl;
			}
		}
};

int main(){
    Actividad12 act;
    act.obtenerDatos();
    act.dinamica();
    act.greedy();
}
