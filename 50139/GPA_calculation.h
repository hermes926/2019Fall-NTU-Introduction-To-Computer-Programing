#ifndef GPA_calculation_h
#define GPA_calculation_h 

struct Class{
    int academic_credit;  
    char score[3];
};
struct Student{
    char name[20];
    int N_class; // total number of classes the student takes.
    int N_credit; // total number of academic credits.
    double GPA;
    struct Class all_class[10];
};
 
void GPA_calculation(struct Student all_student[], int N);

#endif
