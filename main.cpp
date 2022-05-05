#include <iostream>
#include<fstream>
#include <vector>
#include<bitset>

using namespace std;

int main()
{
    fstream f1;
    f1.open("graycode_n.txt", ios::in);
    int n;
    if (!f1.is_open()) {
        exit(-1);
    }
    f1 >> n;
    f1.close();

    vector<int> ret(1 << n);

    for (int i = 0; i < ret.size(); i++) {
        ret[i] = (i >> 1) ^ i;
    }

    fstream f2;
    f2.open("graycode.txt", ios::out);
    if (!f2.is_open()) {
        exit(-1);
    }
    for (auto i = ret.begin(); i != ret.end(); i++) {
        bitset<5>b(*i);
        string s = b.to_string();
        f2 << s << endl;
    }
    f2.close();

    return 0;
}
