
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void wordbreak(vector<string> const &dict, string word, string out)
{
    if(word.size() == 0)
    {
        cout<<out<<endl;
        return;
    }

    for(int i = 1; i <= word.size(); i++)
    {
        string prefix = word.substr(0, i);
        string output = "";
        if(find(dict.begin(), dict.end(), prefix) != dict.end())
        {
            output = (out == "") ? out + prefix : out + " " + prefix;
            wordbreak(dict, word.substr(i), output);
        }
    }
}

int main()
{

    vector<string> dict = { "he", "hell", "hello", "I", "there", "the",
                            "hope", "you", "are", "are", "having", "a", "nice", "day","cat","cats","sand","and","dog"
                          };

    //string word = "hellothereIhopeyouarehavinganiceday";
     string word = "catsanddog";
    wordbreak(dict, word, "");

    return 0;
}

