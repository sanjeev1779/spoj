#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;
main()
{
    int t,k,p,i,j,flag;
    cin>>t;
    long int first[505][2],sec[2505][2],N,l1,l2;
    while(t--)
    {
        int visited[2505];
        memset(visited,0,sizeof(visited));
        cin>>N>>k>>p;
        for(i=0;i<k;i++)
        {
             scanf("%ld %ld",&first[i][0],&first[i][1]);
        }
        for(i=0;i<p;i++)
            scanf("%ld %ld",&sec[i][0],&sec[i][1]);
        flag=0;
        for(i=0;i<k;i++)
        {
           // cout<<"first= "<<first[i][0]<<" "<<first[i][1]<<endl;
            flag=0;
            /*for(j=0;j<p;j++)
            {
                printf("%d = %d %ld %ld\n",j,visited[j],sec[j][0],sec[j][1]);
            }*/
              if(first[i][0]<=first[i][1])
                 l1= first[i][1]-first[i][0]+1;
            else
                l1= N- first[i][0]+1+first[i][1];
            for(j=0;j<p;j++)
            {

                 if(sec[j][0]<=sec[j][1])
                    l2= sec[j][1]-sec[j][0]+1;
                else
                    l2= N- sec[j][0]+1+sec[j][1];
                if(l2<l1)continue;
                if(visited[j]==0)
                {
                     // cout<<"sec= "<<j<<" "<<sec[j][0]<<" "<<sec[j][1]<<endl;
                        //first rotation
                        if(sec[j][0]==1 && sec[j][1]==N)
                        {
                          //  cout<<"complete\n";

                            if(first[i][0]<=first[i][1])
                            {
                                 visited[j]=1; flag=1;
                                if(first[i][0]==1 && first[i][1]==N)continue;
                                else
                                {
                                    if(first[i][0]!=1) { sec[p][0]=1; sec[p][1]= first[i][0]-1; p++;}
                                    if(first[i][1]!=N) {sec[p][0]= first[i][1]+1;  sec[p][1]=N; p++;}
                                }
                                break;
                            }
                            else
                            {
                                flag=0; break;
                            }

                        }
                        else if(first[i][0]<=first[i][1]) // first
                        {
                            if(sec[j][0]<=sec[j][1])
                            {

                                if(sec[j][0]<=first[i][0] && first[i][1]<=sec[j][1]) // for clockwise same direction // matched
                                {
                                   // cout<<"11\n";
                                  //  cout<<i<<endl;
                                    flag=1; visited[j]=1;
                                    if(sec[j][0]<first[i][0])
                                    {
                                        sec[p][0]=sec[j][0]; sec[p][1]=first[i][0]-1; p++;
                                    }
                                    if(sec[j][1]>first[i][1])
                                    {
                                        sec[p][0]=first[i][1]+1;    sec[p][1]=sec[j][1];  p++;
                                    }
                                    break;
                                }
                            }
                            else
                            {


                                if(sec[j][0]<=first[i][0])
                                {
                                   // cout<<"12\n";
                                    flag=1;visited[j]=1;
                                    if(sec[j][0]<first[i][0])
                                    {
                                        sec[p][0]=sec[j][0]; sec[p][1]= first[i][0]-1; p++;
                                    }
                                    if(sec[j][1]<first[i][1])
                                    {
                                        if(first[i][1]!=N) sec[p][0]=first[i][1]+1;    else sec[p][0]=1;
                                        sec[p][1]=sec[j][1]; p++;
                                    }
                                }
                            }
                         }

                         // 2nd rotation
                         else
                         {
                             if(sec[j][0]>sec[j][1])
                             {

                                if(sec[j][0]<=first[i][0] && first[i][1]<=sec[j][1]) // for clockwise same direction // matched
                                {
                                    // cout<<"22\n";
                                  //  cout<<i<<endl;
                                    flag=1; visited[j]=1;
                                    if(sec[j][0]<first[i][0])
                                    {
                                        sec[p][0]=sec[j][0]; sec[p][1]=first[i][0]-1; p++;
                                    }
                                    if(sec[j][1]>first[i][1])
                                    {
                                        sec[p][0]=first[i][1]+1;    sec[p][1]=sec[j][1];  p++;
                                    }
                                    break;
                                }
                             }
                             else if(sec[j][0]==sec[j][1])
                             {
                                 if(first[i][0]==first[i][1] && first[i][0]==sec[j][0])
                                 {
                                     flag=1; visited[j]=1;break;
                                 }
                             }
                         }
                }
            }
            if(flag==0) break;
        }
        if(flag==0)
            printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
