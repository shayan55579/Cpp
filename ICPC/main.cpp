#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

vector<char>op;
vector<int>num;
const int MAXN=2e5+5;
int a[MAXN],b[MAXN];
int main()
{
    string s;
    cin>>s;
    int c = s[0] -'a';// asci code
    int r = 8-(s[1]-'0');
    char a[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;i<8;j++)
            a[i][j] = '.';


    cout<<a;
//    for(int i=0;i<8;i++)
//        for(int j=0;i<8;j++)
//            if(i==r)
//            a[i][j] = 'X';
//    for(int i=0;i<8;i++)
//        for(int j=0;i<8;j++)
//            if(i==r)
//            a[i][j] = 'X';
        return 0;
}




