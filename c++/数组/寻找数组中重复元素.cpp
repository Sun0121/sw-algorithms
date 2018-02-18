#include<iostream>

#include<algorithm>			//sort����ͷ�ļ� 
#include<set>				//STL�е�set������ͷ�ļ� 
#include<cstring>          //memset����ͷ�ļ� 

using namespace std;

/**
	
*	Ѱ���������ظ���Ԫ��

**/ 

/*
	
	��һ��˼·������Ľⷨ����ÿһ�������е�Ԫ�ض�������Ԫ�ؽ���һ�αȽ�
	Ȼ�����������ظ�Ԫ�ص�������ͽ���Ԫ�ؼ��뵽set��(����ʹ��set��ԭ����Ϊ
	���������ͬԪ�س����ظ������)��ʱ�临�Ӷ���n��ƽ�� 
	
	*/ 

void findSameElement1(int *v,int n)
{
	set<int> my_set; 
	
	for(int i = 0;i<n;++ i)
		for(int j = 0;j < n;++ j)
			if(i != j && v[i] == v[j])         //�ж��ظ�Ԫ�� 
				my_set.insert(v[i]);
	
	set<int>::iterator it;
	for(it = my_set.begin();it != my_set.end();++ it)
		cout<<*it<<" ";
}
 
/*
	�ڶ���˼·���Ե�һ��˼·������һ���Ż��������ȶ������������Ȼ���ٱȽ�
	ǰ��Ԫ���Ƿ���ͬ������set�����д洢 
	
	*/ 
	
void findSameElement2(int *v,int n)
{
	set<int> my_set;
	
	sort(v,v+n);
	
	for(int i = 1;i<n;++ i)
		if(v[i] == v[i-1])
			my_set.insert(v[i]);
			
	set<int>::iterator it;
	for(it = my_set.begin();it != my_set.end();++ it)
		cout<<*it<<" ";
} 

/*
	������˼·�����ù�ϣ����뷨�����˷�����ʹ�����������ڴ�СΪn�����飬
	����洢�����ݷ�Χֻ������0 -- n-1�������Ļ������������ÿһ��������
	Ӧ�����һ���±꣬�Ǿ����¿�һ����ԭ����ͬ����С�����飬����������ͳ
	��ԭ������ÿ�������ֵ�Ƶ�ʣ�����ٱ���һ��ԭ���飬�����ָ����ĳ���Ƶ
	�ʴ���һ���Ǳ㽫����ӵ�set�� 
	
	*/


void findSameElement3(int *v,int n)
{
	set<int> my_set;
	
	int *p;
	p = new int [10000000];
	memset(p,0,sizeof(int)*10000000);
	
	for(int i = 0;i < n;++ i)
		p[v[i]]++;
	
	for(int i = 0;i<n;++ i)
		if(p[v[i]] > 1)
			my_set.insert(v[i]);
	
	set<int>::iterator it;
	for(it = my_set.begin();it != my_set.end();++ it)
		cout<<*it<<" ";
}


int main()
{
  /*	int a[8] = {1,84,1,8,12,81,5,8};        //�˴����ڲ���ǰ���ַ��� 
		findSameElement1(a,8);
		cout<<endl;
		findSameElement2(a,8);
		cout<<endl;                       */
		
		
	int *p,temp,i = 0;                        //���������Ե����ַ����������ù�ϣ���˼�� 
	p = new int[10000000];					//��������ĸ���ȡֵ��Χ��0-9999999 
	
	while(cin>>temp)					//����������ݣ��������з���ֹ 
	{
		p[i++] = temp;
		char ch = cin.get();
		if(ch == '\n'||ch == '\r')
			break;
	}
	
	int len = i;
	findSameElement3(p,len);
}