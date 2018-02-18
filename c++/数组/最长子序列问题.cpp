#include<iostream>
#include<stack>

using namespace std; 

/*

*	������������е�����,�����ڵ����ݲ���Ҫ������	

*/  

/*
	
	��һ��˼·����̬�滮������������array[0,i]������������У���������array[0,i-1]�������������
	����һ������lis[n],lis[i]������¼����array[0,i]������������еĳ��ȣ�������巽�����´��벿�� 
	
	*/
void lengthOfLIS1(int *v,int n)
{
	int *lis = new int[n];                 //����洢���ȵ����� 
	for(int i = 0;i<n;++ i)
		lis[i] = 1;
		
	for(int i = 1;i < n;++ i)               //��ÿһ���±�Ϊi��������lis 
		for(int j = 0;j<i;++ j)
			if(v[j]<v[i] && lis[i]<lis[j] + 1)           //��lis,���Ӷ�Ϊn^2 
			{
				lis[i] = lis[j] + 1;
			}
		
	int max = 0;
	for(int i = 0;i<n;++ i)
		if(lis[i]>max)
			max = lis[i];               
			
	cout<<max<<endl;    
} 




int main()
{
	int a[8] = {-1,5,-4,3,6,2,9,7};
	lengthOfLIS1(a,8);
}




/*
	#include <iostream> 
#include <algorithm> 
 
using namespace std; 
 
#define MAXN 1003 
int A[MAXN]; 
int MaxV[MAXN]; 
 
// ��̬�滮�㷨O(nlogn) 
int main() 
{ 
    int n, i, j, k; 
    cin >> n; 
    for (i=1; i<=n; i++) 
        cin >> A[i]; 
    MaxV[1] = A[1]; 
    int nmaxv = 1;  // Ŀǰ�ҵ�������������еĳ��� 
    // ��n���׶Σ�ÿ���׶���1��״̬ 
    for (i=2; i<=n; i++) 
    { 
        // ÿ��״̬��nmaxv�־��ߣ��Եó���Ԫ��i��β����ݹ������еĳ��� 
        int u = 1, v = nmaxv; 
        while (u<=v) 
        { 
            int mid = (u+v)>>1; 
            if (MaxV[mid] < A[i]) 
                u = mid+1; 
            else 
                v = mid-1; 
        } 
 
        // ÿ��Ԫ�ض��������MaxV�е�ĳ��Ԫ�ز���Ӱ�� 
        // ʹ�ö�������ȷ�����ڵ�v+1��λ�� 
        nmaxv = max(nmaxv, v+1); 
        MaxV[v+1] = A[i]; 
    } 
    cout << nmaxv; 
} 

	*/