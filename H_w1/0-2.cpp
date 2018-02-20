/*В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.*/

#include <iostream>
#include <clocale>

using namespace std;

void initArray(int* arr, int N);
void printArray(int* arr, int N);
int CountMaxLengthSameEl(int *, int);
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
	cout << "Инициальзация массива:";
	initArray(A, N);
	printArray(A, N);
	cout << "максимальное длинна последовательности одинаковых чисел:" << CountMaxLengthSameEl(A, N) << endl;
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
	for (int *end_ptr = arr + N; arr < end_ptr; arr++) {
		cout << *arr << " ";
	}
}

int CountMaxLengthSameEl(int *arr, int N) {
	int counter = 1;
	int length = 1;
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (*(arr + i) == *(arr + j)) counter++;
			else { 
			length = counter; 
			break;
			}
		}
		counter = 1;
		if (max < length)
			max = length;
	}
	return max;
}