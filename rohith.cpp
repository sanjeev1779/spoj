#include<stdio.h>
#include<string.h>
#include<limits.h>
int min(int a,int b)
{
if(a<b)
return a;
else
return b;
}
int ch(int a[],int n)
{
int i,j,z,k;
int b[n];
b[0]=0;
for(i=1;i<n;i++)
b[i]=100000;
int u=2;
while(u--)
{

for(i=1;i<n;i++)
{
for(j=0;j<i;j++)
{
if(a[i]==a[j] && b[i]>b[j]+1)
b[i]=1+b[j];
}
if(i<n-1)
z=1+min(b[i-1],b[i+1]);
else if(i==n-1)
z=1+b[i-1];
if(b[i]>z)
b[i]=z;
}
for(i=1;i<n;i++)
{
for(j=n-1;j>i;j--)
{
if(a[i]==a[j] && b[i]>b[j]+1)
b[i]=b[j]+1;
}
if(i<n-1)
z=1+min(b[i-1],b[i+1]);
else if(i==n-1)
z=1+b[i-1];
if(b[i]>z)
b[i]=z;

}
/*for(k=0;k<n;k++)
printf("%d ",b[k]);
printf("\n");*/
}
return b[n-1];
}
main()
{
int a[100050];
char s[100050];
int l,i=0;
scanf("%s",s);
l=strlen(s);
for(i=0;i<l;i++)
a[i]=s[i]-'0';
printf("%d\n",ch(a,l));
return 0;
}
