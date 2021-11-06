#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Dijkstra{

    private:

        int nodes;                  //Numero de nodos
        vector<vector<int>>matrix;  //Matriz del grafo

        /*Función auxiliar para encontrar la distancia minima
          entre un nodo y otro*/
        int minDist(vector<int>dist, vector<bool>visit){
            int minor = 999;
            int index;

            for (int i = 0; i < nodes; i++){
                if (visit[i] == false && dist[i] <= minor){
                    minor = dist[i];
                    index = i;
                }
            }
            return index;
        }

        /*Función que aplica el algoritmo de Dijkstra. Regresa un vector
          con las distancias minimas que hay que reccorrer entre ellos.
          Su complejidad es de O(n²)*/
        vector<int> dijkstraAlgorithm(int node){
            int index;
            int maxVal = 999;
            vector<int>dist;    //Arreglo para calcular distancia
            vector<bool>visit;  //Arreglo para marcar nodos visitados

            for (int i = 0; i < nodes; i++){
                if (i == node) dist.push_back(0);
                else dist.push_back(maxVal);
                visit.push_back(false);
            }

            for (int j = 0; j < nodes; j++){
                index = minDist(dist, visit);
                visit[index] = true;

                for (int k = 0; k < nodes; k++){
                    if (!visit[k] && matrix[index][k] && (dist[index] != maxVal) && (dist[index] + matrix[index][k] < dist[k])){
                        dist[k] = dist[index] + matrix [index][k];
                    }
                }
            }
            return dist;
        }

        //Funcion de recoleccion de datos
        void data(){
            int aux; //Auxiliar para ingreso de datos

            cout << "No. de nodos: ";
            cin >> nodes;
            cout << "Ingresa los datos de la matriz: " << endl;
            for (int i = 0; i < nodes; i++){
                matrix.push_back(vector<int>());
                for (int j = 0; j < nodes; j++){
                    cin >> aux;
                    if (aux == -1) aux = 0;
                    matrix[i].push_back(aux);
                }
            }
            //print2D(matrix);
        }

    public:

        //Funcion que invoca las funciones necesarias
        void evoker(){
            data();

            for (int i = 0; i < nodes; i++){
                vector<int> minDists = dijkstraAlgorithm(i);
                for (int j = 0; j < nodes; j++){
                    cout << "From node " << i + 1 << " to node " << j + 1 << ": " << minDists[j] << endl;
                }
                cout << endl;
            }
        }

        //Funcion que imprime vectores bidimensionales
        void print2DVector(vector<vector<int>>v){
			for (int i = 0; i < v.size(); i++){
                for (int j = 0; j < v[i].size(); j++){
                    cout << v[i][j] << " ";
                }
                cout<< endl;
			}
		}

        //Funcion que imprime vectores
		void printVector(vector<int>v){
			for (int i = 0; i < v.size(); i++){
				cout << v[i] << endl;
			}
			//cout << endl;
		}

};

int main(){
    Dijkstra dj;
    dj.evoker();
}
