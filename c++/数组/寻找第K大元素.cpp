#include<iostream>

using namespace std;

/**
*	目的：从一组数中任意选择一个第K大的数并且打印出来，且时间复杂度要求是(n); 
*	基本解决策略是利用快排的特性，当选择的pivot经过parition后的下标就能看出该
*	pivot对应的数在数组中处于第几大，就可解决问题 

**/

int findPivot(int le,int ri)        //返回每次需要partition的支点的位置 
{
	return ri;
}

void swap(int *v,int a,int b)         
{
	int temp = v[b];
	v[b] = v[a];
	v[a] = temp;
}



/*
	整个快排最关键的一步，在此partition中，将数据大于等于v[pivot]的值放到左边，将
	小于v[pivot]的值放到右边，即从大到小排序， 
		*/ 
int partition(int *v,int le,int ri)
{
	int temp = v[le];
	while(le < ri)
	{
		while(v[ri] < temp) ri--;
		while(le<ri&&v[le] >= temp) le++;
		swap(v,le,ri); 
	}
	return le;
}

int KthLargestElementinanArray(int *v,int le,int ri,int k)
{
	if(k > ri + 1) return 0;          //若K值大于数组长度，则返回错误 
	
	int pivot = findPivot(le,ri);           
	swap(v,pivot,le);							//找到支点位置，并将其值交换到序列最前面，以方便partition的实现 
	
	int temp = partition(v,le,ri);
	swap(v,temp,le);						//经过partition后找到pivot值在数组中应该存在的位置并从序列头将其交换过去 
	
	/*
		确定temp位置与所需的第K大元素的关系，然后确定返回值 
		*/ 
	 
	if(temp == k - 1) return v[temp];
	else if(k-1 < temp)
			return KthLargestElementinanArray(v,le,temp-1,k);
	else
		return KthLargestElementinanArray(v,temp+1,ri,k);
}

int main() 
{
	int a[8] = {5,34,2,5,541,-454,22,6};
	int k = 8;
	cout<<KthLargestElementinanArray(a,0,7,k);
}