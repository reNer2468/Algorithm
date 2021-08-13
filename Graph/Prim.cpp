typedef long long ll;
#define repin(i,start,end) for(ll i=start,i<end;i++)
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using PI=pair<int,int>;
using vPI=vector<PI>;
constexpr int INF=(1<<30)-1;
constexpr ll LLINF=(1LL<<60)-1;

struct edge{int to,cost;};

int Prim(vector<vector<edge>>&g,vb& used,int s){
  int ret=0;
  priority_queue<PI,vPI,greater<PI>> que;
  que.push(PI(0,s));

  while(!que.empty()){
    PI p=que.top(); que.pop();
    int c=p.first;
    int v=p.second;
    
    if(used.at(v)) continue;
    used.at(v)=true;
    ret+=c;
    
    repin(i,0,g.at(v).size()){
      edge e=g.at(v).at(i);
      que.push(PI(e.cost,e.to));
    }
  }
  
  return ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int v; cin>>v;
  vector<vector<edge>> g(v);
  repin(i,0,v){
    while(1){
      int a,b; cin>>a>>b; if(a==-1||b==-1) break;
      g.at(i).push_back({a-1,b});
      g.at(a-1).push_back({(int)i,b});
    }
  }
  
  int s; cin>>s;
  vb used(v,false);
  cout<<Prim(g,used,s-1)<<endl;
  return 0;
}
