/*(6-7) Определить, сколько слов в строке совпадает с заданной
подстрокой. Вывести такие слова на экран. Удалить первое такое слово.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <clocale>

using namespace std;

void strSortWords(char *,char*);
void printStr2(char*,char *, char*, int &n);
void delFWord(char *, char*);


char new_str[50];
int n;
int N = 255;

int main() {
	setlocale(LC_ALL, "Ru");
	char str1[50] = "This is just is a string, is it is  ";
	char str2[10] = "is";
	cout << str1 << endl;
	strSortWords(str1, str2);
	printStr2(str1,new_str, str2,n);
	cout << "Кол-во встречающихся подстрок:" << n << endl;
	cout << "строка без первой встречающейся подстроки:" << endl;
	delFWord(str1, str2);
	cout << str1 << endl;
	system("pause");
	return 0;
}

void strSortWords(char *str1, char* str2) {
	int len2 = strlen(str2);
	int N = strlen(str1);
	int count = 0;
	int j = 0;
	int space = 1;
	for (int i = 0; i < N; i++) {
		if (*(str1 + i) != char(32) && *(str1 + i) != ',' && *(str1 + i) != '.') {
			count++;
		}
		else {
			if (count == len2) {
				int k = i;
				while (count) {
					new_str[j] = str1[k - len2];
					count--;
					j++;
					k++;
				}
			}
			count = 0;
		}
	}
}
void printStr2(char* str1, char *new_str, char *str2, int &n) {
		for (int i = 0; i < strlen(new_str); i++) {
			int count = 0;
			int k = 0;
			for (int j = i;k < strlen(str2); j++) {
				if (new_str[j] == str2[k]) {
					count++;
				}
				if (count == strlen(str2)) {
					cout << str2 << " ";
					n++;
				}
				k++;
			}
		}
	}

void delFWord(char *str1, char* str2) {
	int f_ptr=0;
	int end_ptr=0;
	int N = strlen(str1);
	for (int i = 0; i < strlen(str1); i++) {
		int count = 0;
		int k = 0;
		int n = 0;
		for (int j = i; k < strlen(str2); j++) {
			if (str1[j] == str2[k]) {
				count++;
			}
			if (count == strlen(str2) && str1[j - strlen(str2)] == ' ') {
				f_ptr = j-strlen(str2);
				end_ptr = j;
				n++;
			}
			k++;
		}
		if (n==1) break;
	}
	char tmp[50];
	for (int i =0, j=end_ptr+1; j < strlen(str1); i++,j++) {
		tmp[i] = str1[j];
	}
	for (int i = f_ptr+1,j=0; i < strlen(str1); i++,j++) {
		str1[i] = tmp[j];
	}
	str1[N - strlen(str2)] = 0;
}


