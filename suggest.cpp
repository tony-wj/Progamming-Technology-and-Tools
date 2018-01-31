/*This program gives new friends suggestions on social media platform*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
void addFriend(vector<int>adj[],int u, int v){
	adj[u].push_back(v);
    adj[v].push_back(u);
}
bool knowFriend(vector<int>adj[],int u, int v){
	for (int i = 0; i < adj[u].size(); ++i){
		if(adj[u][i]==v) return true;
	}
	return false;
}
bool suggestFriend(vector<int>adj[],int u, int v){
	if(knowFriend(adj,u,v)) return false;
	for (int i = 0; i < adj[u].size(); ++i){
		if (find(adj[v].begin(),adj[v].end(),adj[u][i])!=adj[v].end()) return true;
	}
	return false;
}
int main(){
	map<string,int> people;
	vector<int> adj[101];
	string str;
	string a,b;
	int n=1;
	while(cin>>str){
		if(str == "FRIEND"){
			cin>>a>>b;
			if (people.count(a)==0){
				people[a]=n;
				n++;
			}
			if(people.count(b)==0){
				people[b]=n;
				n++;
			}
			addFriend(adj,people[a],people[b]);
		}else if(str == "KNOW"){
			cin>>a>>b;
			if(knowFriend(adj,people[a],people[b])){ cout<<"Yes"<<endl; continue;}
			cout<<"No"<<endl;
		}else if (str == "SUGGEST"){
			cin>>a>>b;
			if(suggestFriend(adj,people[a],people[b])){ cout<<"Yes"<<endl; continue;}
			cout<<"No"<<endl;
		}
	}
}