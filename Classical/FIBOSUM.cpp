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


const int MATRIX_SIZE=2;
struct Matrix{
    int size;
    long long mat[MATRIX_SIZE][MATRIX_SIZE];
    Matrix(int r){
        size = r;
        for(int i=0;i<size;++i){
            for(int j=0;j<size;++j){
                mat[i][j]=0;
            }
        }
    }
};

Matrix operator*(Matrix &A , Matrix &B ){
    Matrix T=Matrix(A.size);
    for(int i=0;i<A.size;++i){
        for(int j=0;j<A.size;++j){
            for(int k=0;k<A.size;++k){
                T.mat[i][j]+=(A.mat[i][k]*B.mat[k][j])%MOD;
                T.mat[i][j]%=MOD;
            }
        }
    }
    return T;
}

Matrix power(Matrix A , long long b){
    Matrix temp = Matrix(A.size);
    for(int i=0;i<A.size;++i){
        temp.mat[i][i]=1;
    }
    while(b){
        if(b&1){
            temp = temp*A;
        }
        b>>=1;
        A = A*A;
    }
    return temp;
}


int64_t fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 1;
    }
    Matrix temp(2); 
    temp.mat[0][0] = 1; temp.mat[0][1] =1;
    temp.mat[1][0] = 1; temp.mat[1][1] =0;
    temp = power(temp , n-2);
    int64_t res = (temp.mat[0][0] + temp.mat[0][1])%MOD;
    return res;
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
        int64_t n, m; cin >> n >> m; 
        cout << (((fib(m+2)-1)-(fib(n+1)-1)+MOD+MOD)%MOD) << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
