#include<iostream>
#include<algorithm>

using namespace std;


/**
*	����1����ÿһ�������е�Ԫ�ض��������еĳ��Լ����������Ԫ����һ�αȽϣ� 
*	�����������Ԫ�ؾͷ���true 

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
*	����2���ȶ����������������Ȼ���ٶ�ÿһ��Ԫ���ж�������Ԫ���Ƿ���ȣ�
*	�������Ԫ�أ��Ǿͷ���true, 

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
*	����3����ϣ��˼�룬��ÿһ������Ԫ�ز��뵽��ϣ���е�ÿһ���ض�λ�ã��� 
*	���ֲ���ĳһ��Ԫ��ʱ����ϣ�����Ǹ�λ���Ѿ�����ĳ��Ԫ���ˣ��Ǿͷ���true 

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
*	����4�������鳤����n,����������Ԫ��ȡֵ��0--n-1���������Ч�������Ļ���
*	������ÿһ��Ԫ�ض���Ӧ�����ÿһ���ض��±꣬�ڲ��¿��ռ������£���ÿ
*	һ��Ԫ�ظ�������ֵ������������������Ӧ��λ�ã������������з��֣�ĳһ��
*	�±��Ӧ��ֵ�������ֵ���ñ����������ض��±�λ�õ�ֵ���Ǿͱ�����ֵ�ظ� 
*	�ˡ� 

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
	int n[8] = {8,90,45,86,8,74,36,225};           //����������ݵķ�Χ��0-9999�� 
	
	cout<<method1(n,8)<<endl;
	cout<<method2(n,8)<<endl;
	cout<<method3(n,8)<<endl;
}