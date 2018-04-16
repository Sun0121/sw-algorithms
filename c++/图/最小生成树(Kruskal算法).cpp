
/*

*	��С�������㷨����һ��������ͨ��Ȩͼ�У�������С�Ĵ��۽�ͼ�����е������������γ�һ������ 
*	
*	Kruskal�㷨�����ϴ�ͼ������������������ѡȨֵ��С�����߽��㴮�������� 

*/ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int u; //�����ӵ�һ��������
	int v; //��������һ��������
	int w; //�ߵ�Ȩֵ
	friend bool operator<(const Edge& E1, const Edge& E2)
	{
		return E1.w < E2.w;
	}
};


/*

*	���ò��鼯����ͼ�еĵ� 
*

*/ 
//�������鼯
void MakeSet(vector<int>& uset, int n)
{
	uset.assign(n, 0);
	for (int i = 0; i < n; i++)
		uset[i] = i;
}

//���ҵ�ǰԪ�����ڼ��ϵĴ���Ԫ��ע����whileѭ������ʾֱ���ҵ����ϴ���ԪΪֹ���� uset[i] == i ʱ 
int FindSet(vector<int>& uset, int u)
{
	int i = u;
	while (uset[i] != i) i = uset[i];             //  uset[i] != i˵���õ��Ѿ��������������� 
	return i;
}


void Kruskal(const vector<Edge>& edges, int n)
{
	vector<int> uset;
	vector<Edge> SpanTree;
	int Cost = 0, e1, e2;
	MakeSet(uset, n);
	
	for (int i = 0; i < edges.size(); i++) //��Ȩֵ��С�����˳��ȡ��
	{
		e1 = FindSet(uset, edges[i].u);
		e2 = FindSet(uset, edges[i].v);
		
		if (e1 != e2) //����ǰ�����ӵ���������ڲ�ͬ�����У�ѡȡ�ñ߲��ϲ�����������
		{
			SpanTree.push_back(edges[i]);
			Cost += edges[i].w;
			uset[e1] = e2; //�ϲ���ǰ�����ӵ������������ڼ���
		}
	}
	
	cout << "Result:\n";
	cout << "Cost: " << Cost << endl;
	cout << "Edges:\n";
	for (int j = 0; j < SpanTree.size(); j++)
		cout << SpanTree[j].u << " " << SpanTree[j].v << " " << SpanTree[j].w << endl;
		
	cout << endl;
}
int main()
{

	int n = 5, m = 7;            //����ͼ��5�����㣬7������ 
	
	vector<Edge> edges;          //����ߵļ��� 
	
	edges.assign(m, Edge());           //�Ա߼��ϳ�ʼ�� 
	
	edges[0].u = 1,edges[0].v = 3,edges[0].w = 2;            //��ʼ��ͼ���������� 
	edges[1].u = 1,edges[1].v = 5,edges[1].w = 3; 
	edges[2].u = 1,edges[2].v = 2,edges[2].w = 3; 
	edges[3].u = 3,edges[3].v = 5,edges[3].w = 4; 
	edges[4].u = 2,edges[4].v = 4,edges[4].w = 6; 
	edges[5].u = 2,edges[5].v = 5,edges[5].w = 1; 
	edges[6].u = 3,edges[6].v = 4,edges[6].w = 5; 
	
	sort(edges.begin(), edges.end());       //����֮�󣬿����Ա�Ȩֵ��С�����˳��ѡȡ��
	
	Kruskal(edges, n + 1);

	return 0;
}
