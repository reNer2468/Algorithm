typedef long long ll;
#define repin(i,start,end) for(ll i=start,i<end;i++)
using namespace std;
using vi=vector<int>;

struct UF{
  vll par;
  vll rank;
  vll siz;

  UF(int n){
    par.resize(n);
    rank.resize(n);
    siz.resize(n);
  }

  void init(int n){
    repin(i,0,n){par.at(i)=i; rank.at(i)=0; siz.at(i)=1;}
  }

  int find(int x){
    if(par.at(x)==x) return x;
    else return par.at(x)=find(par.at(x));
  }

  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;

    if(rank.at(x)<rank.at(y)) {par.at(x)=y; siz.at(y)+=siz.at(x);}
    else {par.at(y)=x; siz.at(x)+=siz.at(y); if(rank.at(x)==rank.at(y)) rank.at(x)++;}
  }

  bool same(int x,int y){
    return find(x)==find(y);
  }

  ll size(ll x){
    return siz.at(find(x));
  }
};
