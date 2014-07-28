#include<stdio.h>
#include<iostream>
using namespace std;
int a[100];
int partition_func(int left,int right)
{
    int i=left-1;
    for(int j=left;j<=right-1;j++)
    {
        if(a[j]<=a[right])
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[i],a[right]);
    return i;
}
int median(int left,int right,int kth)
{
    while(1)
    {
        int partI= partition_func(left,right);
        int len= partI-left+1;
        if(len==kth)
            return a[partI];
        if(kth<len)
        {
            right= partI-1;
        }
        else
        {
            left=partI+1;
            kth=kth-len;
        }
    }
}
main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<median(1,n,k)<<endl;
    return 0;
}
