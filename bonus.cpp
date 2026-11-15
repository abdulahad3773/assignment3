#include <iostream>
#include <string>
#include "helperCells.h"
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
    int digits = 0, points = 0;
    int i = 0;
    if (s.length() > 0 && s[0] == '-')
        i = 1;
    for (; i < (int)s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            digits++;
        else if (s[i] == '.')
            points++;
        else
            return false;
    }
    return digits > 0 && points <= 1;
}

double calculate(string formula, int row, int col)
{
    double numbers[ROWS + COLS];
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
        cout << string(WIDTH / 2, ' ') << (char)('A' + c)
             << string(WIDTH - WIDTH / 2 + 1, ' ') << "|";
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
                    value = stod(content[r][c]);

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
        cout << "Arrows: move   Type a value + Enter   Delete: clear   Q: quit";
    cout << flush;
}

int main()
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
                string op = typing.substr(2);
                if (op == "sum" || op == "sub" || op == "mul" || op == "div" || op == "avg")
                    good = true;
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
            else if (key == KEY_DOWN && curRow < ROWS - 1)
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