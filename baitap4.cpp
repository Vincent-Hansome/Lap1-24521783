#include <iostream>
#include<cmath>
using namespace std;
#define pi 3.141592


long double dau(double x){
	if (x > 0)
		return x;
	else
		return -x;
}
int gt(int n) {
	if (n == 0) return 1;
	int x = 1;
	for (int i = 1;i <= n;i++)
		x *= i;
	return x;
}
double tinh(double x) {
	{
		double term = x;
		double a = term;
		int n = 1;
		while (dau(term) >= 0.00001)
		{
			term *= -x * x / ((2 * n) * (2 * n + 1));
			a += term;
			n++;
		}
		return a;
	}
}
int main() {
	double x;
	cout << "Nhap gia tri goc(radian):";
	cin >> x;
	cout << "Gia tri Sin cua goc la:" << tinh(x);
	return 0;
}
