#include <iostream>
#include <clocale>

using namespace std;

class Rectangle{
private:
	int x1,y1;
	int x2,y2;
	int x3 = x1, y3 = y2;
	int x4 = x2, y4 = y1;
public:
	Rectangle() :x1(0), y1(0),x2(0),y2(0) { //cout << "Работает конструктор по умолчанию" << endl;
	};
	~Rectangle() {// cout << "Работает диструктор" << endl;
	};
	Rectangle(Rectangle &other) {
		x1 = other.x1;
		y1 = other.y1;
		x2 = other.x2;
		y2 = other.y2;
	}
	Rectangle(int a, int b, int c, int d) :x1(a), y1(b), x2(c), y2(d) {
		//cout << "Работает конструктор с параметрами" << endl;
	};
	int Rectangle::length(void) {
		return (abs(x1 - x2));
   }
	int Rectangle::height(void) {
		return (abs(y1 - y2));
	}
	int Square(int &a, int &b) {
		return a*b;
	}
	int Perimetr(int &a, int &b) {
		return (a + b) * 2;
	}

	Rectangle operator+(const Rectangle &other) {
		Rectangle tmp;
		tmp.x1 = this->x1 + other.x1;
		tmp.y1 = this->y1 + other.y1;
		tmp.x2 = this->x2 + other.x2;
		tmp.y2 = this->y2 + other.y2;
		return tmp;
	}

	Rectangle operator-(const Rectangle &other) {
		Rectangle tmp;
		tmp.x1 = abs(this->x1 - other.x1);
		tmp.y1 = abs(this->y1 - other.y1);
		tmp.x2 = abs(this->x2 - other.x2);
		tmp.y2 = abs(this->y2 - other.y2);
		return tmp;
	}
	Rectangle operator*(const Rectangle &other) {
		Rectangle tmp;
		tmp.x1 = this->x1 * other.x1;
		tmp.y1 = this->y1 * other.y1;
		tmp.x2 = this->x2 * other.x2;
		tmp.y2 = this->y2 * other.y2;
		return tmp;
	}

	void operator=(const Rectangle &other) {
		x1 = other.x1;
		y1 = other.y1;
		x2 = other.x2;
		y2 =  other.y2;
	}


	friend istream& operator>>(istream &inStream, Rectangle &tmp) {
		cout << "Введите первую образующую точку:" << endl;
		inStream >> tmp.x1 >> tmp.y1;
		cout << "Введите диагональную ей вершину:" << endl;
		inStream >> tmp.x2 >> tmp.y2;
		return inStream;
	};

	friend ostream& operator<<(ostream &outStream, Rectangle &tmp) {
		int a = tmp.length();
		int b = tmp.height();
			outStream << "Образующие точки:" << "A(" << tmp.x1 << "," << tmp.y1 << ")" << ";" << "B(" << tmp.x2 << "," << tmp.y2 << ")" << ";" << endl;
			outStream << "Длина:" << tmp.length() << "Высота:" << tmp.height() << endl;
			outStream << "Периметр:" << tmp.Perimetr(a, b) << "Площадь:" << tmp.Square(a, b) << endl;
			return outStream;
	};
};

int main() {
	setlocale(LC_ALL, "Ru");
	Rectangle rec1;
	Rectangle rec2;
	Rectangle rec3;
	int a1 = 0,b1=0;
	cin >> rec1;
	a1 = rec1.length();
	b1 = rec1.height();
	rec2 = rec1;
	cout << "Первый прямоугольник:" << endl;
	cout << rec1;
	cout << "===========================================================================================================" << endl;
	cout << "Второй прямоугольник:" << endl;
	cout << rec2;
	cout << "===========================================================================================================" << endl;
	rec3 = rec1 + rec2;
	cout << "третий прямоугольник:" << endl;
	cout << rec3;
	cout << "===========================================================================================================" << endl;
	system("pause");
}