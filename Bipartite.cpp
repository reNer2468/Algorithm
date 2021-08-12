bool dfs(vvi& g,vi& color,int v,int c){
  color.at(v)=c;
  repin(i,0,g.at(v).size()){
    if(color.at(g.at(v).at(i))==c) return false;
    if(color.at(g.at(v).at(i))==0&&!dfs(g,color,g.at(v).at(i),-c)) return false;
  }

  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n; cin>>n;
  vvi g(n);
  repin(i,0,n){
    while(1){
      int a; cin>>a; g.at(i).push_back(a);
      if(g.at(i).back()==-1) break;
    }    
    g.at(i).pop_back();
  }

  vi color(n,0);
  repin(i,0,n) if(color.at(i)==0) if(!dfs(g,color,i,1)) {cout<<"No"<<endl; return 0;}
  cout<<"Yes"<<endl;
  
  return 0;
}
