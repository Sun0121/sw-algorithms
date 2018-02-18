#include <iostream>
#include<queue>

using namespace std;

/*
	�ж�һ��ͼ�Ƿ�Ϊ��ͨͼ,˼·����ѡͼ��һ�����㿪ʼ������
	����һ�����������ǣ����Ƿ���ʹ�������������н�㶼
	�����ʹ�����Ϊ��ͨͼ�� 
	
	*/ 

class Graph {
public:
	
	int **graph;             //��¼ͼ��������� 
	int number;       
	int *mark;           //��¼�������    
	    
    Graph(int N) {                            //ͼ�ĳ�ʼ�� 
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
    
    bool connected() {            //�ж��Ƿ���ͨ 
    	dfs(1);
    	//bfs(1);
    	for(int i = 1;i<number;++ i)
    		if(mark[i] == 0)
    			return false;
    	return true;
    }
    
	/*
		������ȱ�����ѡ��ͼ��һ������з��ʣ�Ȼ���ٷ��ʸõ���ھӣ�
		�ݹ���ʣ�ֱ��ĳ������������ھӶ��ѱ����ʣ�Ȼ�󷵻���һ�� 
		
		*/ 


    void dfs(int v)             //��ʾ�Ӷ���v��ʼ���� 
    {
    	mark[v] = 1;          //����v���㲢���ϱ�� 
    	
		for(int w = first(v);w != -1;w = next(v,w))
		 /*
		 ��������v���ھӣ�ֻҪ����һ��δ�����ʣ����Ըõ���� 
		 ������ȥ 
		 */ 
			if(mark[w] == 0) 
				dfs(w);
	}
	
	/*
		������ȱ������ȷ���һ���㣬�ڷ��������������ھӣ�
		*/ 
	
	
	void bfs(int v)           //��v�㿪ʼ���� 
	{
		queue<int> m_queue;      //������Ϊ��������
		 
		m_queue.push(v);
		while(!m_queue.empty())
		{
			int temp = m_queue.front();
			m_queue.pop();
			mark[temp] = 1;           //�Ӷ���ͷ��ȡ��Ԫ�ؽ��з��� 
			
			for(int w = first(temp);w != -1;w = next(temp,w))
			/*
				����ÿ��temp���ھӣ��ж��Ƿ񱻷��ʹ�����û�����ʹ�����������еȴ�����
				 
				*/
				if(mark[w] == 0)
					m_queue.push(w);
		}
 	}
 	
    int first(int v)             //�ҵ�v��ĵ�һ���ھ� 
    {
    	for(int i = 0;i<number;++ i)
    		if(graph[v][i] != 0)
    			return i;
    	return -1;
	}
	
	int next(int v,int w)      //�ҵ�v���w�����һ���ھ� 
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
        //��ȡÿһ����
        for(int i=0;i<C;i++) {
            int v1, v2;
            cin>>v1>>v2;
            graph.add_edge(v1, v2);
        }
        //�ж����ͼ�Ƿ���ͨ��������
        cout << (graph.connected()?"YES":"NO") << endl;
    
    }
    return 0;
}
