
#include <iostream>
#include <vector>

using namespace std;

const int LENGTH = 12;

void group(int index, const vector<string>& data, vector<string>& zeros, vector<string>& ones) {
    int size = data.size();

    for (int i = 0; i < size; ++i) {
        string val = data[i];
        if (val[index] == '0') zeros.push_back(val);
        else if (val[index] == '1') ones.push_back(val);
    }
}

int binToDec(string bin) {
    int ret = 0;
    int factor = 1;
    
    for (int i = LENGTH - 1; i >= 0; --i) {
        if (bin[i] == '1') ret += factor;
        factor *= 2;
    }

    return ret;
}

int main() {
    vector<string> data;
    
    string value;
    while (cin >> value) {
        data.push_back(value);
    }

    vector<string> oxygen = data;
    vector<string> co2 = data;

    for (int i = 0; i < LENGTH; ++i) {
        vector<string> zeroes;
        vector<string> ones;
        if (oxygen.size() > 1) {
            group(i, oxygen, zeroes, ones);
            if (ones.size() >= zeroes.size()) oxygen = ones;
            else oxygen = zeroes;
        }

        zeroes.clear();
        ones.clear();

        if (co2.size() > 1) {
            group(i, co2, zeroes, ones);
            if (zeroes.size() <= ones.size()) co2 = zeroes;
            else co2 = ones;
        }

        zeroes.clear();
        ones.clear();
    }

    cout << binToDec(oxygen[0]) * binToDec(co2[0]) << endl;
}