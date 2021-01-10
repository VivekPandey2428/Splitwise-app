#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<climits>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#include<random>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f first
#define sec second
#define pb push_back
#define p(x) push(x)
#define rep(X,Y) for (int (X) = 0;(X) < (int)(Y);++(X))
#define reps(X,S,Y) for (int (X) = (int)(S);(X) < (int)(Y);++(X))
#define rrep(X,Y) for (int (X) = (int)(Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (int)(Y)-1;(X) >= (int)(S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"
#define cauto const auto
#define f1ton(i,n) for(ll i=1;i<n;i++)

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
void solve(){
    ll transaction_no,friends;
    cin>>transaction_no>>friends;
    int x,y,amount;
    int net[100000]={0};
    // make a array to give every person will recieve at the end of transaction.
    while(transaction_no--){
        cin>>x>>y>>amount;
        net[x]-=amount;
        net[y]+=amount;
    }
    multiset<ll>m;
    rep(i,friends)if(net[i]!=0){
        m.insert(net[i]);
    }
    ll cnt=0;
    while(!m.empty()){
        auto low=m.begin();
        auto high=prev(m.end());

        ll debit=*low;
        ll credit=*high;

        m.erase(low);
        m.erase(high);

        ll settlement_amount=min(-debit,credit);
        cnt++;
        debit+=settlement_amount;
        credit-=settlement_amount;

        if(debit!=0){
            m.insert(debit);
        }
        if(credit!=0){
            m.insert(credit);
        }
    }
    cout<<cnt<<endl;
    }

int main(){
    fastio;
    solve();
    return 0;
}
