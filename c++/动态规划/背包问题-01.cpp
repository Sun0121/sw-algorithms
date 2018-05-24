#include<iostream>

using namespace std;


/*

*	问题： 有一个窃贼在偷窃一家商店时发现有n件物品，第i件物品价值为vi元，重量为wi，假设vi和wi都为整数。他希望带走的东西越值钱越好，
*	但他的背包中之多只能装下W磅的东西，W为一整数。他应该带走哪几样东西？

*	0-1背包问题：每件物品或被带走，或被留下，（需要做出0-1选择）。小偷不能只带走某个物品的一部分或带走两次以上同一个物品。

*/

int knapSackRecu(int w, int val[], int wt[], int n) {            //递归解决，遍历所有可能取到的情况，找出最大的一种 
	
	if(w <= 0 || n <= 0) return 0;          
	
	if(wt[n-1] > w)
		return knapSackRecu(w, val, wt, n-1);
	
	return max(knapSackRecu(w, val, wt, n-1),val[n-1] + knapSackRecu(w - wt[n-1], val, wt, n-1));
	
}

/*

*	动态规划：定义一个二维数组，a[i][j] 记录当前背包容量为i,物品数目为j的当前最优解，
*	采取自下而上的解决方式，将问题分解为要不要拿最后一件物品 

*/

int knapSack(int w, int val[], int wt[], int n) {
	
	int a[w+1][n+1];
	
	for(int i = 0; i <= n;++ i)
		a[0][i] = 0;                  //背包容量为0时，总价值为0 
	
	for(int i = 1;i <= w;++ i)
		a[i][0] = 0;                     //当物品数目为0时，总价值为0
	
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