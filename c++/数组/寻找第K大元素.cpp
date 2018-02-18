#include<iostream>

using namespace std;

/**
*	Ŀ�ģ���һ����������ѡ��һ����K��������Ҵ�ӡ��������ʱ�临�Ӷ�Ҫ����(n); 
*	����������������ÿ��ŵ����ԣ���ѡ���pivot����parition����±���ܿ�����
*	pivot��Ӧ�����������д��ڵڼ��󣬾Ϳɽ������ 

**/

int findPivot(int le,int ri)        //����ÿ����Ҫpartition��֧���λ�� 
{
	return ri;
}

void swap(int *v,int a,int b)         
{
	int temp = v[b];
	v[b] = v[a];
	v[a] = temp;
}



/*
	����������ؼ���һ�����ڴ�partition�У������ݴ��ڵ���v[pivot]��ֵ�ŵ���ߣ���
	С��v[pivot]��ֵ�ŵ��ұߣ����Ӵ�С���� 
		*/ 
int partition(int *v,int le,int ri)
{
	int temp = v[le];
	while(le < ri)
	{
		while(v[ri] < temp) ri--;
		while(le<ri&&v[le] >= temp) le++;
		swap(v,le,ri); 
	}
	return le;
}

int KthLargestElementinanArray(int *v,int le,int ri,int k)
{
	if(k > ri + 1) return 0;          //��Kֵ�������鳤�ȣ��򷵻ش��� 
	
	int pivot = findPivot(le,ri);           
	swap(v,pivot,le);							//�ҵ�֧��λ�ã�������ֵ������������ǰ�棬�Է���partition��ʵ�� 
	
	int temp = partition(v,le,ri);
	swap(v,temp,le);						//����partition���ҵ�pivotֵ��������Ӧ�ô��ڵ�λ�ò�������ͷ���佻����ȥ 
	
	/*
		ȷ��tempλ��������ĵ�K��Ԫ�صĹ�ϵ��Ȼ��ȷ������ֵ 
		*/ 
	 
	if(temp == k - 1) return v[temp];
	else if(k-1 < temp)
			return KthLargestElementinanArray(v,le,temp-1,k);
	else
		return KthLargestElementinanArray(v,temp+1,ri,k);
}

int main() 
{
	int a[8] = {5,34,2,5,541,-454,22,6};
	int k = 8;
	cout<<KthLargestElementinanArray(a,0,7,k);
}