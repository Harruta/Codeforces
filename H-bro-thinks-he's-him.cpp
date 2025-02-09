//#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> ppi;
typedef pair<ll,ppi> pppi;
typedef pair<ll,pppi> ppppi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
#define FOR(i,l,r) for(ll i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,l,r) for(ll i=r-1;i>=l;i--)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define F first
#define S second
#define UB(x,y) (ll)(upper_bound(ALL(x),y)-x.begin())
#define LB(x,y) (ll)(lower_bound(ALL(x),y)-x.begin())
#define COU(x,y) (ll)(upper_bound(ALL(x),y)-lower_bound(ALL(x),y))
#define TU tuple<ll,ll,ll>
#define sz(c) (ll)(c.size())
template<typename T>using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<typename T1,typename T2>ostream&operator<<(ostream&os,pair<T1,T2>&p){os<<p.F<<" "<<p.S;return os;}
template<typename T1,typename T2>istream&operator>>(istream&is,pair<T1,T2>&p){is>>p.F>>p.S;return is;}
template<typename T>ostream&operator<<(ostream&os,vector<T>&v){REP(i,sz(v))os<<v[i]<<(i+1!=sz(v)?" ":"");return os;}
template<typename T>istream&operator>>(istream&is,vector<T>&v){for(T&in:v)is>>in;return is;}
template<class T>bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T&a,T b){if(b<a){a=b;return 1;}return 0;}
const ll mod=998244353;
//const ll mod=1000000007;
//const ll mod=999999893;
ll pow_mod(ll a,ll n,ll mod){
    a%=mod;
    ll res=1;
    while(n){
        if(n%2)res=res*a%mod;
        a=a*a%mod;n/=2;
    }
    return res;
}
ll inv_mod(ll a,ll mod){return pow_mod(a,mod-2,mod);}
template<const long long int mod=998244353>
struct modint{
  using mint=modint<mod>;
  long long int x;
  modint(long long int _x=0):x(_x%mod){if(x<0)x+=mod;}
  long long int val(){return x;}
  mint&operator=(const mint&a){x=a.x;return *this;}
  mint&operator+=(const mint&a){x+=a.x;if(x>=mod)x-=mod;return *this;}
  mint&operator-=(const mint&a){x-=a.x;if(x<0)x+=mod;return *this;}
  mint&operator*=(const mint&a){x*=a.x;x%=mod;return *this;}
  friend mint operator+(const mint&a,const mint&b){return mint(a)+=b;}
  friend mint operator-(const mint&a,const mint&b){return mint(a)-=b;}
  friend mint operator*(const mint&a,const mint&b){return mint(a)*=b;}
  mint operator-()const{return mint(0)-*this;}
  mint pow(long long int n){
    if(!n)return 1;
    mint a=1;
    mint _x=x;
    while(n){
      if(n&1)a*=_x;
      _x=_x*_x;n>>=1;
    }
    return a;
  }
  mint inv(){return pow(mod-2);}
  mint&operator/=(mint&a){return *this*=a.inv();}
  friend mint operator/(const mint&a,mint b){return mint(a)/=b;}
};
using mint=modint<mod>;
typedef vector<mint> vm;
typedef vector<vm> vvm;
typedef vector<vvm> vvvm;
typedef vector<vvvm> vvvvm;
template<class S,S(*op)(S,S),S(*e)()>
struct segtree{
  private:
  size_t N;
  vector<S>seg;
  public:
  segtree(int _N){init(_N);}
  void init(int _N){
    N=1;
    while(N<_N)N<<=1;
    seg.assign(2*N,e());
  }
  void set(int i,S x){
    assert(0<=i&&i<N);
    i+=N;
    seg[i]=x;
    while(i>1){
      i>>=1;
      seg[i]=op(seg[2*i],seg[2*i+1]);
    }
  }
  S get(int i){
    assert(0<=i&&i<N);
    return seg[i+N];
  }
  S prod(int l,int r){
    assert(0<=l&&l<=r&&r<=N);
    l+=N;r+=N;
    S L=e(),R=e();
    while(l<r){
      if(l&1)L=op(L,seg[l]),l++;
      if(r&1)r--,R=op(seg[r],R);
      l>>=1;
      r>>=1;
    }
    return op(L,R);
  }
};
template<class S,S(*op)(S,S),S(*e)(),class T,S(*mapping)(T,S),T(*composition)(T,T),T(*id)()>
struct lazy_segtree{
  private:
  size_t N,h;
  vector<S>seg;
  vector<T>laz;
  public:
  lazy_segtree(int _N){init(_N);}
  void init(int _N){
    N=1,h=0;
    while(N<_N)N<<=1,h++;
    seg.assign(2*N,e());
    laz.assign(2*N,id());
  }
  void set(int i,S x){
    assert(0<=i&&i<N);
    i+=N;
    for(int k=h;k>0;k--){
      int v=i>>k;
      seg[2*v]=mapping(laz[v],seg[2*v]);
      seg[2*v+1]=mapping(laz[v],seg[2*v+1]);
      laz[2*v]=composition(laz[v],laz[2*v]);
      laz[2*v+1]=composition(laz[v],laz[2*v+1]);
      laz[v]=id();
    }
    seg[i]=x;
    for(int v=i>>1;v;v>>=1)seg[v]=op(seg[2*v],seg[2*v+1]);
  }
  S get(int i){
    assert(0<=i&&i<N);
    i+=N;
    for(int k=h;k>0;k--){
      int v=i>>k;
      seg[2*v]=mapping(laz[v],seg[2*v]);
      seg[2*v+1]=mapping(laz[v],seg[2*v+1]);
      laz[2*v]=composition(laz[v],laz[2*v]);
      laz[2*v+1]=composition(laz[v],laz[2*v+1]);
      laz[v]=id();
    }
    for(int v=i>>1;v;v>>=1)seg[v]=op(seg[2*v],seg[2*v+1]);
    return seg[i];
  }
  S prod(int l,int r){
    assert(0<=l&&l<=r&&r<=N);
    if(l==r)return e();
    l+=N;r+=N;
    for(int k=h;k>0;k--){
      int v=l>>k;
      seg[2*v]=mapping(laz[v],seg[2*v]);
      seg[2*v+1]=mapping(laz[v],seg[2*v+1]);
      laz[2*v]=composition(laz[v],laz[2*v]);
      laz[2*v+1]=composition(laz[v],laz[2*v+1]);
      laz[v]=id();
    }
    for(int v=l>>1;v;v>>=1)seg[v]=op(seg[2*v],seg[2*v+1]);
    for(int k=h;k>0;k--){
      int v=(r-1)>>k;
      seg[2*v]=mapping(laz[v],seg[2*v]);
      seg[2*v+1]=mapping(laz[v],seg[2*v+1]);
      laz[2*v]=composition(laz[v],laz[2*v]);
      laz[2*v+1]=composition(laz[v],laz[2*v+1]);
      laz[v]=id();
    }
    for(int v=(r-1)>>1;v;v>>=1)seg[v]=op(seg[2*v],seg[2*v+1]);
    S L=e(),R=e();
    while(l<r){
      if(l&1)L=op(L,seg[l]),l++;
      if(r&1)r--,R=op(seg[r],R);
      l>>=1;
      r>>=1;
    }
    return op(L,R);
  }
  void apply(int l,int r,T f){
    assert(0<=l&&l<=r&&r<=N);
    if(l==r)return;
    l+=N;r+=N;
    for(int k=h;k>0;k--){
      int v=l>>k;
      seg[2*v]=mapping(laz[v],seg[2*v]);
      seg[2*v+1]=mapping(laz[v],seg[2*v+1]);
      laz[2*v]=composition(laz[v],laz[2*v]);
      laz[2*v+1]=composition(laz[v],laz[2*v+1]);
      laz[v]=id();
    }
    for(int v=l>>1;v;v>>=1)seg[v]=op(seg[2*v],seg[2*v+1]);
    for(int k=h;k>0;k--){
      int v=(r-1)>>k;
      seg[2*v]=mapping(laz[v],seg[2*v]);
      seg[2*v+1]=mapping(laz[v],seg[2*v+1]);
      laz[2*v]=composition(laz[v],laz[2*v]);
      laz[2*v+1]=composition(laz[v],laz[2*v+1]);
      laz[v]=id();
    }
    for(int v=(r-1)>>1;v;v>>=1)seg[v]=op(seg[2*v],seg[2*v+1]);
    int _l=l,_r=r;
    while(l<r){
      if(l&1)laz[l]=composition(f,laz[l]),seg[l]=mapping(f,seg[l]),l++;
      if(r&1)r--,laz[r]=composition(f,laz[r]),seg[r]=mapping(f,seg[r]);
      l>>=1;
      r>>=1;
    }
    l=_l;r=_r;
    for(int k=h;k>0;k--){
      int v=l>>k;
      seg[2*v]=mapping(laz[v],seg[2*v]);
      seg[2*v+1]=mapping(laz[v],seg[2*v+1]);
      laz[2*v]=composition(laz[v],laz[2*v]);
      laz[2*v+1]=composition(laz[v],laz[2*v+1]);
      laz[v]=id();
    }
    for(int v=l>>1;v;v>>=1)seg[v]=op(seg[2*v],seg[2*v+1]);
    for(int k=h;k>0;k--){
      int v=(r-1)>>k;
      seg[2*v]=mapping(laz[v],seg[2*v]);
      seg[2*v+1]=mapping(laz[v],seg[2*v+1]);
      laz[2*v]=composition(laz[v],laz[2*v]);
      laz[2*v+1]=composition(laz[v],laz[2*v+1]);
      laz[v]=id();
    }
    for(int v=(r-1)>>1;v;v>>=1)seg[v]=op(seg[2*v],seg[2*v+1]);
  }
};
class dsu{
  public:
  dsu()=default;
	explicit dsu(size_t n):m_parentsOrSize(n,-1){}
	int leader(int i){
		if (m_parentsOrSize[i]<0)return i;
		return(m_parentsOrSize[i]=leader(m_parentsOrSize[i]));
	}
	int merge(int a,int b){
		a=leader(a);
		b=leader(b);
		if (a!=b){
			if(-m_parentsOrSize[a]<-m_parentsOrSize[b])std::swap(a,b);
			m_parentsOrSize[a]+=m_parentsOrSize[b];
			m_parentsOrSize[b]=a;
		}
		return leader(a);
	}
	bool same(int a,int b){return(leader(a)==leader(b));}
	int size(int i){return -m_parentsOrSize[leader(i)];}
	std::vector<std::vector<int>>groups(){
	  int n=(int)m_parentsOrSize.size();
	  std::vector<std::vector<int>>A(n);
	  for(int i=0;i<n;i++)A[leader(i)].emplace_back(i);
	  std::vector<std::vector<int>>res;
	  for(auto a:A)if(a.size())res.emplace_back(a);
	  return res;
	}
    private:
	std::vector<int>m_parentsOrSize;
};
template<typename T>
struct fenwick_tree{
  private:
  vector<T>tree;
  T sum_from_zero(int i){
    i++;
    T s=0;
    while(i){
      s+=tree[i];
      i-=i&-i;
    }
    return s;
  }
  public:
  fenwick_tree(size_t N):tree(vector<T>(N+1)){}
  T sum(int l,int r){
    assert(0<=l&&l<=r&&r<=tree.size());
    return sum_from_zero(r-1)-sum_from_zero(l-1);
  }
  T get(int i){
    assert(0<=i&&i<tree.size());
    return sum(i,i+1);
  }
  void add(int i,T x){
    assert(0<=i&&i<tree.size());
    i++;
    while(i<tree.size()){
      tree[i]+=x;
      i+=i&-i;
    }
  }
};
struct Mo{
  int n;
  vector<pair<int,int>>lr;
  explicit Mo(int n):n(n){}
  void add(int l,int r){lr.emplace_back(l,r);}
  template<typename AL,typename AR,typename EL,typename ER,typename O>
  void build(const AL&add_left,const AR&add_right,const EL&erase_left,const ER&erase_right,const O&out){
    int q=(int)lr.size();
    int bs=n/min<int>(n,sqrt(q));
    vector<int>ord(q);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int a,int b){
      int ablock=lr[a].first/bs,bblock=lr[b].first/bs;
      if(ablock!=bblock)return ablock<bblock;
      return(ablock&1)?lr[a].second>lr[b].second:lr[a].second<lr[b].second;
    });
    int l=0,r=0;
    for(auto idx:ord){
      while(l>lr[idx].first)add_left(--l);
      while(r<lr[idx].second)add_right(r++);
      while(l<lr[idx].first)erase_left(l++);
      while(r>lr[idx].second)erase_right(--r);
      out(idx);
    }
  }
  template<typename A,typename E,typename O>
  void build(const A&add,const E&erase,const O&out){build(add,add,erase,erase,out);}
};
//ll op(ll a,ll b){return max(a,b);}
//ll e(){return -1e18;}
ll op1(ll a,ll b){return min(a,b);}
ll e1(){return 1e18;}
ll ma(ll f,ll x){return f+x;}
ll co(ll f,ll g){return f+g;}
ll id(){return 0;}
const ll mod1=998244353;
const ll mod2=1000000007;
using mint1=modint<mod1>;
using mint2=modint<mod2>;
struct S{
  mint v,p,l0,r0,l1,r1;
};
S op(S a,S b){
  return S{a.v*b.p+b.v*a.p+a.l0*b.r1+a.l1*b.r0,a.p*b.p,a.l0+b.l0*a.p,a.r0*b.p+b.r0,a.l1+b.l1*a.p,a.r1*b.p+b.r1};
}
S e(){
  return S{0,1,0,0,0,0};
}
int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--){
      string T;cin>>T;
      ll Q;cin>>Q;
      segtree<S,op,e>seg(sz(T));
      S s0=S{0,2,1,1,0,0};
      S s1=S{0,2,0,0,1,1};
      REP(i,sz(T))seg.set(i,T[i]=='0'?s0:s1);
      vi ans;
      while(Q--){
        ll a;cin>>a;a--;
        T[a]='0'+'1'-T[a];
        seg.set(a,(T[a]=='0'?s0:s1));
        auto p=seg.prod(0,sz(T));
        ans.emplace_back((p.v+p.p-1).val());
      }
      cout<<ans<<endl;
    }
    return 0;
}