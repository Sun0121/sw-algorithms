

/*

**  数组洗牌：要求将原来的数组的原顺序打乱，按随机顺序重新组合数组

*/

#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int ARRAY_SIZE = 54;      //定义数组大小，刚好一副扑克牌的数目 

/*
	第一种思路，以扑克牌为例，首先规定编号，0到53号扑克牌，先随机得到[1,53]中的一个数，然后与
	牌头第一个数0号牌交换，然后0号牌固定，然后在从[2,53]号中取出一个随机数，再与牌头1交换，然
	后1号牌固定，以此类推，直至最后，[0,51]号牌均已固定，再从[53,53]中随机取出一数与52号交换
	，则52与53号都同时固定。 
*/ 

int GetRandNumInRange(int min,int max)            //获取随机数函数 
{
	int result = rand()%(max - min + 1) +  min;       //获取区间在[min,max]之间的随机数 
	return result;
}

void IndexShuffle(int* Array)
{
	for(int i = 0;i < ARRAY_SIZE-1;++ i)            //一共进行ARRAY_SIZE-1次交换 
	{
		int randomIndex = GetRandNumInRange(i+1,ARRAY_SIZE-1);   //获取[i+1,ARRAY_SIZE-1]间的随机数 
		swap(Array[i],Array[randomIndex]);
	}
}

/*
	第二种思路： 新建一个数组用来存储洗牌后的数组，用原数组中的数对新数组进行随机赋值，当新数组已满
	时退出循环，为了避免发生重复的情况，定义一个数组来记录随机数的产生情况，若该值为true,则证明已经
	产生过而不能再用了，此时就要寻找下一个随机数 
	
*/

void CheckedShuffle(int* Array)
{
	int newArray[ARRAY_SIZE];        //新数组 
	bool assigned[ARRAY_SIZE];       //标记数组 
	
	for(int i = 0;i < ARRAY_SIZE;++ i)           
		assigned[i] = false;
	
	for(int i = 0;i < ARRAY_SIZE;++ i)
	{
		int destIndex = 0;               //定义随机数 
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
	 
	for(int i = 0;i<ARRAY_SIZE;++ i)                  //测试数据 
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

	 