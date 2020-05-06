#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN 1010
array<int , MAXN> arr;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    int case_counter{1};
    while(t--){
         long long N , f;
         cin>>N>>f;
         for(auto i=0;i<f;++i){
             cin>>arr[i];
         }
         sort(arr.begin() ,arr.begin()+f , greater<int>());
         long long sum{};
         auto i = 0;
         for(i=0;i<f;++i){
             sum+=arr[i];
             if(sum>=N)
                 break;
         }
         printf("Scenario #%d:\n",case_counter++);
         if(i==f){
             cout<<"impossible";
         }else{
             cout<<i+1;
         }
         cout<<'\n';
    }
    return 0;
}
