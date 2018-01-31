#include<iostream>
using namespace std;
bool leapYear(int y);
int main(){
  const string MONTH[] = {"January","February","March","April","May","June", "July","August","September","October","November","December"}; 
  int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
  int days_in_month_leap[] = {31,29,31,30,31,30,31,31,30,31,30,31}; 
  int year;
  int days =0;
  cin >> year;
  //days to the 1-1 of that year
  if (year>=2016){
    for (int i = 2016; i < year; ++i)
    {
      if (leapYear(i)==true) days+=366;
      else days+=365;
    }
  }else{
    for (int i = year; i < 2016; ++i)
    {
      if (leapYear(i)==true) days-=366;
      else days-=365;
    }
  }

  if ((days+12)%7==0) cout <<MONTH[0]<<endl;
  if (leapYear(year)==true)
  {
    for (int i = 0; i < 11; ++i)
    {
      days+=days_in_month_leap[i];
      if ((days+12)%7==0) cout <<MONTH[i+1]<<endl;
    }
  }else{
    for (int i = 0; i < 11; ++i)
    {
      days+=days_in_month[i];
      if ((days+12)%7==0) cout <<MONTH[i+1]<<endl;
    }
  }

}

bool leapYear(int y){
  if (y % 400 == 0){
    return true;
  }else if (y % 4 ==0 && y % 100 !=0) {
    return true;
  }else{
    return false;
  }
}