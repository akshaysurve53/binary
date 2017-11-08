#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[],int low,int high,int mid);
void mergesort(int a[],int low,int high);
int binarysearch(int a[],int low,int high,int key);
int n;
int binarysearch(int a[],int low,int high,int key)
{	if(high>=low)
	{
	int mid=(low+high)/2;
	if(key==a[mid])
	{
		return mid;
	}
	if(a[mid]<key)
	{
	return binarysearch(a,mid+1,high,key);
	}
	else
	{
	return binarysearch(a,low,mid-1,key);
	}
	}
	return -1;
}

void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
	 mid=(low+high)/2;
	 mergesort(a,low,mid);
	 mergesort(a,mid+1,high);
	 merge(a,low,high,mid);
	}
	return;
}

void merge(int a[],int low,int high,int mid)
{
	int i,j,k,c[n];
	i=low;
	k=low;
	j=mid+1;
	while(i<=mid&&i<=high)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else
		{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	
	while(i<=mid)
	{
		c[k]=a[i];
		k++;
		i++;
	}
		
	while(j<=high)
	{
		c[k]=a[j];
		k++;
		j++;
	}
	for(i=low;i<k;i++)
	{
		a[i]=c[i];
	}
}

int main()
{
	printf("\nenter n:");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i]=(rand()%n)+1;
		printf("\t%d",a[i]);
	}
	mergesort(a,0,n-1);
	printf("\nsorted array is:");
	for(int i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	int key;
	printf("\n enter no to be search:");
	scanf("%d",&key);
	int loc=binarysearch(a,0,n-1,key);
	if(loc==-1)
	{
	printf("No not found");
	}
	else
	printf("\n%d found at location:%d",key,loc);
	return 0;
} 
