using vi=vector<int>;

bool is_prime(int n){
  for(int i=2;i*i<=n;i++) if(n%i==0) return false;
  return n!=1;
}

vi divisor(int n){
  vi res;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      res.push_back(i);
      if(i!=n/i) res.push_back(n/i);
    }
  }

  return res;
}

map<int,int> prime_factor(int n){
  map<int,int> res;
  for(int i=2;i*i<=n;i++){
    while(n%i==0){
      ++res[i];
      n/=i;
    }
  }

  if(n!=1) res[n]=1;
  
  return res;
}
