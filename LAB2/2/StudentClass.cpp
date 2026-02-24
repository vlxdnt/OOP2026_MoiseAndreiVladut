#include "StudentClass.h"

void Student::SetName(const char* str) {
    int i = 0;
    while (i < 255 && str[i] != '\0') {
        name[i] = str[i];
        i++;
    }
    name[i] = '\0';
}

void Student::SetEnglishGrade(float x) {
    if (x >= 1 && x <= 10) {
        englishGrade = x;
    }
}

void Student::SetHistoryGrade(float x) {
    if (x >= 1 && x <= 10) {
        historyGrade = x;
    }
}

void Student::SetMathGrade(float x) {
    if (x >= 1 && x <= 10) {
        mathGrade = x;
    }
}

char* Student::GetName() {
    return this->name;
}

float Student::GetEnglishGrade() {
    return this->englishGrade;
}

float Student::GetHistoryGrade() {
    return this->historyGrade;
}

float Student::GetMathGrade() {
    return this->mathGrade;
}

float Student::GetAverageGrade() {
    return (mathGrade + historyGrade + englishGrade) / 3;
}