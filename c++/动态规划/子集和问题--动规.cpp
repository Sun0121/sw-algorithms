#include<iostream>
#include<vector>
#include<bitset>

using namespace std;


/*

*	���⣺����һ��int�ͼ���(set) W��Ȼ��ָ��һ����key, �ж� W ��ĳ���Ӽ�������Ԫ�غ��ܷ����key 
*	����˼�룺��̬�滮����ԭ���ⲻ�ϻ��ֳ��������������
*	��������Ի���Ϊ�����Ӽ��Ƿ����ԭ���������һ��Ԫ�ص����������⣬ 

*/



bool isSubSetSumRecu(int w[],int n, int key)             //�ݹ��� 
{
	if(n == 0 && key != 0) return false;
	
	if(key == 0) return true;
	
	if(w[n-1] > key) return isSubSetSumRecu(w, n-1, key);
	
	return isSubSetSumRecu(w, n-1, key - w[n-1]) || isSubSetSumRecu(w, n-1, key);
}


/*

*	����һ�� subSet[key+1][n+1]���������¼�������Ե׶��Ͻ�� 

*/ 
bool isSubSetSum(int w[],int n,int key){
	
	bool subSet[key+1][n+1];             //��subSet[i][j] == 1, �������� w[0,j-1] �д����Ӽ�ʹ�ø��Ӽ���Ϊ i 
	
	for(int i = 0; i < n + 1; ++ i)
		subSet[0][i] = 1;
		
	for(int i = 1; i < key + 1;++ i)
		subSet[i][0] = 0;
	
	for(int i = 1; i < key +1;++ i)
		for(int j = 1;j < n + 1;++ j)
		{
			subSet[i][j] = subSet[i][j-1];
			if(i >= w[j-1]){                     //�����ǰkey���ڵ��ڵ�ǰ�������һ��Ԫ�� 
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