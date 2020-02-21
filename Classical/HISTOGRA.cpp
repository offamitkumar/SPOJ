#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; 
    while(cin>>n){
        long long area{} , max_Area{};
        if(n==0){
            return 0;
        }
        vector<long long>v(n);
        for(auto&itr:v){
            cin>>itr;
        }
        stack<long long>st;
        int i;
        for(i=0;i<n;){
            if((st.empty()) or  v[st.top()]<=v[i]){
                st.push(i++);
            }else{
                int tp = st.top();st.pop();
                if(st.empty()){
                    area = v[tp]*i;
                }else{
                    area = v[tp]*(i-st.top()-1);
                }
            }
            max_Area = max(area , max_Area);
        }
        while(!st.empty()){
            int tp = st.top();st.pop();
            if(st.empty()){
                area = v[tp]*i;
            }else{
                area = v[tp]*(i-st.top()-1);
            }
            max_Area = max(max_Area , area);
        }
        cout<<max_Area<<endl;
    }

    return 0;
}
