#include <stdio.h>

void copy(char* dest, char* src);
int length(char* sir);
void reverseMatrix(char matrix[][255], int rows);
int compare(char* str1, char* str2);
void sort(char matrix[][255], int rows);

int main()
{
    char word[20];
    char words[255][255];
    int nrWords;
    scanf("%d", &nrWords);
    int tmpCuv = 0;
    while (scanf("%19s", word)) {
        copy(words[tmpCuv], word);
        tmpCuv++;
        if (tmpCuv >= nrWords)
            break;
    }
    reverseMatrix(words, nrWords);
    sort(words, nrWords);
    for (int i = 0; i < nrWords; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}

// functie de copiere
void copy(char* dest, char* src) {
    int index = 0;
    while (src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
}

// functie pt lungime
int length(char* sir) {
    int index = 0;
    while (sir[index] != '\0')
        index++;
    return index;
}

// functie de inversare a matricei
void reverseMatrix(char matrix[][255], int rows) {
    for (int i = 0; i < rows / 2; i++) {
        char temp[255];
        copy(temp, matrix[i]);
        copy(matrix[i], matrix[rows - i - 1]);
        copy(matrix[rows - i - 1], temp);
    }
}

// functie de comparare a doua stringuri 
int compare(char* str1, char* str2) {
    int index = 0;
    while (str1[index] != '\0' && str2[index] != '\0') {
        if (str1[index] < str2[index])
            return -1;
        else if (str1[index] > str2[index])
            return 1;
        index++;
    }
    if (str1[index] == '\0' && str2[index] == '\0')
        return 0;
    else if (str1[index] == '\0')
        return -1;
    else
        return 1;
}

// sortez doar elementele de aceeasi dimensiune lexicografic
void sort(char matrix[][255], int rows) {
    for (int i = 0; i < rows - 1; i++)
        for (int j = 0; j < rows; j++)
            if (compare(matrix[i], matrix[j]) < 0 && length(matrix[i]) == length(matrix[j])) {
                char tmp[255];
                copy(tmp, matrix[i]);
                copy(matrix[i], matrix[j]);
                copy(matrix[j], tmp);
            }
}