#include<iostream>
#include<string>

using namespace std;

/*

*	���ʷָ����һ�����ʼ��Ϻ�һ��ָ�����ַ������жϸ��ַ����ܷ񱻷ָ�ɼ�������ĵ��� 
*	���˼�룺��̬�滮������Ϊn���ַ���[0,n-1]�ܷ񱻷ָ���Ƚ��[0,n-2]�ܷ񱻷ָ[0,n-3],[0,n-4]�ܷ񱻷ָ�ȣ�
* 
*   ���ڶ�̬�滮��������ظ��ԣ���ˣ�������ĳ��������֮�󣬽����Ľ����¼����������һ��������������ʱ��ֱ�Ӳ������Ľ������������һ�μ���������⡣
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