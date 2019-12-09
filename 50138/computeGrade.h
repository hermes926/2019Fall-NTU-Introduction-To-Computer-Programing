#ifndef COMPUTEGRADE_H_INCLUDED
#define COMPUTEGRADE_H_INCLUDED
 
typedef struct{
    int rawScore;
    double scaledScore;
}Score;
 
typedef struct{
    char id[10];
    Score score[18];
    double finalScore;
}Student;
 
typedef struct{
    int numStudent;
    Student student[1000];
}Classes;
 
void computeGrade(Classes classes[2]);
 
#endif // COMPUTEGRADE_H_INCLUDED
