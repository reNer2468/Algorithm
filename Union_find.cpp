struct UF{
  vi par;
  vi rank;

  union_find(int n){
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
