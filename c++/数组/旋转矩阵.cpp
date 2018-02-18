#include<iostream>

using namespace std;

/*
*	旋转矩阵：此列中将矩阵顺时针旋转90度，若要旋转180度，270度则多次旋转就可
*	若要逆时针旋转，则相应的改变旋转顺序就可， 
	 
	*/

/* 
	基本思路，按矩阵从最外层至最内层一层一层的旋转，即从第0层到第n/2层，
	对于每一层，先将上层数据保存下来，将左层的放到上层，再将下层放到左
	层，然后将右层放到下层，最后将上层放到右层，则一层转换完毕。 
	 
	*/ 

void rotate(int** v,int n)
{
	for(int i = 0;i < n/2;++ i)            // i表示层数 
	
		for(int j = i;j<n-1-i;++ j)          // j为每一层的转化辅助量 
		{
			int temp = v[i][j];            //将上层数据保存 
			
			v[i][j] = v[n-1-j][i];        //将左层数据放到上层 
			
			v[n-1-j][i] = v[n-1-i][n-1-j];      //将下层数据放到左层 
			
			v[n-1-i][n-1-j] = v[j][n-1-i];      //将右层数据放到下层 
			
			v[j][n-1-i] =  temp;                //将上层放到右层 
		}
}

int main()
{
	int **a;
	a = new int*[5];
	for(int i = 0;i<5;++ i)
		a[i] = new int[5];
		
	for(int i = 0,temp = 1;i<5;++ i)               //准备测试矩阵 
		for(int j = 0;j<5;++ j)
			a[i][j] = temp++;
			
			
			
	for(int i = 0;i<5;++ i)                      //输出原矩阵 
	{
		for(int j = 0;j<5;++ j)
		{
			cout<<a[i][j]<<" "; 
		}
		cout<<endl;
	}
	
	rotate(a,5);                              //旋转矩阵 
	
	cout<<endl;
	
	for(int i = 0;i<5;++ i)                //输出旋转后矩阵 
	{
		for(int j = 0;j<5;++ j)
		{
			cout<<a[i][j]<<" "; 
		}
		cout<<endl;
	}
} 