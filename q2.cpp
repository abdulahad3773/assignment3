#include <iostream>
#include <string>
using namespace std;
int main() {
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