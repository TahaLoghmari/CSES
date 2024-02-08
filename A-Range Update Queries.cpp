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
 
class SegmentTree {
private:
    int n;
    vector<int> a, Tree, Lazy;
    void Check(int p, int s, int e) {
        if (Lazy[p] != 0) {
            Tree[p] += Lazy[p];
            if (s != e) {
                Lazy[2 * p] += Lazy[p];
                Lazy[2 * p + 1] += Lazy[p];
            }
            Lazy[p] = 0;
        }
    }
    void Build(int p, int s, int e) {
        Check(p, s, e);
 
        if (s == e) {
            Tree[p] = a[s];
            return;
        }
 
        Build(2 * p, s, (s + e) / 2);
        Build(2 * p + 1, (s + e) / 2 + 1, e);
 
        Tree[p] = Tree[2 * p] + Tree[2 * p + 1];
    }
    void Update(int p, int s, int e, int i, int v) {
        Check(p, s, e);
        if (s == e) {
            Tree[p] = v;
            return;
        }
        if (i <= (s + e) / 2)
            Update(2 * p, s, (s + e) / 2, i, v);
        else
            Update(2 * p + 1, (s + e) / 2 + 1, e, i, v);
 
        Tree[p] = Tree[2 * p]+Tree[2 * p + 1];
    }
    void Update(int p, int s, int e, int a, int b, int v) {
        Check(p, s, e);
        if (s >= a && e <= b) {
            Tree[p] += v;
            if (s != e) {
                Lazy[2 * p] += v;
                Lazy[2 * p + 1] += v;
            }
            return;
        }
        if (s > b || e < a)
            return;
        Update(2 * p, s, (s + e) / 2, a, b, v);
        Update(2 * p + 1, (s + e) / 2 + 1, e, a, b, v);
        Tree[p] = Tree[2 * p]+Tree[2 * p + 1];
    }
    int Get(int p, int s, int e, int a, int b) {
        Check(p, s, e);
        if (s >= a && e <= b)
            return Tree[p];
        if (s > b || e < a)
            return 0;
        return Get(2 * p, s, (s + e) / 2, a, b)+Get(2 * p + 1, (s + e) / 2 + 1, e, a, b);
    }
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        a = arr;
        Tree.resize(4 * n);
        Lazy.resize(4 * n);
        Build(1, 0, n - 1);
    }
    void Update(int index, int value) {
        Update(1, 0, n - 1, index, value);
    }
    void UpdateRange(int start, int end, int value) {
        Update(1, 0, n - 1, start, end, value);
    }
    int Gett(int start, int end) {
        return Get(1, 0, n - 1, start, end);
    }
};
void solve()
{
    int n , q ; cin >> n >> q ; 
    vector<int> A(n) ; Take(A);
    SegmentTree Result(A) ; 
    for ( int i = 0 ; i < q ; ++i ) 
    {
        int O ; cin >> O ; 
        if ( O == 1 ) 
        {
            int a , b , u ; cin >> a >> b >> u ; 
            Result.UpdateRange( a-1 , b-1 , u ) ; 
        }
        else
        {
            int k ; cin >> k ; 
            cout << Result.Gett(k-1,k-1) << endl ; 
        }
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
