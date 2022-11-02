#include <bits/stdc++.h>
using namespace std;
class Matrix{
public:
    long double a[20][21],z;;
    int n,mul=1;
    void input(){
        cout<<"Enter the size of matrix:";
        cin>>n;
        cout<<"Enter a matrix:\n";
        for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
        cin>>a[i][j];
    }
    void reduce(int f){
        for(int k=0;k<n;k++){
        int q=k;
        if(!a[k][k]){
            for(int h=k+1;h<n;h++)
            if(a[h][k]){
                q=h;
                break;
            }
            double b[n];
            for(int i=0;i<n && q!=k;i++){
                b[i]=a[k][i];
                a[k][i]=a[q][i];
                a[q][i]=b[i];
            }
        }
        if(q==k && !a[k][k])
            continue;
        for(int i=0;i<n;i++){
            if((i<=k && !f)||(i>=k && f))
            continue;
            long double p=(a[i][k]/a[k][k]);
            long double l=a[i][k],m=a[k][k];
            for(int j=k;j<n+1;j++)
            a[i][j]=a[i][j]-p*a[k][j];
            if(!p)
            cout<<endl<<"No reduction for R"<<i+1<<endl;
            else if(p>=0){
                if(l<0){
                    l*=-1;
                    m*=-1;
                }
                cout<<endl<<"R"<<i+1<<" -> "<<"R"<<i+1<<" - ("<<l<<"/"<<m<<")*R"<<k+1<<endl;
            }
            else{
                if(l<0)
                l*=-1;
                else
                m*=-1;
                    cout<<endl<<"R"<<i+1<<" -> "<<"R"<<i+1<<" + ("<<l<<"/"<<m<<")*R"<<k+1<<endl;
                }
                display();
                cout<<"-------------------------------------------------------------------------\n";
            }
        }
    }
    void display(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n+1;j++)
            cout<< fixed << setprecision(2) << a[i][j]<<"\t";
            cout<<endl;
        }
    }
    void remains(){
        for(int i=0;i<n;i++)
        mul*=a[i][i];
        for(int i=0;i<n;i++){
            if(a[i][i]){
                a[i][n]/=a[i][i];
                a[i][i]=1;
            }
        }
        cout<<endl<<"Reduced matrix:\n";
        display();
        cout<<"-------------------------------------------------------------------------\n";
        cout<<endl<<"Determinant: "<<mul<<endl;
        int c=0,d=0;
for(int i=0;i<n;i++){
            if(a[i][i])
            c++;
            if(a[i][i] || a[i][n])
            d++;
        }
        if(c==d && c==n && mul){
            cout<<endl<<"Unique solution\n";
            for (int i=0;i<n;i++)
            cout<<"\nX"<<i+1<<": "<<a[i][n]<<"\t";
        }
        else if(c==d && c<n)
        cout<<endl<<"Infinite solution\n";
        else
        cout<<endl<<"No Solution\n";
        cout<<endl;
    }
};
int main(){
    Matrix obj;
    obj.input();
    obj.reduce(0);
    obj.reduce(1);
    obj.remains();
    return 0;
}