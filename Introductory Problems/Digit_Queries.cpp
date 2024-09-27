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


class DSU{
 vector<int> parent;
vector<int> subtree_size;
int N;
public:
DSU(int n){
N = n;
parent = vector<int>(n+1, 0);
subtree_size = vector<int>(n+1, 1);
for(int i=1; i<=n; i++) parent[i] = i;
}
int findRoot(int u){
while(u != parent[u]){
parent[u] = parent[parent[u]]; //Path compression
u = parent[u];
}
return u;
}
void combine(int u, int v){
int ru = findRoot(u);
int rv = findRoot(v);
if(ru == rv) return;
if(subtree_size[ru] > subtree_size[rv]){
parent[rv] = ru;
subtree_size[ru] += subtree_size[rv];
} else{
parent[ru] = rv;
subtree_size[rv] += subtree_size[ru];
}
}
};
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
      int a ; cin >>a ;
  
   int mul = 1 ;
   int count = 1; 
   int sum = 0;
   int tot = 0 ;
   int prev = -1;
   while (a - sum >= 0) {
      prev = sum ;
      sum += 9 * count * mul ;
      mul = mul * 10 ;
      count++ ;
   }
   // cout << count  << endl ;
   count = count -1;


   int new_index = a -prev   ; // 1 based indexing 

// cout <<"new_index : " << new_index <<endl ; 
 int nth = (new_index)/count ;
   if (new_index%count ==0 ) {

   }
   else{
      nth++;
   }
  

   // cout <<nth <<endl ;

 int i  = 1 ;
   int ten = 1;
   while (i < count) {
      ten = ten * 10;
      i++;
   }

   int actual = ten + nth -1  ;
   // cout <<actual <<endl ;
   
   // int  start = (new_index)/ (count - 1) ; // 1 based indexing 
   // cout << "Nth number : " << start << endl ;
  
   // int actual_number =ten+ start -1 ;
   // cout <<"actual number : " << actual_number <<endl ;
   string ans = to_string(actual) ;
   if ( (new_index%(count) ) == 0) {
      cout << ans[ans.size()-1] <<endl ;
   }  
   else{
      cout <<ans[new_index%count-1] <<endl; 
   }




  
    
        
}

 main(){
    I_am_speed();
    int q; cin >>q;
    while (q--) {
      solve() ;
    }
   

    return 0;
}