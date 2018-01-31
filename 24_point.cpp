/*Solution to the game "24 points"*/
#include<iostream>
#include<algorithm>
using namespace std;
int k=0;
void increment(int a[]){
	a[2]++;
	for (int i = 0; i < 2; ++i)
	{
		if (a[2-i]>4)
		{
			a[1-i]++;
			a[2-i]=0;
		}
	}
}
void calculate(int arr[]){
	int a, b;
	int sym[3]={0,0,0};
	while(sym[0]!=5){
		a=arr[0];
		for (int i = 0; i < 3; ++i){
			b=arr[i+1];
			switch(sym[i]){
			case 0: a=a+b; break;
			case 1: a=a-b; break;
			case 2: a=a*b; break;
			case 3: a=a/b; break;
			case 4: if(a!=0) a=b/a; break;
			}
		}
		if(a==24){
			k=1;
			return;
		} 

		increment(sym);
	}
}
 int main(){
 	int arr[4];
 	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
 	sort(arr,arr+4);
 	do { 
    	calculate(arr);
    	if(k==1){
    		cout<<"Yes";
    		return 0;
    	}
  	} while ( next_permutation(arr,arr+4) );
  	if(k==0){
    	cout<<"No";
    	return 0;
    }
 }
