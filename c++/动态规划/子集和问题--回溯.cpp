#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

/*
*	���⣺����һ��int�ͼ���(set) W��Ȼ��ָ��һ����key, �ж� W ��ĳ���Ӽ�������Ԫ�غ��ܷ����key 
*	����˼�룺���ݽ�����������Ƚ������У� ��������ȱ������п��ܵ����(����������ѡ��������������������) 
*/ 

void printAnswer(bitset<5> X)
{
	for(int i = 0;i < X.size(); ++ i)
		cout<<X[i]<<" ";
	cout<<endl;
}



void subSetSum(vector<int> w, bitset<5> X,int sum, int key,int k)
{
	X[k] = 1;              //����w[k] �������Ӽ� 
	
	if(sum + w[k] == key)
	{
		printAnswer(X);
	} else if(k + 1 < w.size() && sum + w[k] < key) {
		subSetSum(w, X, sum + w[k], key, k + 1);
	}
	
	if(k + 1 < w.size() && sum + w[k+1] <= key)
	{
		X[k] = 0;                             //��w[k]�߳��Ӽ� 
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