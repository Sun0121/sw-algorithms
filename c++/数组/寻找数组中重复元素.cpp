#include<iostream>

#include<algorithm>			//sort函数头文件 
#include<set>				//STL中的set容器的头文件 
#include<cstring>          //memset函数头文件 

using namespace std;

/**
	
*	寻找数组中重复的元素

**/ 

/*
	
	第一种思路：最暴力的解法，对每一个数组中的元素都与其他元素进行一次比较
	然后若发现有重复元素的情况，就将该元素加入到set中(这里使用set的原因是为
	避免加入相同元素出现重复的情况)，时间复杂度是n的平方 
	
	*/ 

void findSameElement1(int *v,int n)
{
	set<int> my_set; 
	
	for(int i = 0;i<n;++ i)
		for(int j = 0;j < n;++ j)
			if(i != j && v[i] == v[j])         //判断重复元素 
				my_set.insert(v[i]);
	
	set<int>::iterator it;
	for(it = my_set.begin();it != my_set.end();++ it)
		cout<<*it<<" ";
}
 
/*
	第二种思路：对第一种思路进行了一次优化，即首先对数组进行排序，然后再比较
	前后元素是否相同，仍用set来进行存储 
	
	*/ 
	
void findSameElement2(int *v,int n)
{
	set<int> my_set;
	
	sort(v,v+n);
	
	for(int i = 1;i<n;++ i)
		if(v[i] == v[i-1])
			my_set.insert(v[i]);
			
	set<int>::iterator it;
	for(it = my_set.begin();it != my_set.end();++ it)
		cout<<*it<<" ";
} 

/*
	第三种思路：利用哈希表的想法，但此方法有使用条件，对于大小为n的数组，
	里面存储的数据范围只能是由0 -- n-1，这样的话，数组里面的每一个数都对
	应数组的一个下标，那就重新开一个与原数组同样大小的数组，新数组用来统
	计原数组中每个数出现的频率，最后再遍历一遍原数组，若发现该数的出现频
	率大于一，那便将其添加到set中 
	
	*/


void findSameElement3(int *v,int n)
{
	set<int> my_set;
	
	int *p;
	p = new int [10000000];
	memset(p,0,sizeof(int)*10000000);
	
	for(int i = 0;i < n;++ i)
		p[v[i]]++;
	
	for(int i = 0;i<n;++ i)
		if(p[v[i]] > 1)
			my_set.insert(v[i]);
	
	set<int>::iterator it;
	for(it = my_set.begin();it != my_set.end();++ it)
		cout<<*it<<" ";
}


int main()
{
  /*	int a[8] = {1,84,1,8,12,81,5,8};        //此处用于测试前两种方法 
		findSameElement1(a,8);
		cout<<endl;
		findSameElement2(a,8);
		cout<<endl;                       */
		
		
	int *p,temp,i = 0;                        //此用来测试第三种方法，即运用哈希表的思想 
	p = new int[10000000];					//数组里面的各数取值范围是0-9999999 
	
	while(cin>>temp)					//输入测试数据，碰到换行符截止 
	{
		p[i++] = temp;
		char ch = cin.get();
		if(ch == '\n'||ch == '\r')
			break;
	}
	
	int len = i;
	findSameElement3(p,len);
}