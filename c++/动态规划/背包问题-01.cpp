#include<iostream>

using namespace std;


/*

*	���⣺ ��һ��������͵��һ���̵�ʱ������n����Ʒ����i����Ʒ��ֵΪviԪ������Ϊwi������vi��wi��Ϊ��������ϣ�����ߵĶ���ԽֵǮԽ�ã�
*	�����ı�����֮��ֻ��װ��W���Ķ�����WΪһ��������Ӧ�ô����ļ���������

*	0-1�������⣺ÿ����Ʒ�򱻴��ߣ������£�����Ҫ����0-1ѡ�񣩡�С͵����ֻ����ĳ����Ʒ��һ���ֻ������������ͬһ����Ʒ��

*/

int knapSackRecu(int w, int val[], int wt[], int n) {            //�ݹ������������п���ȡ����������ҳ�����һ�� 
	
	if(w <= 0 || n <= 0) return 0;          
	
	if(wt[n-1] > w)
		return knapSackRecu(w, val, wt, n-1);
	
	return max(knapSackRecu(w, val, wt, n-1),val[n-1] + knapSackRecu(w - wt[n-1], val, wt, n-1));
	
}

/*

*	��̬�滮������һ����ά���飬a[i][j] ��¼��ǰ��������Ϊi,��Ʒ��ĿΪj�ĵ�ǰ���Ž⣬
*	��ȡ���¶��ϵĽ����ʽ��������ֽ�ΪҪ��Ҫ�����һ����Ʒ 

*/

int knapSack(int w, int val[], int wt[], int n) {
	
	int a[w+1][n+1];
	
	for(int i = 0; i <= n;++ i)
		a[0][i] = 0;                  //��������Ϊ0ʱ���ܼ�ֵΪ0 
	
	for(int i = 1;i <= w;++ i)
		a[i][0] = 0;                     //����Ʒ��ĿΪ0ʱ���ܼ�ֵΪ0
	
	for(int i = 1;i <= w;++ i)
		for(int j = 1;j <= n;++ j)
		{
			a[i][j] = a[i][j-1];
			
			if(w >= wt[j-1]) {
				a[i][j] = max(val[j-1] + a[i - wt[j-1]][j-1], a[i][j-1]);
			}
		}
		
	return a[w][n]; 
}

int main()
{
	int val[] = {200, 250, 140, 150};  
    int wt[] = {1, 3, 2,5};  
    int W = 5;
    cout<<knapSack(W, val, wt, 4);
}