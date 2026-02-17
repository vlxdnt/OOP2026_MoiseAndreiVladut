#include <stdio.h>

int stringToInt(char*);
int main()
{
    FILE* fileptr;
    fileptr = fopen("in.txt", "r");

    if (fileptr == NULL) {
        printf("Eroare la deschidere\n");
    } else {
        char sir[255];
        int sum = 0;
        while (fgets(sir, 255, fileptr)) {
            sum += stringToInt(sir);
        }
        printf("suma: %d\n", sum);
        fclose(fileptr);
    }   
    return 0;
}

int stringToInt(char* sir) {
    int numar = 0;
    int i = 0;
    while (sir[i] != '\0') {
        if (sir[i] >= '0' && sir[i] <= '9') 
            numar = numar * 10 + (sir[i] - '0');
        i++;
    }
    return numar;
}