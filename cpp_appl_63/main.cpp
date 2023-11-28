#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


string cleanWord(const string& dirtyWord) {
    string cleanedWord;
    for (char ch : dirtyWord) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            cleanedWord += ch;
        }
    }
    return cleanedWord;
}

int main() {
    char path[] = "test.txt";
    char buffer[1000];
    FILE* file;
    file = fopen(path, "r");
    if (file == NULL) {
        perror("log");
    }
    else {
        while (fgets(buffer, 999, file)) {
            string word;
            for (char ch : buffer) {
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                    word += ch;
                }
                else if (!word.empty()) {
                    
                    if (word.length() >= 7) {
                        cout << cleanWord(word) << " ";
                    }
                    word.clear();  
                }
            }
        }
        fclose(file);
    }

    return 0;
}
