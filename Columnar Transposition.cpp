#include <iostream>
#include <string>
#include <map>
using namespace std;

void SetPermutationOrder(string key, map<int, int> &keyMap)
{
    for (int i = 0; i < key.size(); i++)
    {
        keyMap[key[i]] = i;
    }
}

string ColumnarTranspositionEncrypt(string text, string key)
{
    string result = "";
    map<int, int> keyMap;
    int row, col, x = 0;
    col = key.length();
    row = text.length() / col;
    if (text.length() % col)
        row += 1;
    char matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (x < text.size())
                matrix[i][j] = text[x];
            else
                matrix[i][j] = '_';
            x++;
        }
    }
    SetPermutationOrder(key, keyMap);
    for (auto itr : keyMap)
    {
        for (int i = 0; i < row; i++)
        {
            result += matrix[i][itr.second];
        }
    }
    return result;
}

string ColumnarTranspositionDecrypt(string ciphertext, string key)
{
    string result = "";
    map<int, int> keyMap;
    int col = key.length();
    int row = ciphertext.length() / col;
    char cipherMat[row][col];
    int x = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cipherMat[j][i] = ciphertext[x++];
        }
    }
    SetPermutationOrder(key, keyMap);
    x = 0;
    for (auto itr = keyMap.begin(); itr != keyMap.end(); itr++)
    {
        itr->second = x++;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            char c = cipherMat[i][keyMap[key[j]]];
            if (c != '_')
                result += c;
        }
    }
    return result;
}

int main()
{
    int Choice;
    string key, text, ciphertext;
    cout << "=======================================\n\n\n  Columnar Transposition \n\n=======================================";
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
            getline(cin, key);
            ciphertext = ColumnarTranspositionEncrypt(text, key);
            cout << "Encrypted String:\n";
            cout << ciphertext << endl;
            break;

        case 2:
            cout << "Enter data to be Decrypted:\n";
            cin.ignore();
            getline(cin, text);
            cout << "Enter the key: ";
            getline(cin, key);
            cout << "Decrypted String:\n";
            cout << ColumnarTranspositionDecrypt(text, key);
            break;
        }
    }

    return 0;
}
