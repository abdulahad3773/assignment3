#include "helperCells.h"
#include <iostream>
#include <string>

using namespace std;

int question1() {
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
using namespace std;
int question2() {
    int year,month;
    bool valid=true;

    while(valid) {
        cout<<"Year::: ";
        cin>>year;
        cout<<"Month::: ";
        cin>>month;

        if(year>=1 && year <=9999 && month >=1 && month<=12)
            valid=false;
        else
            cout<<"Enter valid year or month "<<endl;
    }
    bool leap=false;
    if(year%4 ==0) {
        leap=true;
        if(year%100==0) {
            if(year%400==0) leap=true;
            else leap=false;
        }
    }
    int total=365*(year-1) +(year-1)/4 - (year-1)/100 + (year-1)/400;
    int days=0;
    for(int i=1;i<=month;i++) {
        int day_in_month;
        if(i==4 || i==6 || i==9 || i==11) day_in_month=30;
        else if(i==2) day_in_month=leap?29:28;
        else day_in_month=31;

        if(i<month) total+=day_in_month;
        else days=day_in_month;
    }
    int startDay=(total+1)%7;
    string name;
    switch(month) {
        case 1: name="January"; break;
        case 2: name="February"; break;
        case 3: name="March"; break;
        case 4: name="April"; break;
        case 5: name="May"; break;
        case 6: name="June"; break;
        case 7: name="July"; break;
        case 8: name="August"; break;
        case 9: name="September"; break;
        case 10: name="October"; break;
        case 11: name="November"; break;
        default: name="December"; break;
    }

    string heading=name+ " " +to_string(year);
    cout<<endl;
    int space=(20-(int)heading.length())/2;
    for(int i=1;i<=space;i++) cout<<" ";
    cout<<heading<<endl;
    cout<<"Su Mo Tu We Th Fr Sa"<<endl;

    for(int i=0;i<startDay;i++) cout<<"   ";

    int col=startDay;

    for(int j=1;j<=days;j++) {
        if(j<10) cout<<" ";
        cout<<j<<" ";
        col++;
        if(col==7) {
            cout<<endl;
            col=0;
        }
    }
    return 0;
}
using namespace std;

int question3() {
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

int question4() {
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
using namespace std;

int c0=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0;
int c10=0,c11=0,c12=0,c13=0,c14=0,c15=0,c16=0,c17=0,c18=0,c19=0;
int c20=0,c21=0,c22=0,c23=0,c24=0,c25=0,c26=0,c27=0,c28=0,c29=0;
int c30=0,c31=0,c32=0,c33=0,c34=0,c35=0,c36=0,c37=0,c38=0,c39=0;
int c40=0,c41=0,c42=0,c43=0,c44=0,c45=0,c46=0,c47=0,c48=0,c49=0;
int c50=0,c51=0,c52=0,c53=0,c54=0,c55=0,c56=0,c57=0,c58=0,c59=0;
int c60=0,c61=0,c62=0,c63=0,c64=0,c65=0,c66=0,c67=0,c68=0,c69=0;
int c70=0,c71=0,c72=0,c73=0,c74=0,c75=0,c76=0,c77=0,c78=0,c79=0;
int c80=0,c81=0,c82=0,c83=0,c84=0,c85=0,c86=0,c87=0,c88=0,c89=0;
int c90=0,c91=0,c92=0,c93=0,c94=0,c95=0,c96=0,c97=0,c98=0,c99=0;

int getCell(int r, int c) {
    int i = r * 10 + c;
    if (i == 0) return c0;   if (i == 1) return c1;   if (i == 2) return c2;   if (i == 3) return c3;   if (i == 4) return c4;
    if (i == 5) return c5;   if (i == 6) return c6;   if (i == 7) return c7;   if (i == 8) return c8;   if (i == 9) return c9;
    if (i == 10) return c10; if (i == 11) return c11; if (i == 12) return c12; if (i == 13) return c13; if (i == 14) return c14;
    if (i == 15) return c15; if (i == 16) return c16; if (i == 17) return c17; if (i == 18) return c18; if (i == 19) return c19;
    if (i == 20) return c20; if (i == 21) return c21; if (i == 22) return c22; if (i == 23) return c23; if (i == 24) return c24;
    if (i == 25) return c25; if (i == 26) return c26; if (i == 27) return c27; if (i == 28) return c28; if (i == 29) return c29;
    if (i == 30) return c30; if (i == 31) return c31; if (i == 32) return c32; if (i == 33) return c33; if (i == 34) return c34;
    if (i == 35) return c35; if (i == 36) return c36; if (i == 37) return c37; if (i == 38) return c38; if (i == 39) return c39;
    if (i == 40) return c40; if (i == 41) return c41; if (i == 42) return c42; if (i == 43) return c43; if (i == 44) return c44;
    if (i == 45) return c45; if (i == 46) return c46; if (i == 47) return c47; if (i == 48) return c48; if (i == 49) return c49;
    if (i == 50) return c50; if (i == 51) return c51; if (i == 52) return c52; if (i == 53) return c53; if (i == 54) return c54;
    if (i == 55) return c55; if (i == 56) return c56; if (i == 57) return c57; if (i == 58) return c58; if (i == 59) return c59;
    if (i == 60) return c60; if (i == 61) return c61; if (i == 62) return c62; if (i == 63) return c63; if (i == 64) return c64;
    if (i == 65) return c65; if (i == 66) return c66; if (i == 67) return c67; if (i == 68) return c68; if (i == 69) return c69;
    if (i == 70) return c70; if (i == 71) return c71; if (i == 72) return c72; if (i == 73) return c73; if (i == 74) return c74;
    if (i == 75) return c75; if (i == 76) return c76; if (i == 77) return c77; if (i == 78) return c78; if (i == 79) return c79;
    if (i == 80) return c80; if (i == 81) return c81; if (i == 82) return c82; if (i == 83) return c83; if (i == 84) return c84;
    if (i == 85) return c85; if (i == 86) return c86; if (i == 87) return c87; if (i == 88) return c88; if (i == 89) return c89;
    if (i == 90) return c90; if (i == 91) return c91; if (i == 92) return c92; if (i == 93) return c93; if (i == 94) return c94;
    if (i == 95) return c95; if (i == 96) return c96; if (i == 97) return c97; if (i == 98) return c98;
    return c99;
}

void setCell(int r, int c, int d) {
    int i = r * 10 + c;
    if (i == 0) c0 = d;   else if (i == 1) c1 = d;   else if (i == 2) c2 = d;   else if (i == 3) c3 = d;   else if (i == 4) c4 = d;
    else if (i == 5) c5 = d;   else if (i == 6) c6 = d;   else if (i == 7) c7 = d;   else if (i == 8) c8 = d;   else if (i == 9) c9 = d;
    else if (i == 10) c10 = d; else if (i == 11) c11 = d; else if (i == 12) c12 = d; else if (i == 13) c13 = d; else if (i == 14) c14 = d;
    else if (i == 15) c15 = d; else if (i == 16) c16 = d; else if (i == 17) c17 = d; else if (i == 18) c18 = d; else if (i == 19) c19 = d;
    else if (i == 20) c20 = d; else if (i == 21) c21 = d; else if (i == 22) c22 = d; else if (i == 23) c23 = d; else if (i == 24) c24 = d;
    else if (i == 25) c25 = d; else if (i == 26) c26 = d; else if (i == 27) c27 = d; else if (i == 28) c28 = d; else if (i == 29) c29 = d;
    else if (i == 30) c30 = d; else if (i == 31) c31 = d; else if (i == 32) c32 = d; else if (i == 33) c33 = d; else if (i == 34) c34 = d;
    else if (i == 35) c35 = d; else if (i == 36) c36 = d; else if (i == 37) c37 = d; else if (i == 38) c38 = d; else if (i == 39) c39 = d;
    else if (i == 40) c40 = d; else if (i == 41) c41 = d; else if (i == 42) c42 = d; else if (i == 43) c43 = d; else if (i == 44) c44 = d;
    else if (i == 45) c45 = d; else if (i == 46) c46 = d; else if (i == 47) c47 = d; else if (i == 48) c48 = d; else if (i == 49) c49 = d;
    else if (i == 50) c50 = d; else if (i == 51) c51 = d; else if (i == 52) c52 = d; else if (i == 53) c53 = d; else if (i == 54) c54 = d;
    else if (i == 55) c55 = d; else if (i == 56) c56 = d; else if (i == 57) c57 = d; else if (i == 58) c58 = d; else if (i == 59) c59 = d;
    else if (i == 60) c60 = d; else if (i == 61) c61 = d; else if (i == 62) c62 = d; else if (i == 63) c63 = d; else if (i == 64) c64 = d;
    else if (i == 65) c65 = d; else if (i == 66) c66 = d; else if (i == 67) c67 = d; else if (i == 68) c68 = d; else if (i == 69) c69 = d;
    else if (i == 70) c70 = d; else if (i == 71) c71 = d; else if (i == 72) c72 = d; else if (i == 73) c73 = d; else if (i == 74) c74 = d;
    else if (i == 75) c75 = d; else if (i == 76) c76 = d; else if (i == 77) c77 = d; else if (i == 78) c78 = d; else if (i == 79) c79 = d;
    else if (i == 80) c80 = d; else if (i == 81) c81 = d; else if (i == 82) c82 = d; else if (i == 83) c83 = d; else if (i == 84) c84 = d;
    else if (i == 85) c85 = d; else if (i == 86) c86 = d; else if (i == 87) c87 = d; else if (i == 88) c88 = d; else if (i == 89) c89 = d;
    else if (i == 90) c90 = d; else if (i == 91) c91 = d; else if (i == 92) c92 = d; else if (i == 93) c93 = d; else if (i == 94) c94 = d;
    else if (i == 95) c95 = d; else if (i == 96) c96 = d; else if (i == 97) c97 = d; else if (i == 98) c98 = d;
    else c99 = d;
}

// 1 if the cell is inside the grid and already visited
int isVisited(int r, int c, int n) {
    if (r < 0 || c < 0 || r >= n || c >= n) return 0;
    if (getCell(r, c) >= 5) return 1;
    return 0;
}

int question5() {
    int n;
    cin >> n;

    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ch;
            int d = 0;
            if (ch == '.') d = 0;
            else if (ch == '*') d = 1;
            else if (ch == 'S') d = 7;   // start is visited from the beginning
            else if (ch == 'E') d = 3;
            else if (ch == 'G') d = 4;
            setCell(i, j, d);
        }
    }

    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = getCell(i, j);
                if (d == 1 || d >= 5) continue;   // wall or already visited
                if (isVisited(i - 1, j, n) || isVisited(i + 1, j, n) ||
                    isVisited(i, j - 1, n) || isVisited(i, j + 1, n)) {
                    setCell(i, j, d + 5);
                    changed = 1;
                }
            }
        }
    }

    int gold = 0, solvable = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d = getCell(i, j);
            if (d == 9) gold++;      // visited gold
            if (d == 8) solvable = 1; // visited exit
        }
    }

    if (solvable) cout << "Solvable: YES" << endl;
    else cout << "Solvable: NO" << endl;
    cout << "Gold reachable: " << gold << endl;
    return 0;
}
using namespace std;

