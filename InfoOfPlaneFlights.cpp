/*15. (Роговский)В объекте хранится информация о движении самолётов :
номер рейса(int), пункт назначения(*char либо char[3]), информация о
наличии свободных мест(int).Разработать функции - члены класса, которые
позволяют.
a) По запросу вывести информацию об указанном рейсе.
b) Вывести список рейсов, следующих до указанного пункта
назначения
c) Распечатать по заявке пассажира билет, если есть свободные места
на указанный рейс.Предложить другой рейс, если на указанный
рейс нет билетов, или вывести сообщение о невозможности вылета
в указанный пункт.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <clocale>
#include <ctime>
#include<fstream>

using namespace std;

int num = 1;

char f1[] = "D:\\cityes.txt";

char symb;

void RandCity(char dest[], const int n) {
	const int t = 100;
	char points[t];
	int i = 0;
	ifstream fin(f1, ios::in, ios::binary);
	if (!fin) cout << "No file" << endl;
	while (1) {
		fin.get(symb);
		points[i++] = symb;
		if (fin.eof())break;
	}
	points[i - 1] = 0;
	fin.close();
	int k = 0 + rand() % 5;
	i = 0;
	while (points[i] && k>0) {
		if (points[i] == '|') {
			k--;
		}
		i++;
	}
	char point[15];
	while (points[i] != '|') {
		point[k] = points[i];
		i++;
		k++;
	}
	point[k] = '\0';
	strcpy(dest, point);
}

class InfoOfPlaneFlights
{
private:
	int flight_num;
	char* dest_point;
	int spare_seats;
public:
	int hours=0;
	int minutes=0;
	InfoOfPlaneFlights():flight_num(0),dest_point(nullptr),spare_seats(0){
	//	cout << "Сработал конструктор по умолчанию" << endl;
	};
	InfoOfPlaneFlights(int argFlyght_num, char* argDest_point, int argSpare_sears):
		flight_num(argFlyght_num),dest_point(nullptr),spare_seats(argSpare_sears){
		try {
			dest_point = new char[strlen(argDest_point)+1];
			strcpy(dest_point, argDest_point);
		}
		catch (...) {
			cout << "..." << endl;
			system("pause");
		}
	//	cout << "сработал конструктор с параметрами"<<endl;
	};
	InfoOfPlaneFlights(const InfoOfPlaneFlights &other) {
		flight_num = other.flight_num;
		try {
			dest_point = new char[strlen(other.dest_point)+1];
			strcpy(dest_point, other.dest_point);
		}
		catch (...) {
			cout << "..." << endl;
			exit(0);
		}
		spare_seats = other.spare_seats;
	}
	~InfoOfPlaneFlights() {
	};
	void my_swap( InfoOfPlaneFlights &other) {
		std::swap(flight_num, other.flight_num);
		std::swap(spare_seats, other.spare_seats);
		std::swap(dest_point, other.dest_point);
	}
	InfoOfPlaneFlights& operator = (const InfoOfPlaneFlights &p) {
		InfoOfPlaneFlights tmp(p);
		my_swap(tmp);
		return *this;
	};
	InfoOfPlaneFlights& operator=(InfoOfPlaneFlights &&other){
		if (this == &other) return *this;
		spare_seats = other.spare_seats;
		flight_num = other.flight_num;
			return *this;
	};
	int setFlightnum(int argFlightnum) {
		flight_num = argFlightnum;
		return argFlightnum;
	};
	int setDestpoint(char *argDestpoint) {
		if (dest_point == nullptr) {
			try {
				dest_point = new char[strlen(argDestpoint)+1];
				strcpy(dest_point, argDestpoint);
			}
			catch (...) {
				cout << "..." << endl;
				exit(0);
			}
		}
		else {
			delete[]dest_point;
			try {
				dest_point = new char[strlen(argDestpoint)+1];
				strcpy(dest_point, argDestpoint);
			}
			catch (...) {
				cout << "No memory..." << endl;
				exit(0);
			}
		}
		return 0;
	};
	int setSeats(int argSpare_seats) {
		spare_seats = argSpare_seats;
		return 0;
	};
	int setTime(int argHours, int argMinutes) {
		hours = argHours;
		minutes = argMinutes;
		return 0;
	}
	int getFlight_num() {
		return flight_num;
	};
	char* getDestpoint() {
		return dest_point;
	};
	int getSeats() {
		return spare_seats;
	};
	int  initFlight() {
		const int n = 10;
		char str[n];
		RandCity(str, n);
		setTime(rand() % 24, rand() % 60);
		setDestpoint(str);
		setFlightnum(num++);
		setSeats(rand() % 10);
		return 0;
	}
	friend ostream& operator<<(ostream &outStream, InfoOfPlaneFlights &tmp) {
		cout<< "Номер рейса:№"<< tmp.flight_num-1<< " Время вылета:" <<tmp.hours<<":"<<tmp.minutes<<endl;
		if (tmp.dest_point == nullptr) {
			cout << "Точки назначения нет" <<endl;
		}
		else {
			cout << "Точка назначения:"<< tmp.dest_point << endl;
		}
		cout<<"Свободных мест:" <<tmp.spare_seats << endl;
		return outStream;
	};
};

int  initFlyghts(InfoOfPlaneFlights *flyghts, int n) {
	for (int i = 0; i < n; i++) {
		flyghts[i].initFlight();
	}
	return 0;
}
int printFlyghts(InfoOfPlaneFlights *flyghts, int n) {
	cout << "Список рейсов:" << endl;
	for (int i = 0; i < n; i++) {
		cout << flyghts[i] << endl;
	}
	return 0;
}

int printFlyght(InfoOfPlaneFlights *flyghts, int k) {
	int n;
	cout << "Введите номер рейса, который Вас интерисует." << endl;
	cin >> n;
	cout << "Рейс №:" << n << ":" << endl;
	cout << flyghts[n] << endl;
	return 0;
}

int chooseFlight(InfoOfPlaneFlights *flyghts, int n) {
	char str[10];
	int i = 0;
	cout << "Введите название города:" << endl;
	cin >> str;
	int t = 0;
	fflush(stdin);
	for (int k = 0; k < n; k++) {
		int tmp = strcmp(flyghts[k].getDestpoint(), str);
		if (tmp==0) {
			cout << "Рейсы до " << str << ":" << endl;
			cout << flyghts[k] << endl;
			t++;
		}
	}
		 if(!t)cout << "Данного пункта нет в существующих рейсах, пожалуйста, проверьте Ваш выбор" << endl;
		return 0;
}

int printTickets(InfoOfPlaneFlights *flyghts, int k) {
	int n=0;
	cout << "Введите номер рейса, на который хотите заказать билеты." << endl;
	cin >> n;
	if (flyghts[n].getSeats() == 0) {
		cout << "К сожалению, билетов на данный рейс нет в наличии. Пожалуйста, Выберите другой рейс." << endl;
	}
	else {
		cout << "На данный рейс доступно " << flyghts[n].getSeats();
		if (flyghts[n].getSeats() == 1) {
			cout << " билет." << endl;
		}
		else if (flyghts[n].getSeats() > 1 && flyghts[n].getSeats() <= 4) {
			cout << " билета" << endl;
		}
		else if(flyghts[n].getSeats()>4){
			cout << " билетов" << endl;
		}
	}
	return 0;
}

int DestPointList(InfoOfPlaneFlights *flyghts, int n) {
	for (int k = 0; k < n; k++) {
		int t = 1;
		for (int i = 0; i < n; i++) {
			int tmp = strcmp(flyghts[k].getDestpoint(), flyghts[i].getDestpoint());
			if (tmp == 0 && k!=i) t=0;
			break;
		}
		if (t==1)	cout << flyghts[k].getDestpoint() << " ";
	}
	cout << endl;
	return 0;
}

int EditFlight(InfoOfPlaneFlights *flyghts, int n) {
	cout << "Введите номер рейса, который вы хотите отредактировать." << endl;
	int k=0;
	int i = 0;
	char city[10];
	cin >> k;
	cout << "Введите название города" << endl;
	cin >> city;
	fflush(stdin);
	flyghts[k].setDestpoint(city);
	cout << "Введите количество свободных мест"<< endl;
	cin >> i;
	flyghts[k].setSeats(i);
	cout << "Введите новый номер рейса" << endl;
	cin >> i;
	flyghts[k].setFlightnum(i);
	return 0;
}

int my_exit(InfoOfPlaneFlights *r, int a) {
	exit(1);
	return 0;
}


typedef int func(InfoOfPlaneFlights *arr, int n);
typedef func *ptr_func;

void ForEach(InfoOfPlaneFlights *arr, int N, ptr_func ff) {
	ff(arr,N);
}

int main() {
	setlocale(LC_ALL, "Ru");
	srand(time(0));
	const int n = 4;
	InfoOfPlaneFlights flyghts[n];
	int k = 0;
	func *Menu[8] = {initFlyghts,printFlyghts,chooseFlight,printFlyght,printTickets,DestPointList,EditFlight,my_exit};
	while (1) {
		cout << "===========================================================================================================" << endl;
		cout << "Выберите операцию:" << endl << "0-проинициализировать рейсы." << endl << "1-распечатать список рейсов." << endl;
		cout << "2-распечатать информацию о рейсах по указанному месту." << endl<<"3 - информация о определенном рейсе"<<endl<<"4 - информация о билетах" << endl;
		cout << "5-список городов в которые идут рейсы" <<endl<<"6-Редактировать полет"<<endl<<"7-Bыход"<< endl;
		cin >> k;
		if (k < 0 || k>6) {
			cout << "Введите операцию заново." << endl;
		}
		ForEach(flyghts, n, Menu[k]);
		}
	cout << "===========================================================================================================" << endl;
	system("pause");
	return 0;
}