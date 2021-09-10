#include <bits/stdc++.h>
using namespace std;
typedef long long int in;
int main(){
    int t;
    cin>>t;
    while(t--){
        in n;
        cin>>n;
        in count=0;
        if(n==1)count=0;
        else if(n==2)count=1;
        else if(n==3||n%2==0)count=2;
        else count=3;
        cout<<count<<endl;
    }
}