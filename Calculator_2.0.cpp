#include <iostream>
#include <functional>
#include <locale>

using namespace std;

double sum(double x, double y) {
	return x + y;
}
double sub(double x, double y) {
	return x - y;
}
double mul(double x, double y) {
	return x * y;
}
double div_(double x, double y) {
	if (y == 0) throw invalid_argument("Деление на ноль невозможно");
	return x / y;
}

double use(function<double(double, double)> f, double x, double y) {
	return f(x, y);
}


int main(){
	setlocale(LC_ALL, "RU");
	string oper;
	double x, y;
	cout << "Введите два числа: ";
	cin >> x >> y;
	cout << "Введите операцию(sum, sub, mul, div): ";
	cin >> oper;
	if (oper == "sum" || oper == "sub" || oper == "mul" || oper == "div") {
		try {
			function<double(double, double)> u;
			if (oper == "sum") u = sum;
			else if (oper == "sub") u = sub;
			else if (oper == "mul") u = mul;
			else if (oper == "div") u = div_;
			cout << use(u, x, y);
		}
		catch (invalid_argument e) {
			cout << e.what();
		}
	}
	else cout << "Неверное условие";
}
