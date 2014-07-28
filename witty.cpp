#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
#define traverse_map(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
using namespace std;
int gcd(int a, int b){ int temp; while(b>0)	{ temp= b; b=a%b; a=temp;}	return a;}
main()
{
       //   freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
      int i,j,t,N,M,val;
      string frnd;
      S(t);
      while(t--)
      {
          string fr1,fr2;
            map<string,int>ma; // for mapping friends to their values
            S(N);
            for(i=0;i<N;i++)
            {
                cin>>fr1>>fr2>>M;
                ma[fr1]+=M; // if he gives money to someone , then add to it
                ma[fr2]-=M; // subtract who take money (as a loan)
            }
            vector<int>vec; // it will store values of all friends who are in the sharing
            vector<int>zero[65]; //it will store all subsets of the above vector set such that the sum of values of all elements is zero

            traverse_map(ma,it)
            {
                frnd= (*it).first;
                val = (*it).second;
                if(val!=0) // if he has to take or give some money
                {
                    vec.pb(val); // add to the set
                }
            }
            int l =vec.size(); // size of the set
           // printf("number of elements in the set= %d\n",l);
           // for(i=0;i<l;i++)printf("%d ",vec[i]);
            //printf("\n");

            int subset= 1<<l; //  there are 2^N subsets of a set of length N
          //  printf("number of subsets= %d\n",subset);
            int flag,k,siz,ele;
            int cnt=0;

            // now generate all subsets ( a standard method for generating all subsets of a set, u can search online for its implementation)
            for(i=0;i<subset;i++) // for all subsets 2^N
            {
                int sum=0,x=0;
                for(j=0;j<l;j++)  // check for each element in the list
                {
                    if(i & 1<<j) // if the j bit is set (1), then jth element is in the set
                    {
                        sum+=vec[j]; // sum stores sum of the subset
                        x++; // it stores size of the subset
                    }

                }
                if(sum==0 && x>0) // if the sum of the subset is zero and size should be >0 (mentioned in the problem)
                {
                    for(j=0;j<l;j++) // same as above code , add all elements of  the subset in the zero vector
                    {
                        if(i & 1<<j)
                        {
                            zero[cnt].pb(j);
                        }
                    }
                    cnt++; // increase the number of subsets whose sum is zero
                }
            }


            // here i don't get any idea, how to optimize this part, but the size of the set is very very small, so no problem for this code :)
          // cnt stores the number of subsets whose sum is zero

          // ### Now, we have "cnt" different subsets whose sum is zero, we have to divide the set stored in vector vec above, in maximum number of disjoints subsets



            subset= 1<<cnt;
//
//            for(i=0;i<cnt;i++)
//            {
//                for(j=0;j<zero[i].size();j++)
//                {
//                    printf("%d ",zero[i][j]);
//                }
//                printf("\n");
//            }
//        //    printf("No. of subsets= %d\n",subset);


// similar to above, enummerate over all subsets, and check for disjoint condition, since one element cannot be a part of more than one subset.

            int freq[8]; // for check disjoint condition, there are at most 6 frnds. Each element should appear only once in the set, if not , then it is not disjoint
            int parts,P=0;
            for(i=0;i<subset;i++) // iterative over all subsets
            {
                memset(freq,0,sizeof(freq)); // set freq to 0
                flag=0;
                parts=0;
                for(j=0;j<cnt;j++) // iterative over all subsets of sum 0
                {
                    if(i & 1<<j)
                    {
                        siz= zero[j].size(); // the jth zero-sum subset have siz elements.
                        for(k=0;k<siz;k++) // check each element has not already come in the take set
                        {
                            ele=zero[j][k];
                            if(freq[ele]>0) // element already present, break
                            {
                                flag=1; break; // not disjoint
                            }
                            freq[ele]++; // incresing its frequncy
                        }
                        parts++; // number of zero- sum subsets in the whole set
                    }
                    if(flag==1)break;// not disjoint subsets
                    P= max(P,parts); // take the maximum cardinality of the set
                }
            }
            l = vec.size(); // total number of men participate in taking or giving
            int ans= l-P; // as explained in topcoder forum
            P(ans) // print the ans
      }
return 0;
}
