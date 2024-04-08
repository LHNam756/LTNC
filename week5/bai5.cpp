#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
using namespace std;

map<int,int> mp;
int main() {
    int A[1000];
    int B[1000];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        mp[B[i]]++;
    }
    for(int i=1;i<=n+1;i++)
    {
        cin>>B[i];
        if(mp[B[i]]==0) cout<<B[i];
        else mp[b[i]]--;

    }
    return 0;
}
