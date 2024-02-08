#include <bits/stdc++.h>
using namespace std;
#define IWillWinTCPC cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
#define int long long 
#define Take(x) for ( auto & d : x ) cin >> d ; 
#define No cout << "No" << endl  
#define Yes cout << "Yes" << endl  
#define Sort(x) sort( x.begin() , x.end() ) ;
#define RSort(x) sort( x.begin() , x.end() ) ; reverse ( x.begin() , x.end() ) ; 
#define MOD 998244353
#define Sum(A) accumulate( A.begin() , A.end() , (int)0 ) 
#define MAX LONG_LONG_MAX 
#define MIN LONG_LONG_MIN 
#define endl '\n' 
#define Unique(x) x.erase(unique(x.begin(),x.end()),x.end());
#define isSorted(x) is_sorted(x.begin(),x.end())
/* 
ASk WHY???!!! DOES IT MATTER IF.... ??!! ARE WE SUPPOSED TO DO LIkE HE SAID???!! DOES IT MATTER THAT THE SUBPROBLEMS ARE SEPERATED ? AM I SUPPOSED TO FIND THE OPTIMAL WAY BY MYSELF ? WHY DID HE GCanWeE ME SUCH CONSTRAINT ? CONSIDER ELIMINATING SOME CASSES OR EXCESS ELEMENTS 
*/
/* 
STAY ORGANIZED , DON'T RUSH , DON'T THINk ABOUT A SOLUTION THAT's BASED ON LUCk , DON'T CHECK WRONG RESULTS  , DON'T RUSH TO THE IMPLEMENTATION , THINK CAREFULL , DONT RUSH!!!
*/
 
class FenwickTree {
public:
    vector<int> tree; 
    FenwickTree(int N) {
        tree.resize(N + 1);
    }
 
    void Update(int i, int add) 
    {
        while (i < tree.size()) {
            tree[i] += add;
            i += (i & (-i));
        }
    }
    int Summ(int i) 
    {
        int S = 0;
        while (i > 0) {
            S += tree[i];
            i = i - (i & (-i));
        }
        return S;
    }
    int RangeSum(int l, int r) 
    { 
        return Summ(r) - Summ(l - 1);
    }
};
 
void solve()
{
    int n , q ; cin >> n >> q ; 
    vector<int> A(n) ; Take(A); 
    FenwickTree RangeQuery(n);
    for ( int i = 0 ; i < n ; ++i ) RangeQuery.Update( i + 1 , A[i] ) ; 
    for ( int i = 0 ; i < q ; ++i ) 
    {
        int l , r ; cin >> l >> r ; 
        cout << RangeQuery.RangeSum( l , r ) << endl ; 
    }
 
}
signed main() 
{
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    IWillWinTCPC ;   
    cout<<fixed<<setprecision(14);
    int t = 1 ; 
    // cin >> t ; 
    while ( t-- ) solve();
    return 0;
}
