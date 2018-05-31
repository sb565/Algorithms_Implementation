#include <iostream>
#include <vector>
using namespace std;

vector <int> a;

void insort(int n,int i=1){
    if(i>=n) return;
    int t,k=i;
    while(k-1>=0&&a[k]<a[k-1])
    {
        t=a[k];
        a[k]=a[k-1];
        a[k-1]=t;
        k--;
    }
    insort(n,i+1);
}

int sum(int n){
    if(n<1)return 0;
    if(n==1)
        return a[n-1];
    else
        return a[n-1] + sum(n-1);
}

int power(int a,int b){
    if(b==0)
        return 1;
    else
        return a*power(a,b-1);
}

int fact(int n){
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}

int lsearch(int x, int n){
    if(n<1) return 0;
    else{
        if(a[n-1]==x)
            return 1;
        else
            return lsearch(x,n-1);
    }
}

int bsearch(int x,int b,int e){
    if(e>=b){
        int mid=(b+e)/2;
        if(x==a[mid])
            return mid;
        else if(x>a[mid])
            return bsearch(x,mid+1,e);
        else
            return bsearch(x,b,mid-1);
    }
    return -1;
}

int main()
{
    int n,j,k;
    cout<<"Enter the number of elements :";cin>>n;
    cout<<"Enter the elements :\n";
    for(int i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }
    insort(n);
    cout<<"Sorted array :";
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    cout<<endl;
    cout<<"Sum :"<<sum(n)<<endl;
    cout<<"Enter value to be searched :";cin>>k;
    if(lsearch(k,n))
        cout<<"Element found at :"<<bsearch(k,0,n-1)<<endl;
    else
        cout<<"Element not found"<<endl;

    cout<<"Enter number and power :";cin>>j>>k;
    cout<<power(j,k)<<endl;
    cout<<"Enter number for factorial :";cin>>k;
    cout<<fact(k)<<endl;
    return 0;
}


