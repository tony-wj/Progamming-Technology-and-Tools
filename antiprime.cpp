#include <iostream>
#include <cmath>
using namespace std;
int num_of_dividor(int a, int d){
	int count;
	count=0;
	for (int i = 1; i < 8; ++i)
	{
		if(a%(int)pow(d,i)==0) count++;
	}
	return count;
}
int main(){
	int a;
	cin>> a;
	int num[5]={0,0,0,0,0};
	int largest_now=0;
	int largest_num=0;
	if(a==0){
		cout<<"0"<<endl;
	}else if (a<840){
		for(int i=1; i<=a;i++){
			int total_num=1;
			num[0]=num_of_dividor(i,2);
			num[1]=num_of_dividor(i,3);
			num[2]=num_of_dividor(i,5);
			for (int j = 0; j < 5; ++j)
			{
				if(num[j]!=0) total_num*=(num[j]+1);
			}
			if (largest_now<total_num){
				largest_now=total_num;
				largest_num=i;
			}
		}
	}else if(a<27720){
		for(int i=840; i<=a;i+=420){
			int total_num=1;
			num[0]=num_of_dividor(i,2);
			num[1]=num_of_dividor(i,3);
			num[2]=num_of_dividor(i,5);
			num[3]=num_of_dividor(i,7);
			for (int j = 0; j < 5; ++j)
			{
				if(num[j]!=0) total_num*=(num[j]+1);
			}
			if (largest_now<total_num){
				largest_now=total_num;
				largest_num=i;
			}
		}
	}else{
		for(int i=27720; i<=a;i+=2520){
			int total_num=1;
			num[0]=num_of_dividor(i,2);
			num[1]=num_of_dividor(i,3);
			num[2]=num_of_dividor(i,5);
			num[3]=num_of_dividor(i,7);
			num[4]=num_of_dividor(i,11);
			for (int j = 0; j < 5; ++j)
			{
				if(num[j]!=0) total_num*=(num[j]+1);
			}
			if (largest_now<total_num){
				largest_now=total_num;
				largest_num=i;
			}
		}
	}
	cout<<largest_num<<endl;
	
	
}