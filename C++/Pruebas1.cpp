#include <iostream>
#include <vector>
using namespace std;

		void merge(int lo, int mid, int hi) {
		    //Procede a separar y ordenar los elementos

		    int n1 = mid - lo + 1;
		    int n2 = hi - mid;

		    int a1[n1], a2[n2];

		    for (int i = 0; i < n1; i++){

		        a1[i] = data[lo + i];
			}

			for (int j = 0; j < n2; j++){
		        a2[j] = data[mid + 1 + j];
			}

		    int i, j, k;
		    i = 0;
		    j = 0;
		    k = lo;

		    while (i < n1 && j < n2) {
		        if (a1[i] <= a2[j]) {
		            data[k] = a1[i];
		            i++;
		        }
				else {
		            data[k] = a2[j];
		            j++;
		        }
		        k++;
		    }

		    while (i < n1) {
		        data[k] = a1[i];
		        i++;
		        k++;
		    }

		    while (j < n2) {
		        data[k] = a2[j];
		        j++;
		        k++;
		    }
		}


		void ordenaMerge( int lo, int hi){
		    /*Se inserta el inicio y final de indices del vector.
			  Complejidad: O(nlogn)
			*/
			if (lo >= hi){
        		return;
    		}

			int mid;
    		mid = ( lo + hi )/2;
    		ordenaMerge(lo, mid);
    		ordenaMerge(mid +1,hi);
    		merge( lo, mid, hi);
		}


int main(){
    vector<int>a={-1,5,7,8,12,16,20};
    binSearch(a,5);
}
