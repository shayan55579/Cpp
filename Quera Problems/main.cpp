#include <iostream>

using namespace std;

int main()
{
    int n,x,y;
    cin>>n,x,y;
    int a = n/x;
    int b;
    while(n<a){
         b=n/y;
        a+b;
    }
    cout<<a<<b;
    return 0;
}
