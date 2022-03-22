#include <complex>
#include <iostream>

using namespace std;

typedef complex<double> point;
#define x real()
#define y imag()

int main() {

	point a = 2;
	point b(3,7);

	cout << a << ' ' << b << "\n";
	cout << a + b << "\n";

	return 0;
}

