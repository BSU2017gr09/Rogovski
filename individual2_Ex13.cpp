/*13. Минимальные элементы строк массива А(N,М), не содержащих
отрицательных элементов, заменить произведением их индексов.*/
#include <iostream>
#include <clocale>

using namespace std;

void initArray(int **A, int N, int M);
void printArray(int **A, int N, int M);
void freeMemory(int **A, int N);
typedef void func(int **,int, int);
typedef func *ptr_func;

int MIN = -2; 
int MAX = 10;

int** giveMemory(int N, int M) {
	int **tmp = new int*[N];
	for (int i = 0; i < N; i++) {
		tmp[i] = new int[M];
	}
	return tmp;
}

void FindPosMinOfArrAndMultij(int **A, int N, int M) {
	int p1 = 0, p2 = 0;
	for (int i = 0; i < N; i++) {
		//int k = 0;
		p1 = 0, p2 = 0;
		int min = A[i][0];//10;
		for (int j = 0; j < M; j++) {
			if (A[i][j] >= 0 ) {
				if (A[i][j] < min) {
					min = A[i][j];
					p1 = i; p2 = j;
				}
				//k++;
			}
		}
		//if (k == M) {
		A[p1][p2] = p1*p2;
		//}
	}
	cout << "Преобразование выполнено." << endl;
}

void help(int **a, int b, int N) {
	cout <<"1-Проинициализировать массив" << endl;
	cout <<"2-Вывести массив на экран" << endl;
	cout <<"3-Выполнить преобразования" << endl;
	cout << "4-Выход" << endl;
}

void ForEach(int **A, int N, int M, ptr_func ff) {
	ff(A, N, M);
}

void exit(int **a, int b, int N) {
	exit(1);
}


int main() {
	setlocale(LC_ALL, "Ru");
	cout << "Введиете размер массива." << endl;
	int N, M;
	int k = 0;
	cin >> N >> M;
	int* *A = nullptr;
	A = giveMemory(N, M);
	func* Fmenu[5] = {help,initArray,printArray,FindPosMinOfArrAndMultij,exit};
	while (1) {
		cout << "Выберите операцию(1-4),0-help:" << endl;
		cin >> k;
		ForEach(A, N, M, Fmenu[k]);
	}
		freeMemory(A, N);
		system("pause");
		return 0;
}


void initArray(int **A, int N, int M) {
	cout << "Инициализация массива..." << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = rand() % (MAX - MIN + 1) + MIN;;
		}
	}
}

void printArray(int **A, int N, int M) {
	cout << "Массив:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void freeMemory(int **A, int N) {
	for (int i = 0; i < N; i++) {
		delete[]A[i];
	}
}

