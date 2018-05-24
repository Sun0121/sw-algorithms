#include<iostream>
#include<string>

using namespace std;

/*

*	单词分割：给出一个单词集合和一个指定的字符串，判断该字符串能否被分割成集合里面的单词 
*	解决思想：动态规划：长度为n的字符串[0,n-1]能否被分割，可先解决[0,n-2]能否被分割，[0,n-3],[0,n-4]能否被分割等，
* 
*   基于动态规划子问题的重复性，因此，在求解出某个子问题之后，将它的结果记录下来，当下一次再碰到此问题时，直接查找它的结果，而不是再一次计算该子问题。
*/ 

bool getAnswer(string set[], string key)
{
	int n = key.size();
	
	bool match[n+1];
	
	match[0] = 1;
	
	for(int i = 1;i < n + 1;++ i)
	{
		for(int j = 0;j < i;++ j){
			
			string s = key.substr(j,i - j);
			
			bool temp = false;
			
			for(int k = 0;k < 2;++ k )
			{
				if(s == set[k])
				{
					temp = true;
					break;
				}
			}
			
			if(match[j] && temp){
				match[i] = 1;
				break;
			}
		}
	}
	return match[n];
}

int main()
{
	string key = "leetcode";
	string set[] = {"leet","code"}; 
	cout<<getAnswer(set,key);	
}