#include<iostream>

using namesapce std;

class MinHeap
{
	int *number,length;                     //����С���ѵĴ洢�ṹ��Ԫ�ظ�������ȫ�����������ʺ������� 
	public:
		
		MinHeap(int *array = NULL,int n = 0)
		{
			number = array;
			length = n;
			this->getMinHeaps();
		}
		
		int getLength()
		{
			return length;
		}
		
		void getMinHeaps() 
		{
			for(int i = length/2 - 1;i>=0;--i)             
				siftup(i);
			/*
				����������㿪ʼ��ÿһ�������㶼���Լ��ĺ�����һ�ε�����
				��֤�Լ���ֵС�����Ҷ��ӵ� 
				*/ 
		}
		
		void siftup(int pos)           //��ؼ���һ������posλ�õ�����ڵ���е��� 
		{
			while(!isLeaf(pos))      //�ж�posλ�õĽ���Ƿ�ΪҶ�ӣ�������ֹͣ���� 
			{ 
				 
				int j = leftChild(pos);
				int rc = rightChild(pos);
				if(rc<length&&number[j]>number[rc])   //ȡ�����Һ�����ֵ��С����һ����λ��  
					j = rc;                          
				
				if(number[pos]<number[j]) return;     //����С����һ�����ڸ��׽ڵ㣬�����С�������ʣ����õ����� 
				
				swap(pos,j);                         //����㽻�� 
				
				/*
				   ����֮����Ҫ�Խ������������������е�����ֱ��������Ҷ�ӣ���һ���������� 
				*/ 
				pos = j;        
			}
		}
		
		bool isLeaf(int pos)           //����λ�ý��Ķ���λ�ô����������鳤�ȣ�����ΪҶ�� 
		{
			if(pos>=length/2&&pos<length)
				return true;
			return false;
		}
		
		int leftChild(int pos)
		{
			return 2*pos + 1;
		}
		int rightChild(int pos)
		{
			return 2*pos + 2;
		}
		void swap(int pos,int j)
		{
			int temp;
			temp = number[pos];
			number[pos] = number[j];
			number[j] = temp;
		}
		void display()
		{
			for(int i = 0;i<length;++ i)
				cout<<number[i];
		}
		int getMin()
		{
			return number[0];
		}
		
		bool removeMin(int & it)             //�Ƴ��Ѷ�Ԫ�صĲ��� 
		{
			if(length == 0) return false;
			swap(0,--length);
			if(length!=0) siftup(0);          //�Ըı����λ�����½���ƽ�� 
			it = number[length];
			return true;
		}
		
		bool insert(const int val)         //����Ԫ�� 
		{
			if(length>1000) return false;
			int curr = length++;
			number[curr] = val;          //��ĩβ����Ԫ�� 
			
			while(curr!=0&&number[curr]<number[(curr-1)/2])   //�Բ����Ԫ�ؽ��е������������ȸ��׻�С���򽻻� 
			{
				swap(curr,(curr-1)/2);
				curr = (curr-1)/2;
			}
			return true;
		}
}; 

int main()
{
	int *array,n;
	cin>>n;
	array = new int[n]
	for(int i = 0;i<n;++ i)
		cin>>array[i];
	MinHeap m_heap(array,n);          //�������������ΪС���� 
} 