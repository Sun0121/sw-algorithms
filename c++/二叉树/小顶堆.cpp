#include<iostream>

using namesapce std;

class MinHeap
{
	int *number,length;                     //定义小顶堆的存储结构及元素个数，完全二叉树，最适合用数组 
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
				从最后中央结点开始，每一个中央结点都向自己的孩子做一次调整，
				保证自己的值小于左右儿子的 
				*/ 
		}
		
		void siftup(int pos)           //最关键的一步，对pos位置的中央节点进行调整 
		{
			while(!isLeaf(pos))      //判断pos位置的结点是否为叶子，若是则停止调整 
			{ 
				 
				int j = leftChild(pos);
				int rc = rightChild(pos);
				if(rc<length&&number[j]>number[rc])   //取得左右孩子中值最小的那一个的位置  
					j = rc;                          
				
				if(number[pos]<number[j]) return;     //若最小的那一个大于父亲节点，则符合小顶堆性质，不用调整， 
				
				swap(pos,j);                         //否则便交换 
				
				/*
				   换完之后，需要对交换过的所有子树进行调整，直至调整到叶子，是一个迭代过程 
				*/ 
				pos = j;        
			}
		}
		
		bool isLeaf(int pos)           //若该位置结点的儿子位置大于整个数组长度，则它为叶子 
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
		
		bool removeMin(int & it)             //移除堆顶元素的操作 
		{
			if(length == 0) return false;
			swap(0,--length);
			if(length!=0) siftup(0);          //对改变过的位置重新进行平衡 
			it = number[length];
			return true;
		}
		
		bool insert(const int val)         //插入元素 
		{
			if(length>1000) return false;
			int curr = length++;
			number[curr] = val;          //从末尾插入元素 
			
			while(curr!=0&&number[curr]<number[(curr-1)/2])   //对插入的元素进行迭代调整，若比父亲还小，则交换 
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
	MinHeap m_heap(array,n);          //将测试数组调整为小顶堆 
} 