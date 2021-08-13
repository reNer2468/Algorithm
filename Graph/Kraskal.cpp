typedef long long ll;
#define repin(i,start,end) for(ll i=start,i<end;i++)
using namespace std;
using vi=vector<int>;

struct UF{
  vi par;
  vi rank;

  UF(int n){
    par.resize(n);
    rank.resize(n);
  }

  void init(int n){
    repin(i,0,n){par.at(i)=i; rank.at(i)=0;}
  }

  int find(int x){
    if(par.at(x)==x) return x;
    else return par.at(x)=find(par.at(x));
  }

  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;

    if(rank.at(x)<rank.at(y)) par.at(x)=y;
    else {par.at(y)=x; if(rank.at(x)==rank.at(y)) rank.at(x)++;}
  }

  bool same(int x,int y){
    return find(x)==find(y);
  }
};

struct edge{int u,v,cost;};

bool comp(const edge& e1,const edge& e2){
  return e1.cost<e2.cost;
}

int Kruskal(UF& uf,vector<edge> es,int num_e){
  sort(es.begin(),es.end(),comp);
  int ret=0;

  repin(i,0,num_e){
    edge e=es.at(i);
    if(!uf.same(e.u,e.v)){uf.unite(e.u,e.v); ret+=e.cost;}
  }

  return ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int v,e; cin>>v>>e;
  vector<edge> es(e);
  repin(i,0,e){
    int a,b,c; cin>>a>>b>>c;
    es.at(i)={a-1,b-1,c};
    //es.at(i)={a,b,c};
  }
  
  UF uf(v); uf.init(v);

  cout<<Kruskal(uf,es,e)<<endl;
  
  return 0;
}
