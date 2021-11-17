#include<cmath>
#include <iostream>
#include <math.h>

const int b = 10;

int GetLengthOfInteger(int _Integer) 
{
	return trunc(log10(_Integer)) + 1;
}


int SplitFirstHalf(int _Integer, int _bk)
{
	return _Integer / _bk;
}

int SplitSecondHalf(int _Integer, int _bk)
{
	return _Integer % _bk;
}

int sign(int _Integer)
{
	if (_Integer >= 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int Karazuba(int _x, int _y)
{
	int n = GetLengthOfInteger(_x);
	int n0 = 2; //TODO: Abbruchbedingung besser definieren
	if (n <= n0)
	{
		return _x * _y;
	}
	else
	{
		int k = ceil(n/2);
		int bk = pow(10, n / 2);

		int P = SplitFirstHalf(_x, bk);
		int Q = SplitSecondHalf(_x, bk);
		int S = SplitFirstHalf(_y, bk);
		int T = SplitSecondHalf(_y, bk);

		int E = Q - P;
		int F = T - S;
		int U = Karazuba(P, S);
		int V = Karazuba(abs(E), abs(F));
		int W = Karazuba(Q, T);

		return U * pow(b, 2* k) + ( U + W - sign(E) * sign(F) * V ) * bk + W;
	}
}

int main()
{
	std::cout << Karazuba(12, 12) << std::endl;
	return 0;
}