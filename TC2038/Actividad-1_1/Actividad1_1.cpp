#include <iostream>
#include <vector>

using namespace std;

class Ordena{
    public:
        vector<int>data;//={-1,5,7,8,12,16,20};    //Declara lista de números
        vector<int>info;    //Declara longitud de datos y busquedas
        vector<int>busq;//={7,12};//Declara números a buscar


        void busqueda(){
            int inicio = 0;
            int fin = info[0];
            for (int i =0; i<info[1]; i++){
                int guia = binarySearch(inicio, fin, busq[i]);
                cout<<busq[i]<<"  "<<guia<<endl;
            }
        }


        int binarySearch(int inicio, int fin, int num){
            //Se declara el índice
            int indice;

            /*Si el inicio llega a superar el valor final del indice
            Significa que no encontro coincidencia*/
            if (inicio>fin){
                indice=-1;
            }
            else{
                int medio = (inicio + fin)/2;

                if (num == data[medio]){
                    indice = medio;
                }
                else if(num < data[medio]){
                    indice = binarySearch(inicio,medio-1,num);
                }
                else{
                    indice = binarySearch(medio+1,fin,num);
                }
            }
            return indice;
        }

        void mS(){
            int inicio = 0;
            int fin = info[0] - 1;
            mergeSort(inicio, fin);
            cout<<endl;
            pVector();
            cout<<endl;
            //pVector(data);
        }

        void mergeSort(int inicio, int fin){
            if(inicio>=fin) return;

            int mitad = (fin+inicio)/2; //Redondeo bajo
            mergeSort(inicio, mitad);
            mergeSort(mitad+1,fin);
            merge(inicio, mitad, fin);
        }

        //Función Auxiliar para la mezcla de elementos
        void merge(int inicio, int mitad, int fin){
            //Declaración de longitud de listas
            int izq = mitad - inicio+1;
            int der = fin - mitad;
            int listaIzq[izq], listaDer[der];

            //Creación de listas
            for(int i=0; i<izq; i++){
                listaIzq[i] = data[inicio + i];
            }
            for(int j=0; j<der; j++){
                listaDer[j] = data[mitad + 1 + j];
            }

            int i = 0;
            int j = 0;
            int k = inicio;
            //Comparación y agregado
            while (i < izq && j < der){
                if (listaIzq[i] <= listaDer[j]){
                    data[k] = listaIzq[i];
                    i++;
                }
                else{
                    data[k] = listaDer[j];
                    j++;
                }
                k++;
            }
            while(i < izq){
                data[k] = listaIzq[i];
                i++;
                k++;
            }
            while(j < der){
                data[k] = listaDer[j];
                j++;
                k++;
            }
        }


        void getData(){
            int n;
            for(int i=0; i<2; i++){
                cin>>n;
                info.push_back(n);
            }
            for (int j=0; j<info[0];j++){
                cin>>n;
                data.push_back(n);
            }
            for (int j=0; j<info[1];j++){
                cin>>n;
                busq.push_back(n);
            }
        }

        void pVector(){
            for(int i=0; i<data.size(); i++){
                cout <<data[i]<<" ";
            }
        }

};


int main(){
    Ordena ord;
    ord.getData();
    ord.mS();
    ord.busqueda();
    //vector<int>v=ord.data;
    //ord.pVector(v);

//    int x=ord.binarySearch(0,6,8);
//    cout<<x;
}
