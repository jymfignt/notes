#include <stdio.h>
#include <string.h>
struct Student
{
    char name[10];
    int score;
};
void addStudent(int *times, struct Student student[]);
void printStudents(int n, struct Student student[]);
void calcAverage(int n, struct Student student[]);

int main()
{
    int choice=0,times=0;
    struct Student student[100];   //假设最多容纳100个学生数据
    while(1)
    {
        printf("1. adding\n2. display all students\n3. show the average grades\n4. exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent(&times,student);
                break;
            case 2:
                printStudents(times,student);
                break;
            case 3:
                calcAverage(times,student);
                break;
            case 4:
                printf("Exit the program\n");
                return 0;
            default:
                printf("Invalid input!\n");
        }

    }
    return 0;
}
void addStudent(int *n,struct Student student[])
{
    if(*n>=100)
    {
        printf("Exceeding the capacity of this system!\n");   //如果超过系统容量，发出提醒
        return;
    }
    printf("Student name: ");
    scanf("%s",student[*n].name);
    printf("Grade: ");
    scanf("%d",&student[*n].score);
    (*n)++;
}
void printStudents(int n,struct Student student[])
{
    if(n==0)
    {
        printf("There's no student data here.\n");
        return;
    }

    else if(n>=100)
    {
        printf("Exceeding the capacity of this system!\n");
        return;
    }

            for(int i=0;i<n;i++)
            printf("%s %d\n",student[i].name,student[i].score);

}
void calcAverage(int n,struct Student student[100])
{
    if(n==0)
    {
        printf("There's no student data here.\n");
        return;
    }

    else if(n>=100)
    {
        printf("Exceeding the capacity of this system!\n");
        return;
    }
    else
    {
        int total = 0;
        for(int i=0;i<n;i++)
            total+=student[i].score;
        printf("The average grade is %.2f.\n",(float)(total/n));

    }
}

