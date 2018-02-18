#include<iostream>
#include<algorithm>

using namespace std;


/**
*	方法1：对每一个数组中的元素都与数组中的除自己以外的所有元素作一次比较， 
*	若发现有相等元素就返回true 

**/ 
 
bool method1(int *a,int n)
{
	for(int i = 0;i<n;++ i)
		for(int j = 0;j<n;++ j)
			if(i != j&&a[i] == a[j])
				return true;
	return false;
}



/**
*	方法2：先对整个数组进行排序，然后再对每一个元素判断其相邻元素是否相等，
*	若有相等元素，那就返回true, 

**/ 


bool method2(int *a,int n)
{
	sort(a,a+n);
	for(int i = 1;i<n;++ i)
		if(a[i] == a[i-1])
			return true;
	return false;
} 

/**
*	方法3：哈希表思想，将每一个数组元素插入到哈希表中的每一个特定位置，若 
*	发现插入某一个元素时，哈希表中那个位置已经存在某个元素了，那就返回true 

**/
bool method3(int *v,int n)
{
	int *k;
	k = new int[10000];
	for(int i = 0;i<10000;++ i) k[i] = 0;
	for(int i = 0;i<n;++ i)
	{
		if(k[v[i]] == 1)
			return true;
		k[v[i]]++;  
	}
	return false;
} 

/**
*	方法4：在数组长度是n,数组内所有元素取值是0--n-1的情况下有效，这样的话，
*	数组中每一个元素都对应数组的每一个特定下标，在不新开空间的情况下，将每
*	一个元素根据它的值把他交换到数组中相应的位置，若整个过程中发现，某一个
*	下标对应的值等于这个值本该被交换到的特定下标位置的值，那就表明该值重复 
*	了。 

**/

bool method4(int *v,int n)
{
	for(int i = 0;i<n;++i)
		while(v[i] != i)
		{
			int tmp = v[i];
			if(v[i] == v[tmp])
				return true;
			v[i] == v[tmp];
			v[tmp] = tmp;
		} 
	return false;
}

int main()                      
{
	int n[8] = {8,90,45,86,8,74,36,225};           //假设测试数据的范围在0-9999间 
	
	cout<<method1(n,8)<<endl;
	cout<<method2(n,8)<<endl;
	cout<<method3(n,8)<<endl;
}