#include <iostream>
#include <string>
#include <vector>
using namespace std;

long r{0};
long last;

vector<int> prefix_function(const string& str)
{
        vector<int> pi(str.size());
        pi[0] = -1;
        for(int q{1},k{-1};q<str.size();q++)
        {
                while(k>=0 && str[k+1] != str[q])
                        k = pi[k];
                if(str[k+1]==str[q])
                        ++k;
                pi[q] = k;
        }
        return pi;
}

bool knuth_morris_pratt(string& text, const string& pattern)
{
        auto pi = prefix_function(pattern);
        for(int q{0},k{-1};q<text.size();q++)
        {
                //1)
                while(k>=0 && pattern[k+1]!=text[q])
                        k = pi[k];
                //2)
                if(pattern[k+1] == text[q])
                        ++k;
                if(k==pattern.size()-1)
                {
                    ++r;
                    text[q] = '#';
                    last = q;
                    return false;
                    k = pi[k];
                }
        }
        return true;
}

int main()
{
    string s,p;
    cin >> s >> p;
    while(!knuth_morris_pratt(s,p))
    {
        s.erase(0,max(long(last-p.size()),long(0)));
    }
    cout<<r<<endl;
}
