#include<iostream>
#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

void bubble(int arr[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        #pragma omp parallel for shred(arr,0)
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
    cout<<"\nSorted array is :";
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<arr[i];
    }
}

int main()
{
    int *a,n;
    cout<<"\nEnter how many elements :";
    cin>>n;
    
    a=new int[n];
    
    cout<<"\nEnter nos :";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    auto start=chrono::high_resolution_clock::now();
	#pragma omp parallel num_threads(4)
	{
	    bubble(a,n);
	}
	auto stop=chrono::high_resolution_clock::now();
	auto result=stop-start;
	auto duration=chrono::duration_cast<chrono::milliseconds>(result);
	cout<<"\nBB :"<<to_string(duration.count())<<"ms";

    
    return 0;
}