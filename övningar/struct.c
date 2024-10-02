struct Student {
    char name[100];
    int age;
    int total_marks;
};

void main(){
    char temp_name[100];
    int temp_age;
    int temp_total_marks;

    Student s1;
    Student s2;

    printf("\n Enter the name of student 1: ");
    scanf("%c", &temp_name);
    printf("\n Enter the age of student 1: ");
    scanf("%d", &temp_age);
    printf("\n Enter marks of student 1: ");
    scanf("%d", &temp_total_marks);

    s1.name = temp_name;
    s1.age = temp_age;
    s1.total_marks = temp_total_marks;

    printf("\n Enter the name of student 2: ");
    scanf("%c", &temp_name);
    printf("\n Enter the age of student 2: ");
    scanf("%d", &temp_age);
    printf("\n Enter marks of student 2: ");
    scanf("%d", &temp_total_marks);

    s2.name = temp_name;
    s2.age = temp_age;
    s2.total_marks = temp_total_marks;

    printf("\n Name of student 1: %c",  s1.name);
    printf("\n Age of student  1: %d", s1.age);
    printf("\n Total marks of studetn 1: %d", s1.total_marks);

    printf("\n Name of student 2: %c",  s2.name);
    printf("\n Age of student  2: %d", s2.age);
    printf("\n Total marks of studetn 2: %d", s2.total_marks);
};