const ll N = 1e5+5;
vector<ll> cnt_coprime(N,0);

void Euler_totient(){
	for(ll i=0;i<N;i++){
		cnt_coprime[i] = i;
	}

	for(ll i=2;i<N;i++){
		if(cnt_coprime[i]==i){
			for(ll j=i;j<N;j+=i){
				cnt_coprime[j]-=(cnt_coprime[j]/i);
			}
		}
	}
}