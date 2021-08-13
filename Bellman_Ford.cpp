typedef long long ll;
#define repin(i,start,end) for(ll i=start,i<end;i++)
using namespace std;
using vi=vector<int>;
constexpr int INF=(1<<30)-1;
constexpr ll LLINF=(1LL<<60)-1;

struct edge{int from,to,cost;};

void Bellman_Ford(vector<edge>& es,vi& d,int s){
  d.at(s)=0;
  while(1){
    bool update=false;
    repin(i,0,es.size()){
      edge e=es.at(i);
      if(d.at(e.from)!=INF&&d.at(e.to)>d.at(e.from)+e.cost){
	d.at(e.to)=d.at(e.from)+e.cost;
	update=true;
      }
    }
    if(!update) break;
  }
}

/*無向グラフ前提で考える。*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int v,e; cin>>v>>e;
  vector<edge> es;
  repin(i,0,e){
    int a,b,c; cin>>a>>b>>c;
    es.push_back({a-1,b-1,c});
    es.push_back({b-1,a-1,c});
  }

  vi d(v,INF);
  int s; cin>>s;
  Bellman_Ford(es,d,s);
  cout<<d.at(6)<<endl;
  return 0;
}
