#include "GlobalFunctions.h"
#include "StudentClass.h"
#include <stdio.h>

int main()
{
    Student student1, student2;
    student1.SetName("Alex");
    student1.SetEnglishGrade(10);
    student1.SetHistoryGrade(8);
    student1.SetMathGrade(9);
    student2.SetName("George");
    student2.SetEnglishGrade(5);
    student2.SetHistoryGrade(8);
    student2.SetMathGrade(6);
    
    printf("%s\n", student1.GetName());
    printf("English grade: %f\n", student1.GetEnglishGrade());
    printf("Math grade: %f\n", student1.GetMathGrade());
    printf("History grade: %f\n", student1.GetHistoryGrade());
    printf("Average grade: %f\n", student1.GetAverageGrade());

    printf("%s\n", student2.GetName());
    printf("English grade: %f\n", student2.GetEnglishGrade());
    printf("Math grade: %f\n", student2.GetMathGrade());
    printf("History grade: %f\n", student2.GetHistoryGrade());
    printf("Average grade: %f\n", student2.GetAverageGrade());

    printf("Compare name: %d\n", CompareName(student1.GetName(), student2.GetName()));
    printf("Compare math grades: %d\n", CompareMathGrade(student1.GetMathGrade(), student2.GetMathGrade()));
    printf("Compare english grades: %d\n", CompareEnglishGrade(student1.GetEnglishGrade(), student2.GetEnglishGrade()));
    printf("Compare history grades: %d\n", CompareHistoryGrade(student1.GetHistoryGrade(), student2.GetHistoryGrade()));
    printf("Compare average grades: %d\n", CompareAverageGrade(student1.GetAverageGrade(), student2.GetAverageGrade()));
    return 0;
}