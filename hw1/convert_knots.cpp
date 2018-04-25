#include <iostream>
using namespace std;

double knotsToMph(int knots)
{
	double mph = knots * 6076.0;
	mph = mph/5280.0;
	return mph;	
}

int main()
{
	cout << "--------convert knots into mph --------" << endl;
	cout << "please type an integer:" << endl;
	int K;
	cin >> K;
	cout << K << " Knots = " << knotsToMph(K) << " mph." << endl;
	return 0;
}
