#include<iostream>
#include<vector>
#include<bitset>

using namespace std;


/*

*	问题：给出一个int型集合(set) W，然后指定一个数key, 判断 W 的某个子集的所有元素和能否等于key 
*	核心思想：动态规划，将原问题不断划分成子问题来解决。
*	此问题可以划分为所求子集是否包含原集合中最后一个元素的两个子问题， 

*/



bool isSubSetSumRecu(int w[],int n, int key)             //递归解决 
{
	if(n == 0 && key != 0) return false;
	
	if(key == 0) return true;
	
	if(w[n-1] > key) return isSubSetSumRecu(w, n-1, key);
	
	return isSubSetSumRecu(w, n-1, key - w[n-1]) || isSubSetSumRecu(w, n-1, key);
}


/*

*	建立一个 subSet[key+1][n+1]，将结果记录下来，自底而上解决 

*/ 
bool isSubSetSum(int w[],int n,int key){
	
	bool subSet[key+1][n+1];             //若subSet[i][j] == 1, 表明集合 w[0,j-1] 中存在子集使得该子集和为 i 
	
	for(int i = 0; i < n + 1; ++ i)
		subSet[0][i] = 1;
		
	for(int i = 1; i < key + 1;++ i)
		subSet[i][0] = 0;
	
	for(int i = 1; i < key +1;++ i)
		for(int j = 1;j < n + 1;++ j)
		{
			subSet[i][j] = subSet[i][j-1];
			if(i >= w[j-1]){                     //如果当前key大于等于当前集合最后一个元素 
				subSet[i][j] = subSet[i][j-1] || subSet[i - w[j-1]][j-1];
			}
		}
	
	return subSet[key][n]; 
} 

int main()
{
	int w[9] = {2, 4, 6, 8, 10, 5, 9, 11, 13}; 
	int key = 20;
	cout<<isSubSetSum(w,9,20)<<endl;
	return 0;
} 