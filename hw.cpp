//
// Created by 채민균 on 2017. 5. 29..
//

#include <iostream>

using namespace std;

int main() {
    char text[30], pattern[10], replacement[10];
    cin.getline(text, 21);
    cin.getline(pattern, 11);
    cin.getline(replacement, 11);
    int tSize = 0, pSize = 0, rSize = 0;
    for (int i = 0; i < 20; ++i) {
        if (text[i] != '\0') ++tSize;
        else break;
    }
    for (int i = 0; i < 10; ++i) {
        if (pattern[i] != '\0') ++pSize;
        else break;
    }
    for (int i = 0; i < 10; ++i) {
        if (replacement[i] != '\0') ++rSize;
        else break;
    }

    for (int i = 0; i <= tSize - pSize; ++i) {
        if (text[i] == pattern[0]) {
            bool find = true;
            for (int j = i + 1; j < i + pSize; ++j) {
                if (text[j] != pattern[j - i]) {
                    find = false;
                    break;
                }
            }
            if (find) {
                char front[20] = {'\0'};
                char back[20] = {'\0'};
                for (int j = 0; j < i; ++j) {
                    front[j] = text[j];
                }
                int index = 0;
                for (int j = i + pSize; j < tSize; ++j) {
                    back[index] = text[j];
                    ++index;
                }
                int tIndex = 0;
                for (int j = 0; j < 20; ++j) {
                    if (front[j] == '\0') break;
                    text[tIndex] = front[j];
                    ++tIndex;
                }
                for (int j = 0; j < rSize; ++j) {
                    text[tIndex] = replacement[j];
                    ++tIndex;
                }
                for (int j = 0; j < 20; ++j) {
                    if (back[j] == '\0') break;
                    text[tIndex] = back[j];
                    ++tIndex;
                }
                tSize = tIndex;
            }
        }
    }
    for (int k = 0; k < tSize; ++k) {
        cout << text[k];
    }
    return 0;
}