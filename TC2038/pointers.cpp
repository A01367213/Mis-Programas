#include <iostream>

using namespace std;

class example1{
    public:
        void point1(){
            int var1 = 0;
            int var2[10];
            cout << "Address of var1 variable: ";
            cout << &var1 << endl;

            cout << "Address of var2 variable: ";
            cout << &var2 << endl;
        }

        void point2(){
            int    *ip;    // pointer to an integer
            double *dp;    // pointer to a double
            float  *fp;    // pointer to a float
            char   *ch;     // pointer to character

            cout << fp << endl;
        }

        void point3(){
            int  var = 20;   // actual variable declaration.
            int  *ip;        // pointer variable

            ip = &var;       // store address of var in pointer variable

            cout << "Value of var variable: ";
            cout << var << endl;

            // print the address stored in ip pointer variable
            cout << "Address stored in ip variable: ";
            cout << ip << endl;

            // access the value at the address available in pointer
            cout << "Value of *ip variable: ";
            cout << *ip << endl;
        }

};

int main(){
    example1 ex1;
    //ex1.point1();
//    ex1.point2();
    //ex1.point3();
    string x = "Comer";
    int s = x.size();
    cout << x[2];
}
