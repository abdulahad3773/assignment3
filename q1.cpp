#include <iostream>
using namespace std;

int main() {
int n;

while (true) {
cout << "Enter n: ";
cin >> n;

if (n > 2 && n % 2 == 1) break;

cout << "n must be an odd number greater than 2" << endl;
}

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {

    int top = i;
    int left = j;
    int bot = n - i + 1;
    int right = n - j + 1;
    int small = top;
    if (left<small) small = left;
    if (bot <small) small = bot;
    if (right<small) small = right;
    int value = small % 10;

    cout << value << " ";
}

cout << endl;
}

return 0;
}