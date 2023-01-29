#include <stdio.h>
#include <iostream>
#include <string> 
#include<vector>  

using namespace std;

int main()
{
    int t,n,a,c=0,test=0,i,j;
    cin>>t;
    while(t>0){
        cin>>n;
        int v[n];
        for(i=0;i<n;i++){
            cin>>a;
            v[i]=a;  
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(v[i]==v[j]){
                    c++;
                }
            }
            if(c==3){
                cout<<v[i]<<endl;
                c=0;
                test=1;
                break;
            }
        }
        if(test==0){
            cout<<-1<<endl;
        }
        c=0;
        test=0;
        i=0;
        j=0;
        t--;
    }
    return 0;
}