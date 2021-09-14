#include <iostream>

using namespace std;

int factorial(int n){
    int factorial = 1;
    for(int i = 1; i <=n; ++i) {
            factorial = i*factorial;
        }
    return factorial;
}

main(){
    int r;
    r=factorial(5);
    cout<<r;
}
