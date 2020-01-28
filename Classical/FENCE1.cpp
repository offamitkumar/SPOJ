// author @hello_hell
#include <stdio.h>
#include <math.h>
using namespace std;
int main(void){
    double l;
    while(scanf("%lf",&l) && l!=0){
        printf("%.2f\n",(double)(l*l)/((double)2.0f*M_PI));
    }
    return 0;
}
