#include<iostream>
using namespace std;
//rock 1 paper 2 scissors 3
int alice,bob;
void game(int a[], int b[], int n);
int main(){
	int num;
	cin >> num;
	int Alice[num];
	int Bob[num];
	string shape;
	for (int i=0;i<num;i++){
		cin >> shape;
		if (shape == "rock"){
			Alice[i] = 1;
		}else if(shape == "paper"){
			Alice[i] = 2;
		}else{
			Alice[i] = 3;
		}
	}
	for (int i=0;i<num;i++){
		cin >> shape;
		if (shape == "rock"){
			Bob[i] = 1;
		}else if(shape == "paper"){
			Bob[i] = 2;
		}else{
			Bob[i] = 3;
		}
	}

	game(Alice,Bob,num);

	
	cout << alice <<" "<< bob<<endl;

}

void game(int a[], int b[], int n){
	for (int i = 0; i < n; ++i)
	{
		if(a[i]==1 && b[i]==3){
			alice+=1;
		}else if(a[i]==3 && b[i]==1){
			bob+=1;
		}else if(a[i]>b[i]){
			alice+=1;
		}else if(a[i]<b[i]){
			bob+=1;
		}
	}
}