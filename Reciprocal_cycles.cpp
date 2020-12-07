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
	int maxi = 0;
	int ans;
	range(i,2,1000){
		int t = 1;
		int j = 0;
		map<pair<int,int>,int> m;
		while(true){
			t *= 10;
			int a = t / i;
			t %= i;
			if(t == 0) break;
			if(m.count(make_pair(a,t))){
				if(maxi < j - m[make_pair(a,t)]){
					maxi = j - m[make_pair(a,t)];
					ans = i;
				}
				break;
			}else{
				m[make_pair(a,t)] = j;
			}
			j++;
		}
	}
	cout << ans << endl;
}
