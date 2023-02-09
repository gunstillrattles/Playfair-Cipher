#include<iostream>
#include<string>
using namespace std;
int main() {
    string plaintext, ciphertext, plain_rep;
    string key, rep;
    cout << "Enter plain text : ";
    cin >> plaintext;
    cout << "Enter key : ";
    cin >> key;
    rep = rep + key;
    //to add 'x' in between two same characters
    for (int i = 0; i < plaintext.length();) {
        if (plaintext[i] == plaintext[i + 1]) {
            plain_rep = plaintext.substr(0, i + 1) + 'x' + plaintext.substr(i + 1, plaintext.length() - 1);
            plaintext = plain_rep;
            i = 0;
        }
        i = i + 2;
    }
    if (plaintext.length() % 2 != 0) {
        plaintext = plaintext + 'x';
    }
    //this is to remove duplicates from key
    for (int i = 0; i < key.length(); i++) {
        for (int j = 0; j < key.length(); j++) {
            if (key[i] == key[j] && i != j) {
                key.erase(key.begin() + j);
            }
        }
    }
    //to add other characters in key
    char asc = 97;
    for (int i = key.length(); i < 26; i++) {
        int j = 0;
        for (j; j < rep.length(); j++) {
            if (asc == 106) {
                asc++;
                continue;
            }
            if (asc == rep[j]) {
                j = 0;
                asc++;

                continue;
            }
        }
        if (j == rep.length()) {
            key = key + asc;
            asc++;
        }
    }
    //to add all key elements in two dimensional array
    char a[5][5];
    int m = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            a[i][j] = key[m];
            m++;
        }
    }
    //encrypting-making cypher text
    for (int s = 0; s < plaintext.length(); s++) {
        if (s % 2 == 0) {
            int one = 0, two = 0, three = 0, four = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (plaintext[s] == a[i][j]) {
                        one = i;
                        two = j;
                    }
                    if (plaintext[s + 1] == a[i][j]) {
                        three = i;
                        four = j;
                    }
                }

            }
            if (one == three) {
                if (two == 4) {
                    ciphertext = ciphertext + a[one][0] + a[three][four + 1];
                }
                else if (four == 4) {
                    ciphertext = ciphertext + a[one][two + 1] + a[three][0];
                }
                else {
                    ciphertext = ciphertext + a[one][two + 1] + a[three][four + 1];
                }
            }
            else if (two == four) {
                if (one == 4) {
                    ciphertext = ciphertext + a[0][two] + a[three + 1][four];
                }
                else if (three == 4) {
                    ciphertext = ciphertext + a[one + 1][two] + a[0][four];
                }
                else {
                    ciphertext = ciphertext + a[one + 1][two] + a[three + 1][four];
                }

            }
            else {
                ciphertext = ciphertext + a[one][four] + a[three][two];
            }
        }
        else {
            continue;
        }
    }
    cout << "Cipher text : " << ciphertext;
    return 0;

}