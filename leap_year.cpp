#include<iostream>
using namespace std;
int main(){
  int year;
  while(true){
  	cout<< "Enter a year (or negative number to quit):";
  	cin >> year;
  	if (year < 0) {
  		cout << "Bye!" <<endl;
  		break;
  	}else{
  		if (year % 400 == 0){
  			cout << year << " is a leap year."<<endl;
  		}else if (year % 4 ==0 && year % 100 !=0) {
  			cout << year << " is a leap year." <<endl;
  		}else{
  			cout << year << " is not a leap year." <<endl;
  		}
  	}
  }

}