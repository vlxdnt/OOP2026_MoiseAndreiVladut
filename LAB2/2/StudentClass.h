#pragma once
#include <string>

class Student {
    private:
        std::string name;
        float mathGrade;
        float englishGrade;
        float historyGrade;
    public:
        void SetName(std::string str);
        void SetMathGrade(float x);
        void SetEnglishGrade(float x);
        void SetHistoryGrade(float x);
        std::string GetName();
        float GetMathGrade();
        float GetEnglishGrade();
        float GetHistoryGrade();
        float GetAverageGrade();
};