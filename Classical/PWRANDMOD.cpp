#include<bits/stdc++.h>
using namespace std;
#define LL __int128
 
LL T, a, b, m, ans;
char bf[1 << 25], *p;
 
LL read(){
    LL x(0);
    while( !isdigit(*p) ) ++p;
    while( isdigit(*p) ) x = ( x * 10 ) + ( *p ^ '0' ), ++p;
    return x;
}
 
void write( LL x, bool flg = 1 ){
    if ( x == 0 ){
        if ( flg ) putchar('0');
        return;
    }
    write( x / 10, 0 );
    putchar( x % 10 + '0' );
}
 
 
LL Mul( LL x, LL y ){ LL ans(0); for ( x %= m; y; x = ( x + x ) % m, y >>= 1 ) if ( y & 1 ) ans = ( ans + x ) % m; return ans; }

LL Pow( LL x, LL y ){ LL ans(1); for ( x %= m; y; x = Mul( x, x ), y >>= 1 ) if ( y & 1 ) ans = Mul( ans, x ); return ans; }


 
int main(){
    bf[fread( bf, 1, 1 << 25, stdin )] = '\0'; p = bf;
    T = read();
    while( T-- ){
        a = read(); b = read(); m = read(); ans = 1;
        write(Pow( a, b )); putchar('\n');
    }
 
    return 0;
}
