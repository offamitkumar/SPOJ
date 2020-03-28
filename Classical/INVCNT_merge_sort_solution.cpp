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
#define MOD 1000000007
#define MAXN  200090
array<int,MAXN>arr , temp;
long long counter{};
void merge(int start , int end){
    int mid = (start+end)/2;
    int i = start , j = mid+1 , k = start;
    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            counter+=abs(mid-i+1);
            temp[k++] = arr[j++];
        }else{
            temp[k++] = arr[i++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    for(i = start; i<=end; ++i){
        arr[i] = temp[i];
    }
    return ;
}
void mergeSort(int start , int end){
    if(start==end){return;}
    int mid = (start+end)/2;
    mergeSort(start , mid);
    mergeSort(mid+1 , end);
    merge(start , end);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; scanf("%d",&t);
    while(t--){
         counter = 0;
         int n; scanf("%d",&n);
         for(int i=0;i<n;++i){
             scanf("%d",&arr[i]);
         }
         mergeSort(0 , n-1);
         printf("%lld\n",counter);
    }
    return 0;
}
