#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

/*
*	问题：给出一个int型集合(set) W，然后指定一个数key, 判断 W 的某个子集的所有元素和能否等于key 
*	核心思想：回溯解决，将集合先降序排列， 以深度优先遍历所有可能的情况(用限制条件选出可能满足条件的序列) 
*/ 

void printAnswer(bitset<5> X)
{
	for(int i = 0;i < X.size(); ++ i)
		cout<<X[i]<<" ";
	cout<<endl;
}



void subSetSum(vector<int> w, bitset<5> X,int sum, int key,int k)
{
	X[k] = 1;              //表明w[k] 被加入子集 
	
	if(sum + w[k] == key)
	{
		printAnswer(X);
	} else if(k + 1 < w.size() && sum + w[k] < key) {
		subSetSum(w, X, sum + w[k], key, k + 1);
	}
	
	if(k + 1 < w.size() && sum + w[k+1] <= key)
	{
		X[k] = 0;                             //将w[k]踢出子集 
		subSetSum(w, X, sum, key, k + 1);
	}
}

int main()
{
	int n[5] = {2, 4, 6, 8, 10}; 
	vector<int> W(n, n+5);
    bitset<5> X ;  
	int tempSum = 0, key = 20, startIndex = 0;
	subSetSum(W, X, tempSum, key, startIndex);
	return 0;
} 