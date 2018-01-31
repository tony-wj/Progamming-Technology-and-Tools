#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct animal{
	int begin;
	int end;
};

void print( const vector<animal> & v){
     vector<animal>::const_iterator itr;
     for( itr = v.begin();  itr != v.end() ; itr++ ){
          cout << (*itr).begin <<(*itr).end<< " ";
     }
     cout << endl;
}
bool compare(const animal & a, const animal & b ){
 
  return a.begin < b.begin;
}

int main(){
	int l, n;
	cin >> l;
	cin >> n;
	vector<animal> v;
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		animal a;
		a.begin = x;
		a.end = y;
		v.push_back(a); 
	}
	sort(v.begin(),v.end(),compare);
	vector<animal> u;
	u.push_back(v[0]);
	for (int i = 1; i < n; ++i)
	{
		if(v[i].begin>=u[u.size()-1].end){
			u.push_back(v[i]);
		}else{
			u[u.size()-1].end = v[i].end;
		}
	}
	int len;
	int max_len = u[0].begin - 0;
	for (int i = 1; i < u.size(); ++i)
	{
		len = u[i].begin - u[i-1].end;
		if (len >max_len) max_len = len;
	}
	len = l-u[u.size()-1].end;
	if (len >max_len) max_len = len;
	cout << max_len;

}