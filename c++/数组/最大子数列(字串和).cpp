#include<iostream>

using namespace std;


/**

*	Ŀ�������һ����������������еĺͣ�����˼·�Ƕ���һ������sum��������̬��¼ 
*	�����еĺ�,����һ�������к͵����ֵmax��
*	����ѭ�������У����sum�ĳ���С��0��������Ǿ�����ǰ�������ֵ���¿�ʼ������
*	���кͣ���max������ѭ�������������Ǹ�sum����¼���� 

**/
int maxSubArray(int *v,int n)
{
	int max = 0,sum = 0;
	for(int i = 0;i<n;++ i)
	{
		sum = sum<0 ? v[i]:sum+v[i];               //��sumС��0��������ǰ��������ж����¿�ʼ 
		
		if(sum>max)
			max = sum;
	}
	return max;
}

int main()
{
	int a[9] = {-2,2,-3,4,-1,2,1,-5,3};
	cout<<maxSubArray(a,9);
}