//Horacio Lamas Arellano A01367213

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*La complejidad de kmpAux es O(n) ya que solamente tiene que estar recorriendo de
  forma lineal el texto para así encontrar los patrones en las distintas posiciones

  En cuanto a la función lspArray, la complejidad en el peor de los casos es de O(n + m)
  ya que tiene que retroceder para poder constatar si es o no coincidencia, pero al ser
  ambas variables del mismo orden, se puede decir que su complejidad es de O(n)*/


using namespace std;

class strAlgorithm{
    private:
        string name;        //Nombre del archivo
        string line;        //Auxiliar para obtener valores
        int numTest;        //Número de pruebas
        vector<string>data; //Donde se almacenan los datos
        vector<int>lps;     //Almacenamiento índice de patrones


        //Función auxiliar que contiene todo el proceso de cálculo. Requiere el patron y el texto
        void kmpAux(string pattern, string text){
            int patLen = pattern.size();    //Longitud del patrón
            int txtLen = text.size();		//Longitud del texto
            int operation;			        //Variable auxiliar para conversión de índices

            /*Se solicita el calculo de las coincidencias que pudieran encontrarse dentro del
              patrón. Requiere el patrón y la longitud de éste*/
            lpsArray(pattern, patLen);

            /*Se inicializan los indices a ocupar dentro de la función; uno para el texto y otro
              para el patrón*/
            int i = 0;
            int j = 0;

            //i corresponde al índice asignado al texto
            while (i < txtLen){
                //Se aumentan los índices si hay coincidencia
                if (text[i] == pattern[j]){
                    i += 1;
                    j += 1;
                }
                else{
                    /*Si el indice del patron no es 0, se igualara a un numero dentro del
                      areglo lps que este en la posición j - 1. En caso de que el índice
                      sea 0, se aumentara el índice del texto*/
                    if (j != 0){
                        j = lps[j - 1];
                    }
                    else{
                        i += 1;
                    }
                }

                /*Si el indice del patrón es igual a la longitud del patrón, se imprime la
                  resta del índice del texto con el del patrón. Para continuar la busqueda,
                  se aplica lo anterior*/
                if (j == patLen){
                    operation = i - j + 1;
                    cout << operation << " ";
                    j = lps[j - 1];
                }
            }
            cout << endl;
        }

        /*Función que calcula coincidencias dentro del patrón con el fin de
          reducir los tiempos de cálculo*/
        void lpsArray(string pattern, int patLen){
            int len = 0;    //Índice secundario
            int i = 1;      //Índice primario

            //Se crea el arreglo con elementos igualados a 0
            for (int j = 0; j < (patLen); j++){
                lps.push_back(0);
            }

            //Aplica lo mismo que en la función kmpAux
            while (i < patLen){
                if (pattern[i] == pattern[len]){
                    lps[i] = len + 1;
                    len += 1;
                    i += 1;
                }
                else{
                    if (len != 0){
                        len = lps[len - 1];
                    }
                    else{
                        lps[i] = 0;
                        i += 1;
                    }
                }
            }
        }

    public:

        //Función que asigna valores a las variables utilizadas en la función auxiliar
        void kmpAlgorithm(){
            string text;    //Almacena el texto
            string pattern; //Almacena el patrón
            for (int i = 1; i < data.size(); i++){
                pattern = data[i];
                text = data [i+1];
                i +=1;
                kmpAux(pattern,text);
                lps.clear();
            }
        }

        //Función para obtener valores del archivo
        void obtainValue(){
            cout << "Nombre del archivo: ";
            cin >> name;
            ifstream testFile(name);
            if (testFile.is_open()){
                while (getline(testFile, line)){
                    data.push_back(line);
                }
                testFile.close();
            }
            numTest = stoi(data[0]);
        }

	//Función para imprimir vectores str
        void printVectorStr(vector<string>v){
			for (int i = 0; i < v.size(); i++){
				cout << v[i] << endl;
			}
	}

	//Función para imprimir vectores int
	void printVectorInt(vector<int>v){
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}

};

int main(){
    strAlgorithm kmp;
    kmp.obtainValue();
    kmp.kmpAlgorithm();
    //kmp.kmpAux("TATAC", "TATACCATATATACGTGTTATAC");
    //kmp.lpsArray("TATAC",5);
}
