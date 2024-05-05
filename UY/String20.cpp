#include<iostream>
#include<cstring>

void replace_space(char *str){

    int totalSpaces = 0;

    for (int idx = 0; str[idx] != '\0'; idx++) {
        if (str[idx] == ' ')
            totalSpaces++;
    }

    int newStringLength = strlen(str) + 2 * totalSpaces;
    str[newStringLength] = '\0';

    int oldIdx = strlen(str) - 1;

    for (int idx = newStringLength-1 ; idx >= 0 ;) {
        if (str[oldIdx] == ' ') {
            str[idx] = '0';
            str[idx-1] = '2';
            str[idx-2] = '%';
            idx-=3;
        } else {
            str[idx] = str[oldIdx];
            idx--;
        }
        oldIdx--;
    }

}

int main() {

    char input[10000];
    std::cin.getline(input, 1000);

    replace_space(input);
    
    std::cout<<input<<std::endl;
    return 0;
}