#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct point{
		int x;
		int y;
	};
int find_min(point p_1,point p_2){
	int a = abs(p_1.x - p_2.x);
	int b = abs(p_1.y - p_2.y);
	return (a>=b ? a : b); 
}
int main(){
	int n;
	cin >> n;
	vector<point> v;
	int a,b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		point p;
		p.x = a;
		p.y = b;
		v.push_back(p);
	}
	int min_len = find_min(v[0],v[1]);
	for (int i = 0; i < (v.size()-1); ++i)
	{
		for (int j = i+1; j < v.size(); ++j)
		{
			int len = find_min(v[i],v[j]);
			if (len < min_len)  min_len = len;
		}
	}
	cout << min_len*min_len;
}
