#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define I_am_speed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define vec vector<ll> 
#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;
#define loop(x, start, end) for(int x = start; x < end; ++x) 
#define all(v) v.begin() , v.end() 
#define here(i) cout << " here " << i << endl ; 


void print(vi & v){ 
   int n = v.size(); 
    for(int i =0; i<v.size(); i++){ 
       cout<<v[i]<<" "; 
    }
    cout <<endl ;
    return ; 
} 
void print(vvi & v)
{
   for (int i = 0; i < v.size(); i++)
   {
   for (int j = 0; j < v[i].size(); j++)
   {
   cout << v[i][j] <<" ";
   }
    cout << endl;
   }
   return;
}

void solve() {
    int n ; cin >> n ;
    int tar ; cin >>tar  ;
    vvi v ( n , vi (2, 0)) ;
    loop (i , 0, n ) {
        cin >> v[i][0] ;
        v[i][1] = i+1 ;
    }

    sort  (all (v)) ;

    for (int i  = 0; i<n; i++) {
        int newTar =  tar - v[i][0] ;
        int j = i +1 ;
        int k = n-1; 
        while (j <k) {
            if (v[j][0] + v[k][0] == newTar) {
                cout << v[i][1] << " " << v[j][1] << " " << v[k][1] <<endl ;
                return ;
            }
            else if (v[j][0] + v[k][0] > newTar) {
                k-- ;
            }
            else{
                j++;
            }
        } 
    }

    cout << "IMPOSSIBLE" <<endl ;
        

}
int32_t main(){
    I_am_speed();
    solve() ;
    return 0;
}