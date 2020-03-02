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
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define MOD 1000000007
#define MAXN 2002
long long dp[MAXN][MAXN];
string a , b; 
int n;
int edit(int current_a_index , int current_b_index){
    if((int)a.size()==current_a_index && (int)b.size()==current_b_index){
        return 0;
    }
    if((int)a.size()==current_a_index){
        return n*(b.size()-current_b_index);
    }
    if((int)b.size()==current_b_index){
        return n*(a.size()-current_a_index);
    }
    if(dp[current_a_index][current_b_index]!=-1){
        //cerr<<"found in dp"<<endl;
        return dp[current_a_index][current_b_index];
    }
    return dp[current_a_index][current_b_index]=min({edit(current_a_index+1,current_b_index+1)+abs(a[current_a_index]-b[current_b_index]),edit(current_a_index+1,current_b_index)+n,edit(current_a_index,current_b_index+1)+n});
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    cin>>a>>b;
    memset(dp ,-1 , sizeof(dp));
    cin>>n;
    cout<<edit(0,0)<<endl;
    return 0;
}
