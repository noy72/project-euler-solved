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

int main(){
	long long a[2] = {1, 1}, sum = 0;
	while(true){
		long long nxt = a[0] + a[1];
		if(nxt % 2 == 0) sum += nxt;
		a[0] = a[1];
		a[1] = nxt;
		if(nxt > 4000000) break;
	}
	cout << sum << endl;
}
