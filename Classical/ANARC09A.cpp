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
    string s;
    int _=1;
    for(;cin>>s;++_){
        if(s[0]=='-'){
            return 0;
        }
        cout<<_<<". ";
        stack<char>st;
        int counter{};
        for(int i=0;i<(int)s.size();++i){
            if(st.empty()){
                if(s[i]=='{'){
                    st.push('{');
                }else{
                    counter++;
                    st.push('{');
                }
 
            }else{
                if(s[i]=='{'){
                    st.push('{');
                }else{
                    st.pop();
                }
            }
        }
        cout<<counter+(st.size())/2<<endl;
    }

    return 0;
}
