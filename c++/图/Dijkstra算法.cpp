#include<iostream>

using namespace std;

/*
	求某点到其他点的最短路径问题，Dijkstra算法
	
	*/ 

int *mark,**graph;            //将图和标记数组定义为全局变量 

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

void getMark(int v)          //将已经确定最短路径的点打上标记 
{
	mark[v] = 1;
}

int minVertex(int *D,int len)           //D数组记录的是当前从原点到其他点最短路径长度 
{
	int min = 0;                 
	
	for(int i = 1;i<len;++ i)
	{	if(D[i]<D[min] && mark[i] == 0)    //需从未确定最短路径的点中取出最小的那一个 
			min = i;
	}
	return min;        //此处min记录的是下标 
}

int first(int v,int len)        //返回v点的第一个邻居 
{
	for(int i = 1;i<len;++ i)         
		if(graph[v][i]<24564654)
			return i;
	return -1;
}

int next(int v,int w,int len)          //返回v点继w点后的下一个邻居 
{
	for(int i = w+1;i<len;++ i)
		if(graph[v][i]<24564654)
			return i;
	return -1;
}


/*
	核心算法
	 
	*/ 
void dijkstra(int **graph,int s,int *D,int len)      //s为开始原点 
{
	int i,v,w;
	for(i = 0;i<len;++ i)
		D[i] = 24564654;
	D[s] = 0;                          //初始化，首先s到s的距离为0 
	               
	for(i = 0;i<len;++ i)             //经过len次迭代，就可以确定s点到其他所有点的最短路径 
	{	
		v = minVertex(D,len);           
		getMark(v); 				//取出最短的一点，并打上已确定最短路径的标记 
		
		for(w = first(v,len);w != -1;w = next(v,w,len))    //遍历访问v点的所有邻居 
		{
			/*
				D[v]随时记录着当前s点至v点的最短距离，
				若s到v的距离加上v到w的距离小于原来s直接到w的最短
				距离，则对D[w]进行更新，因为发现一条更短的路径了 
				*/ 
			if(D[v]+graph[v][w]<D[w])        
				D[w] = D[v]+graph[v][w];
		}
	}
}

int main()
{
	int N,C,S,T;              //测试数据，分别是图的点数，变数， 原点和终点 
	
	int Vi,Vj,dis;         //构造连边的元素 
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
			graph[i][j] = 24564654;             //首先将图中所有点到点的距离设置为无穷大 
			
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