const int ROWS = 21;
const int COLS = 8;
const int WIDTH = 10;
const int MAX_INPUT = 9;

string content[ROWS][COLS];
int curRow = 0, curCol = 0;
string typing = "";


bool isNumber(string s)
{
    int digits = 0, decpoints = 0;
    int i = 0;
    if (s.length() > 0 && s[0] == '-')
        i = 1;
    for (; i < (int)s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            digits++;
        else if (s[i] == '.')
            decpoints++;
        else
            return false;
    }
    return digits > 0 && decpoints <= 1;//only 1 decpoint and at least 1 digit
}

double calculate(string formula, int row, int col)
{
    double numbers[29];
    int count = 0;
    int last = col;
    if (formula[1] == 'c')
        last = row;
    for (int i = 0; i < last; i++)
    {
        string text = content[row][i];
        if (formula[1] == 'c')
            text = content[i][col];
        if (isNumber(text))
        {
            numbers[count] = stod(text);
            count++;
        }
    }
    if (count == 0)
        return 0;

    string op = formula.substr(2);
    double result = numbers[0];
    for (int i = 1; i < count; i++)
    {
        if (op == "sum" || op == "avg")
            result = result + numbers[i];
        else if (op == "sub")
            result = result - numbers[i];
        else if (op == "mul")
            result = result * numbers[i];
        else if (op == "div" && numbers[i] != 0)
            result = result / numbers[i];
    }
    if (op == "avg")
        result = result / count;
    return result;
}

