#include<iostream>

using namespace std;


/*
	目的：在不开辟新的空间内存的情况下，将原来的链表倒转过来

	*/ 

template<typename T>
class Node                             //定义结点属性 
{
	public:
		Node(T t = 0,Node<T>* p = NULL)
		{
			element = t;
			next = p;
		}
		T element;
		Node<T>* next;
}; 


int main ()
{
	Node<int> *head,*p,*rear;
	
	/*
		以下构建原始链表作为测试数据 
		*/ 
	for(int i = 1;i<=8;++ i)
	{
		if(i == 1)
		{
			rear = new Node<int>(i);
			head = p = rear;
		}
		else
		{
			rear = new Node<int>(i);
			p->next = rear;
			p = rear;
		}
	}
	
	Node<int> *temp = head;
	do                                      //输出原始链表的值 
	{
		cout<<temp->element<<endl;
		temp = temp->next;
	}while(temp->next!=NULL);
	cout<<temp->element<<endl;
	
	/*
	  	倒转链表的关键操作，首先定义一个指向头结点的指针，当该指针指向的不是尾结点时便进入循环
		按正常思想，可以不断将后面的结点放到最前面来实现，比如顺序为1234的结点，首先换为2134，
		然后再换为3214，最后换为4321，退出循环。
		
		我们发现，每一次交换都是将头结点后的每一个结点即下面的q结点都被按顺序交换到最前面过，直至q指向尾结
		点后被交换到最前面即tmp->next == NULL时停止，
		
		故我们需要做的就是调整好被交换结点的指向，使链表不致断开，最后再将头结点指向被交换的结点 
		 
		 */ 
	
	Node<int>  *tmp = head,*q;            
	
	while(tmp->next != NULL)               //当tmp不是尾结点 
	{
		q = tmp->next;              //指定被交换的结点 
		tmp->next = q->next;       //被交换结点的前一个结点的next指向被交换结点的下一个结点 
		 
		q->next = head;                       //让被放到前面的结点指向头结点 
		head = q;							//头结点变为被交换的q结点 
	}
	
	do
	{
		cout<<q->element<<endl;
		q = q->next;
	}while(q->next!=NULL);
	cout<<q->element<<endl;
}