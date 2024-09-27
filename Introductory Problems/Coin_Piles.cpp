#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve() {
	int q ; cin >>q ;
	while (q--) {
		int a , b ; cin >>a>>b ;
        if( a == 0 && b== 0) {
            cout << "YES" <<endl ;
        }
        if (a == 0 || b == 0) {
            cout << "NO" <<endl ;
        }
		if ((2*a - b) %3 == 0) {
			int y = (2*a - b)/3 ;
			if ( (b - 2*y) >0) {
				cout << "YES" <<endl ;
			}
			else{
				cout << "NO" <<endl ;
			}
		}
		else{
			cout << "NO" <<endl;
		}
	}
	
}
int32_t main() {
	solve() ;
}
