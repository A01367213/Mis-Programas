#include <iostream>
#include <vector>

using namespace std;

class Actividad12{
    private:



    public:
        int n, p, q;
        vector<int>monedas;

        void obtenerDatos(){
            cin >> n;
            for (int i = 0; i < n; i++){
                cin >> monedas[i];
            }
            cout << endl;
            cin >> p;
            cin >> q;

        }

        void imprimir(){
			for (int i = 0; i < n; i++){
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
