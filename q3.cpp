#include <iostream>
using namespace std;

int main() {
    int n=0;

    for(;n<=2||n%2==0;) {
        cout<<"Enter n: ";
        cin>>n;
    }

    int row=2*n-1;

    for(int i=1;i<=row;i++) {
        int d=0;
        if(i<n) d=n-i;
        else d=i-n;
        int w=n-1-d;
        
        for(int j=1;j<=d;j++) {
            cout<<" ";
        }

        for(int j=1;j<=2*w+1;j++) {
            int l=0;
            if(j<=w+1) l=j-1;
            else l=2*w+1-j;
            int k=(n-1-l)%4;
            if(k==0) cout<<'*';
            else if(k==1) cout<<'-';
            else if(k==2) cout<<'o';
            else cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}