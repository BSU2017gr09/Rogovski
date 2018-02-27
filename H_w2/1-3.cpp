/*Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок 
следования.Отрицательные элементы расположить в порядке убывания.Дополнительный массив не использовать.*/

#include <iostream>
#include <clocale>

using namespace std;

void initArray(int* arr, int N);
void printArray(int* arr, int N);
void swap(int *a, int *b);
int NegElements(int *arr,int N);
void sortArray(int *arr, int N);


int MIN = -10;
int MAX = 10;

int main() {
	setlocale(LC_ALL, "Ru");
	int N;
	cout << "Введите размер массива:" << endl;
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
	initArray(A, N);
	printArray(A, N);
	cout << endl;
	cout << "Сортировка:" << endl;
	sortArray(A, N);
	printArray(A, N);
	delete[]A;
	system("pause");
	return 0;
}


void initArray(int *arr, int N) {
	int *ptr_null = arr;
	for (int i = 0; i < N; i++) {
		*(ptr_null + i) = rand() % (MAX - MIN + 1) + MIN;
	}
}

void printArray(int *arr, int N) {
	for (int i = 0; i < N; i++) {
		cout << *(arr + i) << " ";
	}
}



void swap(int *a, int* b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int NegElements(int *arr, int N) {
	int k=0;
	for (int i = 0; i < N; i++) {
		if (*(arr + i) < +0) k++;
	}
	return k;
}

void sortArray(int *arr, int N) {
	int k = NegElements(arr, N);
	int tmp=0;
	int j = k;
	for (int i = 0; i < N; i++) {
		if (*(arr + i) < 0) {
			swap(*(arr + i), *(arr+k));
			k--;
		}
	}
	k = j;
	for (int i = 0; i <k; i++) {
		int* max = arr + k - 1;
		for (int j = i; j < k; j++) {
			int *ptr = arr + j;
			if (*ptr<*max) {
				swap(*ptr, *max);
			}
		}
		k--;
	}
}