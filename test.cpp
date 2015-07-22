#include<iostream>
#include<stdio.h>
using namespace std;

class Collatz{
   public :
        int start;
        int a[1000];
        int x;
        Collatz(int);
        void next();
        bool isPowerofTwo(int);
        void printMax();
};

Collatz :: Collatz(int p){
    a[0] = 0;
    start = p;
    x = 0;
}

void Collatz :: next(){
        int n = start,i=0;
        a[0] = n;
        while ( n != 4 ){
            if ( n % 2 == 1)
                n = n * 3 + 1;
            else n /= 2;
            a[++i] = n;
            cout << n << endl;
        }
        x = i;
          cout << 2 << endl << 1 << endl;
}


bool Collatz :: isPowerofTwo(int n){
    while( n != 2 )
    {
        n = n / 2;
        if ( n % 2 != 0 ) return 0;
    }
return 1;
}

void Collatz :: printMax()
{
    int i,max=2;
    for(i=0;i<x;i++) cout << a[i] << endl;
    for(i=0;i<x;i++){
            if(isPowerofTwo(a[i]))
                        if(a[i]>max) max = a[i];
    }
    cout << "Max = " << max << endl ;

}
int main(){
Collatz obj(9);
obj.next();
obj.printMax();
return 0;
}
