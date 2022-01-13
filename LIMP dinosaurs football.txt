#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, N, K;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        for(int i=N-K; i<=N; i++)
            cout<<i<<" ";
        for(int i=1; i<N-K; i++)
            cout<<i<<" ";
    }
    return 0;
}