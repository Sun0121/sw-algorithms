
/*

*	分治问题：二分法（上下界） 
*	查找：指定一个数,在某个数组中查找，若找到则，则输出，否则输出-1 
* 
*	找最小上界，指定一个数，在某个数组中查找，要求输出此数组中比该数大的数中最小的那个，若找到，则输出，若不存在，则输出-1；
*
* 	找最大上界，指定一个数，在某个数组中查找，要求输出此数组中比该数小的数中最大的那个，若找到，则输出，若不存在，则输出-1；

*/

#include<iostream>
#include<algorithm>
 
using namespace std;

int Binary_search_cir(int *A, int left, int right, int key)
{
	int mid;
	while(left <= right)
	{
		mid = left + (right - left) / 2;
		if(A[mid] == key) 
			return A[mid];
		if(A[mid] > key)
			right = mid - 1;
		if(A[mid] < key)
			left = mid + 1;
	}
	return -1;
}

int Binary_search_rec(int *A, int left, int right, int key)
{
	if(left == right)
	{
		if(A[left] == key) return A[left];
		else return -1;
	}
	
	int mid = (right + left) / 2;
	if(A[mid] == key) return A[mid];
	if(A[mid] > key) return Binary_search_rec(A, left, mid - 1, key);
	if(A[mid] < key) return Binary_search_rec(A, mid + 1,right, key);
} 

/*
*	最小上界，若中间值大于key，那么上界必然在区间【left,mid】中产生，若小于等于key，则必然在[mid+1,right]中长生 
* 	
*/
 
int lower_bound_cir(int *A, int left, int right, int key)
{
    int mid,big = right;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] > key)
            right = mid;
        else
            left = mid + 1;  
    }
    
    if(key >= A[big]) return -1;
    else return A[left]; 
}
 
int lower_bound_rec(int *A, int left, int right, int key)
{
	if(left == right)
	{
		if(key >= A[7]) return -1;                 //此处7指的是数组长度 
		else return A[left];
	}
	int mid = (left + right) / 2;
	if(A[mid] > key) return lower_bound_rec(A,left,mid,key);
	else return lower_bound_rec(A,mid + 1,right,key);
}

/*
*	最大下界，若中间值大于等于key，那么上界必然在区间【left,mid - 1】中产生，若小于key，则必然在[mid,right]中产生， 
* 	
*	需要特别注意的是，如果就按这种方式去划分，必然会陷入死循化，因为当划分到最后关头时，必然会有只剩两个数的情况
*	此时left == mid,如若进入了left = mid 的条件，就必然会进入死循环，所以必须得添加条件来改变为left = mid + 1；这
*	样，二分法最终才能分成一个数输出。
* 
*	所以，使用二分法的必然划分语句必须得有left = mid + 1这一句，而right 得限制则没有那么严格 
*/

int upper_bound_cir(int *A, int left, int right, int key)
{
    int mid; 
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] < key)
        {
        	if(A[mid+1] >= key) return A[mid];        //不用担心越界问题，因为最终都会划分成两个数 
        	else left = mid + 1;
        	
		}
        else
            right = mid - 1;  
            
    }
    if(key <= A[0]) return -1;
    else return A[left]; 
}

int	upper_bound_rec(int *A, int left, int right, int key)
{
	if(left == right)
	{
		if(key <= A[0]) return -1;
		else return A[left];
	}
	int mid = (right + left) / 2;
	if(A[mid] < key)
	{
		if(A[mid + 1] >= key ) return A[mid];
		else return upper_bound_rec(A, mid + 1, right, key);
	}
	else return upper_bound_rec(A, left, mid - 1, key);
}

int main()
{
    int v[8] = {9,6,56,51,78,2,41,101};
    sort(v,v+8); 
    cout<<"查找："<<endl; 
    cout<<Binary_search_cir(v,0,7,78)<<endl;
    cout<<Binary_search_rec(v,0,7,55)<<endl;
    cout<<"上界："<<endl; 
    cout<<lower_bound_cir(v,0,7,101)<<endl;
    cout<<lower_bound_rec(v,0,7,55)<<endl;
    cout<<"下界："<<endl; 
    cout<<upper_bound_cir(v,0,7,1)<<endl;
    cout<<upper_bound_rec(v,0,7,55)<<endl;
    
}
