#include<iostream>
#include<queue>

using namespace std;

/*

	利用拓扑排序判断有向图中是否有圆环，基本思路是先将原图中所有入度为0的点
	加入队列，然后不断从队列中取出某点，然后在图中消去该点及与之相关的所有连
	边，然后又会不断产生新的入度为0的点enqueue,循环直至队列为空 
	
	*/ 

bool isCircle(int **graph,int *indegrees,int number)     //将图，入读和点数传入函数 
{
	queue<int> M;          //定义队列，随时动态记录图中入度为0的点                
	
	for(int i = 1;i<number;++ i)
	{
		if(indegrees[i] == 0)             //初始化队列，将原图中所有入度为0的点添加到队列中 
			M.push(i);
	}
	
	/* 
		接下来进入一个循环，从队列中取出一个点后， 在原图中也取消这个点，
		然后这个点的所有出度就会消失，相应的由该点指向其他点的入度就会消失，
		相应的就会重新产生入度为0的点
		
		*/ 
	
	while(!M.empty())
	{
		int n = M.front();               //从队列中取出入度为0的点
		 
		for(int i = 1;i<number;++ i)
			if(graph[n][i] == 1)             //取出n点后相应的其他点入度就减1              
			{
				indegrees[i]--;              
				 
				if(indegrees[i] == 0)          //重新添加入度为0的点进队 
					M.push(i);
			}
			
		M.pop();                    //从队中弹出该点 
	}
	
	for(int i = 1;i<number;++ i)      //最后，若图中还存在入度不为0的点，那就一定有环 
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
	cin>>n;                                          //测试样例数目 
	while(n>0)
	{
		int number_vertices,number_edges,p,q;         //定义有向图的点的个数与边数，由p点指向q点，点数编号是由1-n 
		cin>>number_vertices>>number_edges;
		
		int *indegrees;
		
		indegrees = new int[number_vertices+1];       //定义每个点的入度，初始化为0 
		for(int i = 0;i<number_vertices+1;++ i)
			indegrees[i] = 0;
		
		int **graph;                              //定义该有向图 
		graph = new int*[number_vertices+1];
		for(int i = 0;i<number_vertices+1;++ i)
			graph[i] = new int[number_vertices+1];
		for(int i = 0;i<number_vertices+1;++ i)
			for(int j = 0;j<number_vertices+1;++ j)
				graph[i][j] = 0;
		 
		for(int i = 0;i<number_edges;++ i)        //根据要求设置该图 
		{
			cin>>p>>q;                 
			graph[p][q] = 1;              //若p点指向q点，则将graph[p][q]置1 
			indegrees[q]++;             //q点入读加1 
		}
		
		if(isCircle(graph,indegrees,number_vertices+1))        //利用拓扑排序判断图中有无圆环 
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
		
		--n;
	}
}