#include<iostream>
#include<stack>

using namespace std; 

/*

*	求最长递增子序列的问题,数组内的数据并不要求连续	

*/  

/*
	
	第一种思路，动态规划法：想求序列array[0,i]的最长递增子序列，即可先求array[0,i-1]的最长递增子序列
	定义一个数组lis[n],lis[i]用来记录序列array[0,i]的最长递增子序列的长度，所求具体方法见下代码部分 
	
	*/
void lengthOfLIS1(int *v,int n)
{
	int *lis = new int[n];                 //定义存储长度的数组 
	for(int i = 0;i<n;++ i)
		lis[i] = 1;
		
	for(int i = 1;i < n;++ i)               //对每一个下标为i的序列求lis 
		for(int j = 0;j<i;++ j)
			if(v[j]<v[i] && lis[i]<lis[j] + 1)           //求lis,复杂度为n^2 
			{
				lis[i] = lis[j] + 1;
			}
		
	int max = 0;
	for(int i = 0;i<n;++ i)
		if(lis[i]>max)
			max = lis[i];               
			
	cout<<max<<endl;    
} 




int main()
{
	int a[8] = {-1,5,-4,3,6,2,9,7};
	lengthOfLIS1(a,8);
}




/*
	#include <iostream> 
#include <algorithm> 
 
using namespace std; 
 
#define MAXN 1003 
int A[MAXN]; 
int MaxV[MAXN]; 
 
// 动态规划算法O(nlogn) 
int main() 
{ 
    int n, i, j, k; 
    cin >> n; 
    for (i=1; i<=n; i++) 
        cin >> A[i]; 
    MaxV[1] = A[1]; 
    int nmaxv = 1;  // 目前找到的最长递增子序列的长度 
    // 有n个阶段，每个阶段有1个状态 
    for (i=2; i<=n; i++) 
    { 
        // 每个状态有nmaxv种决策，以得出以元素i结尾的最长递归子序列的长度 
        int u = 1, v = nmaxv; 
        while (u<=v) 
        { 
            int mid = (u+v)>>1; 
            if (MaxV[mid] < A[i]) 
                u = mid+1; 
            else 
                v = mid-1; 
        } 
 
        // 每个元素都会对数组MaxV中的某个元素产生影响 
        // 使用二分搜索确定其在第v+1个位置 
        nmaxv = max(nmaxv, v+1); 
        MaxV[v+1] = A[i]; 
    } 
    cout << nmaxv; 
} 

	*/