void drawScreen()
{
    int lineWidth = 110;
    string name = string(1, (char)('A' + curCol)) + to_string(curRow);

    clearScreen();

    cout << name << " > " << content[curRow][curCol] << "\n";

    cout << string(lineWidth, '-') << "\n|    |";
    for (int c = 0; c < COLS; c++)
        cout << string(WIDTH / 2, ' ') << (char)('A' + c)<< string(WIDTH - WIDTH / 2 + 1, ' ') << "|";
    cout << "\n" << string(lineWidth, '-') << "\n";

    for (int r = 0; r < ROWS; r++)
    {
        cout << "| " << r;
        if (r < 10)
            cout << " ";
        cout << " |";

        for (int c = 0; c < COLS; c++)
        {
            string text = "";
            if (content[r][c] != "")
            {
                double value;
                if (content[r][c][0] == '=')
                    value = calculate(content[r][c], r, c);
                else
                    value = stod(content[r][c]);//stod convert string to double

                text = to_string(value);
                int end = text.length();
                while (text[end - 1] == '0')
                    end--;
                if (text[end - 1] == '.')
                    end--;
                text = text.substr(0, end);
                if (text == "-0")
                    text = "0";
                if ((int)text.length() > WIDTH)
                    text = text.substr(0, WIDTH);
            }

            if (r == curRow && c == curCol)
                cout << "[" << string(WIDTH - text.length(), ' ') << text << "]|";
            else
                cout << " " << string(WIDTH - text.length(), ' ') << text << " |";
        }
        cout << "\n";
    }
    cout << string(lineWidth, '-') << "\n";

    cout << "Column: =csum  =csub  =cmul  =cdiv  =cavg\n";
    cout << "Row:    =rsum  =rsub  =rmul  =rdiv  =ravg\n";

    if (typing != "")
        cout << name << " > " << typing;
    else
        cout << "Delete: clear Enter: submit  Q: quit";
    cout << flush;
}

