using namespace std;
using vi=vector<int>;
using vb=vector<bool>;

int sieve(int n,vi& prime,vb& is_prime){
  int p=0;
  for(int i=0;i<=n;i++) is_prime.at(i)=true;
  is_prime.at(0)=is_prime.at(1)=false;
  for(int i=2;i<=n;i++){
    if(is_prime.at(i)){
      prime.at(p++)=i;
      for(int j=2*i;j<=n;j+=i) is_prime.at(j)=false;
    }
  }

  return p;
}
