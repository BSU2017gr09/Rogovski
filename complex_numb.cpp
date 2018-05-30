#include <iostream>
#include <clocale>

using namespace std;

struct Complex{
private: 
		float Re;
		float Im;
public:
	Complex(double a=0, double b=0) :Re(a), Im(b) { cout << "Конструктор сработал" << endl; };
	~Complex() { cout << "Работает диструктор" << endl; };
	Complex operator=(const Complex&other) {
		this->Re=other.Re;
		this->Im = other.Im;
		return *this;
	};
	Complex operator+(const Complex &other) {
		Complex tmp;
		tmp.Re = this->Re + other.Re;
		tmp.Im = this->Im + other.Im;
		return tmp;
	};
	Complex operator-(const Complex &other) {
		Complex tmp;
		tmp.Re = this->Re + other.Re;
		tmp.Im = this->Im + other.Im;
		return tmp;
	};
	Complex operator*(const Complex &other) {
		Complex tmp;
		tmp.Re = (this->Re*other.Re) - (this->Im*other.Im);	
		tmp.Im= (this->Im*other.Im) - (this->Re*other.Re);
		return tmp;
	};
	friend istream& operator>>(istream &inStream, Complex &tmp) {
		inStream >> tmp.Re >> tmp.Im;
		return inStream;
	};
	friend ostream& operator<<(ostream &outStream, Complex &tmp) { 
	outStream << tmp.Re << "+" << tmp.Im<<"i";
	return outStream; 
	};
};

int	main(){
	setlocale(LC_ALL, "Ru");
	Complex z1;
	Complex z2;//тут бы еще массивчик. И его проинициализировать, отсортировать и еще что то...
	cin >> z1;
	cin >> z2;
	cout << z1 + z2;
	system("pause");
	return 0;
}
