#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string RailFenceEncrypt(string text, int key)
{
    string result;
    char rail[key][text.length()];
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < text.length(); j++)
        {
            rail[i][j] = '\n';
        }
    }
    bool dir_down;
    int row = 0, col = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        else if (row == key - 1)
            dir_down = false;
        rail[row][col++] = text[i];
        if (dir_down)
            row++;
        else
            row--;
    }
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < text.length(); j++)
        {
            if (rail[i][j] != '\n')
                result.push_back(rail[i][j]);
        }
    }
    return result;
}

string RailFenceDecrypt(string ciphertext, int key)
{
    string result;
    char rail[key][ciphertext.length()];
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < ciphertext.length(); j++)
        {
            rail[i][j] = '\n';
        }
    }
    bool dir_down;
    int row = 0, col = 0;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        else if (row == key - 1)
            dir_down = false;
        rail[row][col++] = '*';
        if (dir_down)
            row++;
        else
            row--;
    }
    int index = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < ciphertext.length(); j++)
        {
            if (rail[i][j] == '*' && index < ciphertext.length())
                rail[i][j] = ciphertext[index++];
        }
    }
    row = 0, col = 0;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        else if (row == key - 1)
            dir_down = false;
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);
        if (dir_down)
            row++;
        else
            row--;
    }
    return result;
}

int main()
{
    int Choice, key;
    string text, ciphertext;

    cout << "=======================================\n\n\n Railfence Cipher \n\n=======================================";
    while (1)
    {
        cout << "\n 1. Encryption \n 2. Decryption\n 3. Exit\nEnter Choice: ";
        cin >> Choice;
        if (Choice > 2)
            break;
        switch (Choice)
        {
        case 1:

            cout << "Enter data to be Encrypted:\n";
            cin.ignore();
            getline(cin, text);
            cout << "Enter the key: ";
            cin >> key;
            ciphertext = RailFenceEncrypt(text, key);
            cout << "Encrypted String:\n";
            cout << ciphertext << endl;
            break;

        case 2:
            cout << "Enter data to be Decrypted:\n";
            cin.ignore();
            getline(cin, ciphertext);
            cout << "Enter the key: ";
            cin >> key;
            cout << "Decrypted String:\n";
            cout << RailFenceDecrypt(ciphertext, key);
            break;
        }
    }

    return 0;
}
