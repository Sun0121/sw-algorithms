#include<iostream>

using namespace std;


/*
	Ŀ�ģ��ڲ������µĿռ��ڴ������£���ԭ��������ת����

	*/ 

template<typename T>
class Node                             //���������� 
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
		���¹���ԭʼ������Ϊ�������� 
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
	do                                      //���ԭʼ�����ֵ 
	{
		cout<<temp->element<<endl;
		temp = temp->next;
	}while(temp->next!=NULL);
	cout<<temp->element<<endl;
	
	/*
	  	��ת����Ĺؼ����������ȶ���һ��ָ��ͷ����ָ�룬����ָ��ָ��Ĳ���β���ʱ�����ѭ��
		������˼�룬���Բ��Ͻ�����Ľ��ŵ���ǰ����ʵ�֣�����˳��Ϊ1234�Ľ�㣬���Ȼ�Ϊ2134��
		Ȼ���ٻ�Ϊ3214�����Ϊ4321���˳�ѭ����
		
		���Ƿ��֣�ÿһ�ν������ǽ�ͷ�����ÿһ����㼴�����q��㶼����˳�򽻻�����ǰ�����ֱ��qָ��β��
		��󱻽�������ǰ�漴tmp->next == NULLʱֹͣ��
		
		��������Ҫ���ľ��ǵ����ñ���������ָ��ʹ�����¶Ͽ�������ٽ�ͷ���ָ�򱻽����Ľ�� 
		 
		 */ 
	
	Node<int>  *tmp = head,*q;            
	
	while(tmp->next != NULL)               //��tmp����β��� 
	{
		q = tmp->next;              //ָ���������Ľ�� 
		tmp->next = q->next;       //����������ǰһ������nextָ�򱻽���������һ����� 
		 
		q->next = head;                       //�ñ��ŵ�ǰ��Ľ��ָ��ͷ��� 
		head = q;							//ͷ����Ϊ��������q��� 
	}
	
	do
	{
		cout<<q->element<<endl;
		q = q->next;
	}while(q->next!=NULL);
	cout<<q->element<<endl;
}