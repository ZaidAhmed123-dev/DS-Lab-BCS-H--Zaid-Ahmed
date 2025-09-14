#include<iostream>
#include<ctime>
using namespace std;

void bubble(int a[], int n, int &c, int &s) 
{
    c = s = 0;
    for(int i=0; i<n-1; i++) 
    {
        for(int j=0; j<n-i-1; j++) 
        {
            c++;
            if(a[j] > a[j+1]) 
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                s++;
            }
        }
    }
}

void insert(int a[], int n, int &c, int &s) 
{
    c = s = 0;
    for(int i=1; i<n; i++) 
    {
        int k = a[i];
        int j = i-1;
        while(j >= 0) 
        {
            c++;
            if(a[j] > k) 
            {
                a[j+1] = a[j];
                s++;
                j--;
            } 
            else break;
        }
        a[j+1] = k;
    }
}

void shell(int a[], int n, int &c, int &s) 
{
    c = s = 0;
    for(int g=n/2; g>0; g/=2) 
    {
        for(int i=g; i<n; i++) 
        {
            int t = a[i];
            int j = i;
            while(j >= g)
              {
                c++;
                if(a[j-g] > t) 
                {
                    a[j] = a[j-g];
                    s++;
                    j -= g;
                } 
                else 
                  break;
            }
            a[j] = t;
        }
    }
}

int main() {
    int n;
    cout << "size: ";
    cin >> n;

    int *a = new int[n];
    for(int i=0; i<n; i++) 
    {
        a[i] = rand() % 10000;
    }

    int *b = new int[n];
    int *c = new int[n];
    int *d = new int[n];
    for(int i=0; i<n; i++) 
    {
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    int cmp, sw;
    clock_t st, en;

    st = clock();
    bubble(b, n, cmp, sw);
    en = clock();
    cout << "bubble - time: " << (double)(en-st)/CLOCKS_PER_SEC << "s comps: " << cmp << " swaps: " << sw << endl;

    st = clock();
    insert(c, n, cmp, sw);
    en = clock();
    cout << "insert - time: " << (double)(en-st)/CLOCKS_PER_SEC << "s comps: " << cmp << " swaps: " << sw << endl;

    st = clock();
    shell(d, n, cmp, sw);
    en = clock();
    cout << "shell - time: " << (double)(en-st)/CLOCKS_PER_SEC << "s comps: " << cmp << " swaps: " << sw << endl;

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;
}
