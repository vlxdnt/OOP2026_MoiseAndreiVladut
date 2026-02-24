#pragma once

class Student {
    private:
        char name[255];
        float mathGrade;
        float englishGrade;
        float historyGrade;
    public:
        void SetName(const char* str);
        void SetMathGrade(float x);
        void SetEnglishGrade(float x);
        void SetHistoryGrade(float x);
        char* GetName();
        float GetMathGrade();
        float GetEnglishGrade();
        float GetHistoryGrade();
        float GetAverageGrade();
};