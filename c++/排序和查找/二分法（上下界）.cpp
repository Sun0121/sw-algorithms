
/*

*	�������⣺���ַ������½磩 
*	���ң�ָ��һ����,��ĳ�������в��ң����ҵ�����������������-1 
* 
*	����С�Ͻ磬ָ��һ��������ĳ�������в��ң�Ҫ������������бȸ������������С���Ǹ������ҵ�����������������ڣ������-1��
*
* 	������Ͻ磬ָ��һ��������ĳ�������в��ң�Ҫ������������бȸ���С�����������Ǹ������ҵ�����������������ڣ������-1��

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
*	��С�Ͻ磬���м�ֵ����key����ô�Ͻ��Ȼ�����䡾left,mid���в�������С�ڵ���key�����Ȼ��[mid+1,right]�г��� 
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
		if(key >= A[7]) return -1;                 //�˴�7ָ�������鳤�� 
		else return A[left];
	}
	int mid = (left + right) / 2;
	if(A[mid] > key) return lower_bound_rec(A,left,mid,key);
	else return lower_bound_rec(A,mid + 1,right,key);
}

/*
*	����½磬���м�ֵ���ڵ���key����ô�Ͻ��Ȼ�����䡾left,mid - 1���в�������С��key�����Ȼ��[mid,right]�в����� 
* 	
*	��Ҫ�ر�ע����ǣ�����Ͱ����ַ�ʽȥ���֣���Ȼ��������ѭ������Ϊ�����ֵ�����ͷʱ����Ȼ����ֻʣ�����������
*	��ʱleft == mid,����������left = mid ���������ͱ�Ȼ�������ѭ�������Ա��������������ı�Ϊleft = mid + 1����
*	�������ַ����ղ��ֳܷ�һ���������
* 
*	���ԣ�ʹ�ö��ַ��ı�Ȼ�������������left = mid + 1��һ�䣬��right ��������û����ô�ϸ� 
*/

int upper_bound_cir(int *A, int left, int right, int key)
{
    int mid; 
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] < key)
        {
        	if(A[mid+1] >= key) return A[mid];        //���õ���Խ�����⣬��Ϊ���ն��Ữ�ֳ������� 
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
    cout<<"���ң�"<<endl; 
    cout<<Binary_search_cir(v,0,7,78)<<endl;
    cout<<Binary_search_rec(v,0,7,55)<<endl;
    cout<<"�Ͻ磺"<<endl; 
    cout<<lower_bound_cir(v,0,7,101)<<endl;
    cout<<lower_bound_rec(v,0,7,55)<<endl;
    cout<<"�½磺"<<endl; 
    cout<<upper_bound_cir(v,0,7,1)<<endl;
    cout<<upper_bound_rec(v,0,7,55)<<endl;
    
}
