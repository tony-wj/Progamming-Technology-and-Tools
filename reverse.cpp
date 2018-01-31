#include<iostream>
#include<string>
#include <sstream>
using namespace std;
string reverse(string s){
	int n=s.length();
	for (int i = 1; i < n/2; ++i)
	{
		swap(s[i],s[n-i-1]);
	}
	return s;
}
void swap(char &a, char &b){
	char temp = a;
	a=b;
	b=temp;
}
int main(){
	char word[50];
	string s;
	while(cin >> word){
		if(word[0]=='\n') break;
		s=word;
	}
	cout << s;
}
