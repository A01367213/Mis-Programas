#include <iostream>


using namespace std;

class Nodo{
    public:
        int info;
        Nodo *next;
        // Nodo

        Nodo(int dato){
            info=dato;
            next=nullptr;
        }

};


class Lista{
    Nodo *primero=nullptr;

    public:
        void insertarInicio(int dato){
            Nodo *p=new Nodo(dato);
            p->next=primero;
            primero=p;
        }

        void eliminarInicio(){
            if (primero != nullptr){
                Nodo *p = primero;
                primero = primero -> next;
                delete(p);
            }
            else cout << "Lista Vacía\n";

        }

        void imprimirLista(){
            Nodo *p;
            p=primero;
            while(p!= nullptr){
                cout<<p->info<<" ";
                p=p->next;
            }
            cout << endl;
        }
};

int main(){
    Lista miLista;
    miLista.insertarInicio(5);
    miLista.insertarInicio(7);
    miLista.insertarInicio(9);
    miLista.imprimirLista();
    miLista.eliminarInicio();
    miLista.imprimirLista();
    miLista.eliminarInicio();
    miLista.imprimirLista();

}
