#include <vector>
#include <iostream>

using namespace std;

class ordenamiento(){
	public:
		int lista[7] = {1,2,3,4,5,6,7};
		int lista2[7];

		void  descendiente(){
			int x = 7;

			for (int i = 0; i < x; i++){
				lista2[i] = lista[x - 1 - i];
			}
			for (int j = 0; j<x; j++){
				cout<<lista2[j];
			}

		}

		int binarySearch(int low, int high, int num){
			int indice;
			int mid = (low + high)/2;

			if (low > high){
				indice = -1;
			}
			else{
				if (num == lista[mid]){
					indice = mid;
				} 
				else if (num > lista[mid]){
					indice = binarySearch(low, mid-1);
				}
				else{
					indice = binarySearch(mid + 1, high);
				}
			}
			return indice;
		}
};


int main(){
	ordenamiento ord;
	ord.descendiente();
	cout<< endl;
	x = ord.binarySearch(0,6,6);
	cout<<x;
}

