/*В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.*/

#include <iostream>
#include <clocale>

using namespace std;

void initArray(int* arr, int N);
void printArray(int* arr, int N);
int CountNumbSameEl(int*, int N);

int MIN = 0;
int MAX = 10;

int main() {
	setlocale(LC_ALL, "Ru");
	
    int N;
	cin >> N;
	int *A;
	try {
		A = new int[N];
	}
	catch (...) {
		cout << "Недостаточно памяти." << endl;
		system("pause");
		return 0;
	}
	cout << "Инициальзация массива:" ;
	initArray(A, N);
	printArray(A, N);
	cout << endl;
	cout << "Подсчет эллементов встречающихся более одного раза:";
	 cout << CountNumbSameEl(A, N) << endl;
	delete[]A;
	system("pause");
	return 0;
}

void initArray(int *arr, int N) {
	int *ptr_null = arr;	
	for (int i = 0; i < N; i++) {
		*(ptr_null + i)= rand() % (MAX - MIN + 1) + MIN;
	}
}

void printArray(int *arr, int N) {
	for (int *end_ptr =arr+N; arr < end_ptr; arr++) {
		cout << *arr << " ";
	}
}

int CountNumbSameEl(int *arr, int N) {
	int *ptr_null = arr;
	int counter = 0;
	int numb = 0;
	for (int i = 0; i < N; i++) {
		for (int j =i+1; j < N; j++) {
			if (*(ptr_null + i) == *(ptr_null + j)) {
				counter++;
			}
			if (counter>=1) {
				numb++;
			}
			 if (counter >= 2) {
				numb--;
			}
			 counter = 0;
		}
	}
	return numb;
}