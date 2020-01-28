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
#include <cassert>
#include <bitset>
using namespace std;
vector<int>factor[1000010];
vector<int>divisor(1000001);
vector<int>prime;
void siv(void){
    for(int i=1;i<=1000000;++i){
        for(int j=i;j<=1000000;j+=i){
            ++divisor[j];
        }
    }
    for(int i=2;i<=1000000;++i){
        if(factor[i].size()==0){
            for(int j=i;j<=1000000;j+=i){
                factor[j].push_back(i);
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    siv();
    int counter{};
    for(int i=1;i<=1000000;++i){
        int x = divisor[i];
        if(factor[x].size()==2 && factor[x][0] * factor[x][1] == x){
            counter++;
            if(counter%9==0){
                cout<<i<<endl;
            }
        }
    }
    return 0;
}
