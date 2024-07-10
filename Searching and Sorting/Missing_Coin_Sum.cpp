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
    int n ; cin >>n ;
    vi v (n) ;
    loop ( i , 0, n)  cin >> v[i] ;
    sort (all(v) ) ;

    // range intersection  
    if (v[0] == 1) {
        // already existing range 
        int l = 1;
        int r = 1;
        int newl , newr ; 
        for (int i = 1;i <n; i++) {
            newl = v[i] ;
            newr = v[i]+r ;

            if (newl == r+1){
                r = newr ;
            }
            else if (newl <=r) {
                r = newr ;
            }
            else {
                cout <<r+1 <<endl ;
                return ;
            }

        }
        cout <<r+1 <<endl ;

    }
    else{ 
        cout <<1 <<endl ;
        return ;
    }
    
        

}
int32_t main(){
    I_am_speed();
    solve() ;
    return 0;
}
