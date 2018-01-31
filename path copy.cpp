#include <iostream>
#include <vector>
#include<list>
#include<cmath>
using namespace std;
struct point{
    int x;
    int y;
    int visited;
};
bool distance(point a,point b,int d){
    if((pow((a.x-b.x),2.0)+pow((a.y-b.y),2.0))<pow(d,2.0)) return true;
    return false;
}
void link(vector<int>arr[],int v, int u){
    arr[v].push_back(u);
    arr[u].push_back(v);
}
int main(){
    int n, d;
    vector<int> arr[10];
    vector<point> phone;
    cin>>n>>d;
    int x,y;
    point newPhone;
    for (int i = 0; i < n; ++i)
    {
        cin>>x>>y;
        newPhone.x=x;
        newPhone.y=y;
        phone.push_back(newPhone);
    }
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            if(distance(phone[i],phone[j],d)) link(arr,i,j);
        }
    }
    phone[0].visited=1;
    vector<int>queue;
    for (int j = 0; j < arr[0].size(); ++j){
        if(phone[arr[0][j]].visited==0){
            queue.push_back(arr[0][j]);
            phone[arr[0][j]].visited=1;
        }
    }
    int t;
    while(queue.size()!=0){
        for (int i = queue.size()-1; i > -1; --i){
            t = queue[i];
            queue.pop_back();
            for (int j = 0; j < arr[t].size(); ++j){
                if(phone[arr[t][j]].visited==0){
                    queue.push_back(arr[t][j]);
                    phone[arr[t][j]].visited=1;
                }
            }
        }
    }
    if(phone[n-1].visited==1){
        cout<<"y"<<endl;
    }else{
        cout<<"n"<<endl;
    }
}