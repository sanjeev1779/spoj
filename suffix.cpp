//Naive algorithm for the construction of the suffix array of a given string
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string s;
    map<string,int> m;
    cin >> s;
    vector<string> v;
    for(int i = 0; i < s.size();i++)
    {
        m[s.substr(i,s.size()-i)] = i;
        v.push_back(s.substr(i,s.size()-i));
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size();i++)
    {
        cout << m[v[i]]+1<< endl;
    }
    return 0;
}
