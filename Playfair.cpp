#include <bits/stdc++.h>
using namespace std;

class PlayFair
{
    vector<vector<char>> table;

public:
    PlayFair(string key)
    {
        this->table = tableCreation(key);
        cout << endl;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    vector<vector<char>> tableCreation(string key)
    {
        vector<bool> arr(26, true);

        vector<vector<char>> myTable(5, vector<char>(5, ' '));
        int x = 0, y = 0;

        for (int i = 0; i < key.length(); i++)
        {
            if (arr[key[i] - 'A'] && key[i] != 'I')
            {
                myTable[x][y] = key[i];
                y++;
                if (y == 5)
                {
                    x++;
                    y = 0;
                }
                arr[key[i] - 'A'] = false;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (arr[i] && i != 8)
            {
                myTable[x][y] = 'A' + i;
                y++;
                if (y == 5)
                {
                    x++;
                    y = 0;
                }
            }
        }

        return myTable;
    }

    string findEncryption(char first, char second)
    {
        pair<int, int> pos1;
        pair<int, int> pos2;

        string text = "";
        for (int i = 0; i < table.size(); i++)
        {
            for (int j = 0; j < table[0].size(); j++)
            {
                if (table[i][j] == first)
                {
                    pos1 = {i, j};
                }
                if (table[i][j] == second)
                {
                    pos2 = {i, j};
                }
            }
        }

        if (pos1.first == pos2.first)
        {
            text += table[pos1.first][(pos1.second + 1) % 5];
            text += table[pos1.first][(pos2.second + 1) % 5];
            return text;
        }
        if (pos1.second == pos2.second)
        {
            text += table[(pos1.first + 1) % 5][pos1.second];
            text += table[(pos2.first + 1) % 5][pos2.second];
            return text;
        }
        int col = pos1.second;
        while (col != pos2.second)
        {
            col = (col + 1) % 5;
        }
        text += table[pos1.first][col];
        col = pos2.second;
        while (col != pos1.second)
        {
            col = (col + 1) % 5;
        }
        text += table[pos2.first][col];

        return text;
    }

    string findDecryption(char first, char second)
    {
        pair<int, int> pos1;
        pair<int, int> pos2;

        string text = "";
        for (int i = 0; i < table.size(); i++)
        {
            for (int j = 0; j < table[0].size(); j++)
            {
                if (table[i][j] == first)
                {
                    pos1 = {i, j};
                }
                if (table[i][j] == second)
                {
                    pos2 = {i, j};
                }
            }
        }

        if (pos1.first == pos2.first)
        {
            text += table[pos1.first][(5 + (pos1.second - 1)) % 5];
            text += table[pos1.first][(5 + (pos2.second - 1)) % 5];
            return text;
        }
        if (pos1.second == pos2.second)
        {
            text += table[(5 + pos1.first - 1) % 5][pos1.second];
            text += table[(5 + pos2.first - 1) % 5][pos2.second];
            return text;
        }
        int col = pos1.second;
        while (col != pos2.second)
        {
            col = (col + 1) % 5;
        }
        text += table[pos1.first][col];
        col = pos2.second;
        while (col != pos1.second)
        {
            col = (col + 1) % 5;
        }
        text += table[pos2.first][col];

        return text;
    }

    string encrypt(string plainText)
    {

        string str = "";

        for (int i = 0; i < plainText.length(); i++)
        {
            if (plainText[i] != ' ')
            {
                str += plainText[i];
            }
        }
        plainText = str;
        int n = plainText.length();

        //splitting into two chars
        int i = 0;
        vector<pair<char, char>> groups;
        while (i < n)
        {
            if (i != n - 1 && plainText[i] != plainText[i + 1])
            {
                groups.push_back({plainText[i], plainText[i + 1]});
                i += 2;
            }
            else
            {
                groups.push_back({plainText[i], 'X'});
                i += 1;
            }
        }
        cout << "Plain Text After Splitting" << endl;

        string encryptedString = "";

        for (i = 0; i < groups.size(); i++)
        {
            cout << groups[i].first << groups[i].second << " ";

            encryptedString += findEncryption(groups[i].first, groups[i].second);
        }
        cout << endl
             << endl;

        return encryptedString;
    }

    string decrypt(string encrypted)
    {
        int n = encrypted.length();

        //splitting into two chars
        int i = 0;
        vector<pair<char, char>> groups;
        while (i < n)
        {
            groups.push_back({encrypted[i], encrypted[i + 1]});
            i += 2;
        }
        cout << "Encrypted After Splitting" << endl;

        string decryptedString = "";

        for (i = 0; i < groups.size(); i++)
        {
            cout << groups[i].first << groups[i].second << " ";
        }
        cout << endl;
        cout << "Decrypted in split" << endl;

        for (i = 0; i < groups.size(); i++)
        {
            string text = findDecryption(groups[i].first, groups[i].second);
            cout << text << " ";
            decryptedString += text;
        }
        cout << endl
             << endl;

        return decryptedString;
    }
};
int main()
{
    string input;
    cout << "Enter String" << endl;
    getline(cin, input);
    cout << "Enter key" << endl;
    string key;
    cin >> key;

    for (int i = 0; i < input.length(); i++)
    {
        input[i] = toupper(input[i]);

        if (input[i] == 'I')
        {
            input[i] = 'J';
        }
    }
    cout << endl;
    for (int i = 0; i < key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }
    PlayFair cipher(key);

    string encryptedText = cipher.encrypt(input);
    cout << "Encrypted Text: " << encryptedText << endl
         << endl;
    ;
    string decryptedText = cipher.decrypt(encryptedText);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
