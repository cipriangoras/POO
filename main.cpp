#include "Math.h"
int main()
{
	Math d;

	cout << d.Add(12, 43) << endl;
	cout << d.Add(12, 43, 44) << endl;
	cout << d.Add(12.3, 43.3) << endl;
	cout << d.Add(12.4, 43.3, 32.2) << endl;
	cout << d.Mul(12, 43) << endl;
	cout << d.Mul(12.2, 43.3) << endl;
	cout << d.Mul(12.3, 43.3, 44.66) << endl;
	cout << d.Add(5, 1, 2, 3, 4) << endl;
	cout << d.Add("10", "40") << endl;

}
