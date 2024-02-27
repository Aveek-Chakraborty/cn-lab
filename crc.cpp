#include <bits/stdc++.h>

using namespace std;




void crc(string data, string gen, string& rem) {
    int dwordSize = data.length() - (gen.length() - 1);
    string out = data;

    for (int i = 0; i < dwordSize; i++) {
        if (out[i] == '0')
            continue;
        for (int j = 0; j < gen.length(); j++) {
            out[i + j] = (gen[j] == out[i + j] ? '0' : '1');
        }
    }
    rem = out.substr(dwordSize);
}



int main() {
    string dword, augWord, cword, rem, recv;
    string gen = "10001000000100001";

    cout << "\nCRC-16 Generator : x^16 + x^12 + x^5 + 1 ";
    cout << "\nBinary Form : " << gen;
    cout << "\n\nEnter Dataword : ";
    cin >> dword;

    augWord = dword + string(gen.length() - 1, '0');
    cout << "\nAugmented dataword is : " << augWord;

    crc(augWord, gen, rem);
    cword = dword + rem;

    cout << "\n\nFinal data transmitted : " << cword;
    cout << "\n\nEnter the data received : ";
    cin >> recv;

    if (recv.length() < cword.length()) {
        cout << "\n Invalid input \n";
        return 0;
    }

    crc(recv, gen, rem);
    cout << "\nSyndrome = " << rem;

    for (char bit : rem) {
        if (bit == '1') {
            cout << "\nError occurred !!! Corrupted data received.\n";
            return 0;
        }
    }
    cout << "\nNo Error. Data received successfully.\n";
    return 0;
}
