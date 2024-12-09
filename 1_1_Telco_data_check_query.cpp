#include <bits/stdc++.h>
using namespace std;

bool isPhoneNumber(string s){
    if (s.length() != 10) return false;
    for (char c: s) if (c<'0' || c>'9') return false;
    return true;
}

int countTime(string ftime, string etime){
    int fromTime = 3600*((ftime[0]-'0')*10 + ftime[1]-'0') + 60*((ftime[3]-'0')*10 + ftime[4]-'0') + ((ftime[6]-'0')*10 + ftime[7]-'0');
    int endTime = 3600*((etime[0]-'0')*10 + etime[1]-'0') + 60*((etime[3]-'0')*10 + etime[4]-'0') + ((etime[6]-'0')*10 + etime[7]-'0');
    return (endTime-fromTime);
}

map <string,int> numberCalls, timeCall;

int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    string cmd;
    int totalCalls = 0;
    int incorrectPhone = 0;

    while (cin >> cmd) {
        if (cmd == "#") {
            break;
        }
        else {
            ++totalCalls;
            string fnum, tnum, date, ftime, etime;
            cin >> fnum >> tnum >> date >> ftime >> etime;
            if (!isPhoneNumber(fnum) || !isPhoneNumber(tnum)) ++incorrectPhone;
            numberCalls[fnum]++;
            timeCall[fnum] += countTime(ftime, etime);
        }
    }
    while (cin >> cmd) {
        if (cmd == "#") {
            break;
        }
        else if (cmd == "?check_phone_number") {
            if (incorrectPhone == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (cmd == "?number_calls_from") {
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;
        }
        else if (cmd == "?number_total_calls")
            cout << totalCalls << endl;
        else if (cmd == "?count_time_calls_from") {
            string phone;
            cin >> phone;
            cout << timeCall[phone] << endl;
        }
    }
}
