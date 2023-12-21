#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_CHAR = 256;

void computeShifts(const string& pattern, vector<int>& shifts) {
    int m = pattern.size();

    for (int i = 0; i < MAX_CHAR; ++i) {
        shifts[i] = m;
    }

    for (int i = 0; i < m - 1; ++i) {
        shifts[pattern[i]] = m - 1 - i;
    }
}

int horspoolSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> shifts(MAX_CHAR);

    computeShifts(pattern, shifts);

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }

        if (j < 0) {
            return i;
        } else {
            i += shifts[text[i + m - 1]];
        }
    }

    return -1;
}

int main() {
    int quit;
    string text;
    string pattern;
    
    cout<<"\nEnter DNA in any combination with alphabets A C G T:";
    cin>>text;
    
    do
    {
        cout<<"Enter the pattern that you want to search in the DNA sequence:";
        cin>>pattern;
        int result = horspoolSearch(text, pattern);

        if (result != -1) {
            cout << "Pattern found at index " << result << endl;
        } else {
            cout << "Pattern not found in the text" << endl;
        }
        cout<<"\nEnter 1 to exit and 0 to continue:";
        cin>>quit;
    }while(quit!=1);
    

    return 0;
}