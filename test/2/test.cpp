#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	double x, n;
	double result=1;
	cin >> x >> n;
	if (n >= 0)
	{
		for (int i = 1;i <= n;i++)
		{
			double c = 1;
			for (int j = 1;j <= i;j++)
			{
				c = c * j;
			}
			result = result + pow(x, i * 1.0) / c;
		}printf("%.6lf\n", result);
	}
	else printf("error");
	return 0;
}