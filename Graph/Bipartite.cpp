typedef long long ll;
#define repin(i,start,end) for(ll i=start,i<end;i++)
using namespace std;
using vi=vector<int>;
using vvi=vector<vector<int>>;

bool Check_Bipartite(vvi& g,vi& color,int v,int c){
  color.at(v)=c;
  repin(i,0,g.at(v).size()){
    if(color.at(g.at(v).at(i))==c) return false;
    if(color.at(g.at(v).at(i))==0&&!Check_Bipartite(g,color,g.at(v).at(i),-c)) return false;
  }

  return true;
}

/*
無向グラフとして考える。
グラフは1から始めるものとする。
*/

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n; cin>>n;
  vvi g(n);
  repin(i,0,n){
    while(1){
      int a; cin>>a;
      if(a==-1) break;
      g.at(i).push_back(a-1); g.at(a-1).push_back(i);
    }    
    g.at(i).pop_back();
  }

  vi color(n,0);
  repin(i,0,n) if(color.at(i)==0) if(!Check_Bipartite(g,color,i,1)) {cout<<"No"<<endl; return 0;}
  cout<<"Yes"<<endl;
  
  return 0;
}
