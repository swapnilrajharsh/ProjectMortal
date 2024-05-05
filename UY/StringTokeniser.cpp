#include<iostream>
#include<cstring>

char *strToken(char *str, char delim) {
    
    static char *input = NULL;

    if (str != NULL)
        input = str;

    if (input == NULL)
        return NULL;

    char *token = new char[strlen(input) + 1];
    int i = 0;
    for (; input[i]!='\0'; i++) {
        if (input[i] != delim) {
            token[i] = input[i];
        } else {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }

    token[i] = '\0';
    input = NULL;
    return token;
    
}

int main() {

    char s[10000];
    std::cin.getline(s, 1000);

    char *token = strToken(s, ' '); /* params - string, delimiter*/

    while (token != NULL)
    {
        std::cout<< token << std::endl;
        token = strToken(NULL, ' ');
    }
    
    return 0;
}