#include "GlobalFunctions.h"

int CompareName(std::string firstStudent, std::string secondStudent) {
    if (firstStudent == secondStudent)
        return 0;
    if (firstStudent > secondStudent)
        return 1;
    if (firstStudent < secondStudent)
        return -1;
}

int CompareMathGrade(float firstGrade, float secondGrade) {
    if (firstGrade == secondGrade)
        return 0;
    if (firstGrade > secondGrade)
        return 1;
    if (firstGrade < secondGrade)
        return -1;
}

int CompareEnglishGrade(float firstGrade, float secondGrade) {
    if (firstGrade == secondGrade)
        return 0;
    if (firstGrade > secondGrade)
        return 1;
    if (firstGrade < secondGrade)
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