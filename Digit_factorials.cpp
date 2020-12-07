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

vector<int> getDigit(long long a){
	vector<int> res;
	while(a != 0){
		res.emplace_back(a % 10);
		a/=10;
	}
	return res;
}

const long long M = 1000000007;

class Combination{
	public:
		vector<long long> fact, rev;
		Combination(int n = 200005) : fact(n), rev(n) { // n = h + w
			fact[0] = fact[1] = 1;
			range(i,2,n){
				(fact[i] = fact[i - 1] * i) %= M;
			}
			rev[n - 1] = power(fact[n - 1], M - 2) % M;
			for (int i = n - 1; i > 0; i--) {
				rev[i - 1] = rev[i] * i % M;
			}
		}
		long long power(long long x, long long n){ //べき乗 x^n mod M
			long long res = 1;
			if(n > 0){
				res = power(x, n / 2);
				if(n % 2 == 0) res = (res * res) % M;
				else res = (((res * res) % M) * x ) % M;
			}
			return res;
		}
		long long factorial(long long l, long long r){ return fact[r] * rev[l - 1] % M; }
		long long factorial(long long n){ return fact[n]; }
		long long combination(long long n, long long r){ //nCr (1,1)から(w,h)だと、引数は(w - 1, h - 1, M)
			return factorial(n - r + 1, n) * rev[r] % M;
		}
};

int main(){
	Combination c;
	long long ans = 0;
	range(i,3,1e7){ // どこまで回すか
		vector<int> a = getDigit(i);
		long long sum = 0;
		rep(j,a.size()){
			sum += c.factorial(a[j]);
			if(i < sum) break;
		}
		if(i == sum){
			cout << i << endl;
			ans += sum;
		}
	}
	cout << ans << endl;
}
