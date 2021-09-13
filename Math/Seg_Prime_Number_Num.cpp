using namespace std;
using vb=vector<bool>;

void segment_sieve(ll a,ll b,vb& is_prime,vb& is_prime_small){
  for(int i=0;ll(i)*i<b;i++) is_prime_small.at(i)=true;
  for(int i=0;i<b-a;i++) is_prime.at(i)=true;
  
  for(int i=2;ll(i)*i<b;i++){
    if(is_prime_small.at(i)){
      for(int j=2*i;ll(j)*j<b;j+=i) is_prime_small.at(j)=false;
      for(ll j=max(2LL,(a+i-1)/i)*i;j<b;j+=i) is_prime.at(j-a)=false;
    }
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll a,b; cin>>a>>b;
  
  vb is_prime(b-a,false);
  vb is_prime_small(int(sqrt(b))+1,false);

  ll count=0;
  segment_sieve(a,b,is_prime,is_prime_small);
  repin(i,0,b-a) if(is_prime.at(i)) count++;

  cout<<count<<endl;
  return 0;
}
