/*Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.*/
#include <iostream>
#include <clocale>

using namespace std;

void initArray(int* arr, int N);
void printArray(int* arr, int N);
void sortArray(int *arr, int N, int k);

int MIN = 0;
int MAX = 10;

int main(){ 
	setlocale(LC_ALL, "Ru");
	int N;
	cout << "Введите кол-во эллементов" << endl;
	cin >> N;
	int k;
	cout << "Введите номер элемента, с которого начинать ставить эллементы по возрастанию" << endl;
	cin >> k;
	int *A;
	try {
		A = new int[N];
	}
	catch (...) {
		cout << "Что-то пошло не так." << endl;
		system("pause");
		return 0;
	}
	cout << "Инициализация:" << endl;
	initArray(A, N);
	printArray(A, N);
	cout << endl;
	cout << "Сортировка:" << endl;
	sortArray(A, N, k);
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
	for(int i = 0;i < N; i++) {
		cout << *(arr+i) << " ";
	}
}

void sortArray(int *arr, int N, int k) {
	for (int i=k; i <N;i++) {
		int* max = arr + N - 1;
		for (int j = i; j < N;j++) {
			int *ptr = arr + j;
			if (*ptr>*max){
				swap(*ptr, *max);
			}
		}
		N--;
	}
}

void swap(int *a, int* b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}