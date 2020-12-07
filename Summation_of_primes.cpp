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

const int kN = 2000001;
long long primeNumber(){
	bool prime[kN];
	long long res = 0;
	rep(i,kN) prime[i] = 1;
	prime[0] = prime[1] = 0;
	rep(i,kN){
		if(prime[i]){
			res += i;
			for(int j = i + i; j < kN; j+=i){
				prime[j] = 0;
			}
		}
	}
	return res;
}

int main(){
	cout << primeNumber() << endl;
}
