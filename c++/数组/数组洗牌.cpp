

/*

**  ����ϴ�ƣ�Ҫ��ԭ���������ԭ˳����ң������˳�������������

*/

#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int ARRAY_SIZE = 54;      //���������С���պ�һ���˿��Ƶ���Ŀ 

/*
	��һ��˼·�����˿���Ϊ�������ȹ涨��ţ�0��53���˿��ƣ�������õ�[1,53]�е�һ������Ȼ����
	��ͷ��һ����0���ƽ�����Ȼ��0���ƹ̶���Ȼ���ڴ�[2,53]����ȡ��һ���������������ͷ1������Ȼ
	��1���ƹ̶����Դ����ƣ�ֱ�����[0,51]���ƾ��ѹ̶����ٴ�[53,53]�����ȡ��һ����52�Ž���
	����52��53�Ŷ�ͬʱ�̶��� 
*/ 

int GetRandNumInRange(int min,int max)            //��ȡ��������� 
{
	int result = rand()%(max - min + 1) +  min;       //��ȡ������[min,max]֮�������� 
	return result;
}

void IndexShuffle(int* Array)
{
	for(int i = 0;i < ARRAY_SIZE-1;++ i)            //һ������ARRAY_SIZE-1�ν��� 
	{
		int randomIndex = GetRandNumInRange(i+1,ARRAY_SIZE-1);   //��ȡ[i+1,ARRAY_SIZE-1]�������� 
		swap(Array[i],Array[randomIndex]);
	}
}

/*
	�ڶ���˼·�� �½�һ�����������洢ϴ�ƺ�����飬��ԭ�����е�������������������ֵ��������������
	ʱ�˳�ѭ����Ϊ�˱��ⷢ���ظ������������һ����������¼������Ĳ������������ֵΪtrue,��֤���Ѿ�
	�����������������ˣ���ʱ��ҪѰ����һ������� 
	
*/

void CheckedShuffle(int* Array)
{
	int newArray[ARRAY_SIZE];        //������ 
	bool assigned[ARRAY_SIZE];       //������� 
	
	for(int i = 0;i < ARRAY_SIZE;++ i)           
		assigned[i] = false;
	
	for(int i = 0;i < ARRAY_SIZE;++ i)
	{
		int destIndex = 0;               //��������� 
		bool foundIndex = false;
		
		while(foundIndex == false)
		{
			destIndex = rand()%ARRAY_SIZE;
			
			if(assigned[destIndex] == false)
				foundIndex = true;
		}
		
		assigned[destIndex] = true;
		
		newArray[i] = Array[destIndex];
	}
	
	memcpy(Array,newArray,sizeof(newArray));
} 

int main()
{
	int array[ARRAY_SIZE];
	int n = 1;
	 
	for(int i = 0;i<ARRAY_SIZE;++ i)                  //�������� 
		array[i] = n++;
	
	for(int i = 0; i < ARRAY_SIZE;++ i)
	{
		cout<<array[i]<<" ";
		if(i % 6 == 5)
			cout<<endl;
	}
	cout<<endl;
	
	IndexShuffle(array);
	
	for(int i = 0; i < ARRAY_SIZE;++ i)
	{
		cout<<array[i]<<" ";
		if(i % 6 == 5)
			cout<<endl;
	}
	cout<<endl;
	
	CheckedShuffle(array);
	
	for(int i = 0; i < ARRAY_SIZE;++ i)
	{
		cout<<array[i]<<" ";
		if(i % 6 == 5)
			cout<<endl;
	}
} 

	 