#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int max=0;
    int distance=0;
    for(char c:s){
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y'){
            distance=0;
        }
        else{
            distance++;
            if(distance>max){
                max=distance;
            }
        }

    }
    cout<<max+1;
    return 0;
}