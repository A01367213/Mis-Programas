#include <iostream>
#define MAX 5

using namespace std;

class Pila{
    int top = -1;
    int datos[MAX];

public:
    void push(int n){
        if (top == MAX-1){
            cout<<"Pila llena\n";
        }
        else {
            top++;
            datos[top]=n;
        }
    }

    void pop(){
        if (top == -1){
            cout<<"Pila vacía\n";
        }
        else{
            top--;
        }
    }

    int tope(){
        if(top==-1){
            cout<<"Pila Vacía\n";
        }
        else{
            return datos[top];
        }
    }

};


int main(){
    Pila miPila;
    miPila.push(4);
    miPila.push(-3);
    cout<<"Tiene que imprimir un -3: "<<miPila.tope()<<endl;
    miPila.pop();
    cout<<"Tiene que imprimir un 4: "<<miPila.tope()<<endl;
    miPila.pop();
    cout<<"Tiene que imprimir un mensaje: "<<miPila.tope()<<endl;
    miPila.pop();

}
