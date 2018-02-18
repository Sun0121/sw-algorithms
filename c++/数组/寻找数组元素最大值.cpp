#include<iostream>

using namespace std;

/**

*	遍历一遍就能找到最大值 

**/

int getMax(int *v,int n)
{
	int max = 0;
	for(int i = 0;i<n;++ i)
		if(v[i]>max)
			max = v[i];
	return max;
} 

int main()
{
	int a[8] = {1,32,5,3,65,78,356,52};
	cout<<getMax(a,8)<<endl; 
}