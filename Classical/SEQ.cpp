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
#define MOD 1000000000
#define MAXK 12
array<long long,MAXK>Ai;
array<long long,MAXK>C;
int SIZE;
struct Matrix {
    long long A[13][13];
    Matrix(){
        for(int i=0;i<13;++i){
            for(int j=0;j<13;++j){
                A[i][j] = 0;
            }
        }
    }
    void iden(void){
        for(int i=0;i<13;++i){
            A[i][i] = 1;
        }
    }
};
Matrix operator*(Matrix&m1 , Matrix &m2){
    Matrix temp;
    for(int i=1;i<=SIZE;++i){
        for(int j=1;j<=SIZE;++j){
            for(int k=1;k<=SIZE;++k){
                temp.A[i][j] = (temp.A[i][j]+m1.A[i][k]*m2.A[k][j]+MOD+MOD+MOD)%MOD;
            }
        }
    }
    return temp;
}
void pow(Matrix &res , Matrix&magic ,long long n){
    res.iden();
    while(n){
        if(n&1){
            res = res*magic;
        }
        n>>=1;
        magic = magic*magic;
    }
    return;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d",&SIZE);
        for(int i=1;i<=SIZE;++i){
            scanf("%lld",&Ai[i]);
            Ai[i]%=MOD;
        }
        reverse(Ai.begin(),Ai.begin()+1+SIZE);
//        cerr<<endl;
        for(int i=1;i<=SIZE;++i){
            scanf("%lld",&C[i]);
            C[i]%=MOD;
        }
        long long n; scanf("%lld",&n);
        if(n<=SIZE){
            printf("%lld\n",Ai[n-1]);
            continue;
        }
        Matrix res;
        Matrix magic;
        for(int i=1;i<=SIZE;++i){
            magic.A[1][i] = C[i];
            if(i!=SIZE){
                magic.A[i+1][i] = 1;
            }
        }
        /*
        cerr<<"This is magic: "<<endl;
        for(int i=1;i<=SIZE;++i){
            for(int j=1;j<=SIZE;++j){
                cerr<<magic.A[i][j]<<' ';
            }
            cerr<<endl;
        }
        */
        pow(res ,magic ,n-SIZE);
        /*cerr<<"This is res: "<<endl;
        for(int i=1;i<=SIZE;++i){
            for(int j=1;j<=SIZE;++j){
                cerr<<res.A[i][j]<<' ';
            }
            cerr<<endl;
        }
        cerr<<"this is a: ";
        for(int i=1;i<=SIZE;++i){
            cerr<<Ai[i-1]<<' ';
        }
        cerr<<endl;
        */
        long long ans{};
        for(int i=1;i<=SIZE;++i){
            //cout<<"res = "<<res.A[1][i]<<"\t"<<"a = "<<Ai[i-1]<<endl;
            ans = (ans+MOD+MOD+res.A[1][i]*Ai[i-1])%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
