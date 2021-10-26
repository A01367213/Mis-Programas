#include <iostream>
#include <vector>

using namespace std;

class knapsack{
    private:
        int n;                      //Número de elementos
        int maxWeight;              //Peso máximo
        vector<int>val;             //Valor de elementos
        vector<int>weight;          //Peso de elementos
        vector<vector<int>>matrix;  //Matriz

        //Función para crear matriz
        void createMatrix(){
            for (int i = 0; i <= (n + 1); i++){
                matrix.push_back(vector<int>());
            }
            for (int i = 0; i <= maxWeight; i++){
                if (matrix[0].size() != maxWeight + 1){
                    matrix[0].push_back(0);
                }

                if (i <=n){
                    matrix[i].push_back(0);
                }
            }
            //print2D(matrix);
        }

    public:

        //Función de solución
        void solution(){
            createMatrix();

            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= maxWeight; j++){
                    if (weight[i - 1] > j){
                        matrix[i].push_back(matrix[i - 1][j]);
                    }
                    else{
                        matrix[i].push_back(max(matrix[i - 1][j], matrix[i - 1][j - weight[i - 1]] + val[i - 1]));
                    }
                }
            }
            //print2D(matrix);
            cout << "Beneficio Optimo: " << matrix[n][maxWeight] << endl;
        }



        //Función para obtener datos
        void obtainData(){
            int data;

            cout << "No. de elementos: " << endl;
            cin >> n;

            cout << "Valor de cada elemento: " << endl;
            for (int i = 0; i < n; i++){
                cin >> data;
                val.push_back(data);
            }
            //printVectorInt(val);

            cout << "Peso de cada elemento: " << endl;
            for (int i = 0; i < n; i++){
                cin >> data;
                weight.push_back(data);
            }
            //printVectorInt(weight);

            cout << "Peso máximo: " << endl;
            cin >> maxWeight;
        }

        void printVectorInt(vector<int>v){
            for (int i = 0; i < v.size(); i++){
                cout << v[i] << " ";
            }
            cout << endl;
        }

        void print2D(vector<vector<int>>v){
			for (int i = 0; i < v.size(); i++){
                for (int j = 0; j < v[i].size(); j++){
                    cout << v[i][j] << " ";
                }
                cout<< endl;
			}
		}
};

int main(){
    knapsack nap;

    nap.obtainData();
    nap.solution();
    //nap.createMatrix();
}
