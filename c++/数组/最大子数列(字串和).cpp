#include<iostream>

using namespace std;


/**

*	目的是求解一个数组中最大子序列的和，基本思路是定义一个变量sum，用来动态记录 
*	子序列的和,定义一个子序列和的最大值max，
*	整个循环过程中，如果sum的出现小于0的情况，那就舍弃前面数组的值重新开始建立子
*	序列和，而max则将整个循环过程中最大的那个sum给记录下来 

**/
int maxSubArray(int *v,int n)
{
	int max = 0,sum = 0;
	for(int i = 0;i<n;++ i)
	{
		sum = sum<0 ? v[i]:sum+v[i];               //若sum小于0，则舍弃前面的子序列而重新开始 
		
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