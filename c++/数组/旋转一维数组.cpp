#include<iostream>

using namespace std;

	/*   

	˼·�Ƿֱ���������߿�ʼ�������ݡ�ֱ�������±��໥������ֹͣ 
	
	*/ 
void rotate(int *a,int n)          
{
	int i = 0,j = n-1;
	while(i<j)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
}

int main()
{
	int n;
	cin>>n;
	int *array;
	array = new int[n];
	for(int i = 0;i<n;++ i)
		cin>>array[i];
	rotate(array,n);
	for(int i = 0;i<n;++ i)
		cout<<array[i]<<" ";
}