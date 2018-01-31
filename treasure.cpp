/*Treature puzzle*/
#include<iostream>
#include<vector>
using namespace std;
bool match(int x, int y, vector<int>t[], vector<int>m[],int dt){
	for (int i = 0; i < dt; ++i){
		for (int j = 0; j < dt; ++j){
			if(t[j][i]!=m[j+y][i+x]) return false;
		}
	}
	return true;
}
void reverse(vector<int>t[],int dt){
	vector<int>temp[100];
	for (int i = 0; i < dt; ++i)
	{
		temp[i]=t[i];
	}
	for (int i = 0; i < dt; ++i){
		for (int j = 0; j < dt; ++j){
			t[dt-j-1][i]=temp[i][j];
		}
	}
}
int main(){
	int Dim_T, Dim_M;
	vector<int>t[101];
	vector<int>m[101];
	cin>>Dim_T;
	char x;
	for (int j = 0; j < Dim_T; ++j){
		for (int i = 0; i < Dim_T; ++i){
			cin>>x;
			t[j].push_back((int)x);
		}
	}
	cin>>Dim_M;
	for (int j = 0; j < Dim_M; ++j){
		for (int i = 0; i < Dim_M; ++i){
			cin>>x;
			m[j].push_back((int)x);
		}
	}
	for (int k = 0; k < 3; ++k)
	{
		for (int i = 0; i < (Dim_M-Dim_T+1); ++i){
			for (int j = 0; j < (Dim_M-Dim_T+1); ++j){
				if(match(i,j,t,m,Dim_T)){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		reverse(t,Dim_T);
	}
	
	return 0;
}