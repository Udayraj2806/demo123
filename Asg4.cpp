#include <bits/stdc++.h>

using namespace std;

string key;
void func(string k)
{
    key.clear();
    for (int i = 0; i < k.size(); ++i)
    {
        if (k[i] >= 'A' && k[i] <= 'Z')
            key += k[i];
        else if (k[i] >= 'a' && k[i] <= 'z')
            key += k[i] + 32;
    }
}
string encryption(string t)
{
    string output;
    for (int i = 0, j = 0; i < t.length(); ++i)
    {
        char c = t[i];
        if (c == ' ')
            continue;
        if (c >= 'a' && c <= 'z')
            c += 32;
        else if (c < 'A' || c > 'Z')
            continue;
        output += (c + key[j] - 2 * 'A') % 26 + 'A';
        j++;
        j = j % key.size();
    }
    return output;
}
string decryption(string t)
{
    string output;
    for (int i = 0, j = 0; i < t.length(); ++i)
    {
        char c = t[i];
        if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
            continue;
        output += (c - key[j] + 26) % 26 + 'A';
        j = (j + 1) % key.length();
    }
    return output;
}

int main()
{

    int choice;
    int datachoice;
    string sample, key;
    int shift;
    cout << "=======================================\n\n\n Vigenere Cipher \n\n=======================================";

    while (1)
    {
        cout << "\n 1. Encryption \n 2. Decryption\n 3. Exit\nEnter Choice: ";
        cin >> choice;
        if (choice > 2)
            break;
        switch (choice)
        {
        case 1:

            cout << "Enter data to be Encrypted:\n";
            cin.ignore();
            getline(cin, sample);
            cout << "Enter the key: ";
            getline(cin, key);
            func(key);
            cout << "Encrypted String:\n";
            cout << encryption(sample) << endl;
            break;

        case 2:
            cout << "Enter data to be Decrypted:\n";
            cin.ignore();
            getline(cin, sample);
            cout << "Enter the key: ";
            getline(cin, key);
            func(key);
            cout << "Decrypted String:\n";
            cout << decryption(sample) << endl;
            ;
            break;
        }
    }
    return 0;
}