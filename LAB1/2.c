#include <stdio.h>

void copy(char* dest, char* src);
int length(const char* str);
int compare(const char* str1, const char* str2);
void mergePointers(char* ptrs[], int left, int mid, int right);
void mergeSortPointers(char* ptrs[], int left, int right);

int main()
{
    char word[255];
    char words[255][255];
    char* ptrs[255];
    int nrWords;
    scanf("%d", &nrWords);
    int tmpCnt = 0;
    while (scanf("%254s", word)) { // %254s pt a preveni overflow
        copy(words[tmpCnt], word);
        ptrs[tmpCnt] = words[tmpCnt];
        tmpCnt++;
        if (tmpCnt >= nrWords)
            break;
    }
    mergeSortPointers(ptrs, 0, nrWords - 1);
    printf("---------------------------------\n");
    for (int i = 0; i < nrWords; i++) {
        printf("%s\n", ptrs[i]);
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
int length(const char* str) {
    int index = 0;
    while (str[index] != '\0')
        index++;
    return index;
}

// functie de comparare a doua stringuri 
int compare(const char* str1, const char* str2) {
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

void mergePointers(char* ptrs[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    char* tmp[255];

    while (i <= mid && j <= right) {
        int leni = length(ptrs[i]);
        int lenj = length(ptrs[j]);

        if (leni > lenj || (leni == lenj && compare(ptrs[i], ptrs[j]) < 0)) {
            tmp[k] = ptrs[i];
            i++;
        } else {
            tmp[k] = ptrs[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        tmp[k] = ptrs[i];
        i++;
        k++;
    }

    while (j <= right) {
        tmp[k] = ptrs[j];
        j++;
        k++;
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        ptrs[i] = tmp[k];
    }
}

void mergeSortPointers(char* ptrs[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortPointers(ptrs, left, mid);
        mergeSortPointers(ptrs, mid + 1, right);
        mergePointers(ptrs, left, mid, right);
    }
}