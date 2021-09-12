#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

int main()
{
    int wordCount = 0;
    int jobDescCount = 0;
    int salary = 0;
    int totalSalary = 0;
    string str;
    string jobDesc;
    unordered_map<string, int> map;

    cin >> wordCount >> jobDescCount;

    for (int i = 0; i < wordCount; i++)
    {
        cin >> jobDesc >> salary;

        map[jobDesc] = salary;       

    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (getline(cin, str))
    {
        stringstream ss(str);

        if(ss.peek() == '.')
        {
            ss.ignore();
            cout << totalSalary << endl;
            totalSalary = 0;
        }
        else
        {
            while (ss >> str)
            {
                auto itr = map.find(str);
                if(itr != map.end())
                {
                    totalSalary += itr->second;
                }
            }
        }
    }
    return 0;
}