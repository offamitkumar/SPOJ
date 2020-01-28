// author @hello_hell
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
long long ff(long long a){
    if(a==1LL){
        return 1LL;
    }
    long long ans = 1LL;
    while(a%2==0){
        a/=2LL;
        ans = 2LL;
    }
    for(int i=3LL;i<=(long long)sqrt(a);i+=2LL){
        if(a%i==0LL){
            ans = i;
            while(a%i==0LL){
                a/=i;
            }
        }
    }
    return max(ans,a);
}
int main(void){
    long long a,b;scanf("%lld%lld",&a,&b);
    a = ff(a);
    b = ff(b);
    printf("%lld\n",max(0LL,b-a));
    return 0;
}
