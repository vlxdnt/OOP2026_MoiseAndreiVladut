#include "StudentClass.h"

void Student::SetName(std::string str) {
    name = str;
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

std::string Student::GetName() {
    return name;
}

float Student::GetEnglishGrade() {
    return englishGrade;
}

float Student::GetHistoryGrade() {
    return historyGrade;
}

float Student::GetMathGrade() {
    return mathGrade;
}

float Student::GetAverageGrade() {
    return (mathGrade + historyGrade + englishGrade) / 3;
}