#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

const int kN = 1000000;
void primeNumber(bool prime[kN]){
	rep(i,kN) prime[i] = 1;
	prime[0] = prime[1] = 0;
	rep(i,kN){
		if(prime[i]){
			for(int j = i + i; j < kN; j+=i){
				prime[j] = 0;
			}
		}
	}
}

int main(){
	bool p[kN];
	primeNumber(p);
	int maxi = 0, ans;
	range(a,-999,1000){
		range(b,-1000,1001){
			int n = 0;
			while(p[ abs(n * n + a * n + b) ]) n++;
			if(maxi < n){
				maxi = n;
				ans = a * b;
			}
		}
	}
	cout << ans << endl;
}
