#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n[100];
	int a,i,b,x,y,z;
    cin >> a;
	for(i=0;i<a;i++)
	{
        cin >> n[i];
	}
	scanf("%d",&b);
	y=a-1;
	x=0;
	do
	{
		z=(x+y)/2;
		if(n[z]==b)
		{
			printf("%d",z+1);
			break;
		}
		if(n[z]>b)
		{
			y=z-1;
		}
		if(n[z]<b)
		{
			x=z+1;
		}
	}while(x<=y);
	return 0;
}