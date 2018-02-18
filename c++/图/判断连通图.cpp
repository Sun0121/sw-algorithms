#include <iostream>
#include<queue>

using namespace std;

/*
	判断一个图是否为连通图,思路是任选图中一个顶点开始遍历，
	利用一个数组来打标记，看是否访问过，遍历完后所有结点都
	被访问过，则为连通图。 
	
	*/ 

class Graph {
public:
	
	int **graph;             //记录图的相关属性 
	int number;       
	int *mark;           //记录访问情况    
	    
    Graph(int N) {                            //图的初始化 
       	number = N + 1;
		graph = new int*[number];
		for(int i = 0;i<number;++ i)
			graph[i] = new int[number];
		for(int i= 0;i<number;++ i)
			for(int j = 0;j<number;++ j)
				graph[i][j] = 0;
		mark = new int[number];
		for(int i = 0;i < number;++ i)
			mark[i] = 0; 
		
    }
    void add_edge(int v1, int v2) {
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
    }
    
    bool connected() {            //判断是否连通 
    	dfs(1);
    	//bfs(1);
    	for(int i = 1;i<number;++ i)
    		if(mark[i] == 0)
    			return false;
    	return true;
    }
    
	/*
		深度优先遍历，选择图中一个点进行访问，然后再访问该点的邻居，
		递归访问，直到某个顶点的所有邻居都已被访问，然后返回上一级 
		
		*/ 


    void dfs(int v)             //表示从顶点v开始访问 
    {
    	mark[v] = 1;          //访问v顶点并打上标记 
    	
		for(int w = first(v);w != -1;w = next(v,w))
		 /*
		 遍历所有v点邻居，只要其中一点未被访问，就以该点继续 
		 访问下去 
		 */ 
			if(mark[w] == 0) 
				dfs(w);
	}
	
	/*
		广度优先遍历，先访问一个点，在访问这个点的所有邻居，
		*/ 
	
	
	void bfs(int v)           //从v点开始遍历 
	{
		queue<int> m_queue;      //队列作为辅助工具
		 
		m_queue.push(v);
		while(!m_queue.empty())
		{
			int temp = m_queue.front();
			m_queue.pop();
			mark[temp] = 1;           //从队列头中取出元素进行访问 
			
			for(int w = first(temp);w != -1;w = next(temp,w))
			/*
				对于每个temp的邻居，判断是否被访问过，若没被访问过，就添进队列等待访问
				 
				*/
				if(mark[w] == 0)
					m_queue.push(w);
		}
 	}
 	
    int first(int v)             //找到v点的第一个邻居 
    {
    	for(int i = 0;i<number;++ i)
    		if(graph[v][i] != 0)
    			return i;
    	return -1;
	}
	
	int next(int v,int w)      //找到v点继w后的下一个邻居 
	{
		for(int i = w + 1;i<number;++ i)
			if(graph[v][i] != 0)
				return i;
		return -1;
	}
};
int main() {
    int M;
    cin>>M;
    while(M--) {
        int N, C;
        cin>>N>>C;
    
        Graph graph(N);
        //读取每一条边
        for(int i=0;i<C;i++) {
            int v1, v2;
            cin>>v1>>v2;
            graph.add_edge(v1, v2);
        }
        //判断这个图是否连通并输出结果
        cout << (graph.connected()?"YES":"NO") << endl;
    
    }
    return 0;
}
