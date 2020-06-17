//  Author : Amit Kumar 

#include <iostream>
#include <algorithm> 
#include <string> 
#include <sstream>
#include <fstream>
#include <iomanip> 
#include <chrono> 
#include <numeric> 
#include <utility>
#include <functional>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <deque>
#include <list>


#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
using namespace __gnu_pbds;
template<typename TypeInfo>
using new_set = tree< 
/* ob.order_of_key(element) -> number of element strictly less than element
 * *ob.find_by_order(n) ->  nth element in increasing order
 */
         TypeInfo ,
         null_type ,
         less<TypeInfo> ,
         rb_tree_tag ,
         tree_order_statistics_node_update 
 > ;

void debug_out() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void debug_out(HEAD H, TAIL... T) {
  cerr << " " << (H);
  debug_out(T...);
}
 
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 


const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD  = (int)1e9+7;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}


int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            //
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int t; cin >> t; 
    while(t--){
        int64_t n; cin >> n;
        if(MillerRabin(n)){
            cout <<"YES";
        }else{
            cout <<"NO";
        }
        cout << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
