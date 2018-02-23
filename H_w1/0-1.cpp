/*Â ìàññèâå ðàçìåðà N, çàïîëíåííîãî ñëó÷.÷èñëàìè îò 0 äî 10, ïîäñ÷èòàòü êîëè÷åñòâî ýëåìåíòîâ, âñòðå÷àþùèõñÿ áîëåå îäíîãî ðàçà.*/

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
		cout << "Íåäîñòàòî÷íî ïàìÿòè." << endl;
		system("pause");
		return 0;
	}
	cout << "Èíèöèàëüçàöèÿ ìàññèâà:" ;
	initArray(A, N);
	printArray(A, N);
	cout << endl;
	cout << "Ïîäñ÷åò ýëëåìåíòîâ âñòðå÷àþùèõñÿ áîëåå îäíîãî ðàçà:";
	 cout << CountNumbSameEl(A, N) << endl;
	delete[]A;
	system("pause");
	return 0;
}

void initArray(int *arr, int N) {
	int *ptr_null = arr;	// ну и имя ты выбрал!!!!
	for (int i = 0; i < N; i++) {
		*(ptr_null + i)= rand() % (MAX - MIN + 1) + MIN;
	}
}

void printArray(int *arr, int N) {
	for (int *end_ptr =arr+N; arr < end_ptr; arr++) {// а зачем нам вообще end_ptr????
		cout << *arr << " ";
	}
}

int CountNumbSameEl(int *arr, int N) {
	int *ptr_null = arr;//что за имя??????
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
