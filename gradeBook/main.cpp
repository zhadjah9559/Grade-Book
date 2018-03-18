/*
 * {Westfield State University}:Program Design 2
 * Zachary Hadjah
 * 
 */

/* 
 * File:   main.cpp
 * Author: zach
 *
 * Created on March 17, 2018, 4:11 PM
 */

#include <cstdlib>

using namespace std;

class Student
{
     private:
        char name[20];
        int project[6];
        int exam[2];
        int quiz[5];
        double project_avg;
        double exam_avg;
        double quiz_avg;
        int final;
        double average;
        char grade[3];
     public: 
        Student();
        void get_student_scores();
        void compute_student_stats();
        void determine_student_grade();
        void display_student_name_gpa_grade();
        double student_average();
};
 
void Student::get_student_scores()
{
    
}

void Student::compute_student_stats()
{
    
}
void Student::determine_student_grade()
{
    
}
void Student::display_student_name_gpa_grade()
{
    
}

double Student::student_average()
{
    
}
 
 class Course
 {
    private:
        Student student[7];
        int index_of_highest;
        int index_of_lowest;
    public:
        Course();
        ~Course();
        void get_grades();
        void evaluate_class();
        void determine_index_of_highest_lowest();
        void display_highest();
        void display_lowest();
        void display_stats();
 };
 
Course::Course()
{
    
}
Course::~Course()
{
    
}
void Course::get_grades()
{
    
}

void Course::evaluate_class()
{
    
}

void Course::determine_index_of_highest_lowest()
{
    
}

void Course::display_highest()
{
    
}
void Course::display_lowest()
{
    
}

void Course::display_stats()
{
    
}

int main(int argc, char** argv) 
{
    return 0;
}

