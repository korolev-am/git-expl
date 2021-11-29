#include <iostream>

class complex {
	double re, im;
public:
	complex (double r = 0, double i = 0) {
		re = r;
		im = i;
		std::cout << "constr" << std::endl;
	}
	operator double () {
		std::cout << "operator double " << std::endl;
		return re;
	}
	double get_re () { return re; }
	void print() const {
		std::cout << "re=" << re << " im=" << im << std::endl;
	}
};

template <class T> T f (T& x, T& y) {
	std::cout << "template f" << std::endl;
	return x > y ? x : y;
}
double f (double x, double y)
{
	std::cout << "ordinary f" << std::endl;
	return x > y ? -x : -y;
}

int main ()
{
	complex a(2, 5), b(2, 7), c;
	double x = 3.5, y = 1.1;
	int i, j = 8, k = 10;
	c = f (a, b);		//template
	std::cout << "c = ";
	c.print ();
	x = f (a, y);
	std::cout << "x = " << x << std::endl;
	i = f (j, k);
	std::cout << "i = " << i << std::endl;
	std::cout << "Выбор сделан!" << std::endl;
	return 0;
}