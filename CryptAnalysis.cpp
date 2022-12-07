#include <bits/stdc++.h>
using namespace std;

int main()
{
    string v1;
    vector<string> v;
    cout << "=======================================\n\n\n  CryptAnalysis  \n\n=======================================";

    cout << "\n Enter cipher text : ";
    getline(cin, v1);

    string output;

    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != ' ')
            output += v1[i];

        if (v1[i] >= 65 && v1[i] <= 90)
            output[i] += 32;
    }

    for (int j = 0; j < 26; j++)
    {
        for (int i = 0; i < output.size(); i++)
            output[i] = 'a' + (output[i] - 'a' - j + 26) % 26;
        v.push_back(output);
    }
    cout << "\n Input the plain text: " << output << endl;

    for (auto ele : v)
        cout << ele << "\n";
    return 0;
}
