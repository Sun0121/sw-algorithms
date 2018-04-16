/*	并查集的理解与应用 

*	问题：给一块图，给出连边，要求输出至少再要多少条连边才能将整个图联通。 
* 	思路，每一条连边可以连接两个联连通分量，若有n个连通分量，就需要n-1 条连边，所以问题转化为求解图中有多少连通分量 


*	理解方式，利用江湖门派来理解，每个人刚开始初入江湖，自己便是自己的掌门，但江湖不断变化，经历合并分裂后江湖形成几大门派， 
*	这时候要区分出你和我是不是一个门派，只要不断沿着我们的上级不断找上去，直到找到我们的掌门就可区分出门派，掌门拥有的特点
*	就是自己便是自己的掌门， 
* 

*/ 



#include<iostream>
#include<string.h> 
using namespace std;

int  pre[1050];           // 标记每个人的上级 

bool t[1050];               //t 用于标记独立块的根结点

int Find(int x)             // 找到根节点，即找到每个门派的掌门
{
	int r=x;
	while(r!=pre[r])          //当满足自己就是自己的掌门时，就是该门派掌门 
		r=pre[r];              //此处，r就是掌门 
	
	int i=x,j;                // 此处是将x及其非掌门的上级的上级全部换位掌门 
	while(pre[i]!=r)    
	{
		j=pre[i];       
		pre[i]=r;
		i=j;
	}
	return r;
}

void mix(int x,int y)        //门派合并过程 
{ 
	int fx=Find(x),fy=Find(y);
	if(fx!=fy)             // 如果掌门不是一个人，那就让掌门变成一个人 
	{
		pre[fy]=fx;
	}
} 

int main()
{
	int N,M,a,b,i,j,ans;
	while(scanf("%d%d",&N,&M)&&N)
	{
		for(i=1;i<=N;i++)          //初始化，每个人的掌门都是自己 
			pre[i]=i;
		
		for(i=1;i<=M;i++)          //吸收并整理数据 
		{
			scanf("%d%d",&a,&b);
			mix(a,b);
		}
		
		
		memset(t,0,sizeof(t));
		
		for(i=1;i<=N;i++)          //标记根结点
		{
			t[Find(i)]=1;             // 找到掌门，并将其标记 
		}
		for(ans=0,i=1;i<=N;i++)
			if(t[i])
				ans++;
				
		printf("%d\n",ans-1);
		
	}
	return 0;
}
