/*identify perfect numbers*/
#include<iostream>
using namespace std;
bool perfectNumber(int n);

int main(){
	int a, b;
	cin >> a >> b;
	for (int i = a; i < b+1; i++)
	{
		if (perfectNumber(i) == true) cout << i <<endl;
	}
}

bool perfectNumber(int n){
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i ==0) sum+=i;
	}
	if (sum == n) return true;
	return false;
}