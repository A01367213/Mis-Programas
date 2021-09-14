#include <iostream>
#include <vector>

using namespace std;

class Actividad12{
    private:
        int n, p, q;
        vector<int>monedas;

    public:
        void obtenerDatos(){
            cin >> n;
            for (int i = 0; i < n; i++){
                cin >> monedas[i];
            }
            cin >> p;
            cin >> q;
            imprimir();
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
}
