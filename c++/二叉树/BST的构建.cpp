#include<iostream>
#include <stack>

using namespace std;

int number = 0;

/*
1��	ͨ������ķ�ʽ
	*/ 
	
	
/*  ������ṹ   */ 
class Node {              
public:
	int elem;                   
    Node *left, *right;
    Node(int elem, Node *left=NULL, Node *right=NULL) {
        this->elem = elem;
        this->left = left;
        this->right = right;
    }
};

Node* insert1(Node* node,int temp)         //ͨ������������BST,�����ڵ㷵�� 
{
	if(node == NULL)
	{
		return new Node(temp);
	}
	Node* p, *q;
	q = node;
	p = node;
	while(p != NULL)
	{	
		q = p;                                //ʼ�ձ�֤q��p�ĸ��ף������ڽ�����ʱ����ܽ���㴮���� 
		if(temp < p->elem)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	if(temp<q->elem)
	{
		q->left = new Node(temp);
	}
	else
	{
		q->right = new Node(temp);
	}
	return node;
}

void insert2(Node* &node,int temp)                //�ݹ齨����ָ������ 
{
	if(node == NULL)
	{
		node = new Node(temp);
		return;
	}
	if(temp<node->elem)
		insert2(node->left,temp);                
	else
		insert2(node->right,temp);
}
void traverse1(Node *node,int *result)                     //����ǵݹ��������������浽����result�� 
{
	if(node == NULL)
		return;
	stack<Node*> m_stack;
	m_stack.push(node);
	while(!m_stack.empty()) 	
	{
		Node* temp = m_stack.top();
		m_stack.pop();
		result[number++] = temp->elem;
		if(temp->right != NULL)
			m_stack.push(temp->right);
		if(temp->left != NULL)
			m_stack.push(temp->left);
	}
}

void traverse2(Node *node,int *result)                 //����ݹ������ע������ͷ���ֵ 
{
	if(node == NULL)
		return;
	result[number++] = node->elem;
	traverse2(node->left,result);
	traverse2(node->right,result);
}

/*   
	ͨ������ķ�ʽ
	*/
void insert3(int *tree,int index,int elem)          //index��������Ϊ�˵ݹ��ʱ���ܽ����Ҷ���λ�ô���ȥ 
{
	if(tree[index] == 0) 
	{
		tree[index] = elem; 
		return;
	} 
	if(elem<tree[index])
		insert3(tree,2*index+1,elem);
	else
		insert3(tree,2*index+2,elem);
} 

void insert4(int *tree,int elem)                   //�������齨�� 
{
	int index = 0;
	if(tree[index] == 0)
	{
		tree[index] = elem;
		return;
	}
	while(tree[index] != 0)
	{
		if(elem<tree[index])
			index = 2*index + 1;
		else
			index = 2*index + 2;
	}
	tree[index] = elem;
}

void traverse3(int *tree,int index,int *result)         //������� ���ݹ飩 
{
	if(tree[index] == 0)
		return;
	result[number++] = tree[index];
	traverse3(tree,2*index+1,result);
	traverse3(tree,2*index+2,result);
} 

void traverse4(int *tree,int *result)
{
	int index = 0;
	if(tree[index] == 0)
		return;
	stack<int> m_stack;
	m_stack.push(index);
	while(!m_stack.empty())
	{
		int temp = m_stack.top();
		m_stack.pop();
		result[number++] = tree[temp];
		if(tree[2*temp+2] != 0)
			m_stack.push(2*temp+2);
		if(tree[2*temp+1] != 0)
			m_stack.push(2*temp+1);
	}
} 

int main()
{
	int n;                        //������Եĸ��� 
	cin>>n;
	int temp,*tree;
	tree = new int[100000];
	for(int i = 0;i<n;++ i)
	{
		tree[i] = 0;
	}
	for(int i = 0;i<n;++ i)
	{
		cin>>temp;
		insert3(tree,0,temp);
	}
	int *result;
	result = new int[n];
	traverse4(tree,result);
	for(int i = 0;i<n;++ i)
	{
		cout<<result[i]<<" ";
	}
}