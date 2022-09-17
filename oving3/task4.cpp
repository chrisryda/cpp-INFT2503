#include <iostream>
#include <string>

using namespace std; 

int main() 
{
    string word1, word2, word3;

    cout << "Please enter word one: ";
    cin >> word1;

    cout << "Please enter word two: ";
    cin >> word2;

    cout << "Please enter word three: ";
    cin >> word3;

    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << "Sentence: " << sentence << "\n" << endl;

    cout << "Length of '" << word1 << "': " << word1.length() << endl;
    cout << "Length of '" << word2 << "': " << word2.length() << endl;
    cout << "Length of '" << word3 << "': " << word3.length() << endl;
    cout << "Length of sentence: " << sentence.length() << "\n" << endl;

    string sentence2 = sentence;

    if (sentence2.length() >= 12) {
        sentence2.replace(9, 3, "xxx");
        cout << "Original sentence: " << sentence << endl;
        cout << "Sentence 2: " << sentence2 << "\n" << endl; 
    } else {
        cout << "Sentence too short to replace sign 10-12\n";
    }

    if (sentence.length() >= 5) {
        string sentence_start = sentence.substr(0, 5);
        cout << "Original sentence: " << sentence << endl;
        cout << "Sentence start: " << sentence_start << "\n" << endl; 
    } else {
        cout << "Sentence shorter than 5 signs\n";
    }

    size_t found = sentence.find("hallo");
    if (found != string::npos)
    {
        cout << "Sentence contains 'hallo' at index " << found << "\n" << endl;
    } else {
        cout << "Sentence does not contain 'hallo'" << "\n" << endl;
    }
 
    string substr = "er";
    int index = 0;
    while ((index = sentence.find(substr, index)) != string::npos) {
        cout << "Occurance of 'er' at index " << index << endl;
        index += substr.length();
    }
    if (index == 0)
    {
        cout << "Sentence does not contain 'er'" << endl;
    }
    
    
}
