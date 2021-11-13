#include <iostream>
#include <math.h>
#include <ctime>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu();
void imprimirArray(int, int, int*);
int* recursivo(int*, int, int, int, int,  int);
int* generarMatrix(int);
void imprimir(int**&, int, int);
void suma (int**&, int , int);

using namespace std;

void imprimir(){

	int matriz [4][5];
			
	for (int fila = 0; fila < 4; fila++){
		for (int columna = 0; columna < 5; columna++){
			matriz[fila][columna] = rand() % 2;
			cout << matriz[fila][columna] << " ";

		}
		cout << endl;
	}	
}

int main() {//int argc, char** argv
	srand(time(NULL));
	int opcion = menu();
	while (opcion != 4){
		switch (opcion){
			case 1:{	
				
				int** matriz = new int*[4];
				
				for(int i = 0; i < 4; i++){
						matriz[i] = new int[5];
				}
				
				for(int i=0; i < 4; i++){
					for (int j=0; j < 5; j++){
						matriz[i][j] = rand() % 2;
					}
				}
				
				imprimir(matriz, 4, 5);
				suma(matriz, 4 , 5);
				break;
			}
			case 2:{
				
				int* array = generarMatrix(20);
				recursivo(array, 0, 0, 0, 0, 0);
				cout << " " << endl;
				cout << "El resultado es: ";
				imprimirArray(20, 0, array);

				break;
			}
			case 3:{
				
				break;
			}
		}
		cout <<endl; 
		opcion = menu(); 		
	}		
	return 0;
}

void imprimirArray(int size, int size2, int* array) {
	
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}	
}

int* recursivo(int* numeros, int size, int bandera, int numMenor,  int banderaLocacion,  int numMenorLocacion){
    if(banderaLocacion==size-1){
        return numeros;
    } else {
        for (int i = banderaLocacion+1; i < size; i++) {
            if (numMenor > numeros[i]) {
                numMenor = numeros[i];
                numMenorLocacion = i;
            }
        }
        
        numeros[banderaLocacion] = numMenor;
        numeros[numMenorLocacion] = bandera;
        int temporal = numeros[banderaLocacion+1];

        for (int i = 0; i < size; i++) {
            cout << numeros[i] << " ";
        }
        
        cout << "|      " << numMenor << " es el numero menor\n";
        
        return recursivo(numeros, 20, temporal, temporal, banderaLocacion+1, banderaLocacion+1);
    }
}

int* generarMatrix(int size) {
	int* array = NULL;
	array = new int[size];
	for(int i=0; i < size; i++) {
		array[i] = rand() % 100;
	}
	return array;
}

///////////////////////////////////////////////////////////////////

void imprimir(int**& arr, int size, int size2){
	for(int i=0; i < size; i++){
		for (int j=0; j < size2; j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << "\n";	
}

void suma(int**& arr, int size, int size2){
	string numB[size];
	for(int i=0; i < size; i++){
		numB[i] = "";
	}
	
	for(int i=0; i < size; i++){
		for(int j=0; j < size2; j++){
			numB[i] += to_string(arr[i][j]);
		}
	}
	
	long numD[size];
	long suma = 0;
	
	for(int i=0; i < size; i++){
		numD[i] = stol(numB[i],0,2);
		cout << numB[i] << " = " << numD[i] << endl;
		suma += numD[i];
	}
	cout << "\n";
	cout << "La suma es: " << suma << endl;	
}

///////////////////////////////////////////////////////////////////
string palindrome(string palabra){
	vector<int> ocurLetras;
	vector<char> letras;
	
	for(int i=0; i <26; i++){
		ocurLetras.push_back(0);
		letras.push_back(i+97);
	}

	// ocurLetras por cada letra se le va asumar 1
	//cuando con la posicion, eos devuelve la posicion de la letra
	//y ahi se suma 1
	
	for(int i=0; i < palabra.size(); i++){
		
	}
	
}

int posicionLetra(vector<char> letras, char letraBuscar){
	for(int i=0; i < letras.size(); i++){
		if(letras[i] == letraBuscar){
			return i;
		}
	}	
}


int menu(){
	int opcion = 0; 
	while (opcion != 4){
		cout << "\n";
		cout << "* * * * *  * * MENU * * * * * * *" <<endl;
		cout << "*	1) Ejercicio 1		*"<<endl;
		cout << "*	2) Ejercicio 2		*" <<endl; 
		cout << "*	3) Ejercicio 3		*" <<endl; 
		cout << "*	4) Salir      		*" <<endl; 
		cout << "* * * * * * * * * * * * * * * * *" <<endl; 
		cout << " Ingrese la opcion que desee: " <<endl; 
		cin>> opcion; 
		cout << "\n";
		if (opcion == 4){
			cout << "\n";
			cout << "Ha elegido salir del sistema. " <<endl; 
		}else if (opcion > 0 && opcion < 4){
			break; 
		}
	}
	return opcion; 
}
