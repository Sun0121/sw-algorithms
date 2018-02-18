#include<iostream>
#include<string>
#include<queue>
using namespace std;

/*

	按先序遍历的顺序给出一个只包含大小写英文字母的字符串，
	规定字符串中大写字母作叶子，小写字母作中间节点，要求
	将字符串建成一棵树，最后再层序遍历这棵树。
	
	 
	
	*/


class Node                     //定义树的结点 
{
	public:
	Node *left;
	Node *right;
	char ch;
	Node(char c,Node* le = NULL,Node *ri = NULL)
	{
		ch = c;
		left = le;
		right = ri;
	}
};


/*
	将字符串读入按顺序建树，碰到大写字母后返回，
	然后建好左右节点，左后返回该节点 

	*/ 
Node* getTree(Node* node,string str,int &fence)
{
	if(str[fence]>=65&&str[fence]<=90)
	{
	 	return new Node(str[fence++]);
	}
		
	node = new Node(str[fence++]);
	
	node->left = getTree(node->left,str,fence);
	node->right = getTree(node->right,str,fence);
	
	return node;
} 


 
void traverse(Node *root)               //利用队列进行层序遍历 
{
	if(root == NULL)
		return;
	queue<Node*> m_stack;
	m_stack.push(root);
	while(!m_stack.empty())
	{
		Node *temp = m_stack.front();
		m_stack.pop();
		cout<<temp->ch;
		if(temp->left != NULL)              //从左至右，将左右儿子结点不断入队 
			m_stack.push(temp->left);
		if(temp->right != NULL)
			m_stack.push(temp->right);
	}
}

int main()
{
	string s;
	cin>>s;
	int fence = 0;
	Node *tree = NULL;
	tree = getTree(tree,s,fence);
	traverse(tree);
} 