// author @hello_hell
#include <stdio.h>
#include <cmath>
using namespace std;
int get_tot(int x){
    int counter = x;
    for(int i=2;i<=sqrt(x)+1;++i){
        if(x%i==0){
            while(x%i==0){
                x/=i;
            }
            counter-=(counter/i);
        }
    }
    if(x>1){
        counter-=(counter/x);
    }
    return counter;
}
int main(void){
    int t;scanf("%d",&t);
    while(t--){
        int x;scanf("%d",&x);
        printf("%d\n",get_tot(x));
    }
    return 0;
}
