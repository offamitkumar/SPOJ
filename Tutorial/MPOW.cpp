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
using namespace std;
const long long mod = (long long)1e9+7ll;
struct Matrix {
    int size;
    vector<vector<long long>>arr;
    Matrix(int x){
        size = x; 
        arr.resize(size);
        for(int i=0;i<size;++i){
            arr[i].resize(size);
        }
    }
    void make_identical(void){
        for(int i=0;i<size;++i){
            arr[i][i] = 1;
        }
    }
};
Matrix operator*(Matrix &A , Matrix &B){
    Matrix T(A.size);
    for(int i=0;i<A.size;++i){
        for(int j=0;j<A.size; ++j){
            for(int k=0;k<A.size;++k){
                T.arr[i][j]+=A.arr[i][k]*B.arr[k][j];
                T.arr[i][j]%=mod;
            }
        }
    }
    return T;
}
Matrix mat(Matrix &A, int n ){
    Matrix temp(A.size);
    temp.make_identical();
    while(n){
        if(n&1){
            temp = temp * A;
        }
        A = A * A;
        n>>=1;
    }
    return temp;
}

int main(void){
    //freopen("input","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n , m; cin>> m >> n; 
        Matrix A(m);
        for(int i=0;i<m; ++i){
            for(int j=0;j<m;++j){
                cin>>A.arr[i][j];
            }
        }
        A = mat(A , n);
        for(int i=0;i<m; ++i){
            for(int j=0;j<m; ++j){
                cout<<A.arr[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
