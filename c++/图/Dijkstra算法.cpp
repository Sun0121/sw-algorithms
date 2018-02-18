#include<iostream>

using namespace std;

/*
	��ĳ�㵽����������·�����⣬Dijkstra�㷨
	
	*/ 

int *mark,**graph;            //��ͼ�ͱ�����鶨��Ϊȫ�ֱ��� 

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

void getMark(int v)          //���Ѿ�ȷ�����·���ĵ���ϱ�� 
{
	mark[v] = 1;
}

int minVertex(int *D,int len)           //D�����¼���ǵ�ǰ��ԭ�㵽���������·������ 
{
	int min = 0;                 
	
	for(int i = 1;i<len;++ i)
	{	if(D[i]<D[min] && mark[i] == 0)    //���δȷ�����·���ĵ���ȡ����С����һ�� 
			min = i;
	}
	return min;        //�˴�min��¼�����±� 
}

int first(int v,int len)        //����v��ĵ�һ���ھ� 
{
	for(int i = 1;i<len;++ i)         
		if(graph[v][i]<24564654)
			return i;
	return -1;
}

int next(int v,int w,int len)          //����v���w������һ���ھ� 
{
	for(int i = w+1;i<len;++ i)
		if(graph[v][i]<24564654)
			return i;
	return -1;
}


/*
	�����㷨
	 
	*/ 
void dijkstra(int **graph,int s,int *D,int len)      //sΪ��ʼԭ�� 
{
	int i,v,w;
	for(i = 0;i<len;++ i)
		D[i] = 24564654;
	D[s] = 0;                          //��ʼ��������s��s�ľ���Ϊ0 
	               
	for(i = 0;i<len;++ i)             //����len�ε������Ϳ���ȷ��s�㵽�������е�����·�� 
	{	
		v = minVertex(D,len);           
		getMark(v); 				//ȡ����̵�һ�㣬��������ȷ�����·���ı�� 
		
		for(w = first(v,len);w != -1;w = next(v,w,len))    //��������v��������ھ� 
		{
			/*
				D[v]��ʱ��¼�ŵ�ǰs����v�����̾��룬
				��s��v�ľ������v��w�ľ���С��ԭ��sֱ�ӵ�w�����
				���룬���D[w]���и��£���Ϊ����һ�����̵�·���� 
				*/ 
			if(D[v]+graph[v][w]<D[w])        
				D[w] = D[v]+graph[v][w];
		}
	}
}

int main()
{
	int N,C,S,T;              //�������ݣ��ֱ���ͼ�ĵ����������� ԭ����յ� 
	
	int Vi,Vj,dis;         //�������ߵ�Ԫ�� 
	cin>>N>>C>>S>>T;
	int number = N + 1;
	int *path;
	graph = new int*[number];
	for(int i = 0;i<number;++ i)
	{
		graph[i] = new int[number];
	}
	path = new int[number];
	mark = new int[number];
	
	for(int i = 0;i<number;++ i)
		mark[i] = 0;
		
	for(int i = 0;i<number;++ i)
		for(int j = 0;j<number;++ j)
			graph[i][j] = 24564654;             //���Ƚ�ͼ�����е㵽��ľ�������Ϊ����� 
			
	for(int i = 0;i<C;++ i)
	{
		cin>>Vi>>Vj>>dis;
		dis = min(dis,graph[Vi][Vj]);
		graph[Vi][Vj] = dis;
		graph[Vj][Vi] = dis;
	}
	
	dijkstra(graph,S,path,number);
	cout<<path[T]<<endl;
	delete path;
	delete mark;
	for(int i = 0;i<number;++ i)
		delete graph[i];
}