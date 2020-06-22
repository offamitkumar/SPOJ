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

void show_me() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void show_me(HEAD H, TAIL... T) {
  cerr << " " << (H);
  show_me(T...);
}
 
#ifdef HELL_JUDGE
#define show(...) cerr << "[" << #__VA_ARGS__ << "]:", show_me(__VA_ARGS__)
#else
#define show(...) 0
#endif
 
template<typename A, typename B>
ostream& operator<<(ostream&out, const pair<A, B>&p){
    out << p.first << ' ' << p.second ;
    return out;
}

template<typename A, typename B>
istream& operator>>(istream&in, pair<A, B>&p){
    in >> p.first >> p.second ;
    return in;
}

template<typename A> 
istream& operator>>(istream&in, vector<A>&vec){
    for(auto&itr:vec){
        in >> itr;
    }
    return in;
}

template<typename A>
ostream& operator<<(ostream&out,const vector<A>&vec){
    for(auto&itr:vec){
        out << itr <<' '; // VVV 
    }
    return out;
}

const int MAXM = (int)1e5+100;
const int MOD  = (int)1e9+7;


const int N = 10000010;
int lp[N+1];
vector<int> pr;


void check2(int64_t &a){
    if(a<0){
        a = (a+MOD+MOD)%MOD;
    }
}
void check1(int64_t &a, int64_t &b){
    a%=MOD;
    b%=MOD;
    check2(a);
    check2(b);
}
int64_t mul(int64_t a, int64_t b){
    check1(a,b);
    int64_t temp = (a*b)%MOD;
    check2(temp);
    return temp;
}
int64_t add(int64_t a, int64_t b){
    check1(a,b);
    int64_t temp = (a+b)%MOD;
    check2(temp);
    return temp;
}
int64_t sub(int64_t a, int64_t b){
    check1(a,b);
    int64_t temp = (a-b)%MOD;
    check2(temp);
    return temp;
}
int64_t inverse(int64_t a, int64_t uMOD = (int64_t)1e9+7ll) { 
    int64_t m0 = uMOD; 
    int64_t y = 0ll, x = 1ll; 
    if (uMOD == 1ll) return 0ll; 
    while (a > 1ll) { 
        int64_t q = a / uMOD; 
        int64_t t = uMOD; 
        uMOD = a % uMOD, a = t; t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0ll) x += m0; 
    return x; 
} 
int64_t div(int64_t a, int64_t b){
    check1(a,b);
    int64_t temp = (mul(a,inverse(b,MOD)))%MOD;
    check2(temp);
    return temp;
}

int64_t m_pow(int64_t a, int64_t b , int64_t uMOD = (int64_t)1e9+7){
    int64_t res{1ll};
    while(b){
        if(b&1ll){
            (res*=a)%=uMOD;
        }
        (a*=a)%=uMOD;
        b>>=1ll;
    }
    return res;
}

signed main(void){
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

    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }

    int t; cin >> t; 
    while(t--){
        int64_t n; cin >> n; 
        int64_t res=1;
        for(int i=0;pr[i]<=n;++i){
            int64_t x=1;
            while(mul(x,pr[i])<=n){
                x = mul(x , pr[i]);
            }
            res = mul(x,res);
        }
        cout << res << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
