

#include <iostream>
using namespace std;


int sumFib(int k, int base) {
    int a = 1, b = 1, sumf = 0;
    for (int i = 1; i <= k; i++) {
        sumf = (sumf + a) % base;
        int next = (a + b) % base;
        a = b;
        b = next;
    }
    return sumf;
}

char toDigit(int v) {
    return (v < 10) ? char('0' + v) : char('A' + (v - 10));
}

int main() {
    int n, base;
    int seed;

    cout << "N: ";
    cin >> n;
    cout << "Base: ";
    cin >> base;
    cout << "Seed: ";
    cin >> seed;

    while (n < 1 || base < 2 || base > 16||seed < 1 || seed >= base) {
    cout << "Invalid input! Please enter again." << endl;
    cout << "N: ";
    cin >> n;
    cout << "Base : ";
    cin >> base;
    cout << "Seed: ";
    cin >> seed;
    }
    int middle = n - 1;  
    cout << endl;
    for (int i = 0; i < (2 * n - 1); i++) {
        for (int j = 0; j < (2 * n - 1); j++) {
            int dr = i - middle;
            int dc = j - middle; 
            int adr = abs(dr);
            int adc =  abs(dc);
            int k = adr > adc ? adr : adc;

            int off = 0;
            if (k > 0) {
                int S = sumFib(k, base);
                if (dr == -k) off = S;                             
                else if (dr == k) off = -S;                            
                else if (dc == k) off = (dr <= 0) ? S : S - 2 * sumFib(dr, base);   
                else off = (dr >= 0) ? -S : -S + 2 * sumFib(-dr, base); 
            }
            int v = ((seed + off) % base + base) % base;
            cout << toDigit(v) << ' ';
        }
        cout << endl;
    }
    return 0;
}