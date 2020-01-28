#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
using namespace std;
vector<int>prime;
bool ar[90000001];
void siv(void){
    int maxN = 90000000;
    ar[0]=ar[1]=true;
    for(int i=2;i*i<=maxN;++i){
        if(!ar[i]){
            for(int j=i*i;j<=maxN;j+=i){
                ar[j]=true;
            }
        }
    }
    for(int i=2;i<=maxN;++i){
        if(!ar[i]){
            prime.emplace_back(i);
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    siv();
    int q;cin>>q;
    while(q--){
        int n; cin>>n;
        cout<<prime[n-1]<<endl;
    }
    return 0;
}
