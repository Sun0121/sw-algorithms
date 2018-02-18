#include<iostream>
#include<queue>

using namespace std;

/*

	�������������ж�����ͼ���Ƿ���Բ��������˼·���Ƚ�ԭͼ���������Ϊ0�ĵ�
	������У�Ȼ�󲻶ϴӶ�����ȡ��ĳ�㣬Ȼ����ͼ����ȥ�õ㼰��֮��ص�������
	�ߣ�Ȼ���ֻ᲻�ϲ����µ����Ϊ0�ĵ�enqueue,ѭ��ֱ������Ϊ�� 
	
	*/ 

bool isCircle(int **graph,int *indegrees,int number)     //��ͼ������͵������뺯�� 
{
	queue<int> M;          //������У���ʱ��̬��¼ͼ�����Ϊ0�ĵ�                
	
	for(int i = 1;i<number;++ i)
	{
		if(indegrees[i] == 0)             //��ʼ�����У���ԭͼ���������Ϊ0�ĵ���ӵ������� 
			M.push(i);
	}
	
	/* 
		����������һ��ѭ�����Ӷ�����ȡ��һ����� ��ԭͼ��Ҳȡ������㣬
		Ȼ�����������г��Ⱦͻ���ʧ����Ӧ���ɸõ�ָ�����������Ⱦͻ���ʧ��
		��Ӧ�ľͻ����²������Ϊ0�ĵ�
		
		*/ 
	
	while(!M.empty())
	{
		int n = M.front();               //�Ӷ�����ȡ�����Ϊ0�ĵ�
		 
		for(int i = 1;i<number;++ i)
			if(graph[n][i] == 1)             //ȡ��n�����Ӧ����������Ⱦͼ�1              
			{
				indegrees[i]--;              
				 
				if(indegrees[i] == 0)          //����������Ϊ0�ĵ���� 
					M.push(i);
			}
			
		M.pop();                    //�Ӷ��е����õ� 
	}
	
	for(int i = 1;i<number;++ i)      //�����ͼ�л�������Ȳ�Ϊ0�ĵ㣬�Ǿ�һ���л� 
	{
		if(indegrees[i] != 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n;
	cin>>n;                                          //����������Ŀ 
	while(n>0)
	{
		int number_vertices,number_edges,p,q;         //��������ͼ�ĵ�ĸ������������p��ָ��q�㣬�����������1-n 
		cin>>number_vertices>>number_edges;
		
		int *indegrees;
		
		indegrees = new int[number_vertices+1];       //����ÿ�������ȣ���ʼ��Ϊ0 
		for(int i = 0;i<number_vertices+1;++ i)
			indegrees[i] = 0;
		
		int **graph;                              //���������ͼ 
		graph = new int*[number_vertices+1];
		for(int i = 0;i<number_vertices+1;++ i)
			graph[i] = new int[number_vertices+1];
		for(int i = 0;i<number_vertices+1;++ i)
			for(int j = 0;j<number_vertices+1;++ j)
				graph[i][j] = 0;
		 
		for(int i = 0;i<number_edges;++ i)        //����Ҫ�����ø�ͼ 
		{
			cin>>p>>q;                 
			graph[p][q] = 1;              //��p��ָ��q�㣬��graph[p][q]��1 
			indegrees[q]++;             //q�������1 
		}
		
		if(isCircle(graph,indegrees,number_vertices+1))        //�������������ж�ͼ������Բ�� 
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
		
		--n;
	}
}