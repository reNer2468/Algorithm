void Warshall_Floyd(vvi& d,int v){
  repin(k,0,v) repin(i,0,v) repin(j,0,v)
    d.at(i).at(j)=min(d.at(i).at(j),d.at(i).at(k)+d.at(k).at(j));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int v; cin>>v;
  vvi d(v,vi(v,INF)); repin(i,0,v) d.at(i).at(i)=0;
  
  repin(i,0,v){
    while(1){
    int a,b; cin>>a>>b;
    if(a==-1||b==-1) break;
    d.at(i).at(a-1)=b;
    d.at(a-1).at(i)=b;
    }
  }
  
  Warshall_Floyd(d,v);

  repin(i,0,v){repin(j,0,v) {if(j)cout<<" "; cout<<d.at(i).at(j);} cout<<endl;}
  
  return 0;
}