int bonus()
{
    while (true)
    {
        drawScreen();
        int key = readKey();

        if (key < 0)
            break;

        else if (key >= 32 && key <= 126 && (typing != "" || (key != 'q' && key != 'Q')))
        {
            if ((int)typing.length() < MAX_INPUT)
                typing = typing + (char)key;
        }
        else if (key == KEY_ENTER)
        {
            bool good = isNumber(typing);
            if (typing.length() == 5 && typing[0] == '=' &&
                (typing[1] == 'c' || typing[1] == 'r'))
            {
                string op = typing.substr(2);//sub
                if (op == "sum" || op == "sub" || op == "mul" || op == "div" || op == "avg")
                    good = true;//invalid will not store cause good will be false
            }
            if (good)
                content[curRow][curCol] = typing;
            typing = "";
        }
        else if (key == KEY_DELETE)
        {
            if (typing != "")
                typing = typing.substr(0, typing.length() - 1);
            else
                content[curRow][curCol] = "";
        }
        else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
        {
            typing = "";
            if (key == KEY_UP && curRow > 0)
                curRow--;
            else if (key == KEY_DOWN && curRow < ROWS - 1)//as rows starts from 0 so the last row is ROWS - 1
                curRow++;
            else if (key == KEY_LEFT && curCol > 0)
                curCol--;
            else if (key == KEY_RIGHT && curCol < COLS - 1)
                curCol++;
        }
        else if (key == 'q' || key == 'Q')
            break;
    }
    cout << endl;
    return 0;
}
int main()
{
    while (true)
    {
        int choice;
        cout << "Choose a question (1-5) or 6 for bonus: ";
        cin >> choice;
        switch (choice)
        {
            case 1: question1(); break;
            case 2: question2(); break;
            case 3: question3(); break;
            case 4: question4(); break;
            case 5: question5(); break;
            case 6: bonus(); break;
            default: cout << "Invalid choice." << endl; break;
        }

        char again;
        cout << "\nDo you want to run another question? (y/n): ";
        cin >> again;
        if (again == 'n' || again == 'N')
            break;
    }
    return 0;
}
