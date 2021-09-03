#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    string str;
    string validSmiles[4] = {":)", ";)", ":-)", ";-)"};
    unordered_map<string, int> m_ValidSmiles;

    cin >> str;

    for(int i = 0; i < 4; i++)
    {
        m_ValidSmiles[validSmiles[i]]++;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == ':' || str[i] == ';')
        {
            if(m_ValidSmiles.count(str.substr(i, 2)))
            {
                cout << i << endl;
            }
            if(m_ValidSmiles.count(str.substr(i, 3)))
            {
                cout << i << endl;
            }
        }
    }
    
    return 0;
}