#include "GlobalFunctions.h"

int CompareName(char* firstStudent, char* secondStudent) {
    int i = 0;
    while (firstStudent[i] != '\0' && secondStudent[i] != '\0') {
        if (firstStudent[i] > secondStudent[i])
            return 1;
        if (firstStudent[i] < secondStudent[i])
            return -1;
        i++;
    }
    if (firstStudent[i] == '\0' && secondStudent[i] == '\0')
        return 0;
    if (firstStudent[i] == '\0')
        return -1;
    return 1;
        return -1;
}

int CompareMathGrade(float &firstGrade, float &secondGrade) {
    if (firstGrade == secondGrade)
        return 0;
    if (firstGrade > secondGrade)
        return 1;
    if (firstGrade < secondGrade)
        return -1;
}

int CompareEnglishGrade(float *firstGrade, float *secondGrade) {
    if (*firstGrade == *secondGrade)
        return 0;
    if (*firstGrade > *secondGrade)
        return 1;
    if (*firstGrade < *secondGrade)
        return -1;
}

int CompareHistoryGrade(float firstGrade, float secondGrade) {
    if (firstGrade == secondGrade)
        return 0;
    if (firstGrade > secondGrade)
        return 1;
    if (firstGrade < secondGrade)
        return -1;
}

int CompareAverageGrade(float firstGrade, float secondGrade) {
    if (firstGrade == secondGrade)
        return 0;
    if (firstGrade > secondGrade)
        return 1;
    if (firstGrade < secondGrade)
        return -1;
}