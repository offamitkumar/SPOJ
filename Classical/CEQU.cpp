// author @hello_hell
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;++i){
        int a, b, c;scanf("%d%d%d",&a,&b,&c);
        printf("Case %d: %s\n",i,((c%__gcd(a,b)==0)?"Yes":"No"));
    }
    return 0;
}
