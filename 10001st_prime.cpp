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

bool primeNumber(int n){
	if(n < 2) return 0;
	else{
		for(int i = 2; i * i <= n; i++){
			if(n % i == 0) return 0;
		}
		return 1;
	}
}

int main(){
	int i = 2, cnt = 0;
	while(cnt < 10000){
		cnt += primeNumber(i) ? 1 : 0;
		i++;
	}
	cout << i - 1 << endl;
}
