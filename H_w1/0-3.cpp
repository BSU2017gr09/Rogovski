/*Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N.
Написать функцию циклического сдвига элементов массива вправо на k элементов.*/
#include <iostream>

using namespace std;

void initArray(int* arr, int N);
void printArray(int* arr, int N);
void ShiftToRight(int *arr, int N, int k);
void swap(int*, int*);

int main() {
	setlocale(LC_ALL, "Ru");
	int N;
	int k;
	cout << "Введите размер массива" << endl;
	cin >> N;
	cout << "Введите число сдвига на К эллементов вправо" << endl;
	cin >> k;
	int *A;
	try {
		A = new int[N];
	}
	catch (...) {
		cout << "что-то пошло не так" << endl;
		system("pause");
		return 0;
	}
	cout << "Инициальзация массива:";
	initArray(A, N);
	printArray(A, N);
	cout << endl;
        cout << "Сдвиг на k эллементов в право:" << endl; 
	ShiftToRight(A, N, k);
	printArray(A, N);
	delete[]A;
	system("pause");
	return 0;
}

void initArray(int *arr, int N) {
	int *ptr_null = arr;
	for (int i = 0; i < N; i++) {
		*(ptr_null + i) = rand() % (N - (-N) + 1) + (-N);
	}
}

void printArray(int *arr, int N) {
	for (int *end_ptr = arr + N; arr < end_ptr; arr++) {
		cout << *arr << " ";
	}
}

void ShiftToRight(int *arr, int N, int k) {
	int* ptr_end = arr + N-1;
	for (int *ptr_null = arr; ptr_null < arr + N/2; ptr_null++) {
		swap(ptr_null, ptr_end);
		ptr_end--;
	}
	ptr_end = arr+N-k-1;
	for (int *ptr_null = arr; ptr_null < arr + (N-k); ptr_null++) {
		swap(ptr_null, ptr_end);
		ptr_end--;
	}
	ptr_end = arr + N - 1;
	for (int *ptr_null = arr+(N-k); ptr_null < arr + k/2; ptr_null++) {
		swap(ptr_null, ptr_end-(N-k));
		ptr_end--;
	}
}

void swap(int *a, int* b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}