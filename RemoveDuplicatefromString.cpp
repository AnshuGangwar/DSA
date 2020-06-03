
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void removeDuplicates(vector<string> &names, int n)
{
   unordered_set<string> s;// for fast access

    for (int i = 0; i < n; i++)
        s.insert(names[i]);
    for(auto x:s)
        cout << x << " ";
}

int main()
{
    vector<string> names;
    names.push_back("rashmi");
    names.push_back("ram");
    names.push_back("rekha");
    names.push_back("rashmi");
    names.push_back("raja");
    names.push_back("ranjith");
    names.push_back("ram");
    names.push_back("ramya");
    names.push_back("ranjith");

    int n = names.size();
    removeDuplicates(names, n);
}

