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

vector<int> a = {1,2,5,10,20,50,100,200};
int cnt;

void dfs(int i, int sum){
	if(sum == 200){
		cnt++;
		return;
	}
	if(sum > 200) return;

	range(j,i,a.size()){
		dfs(j, sum + a[j]);
	}
}

int main(){
	dfs(0,0);
	cout << cnt << endl;
}

