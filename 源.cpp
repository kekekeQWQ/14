#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Circle {

	friend float CirclePerm(int, float *);

private:
	float Center(int t);
	void Compute(void);
	void Backtrack(int t);
	float min, *x, *r;
	int n;
};
float Circle::Center(int t)
{
	float temp = 0;
	for (int j = 1; j < t; j++)
	{
		float valuex = x[j] + 2.0*sqrt(r[t] * r[j]);
		if (valuex > temp)
			temp = valuex;
	}
	return temp;
}
void Circle::Compute(void)
{
	float low = 0,
		high = 0;
	for (int i = 1; i <= n; i++)
	{
		if (x[i] - r[i] < low)
			low = x[i] - r[i];
		if (x[i] + r[i] > high)
			high = x[i] + r[i];
	}
	if (high - low < min)
		min = high - low;
}
void Circle::Backtrack(int t)
{
	if (t > n)
		Compute();
	else
		for (int j = t; j <= n; j++)
		{
			swap(r[t], r[j]);
			float centerx = Center(t);
			if (centerx + r[t] + r[1] < min)
			{
				x[t] = centerx;
				Backtrack(t + 1);
			}
			swap(r[t], r[j]);
		}
}
float CirclePerm(int n, float *a)
{
	Circle X;
	X.n = n;
	X.r = a;
	X.min = 100000;
	float *x = new float[n + 1];
	X.x = x;
	X.Backtrack(1);
	delete[] x;
	return X.min;
}
int main()
{
	int n;
	cout << "please enter your numbers:";
	cin >> n;
	float *p = new float[n + 1];
	cout << "please enter your circles:";
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	cout << CirclePerm(n, p) << endl;
	delete[] p;
	return 0;
}