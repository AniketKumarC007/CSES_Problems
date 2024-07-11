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

void addNum (int a, multiset<int>& left , multiset<int>& right) {

    left.insert(a) ;
    auto it = left.end(); 
    it--; 
    right.insert(*(left.rbegin())) ;
    left.erase(it) ;

    if (left.size() < right.size()) {

        left.insert(*right.begin()) ;
        right.erase(right.begin()) ;
    }

}
void solve() {
    int n ; cin >>n;
    int k ; cin >> k ; 
    vi v (n) ;
    loop ( i ,  0, n)  cin >>v[i] ;
    vi temp ;
    multiset<int> left , right;
    for (int i = 0 ; i <k ; i++) {
        addNum(v[i] , left , right ) ;
    }
    // cout <<"Median rn : " << *left.rbegin() <<endl  ;
    // cout<< *left.rbegin() <<" "  ;

    temp.push_back(*left.rbegin() ) ;
    int start  = 0 ; 
    for (int i = k; i<n; i++) {
        if (left.find(v[start]) != left.end()) {
            // cout << "Removing from left " <<v[start] << endl ;
            auto it = left.find(v[start]) ;
            left.erase(it) ;
        }
        else if (right.find(v[start]) != right.end()) {
            // cout << "Removing from Right " <<v[start] << endl ;
            auto it = right.find(v[start]) ;
            right.erase(it) ;
        }
        addNum (v[i] , left, right) ;
        // cout <<"Median rn : " << *left.rbegin() <<endl  ;
        // cout << *left.rbegin() <<" "  ;
        temp.push_back(*left.rbegin() ) ;
        start++;
    }
    
}

int32_t main(){
    I_am_speed();
    solve() ;
    return 0;
}