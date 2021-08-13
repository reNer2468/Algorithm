struct edge{int from,to,cost;};

bool Find_Negative_Loop(vector<edge>& es,vi& d,int v){
  repin(i,0,v) repin(j,0,es.size()){
      edge e=es.at(j);
      
      if(d.at(e.to)>d.at(e.from)+e.cost){
	d.at(e.to)=d.at(e.from)+e.cost;
	if(i==v-1) return true;
      }
  }

  return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int v,e; cin>>v>>e;
  vector<edge> es;
  repin(i,0,e){
    int a,b,c; cin>>a>>b>>c;
    es.push_back({a-1,b-1,c});
  }

  vi d(v,0);

  cout<<(Find_Negative_Loop(es,d,v)?"Find Negative Loop":"Not Find Negative Loop")<<endl;
  
  return 0;
}
