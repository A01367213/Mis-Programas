// Actividad Integral 1.3
// Horacio Lamas Arellano  A01367213
// Juan Pablo Ortiz Ortega A01366969
// 19 de Octubre de 2020

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Ordenamiento{

    public:
		vector<string>datos;

        void leerArchivo(){
            ifstream in("bitacora.txt");
            if(!in){
                cerr << "ERROR al abrir el archivo : " << "bitacora.txt" << endl;
                return;
            }
            string linea;
            while (getline(in, linea)){
                if(linea.size() > 0)
                    datos.push_back(linea);
            }
            in.close();
         }
        void imprimirVector(){
            for (int i = 0 ; i < datos.size(); i++){
                cout << datos[i] << endl;
            }
            cout << endl;
        }

        void OrdenaMes(){
            string a, actual, anterior;
            int mes1, mes2;
            for(int i = 1; i < datos.size(); i++){
                for(int j = i; j>0; j--){
                    actual = datos[j];
                    anterior = datos[j-1];
                    if (actual.substr(0,3) == "Jun") mes1 = 6;
                    if (anterior.substr(0,3) == "Jun") mes2 = 6;
                    if (actual.substr(0,3) == "Jul") mes1 = 7;
                    if (anterior.substr(0,3) == "Jul") mes2 = 7;
                    if (actual.substr(0,3) == "Aug") mes1 = 8;
                    if (anterior.substr(0,3) == "Aug") mes2 = 8;
                    if (actual.substr(0,3) == "Sep") mes1 = 9;
                    if (anterior.substr(0,3) == "Sep") mes2 = 9;
                    if (actual.substr(0,3) == "Oct") mes1 = 10;
                    if (anterior.substr(0,3) == "Oct") mes2 = 10;
                    if(mes1 < mes2){
                        a = datos[j-1];
                        datos[j-1] = datos[j];
                        datos[j] = a;
                    }
                    else
                        break;

                }
            }
        }
        void OrdenaDia(){
            string a, actual, anterior,dia1,dia3;
            int dia2,dia4;

            for(int i = 1; i < datos.size(); i++){
                for(int j = i; j>0; j--){
                    actual = datos[j];
                    anterior = datos[j-1];
                    dia1 = actual.substr(4,2);
                    dia2 = stoi(dia1);
                    dia3 = anterior.substr(4,2);
                    dia4 = stoi(dia3);
                    if(dia2 < dia4){
                        a = datos[j-1];
                        datos[j-1] = datos[j];
                        datos[j] = a;
                    }
                    else
                        break;

                }
            }
        }
        void OrdenaHora(){
            string a, actual, anterior,hora1,hora3,minuto1,minuto3;
            int hora2,hora4,minuto2,minuto4;

            for(int i = 1; i < datos.size(); i++){
                for(int j = i; j>0; j--){
                    actual = datos[j];
                    anterior = datos[j-1];
                    if(actual.substr(5,1) == " "){
                        hora1 = actual.substr(6,2);
                        hora2 = stoi(hora1);
                    }
                    if(anterior.substr(5,1) == " "){
                        hora3 = anterior.substr(6,2);
                        hora4 = stoi(hora3);
                    }
                    if(actual.substr(5,1) != " "){
                        hora1 = actual.substr(7,2);
                        hora2 = stoi(hora1);
                    }
                    if(anterior.substr(5,1) != " "){
                        hora3 = anterior.substr(7,2);
                        hora4 = stoi(hora3);
                    }
                    if((hora2 < hora4)){
                        a = datos[j-1];
                        datos[j-1] = datos[j];
                        datos[j] = a;
                    }
                    else
                        break;
                }
            }
        }

        void OrdenaMinuto(){
            string a, actual, anterior, minuto1,minuto3;
            int minuto2,minuto4;

            for(int i = 1; i < datos.size(); i++){
                for(int j = i; j>0; j--){
                    actual = datos[j];
                    anterior = datos[j-1];
                    if(actual.substr(5,1) == " "){
                        minuto1 = actual.substr(9,2);
                        minuto2 = stoi(minuto1);
                    }
                    if(anterior.substr(5,1) == " "){
                        minuto3 = anterior.substr(9,2);
                        minuto4 = stoi(minuto3);
                    }
                    if(actual.substr(5,1) != " "){
                        minuto1 = actual.substr(10,2);
                        minuto2 = stoi(minuto1);
                    }
                    if(anterior.substr(5,1) != " "){
                        minuto3 = anterior.substr(10,2);
                        minuto4 = stoi(minuto3);
                    }
                    if(minuto2 < minuto4){
                        a = datos[j-1];
                        datos[j-1] = datos[j];
                        datos[j] = a;
                    }
                    else
                        break;
                }
            }
        }

        void Grabar(){
            ofstream outFile("BitacoraOrdenada.txt");
            for (const auto &e : datos) outFile << e << "\n";
        }

        void Intervalo(){
            string dia1, dia2, mes1, mes2, linea;
            int n1, n2, pos1, pos2, aux;

            cout << "Favor de ingresar los datos de la siguiente forma..." << endl;
            cout << "Ejemplo: 1° de Junio " << endl;
            cout << "Día: 1" << endl;
            cout << "Mes: Jun" << endl;
            cout << "\n";
            cout << "Fecha de inicio" << endl;
            cout << "Día: ";
            cin >> dia1;
            if (dia1.length() == 1) n1 = 1;
            else n1 = 2;
            cout << "Mes: ";
            cin >> mes1;
            cout << "Fecha de fin" << endl;
            cout << "Día: ";
            cin >> dia2;
            aux = stoi(dia2);
            aux = aux + 1;
            dia2 = to_string(aux);
            if (dia2.length() == 1) n2 = 1;
            else n2 = 2;
            cout << "Mes: ";
            cin >> mes2;
            for(int i = 0; i < datos.size(); i++){
                    linea = datos[i];
                    if (linea.substr(4,n1) == dia1){
                        if (linea.substr(0,3) == mes1){
                            pos1 = i;
                            break;

                        }
                    }
                }
            for(int i = 0; i < datos.size(); i++){
                    linea = datos[i];
                    if (linea.substr(4,n2) == dia2){
                        if (linea.substr(0,3) == mes2){
                            pos2 = i;
                            break;
                        }
                    }
                }
            if (pos2 == 0) pos2 = datos.size();
            for (int i = pos1 ; i < pos2; i++){
                linea = datos[i];
                cout << datos[i] << endl;
                }
                cout << endl;
            }


};
int main(){
	Ordenamiento ord;
    ord.leerArchivo();
    ord.OrdenaMinuto();
    ord.OrdenaHora();
    ord.OrdenaDia();
    ord.OrdenaMes();
    ord.Grabar();
    cout << "iacabo";

    bool bandera = true;
    string op;
    cout << bandera;
    while (bandera == true){
        ord.Intervalo();
        cout << "¿Desea continuar haciendo búsquedas? (S/N): ";
        cin >> op;
        if (op == "N") bandera = false;


    }



}
