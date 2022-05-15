struct RMQ{
  ll n;
  vll dat;

  void init(int _n_){
    n=1;
    while(n<_n_) n*=2;
    repin(i,0,2*n-1) dat.push_back(LLINF);
  }

  void update(ll k,ll a){
    k+=n-1; dat.at(k)=a;    
    while(k>0){k=(k-1)/2; dat.at(k)=min(dat.at(k*2+1),dat.at(k*2+2));}
  }

  ll query(ll a,ll b,ll k,ll l,ll r){
    if(r<=a||b<=l) return LLINF;
    if(a<=l&&r<=b) return dat.at(k);
    else{
      ll vl=query(a,b,k*2+1,l,(l+r)/2);
      ll vr=query(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }
};
