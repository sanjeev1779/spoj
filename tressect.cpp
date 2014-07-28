#define LL long long
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void computeLPSArray(string pat, int M, int *lps);

int KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
        return 1;
        j = lps[j-1];
      }

      // mismatch after j matches
      else if(pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
    return 0;
}

void computeLPSArray(string pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
// Driver program to test above function
int main()
{
   int t,N,i;
   LL last,cur;
   cin>>t;
   string pat;
   while(t--)
    {
        cin>>N;
        cin>>last;
        string text="";
        for(i=1;i<N;i++)
        {
            cin>>cur;
            if(cur>last)
                text+='G';
            else if(cur<last)
                text+='L';
            else text+='E';
            last=cur;
        }
        cin>>pat;
        int x=KMPSearch(pat,text);
        if(x) printf("YES\n");
        else printf("NO\n");

    }
   return 0;
}
