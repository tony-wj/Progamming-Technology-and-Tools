#include <iostream>
#include <string>
using namespace std;
bool is_name(string s){
	for (int i = 0; i < s.length()-1; ++i)
	{
		if(s[i]==s[i+1]) return false;
	}
	return true;
}
int main(){
	string str;
	cin>>str;
	while(is_name(str)!=1){
		for (int i = 0; i < str.length()-1; ++i){
			if(str[i]==str[i+1]){
				str.erase(i,2);
			}
		}
	}
	cout << str<<endl;

}