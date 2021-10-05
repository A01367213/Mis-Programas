#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class strAlgorithm{
    private:
        string name = "prueba1.txt";        //Nombre del archivo
        string line;        //Auxiliar para obtener valores
        int numTest;        //Número de pruebas
        vector<string>data; //Donde se almacenan los datos
        vector<int>lps;     //Almacenamiento índice de patrones

    public:

        void kmpAlgorithm(){
            string text, pattern;
            int patLen, txtLen;

            for (int i = 1; i < data.size(); i++){
                pattern = data[i];
                text = data [i+1];
                i +=1;
                patLen = pattern.size();
                txtLen = text.size();
            }
        }

        void lpsArray(string pattern, int patLen){
            int len = 0;
            int i = 1;
            for (int j = 0; j < (patLen); j++){
                lps.push_back(0);
            }
            printVectorInt(lps);
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
            printVectorInt(lps);

        }


        //Función para obtener valores del archivo
        void obtainValue(){
            //cout << "Nombre del archivo: ";
            //cin >> name;
            ifstream testFile(name);
            if (testFile.is_open()){
                while (getline(testFile, line)){
                    data.push_back(line);
                }
                testFile.close();
            }
            numTest = stoi(data[0]);
            printVectorStr(data);
        }

        void printVectorStr(vector<string>v){
			for (int i = 0; i < v.size(); i++){
				cout << v[i] << endl;
			}
		}
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
    kmp.lpsArray("aabaaac",7);
}
