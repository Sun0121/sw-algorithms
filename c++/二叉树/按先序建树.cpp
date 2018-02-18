#include<iostream>
#include<string>
#include<queue>
using namespace std;

/*

	�����������˳�����һ��ֻ������СдӢ����ĸ���ַ�����
	�涨�ַ����д�д��ĸ��Ҷ�ӣ�Сд��ĸ���м�ڵ㣬Ҫ��
	���ַ�������һ����������ٲ�������������
	
	 
	
	*/


class Node                     //�������Ľ�� 
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
	���ַ������밴˳������������д��ĸ�󷵻أ�
	Ȼ�󽨺����ҽڵ㣬��󷵻ظýڵ� 

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


 
void traverse(Node *root)               //���ö��н��в������ 
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
		if(temp->left != NULL)              //�������ң������Ҷ��ӽ�㲻����� 
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