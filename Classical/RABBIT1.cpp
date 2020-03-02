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
long long MOD;

struct Matrix {
    long long A[2][2];
    void iden(void){
        for(long long i=0;i<2;++i){
            A[i][i] =1;
        }
    }
    Matrix(){
        for(long long i=0;i<2;++i){
            A[i][0]=0;
            A[i][1]=0;
        }
    }
};

Matrix operator*(Matrix&m1 , Matrix &m2){
    Matrix temp;
    for(long long i=0;i<2;++i){
        for(long long j=0;j<2;++j){
            for(long long k=0;k<2;++k){
                temp.A[i][j]+=(m1.A[i][k]*m2.A[k][j])%MOD;
            }
            temp.A[i][j]%=MOD;
        }
    }
    return temp;
}

Matrix pow(Matrix &res , Matrix &a , long long n){
    res.iden();
    while(n){
        if(n&1){
            res = res*a;
        }
        a = a*a;
        n>>=1;
    }
    return res;
}

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long t;scanf("%lld",&t);
    while(t--){
        long long n , m; scanf("%lld%lld",&n,&m);
        MOD = (1<<m);
        //printf("power = %lld\n",MOD);
        if(n==1 ){
            printf("%d\n",1%MOD);
        }else{
            Matrix a;
            a.A[0][0] = a.A[0][1] = 1;
            a.A[1][0] = 1;
            Matrix pw;pow(pw ,a , n-1);
            printf("%lld\n", (pw.A[0][1]+pw.A[0][0])%MOD);
        }
    }
    return 0;
}
