#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string s; getline(cin, s);
    int num(0), big(0), small(0), space(0);
    for (auto &it : s) {
        if (isdigit(it)) num++;
        else if (isupper(it)) big++;
        else if (islower(it)) small++;
        else if (isspace(it)) space++;
    }
    cout << "Сд��ĸ=" << small << endl;
    cout << "��д��ĸ=" << big << endl;
    cout << "����=" << num << endl;
    cout << "�ո�=" << space << endl;
    return 0;
}

