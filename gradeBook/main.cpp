/*==============================================================================
Zachary Hadjah                    March 21st 2018
Junior Year                       Data Structures/ Algorithm Analysis

This program contains two classes, Student and Course,  that will allow the user
to analyze the performance of students in a particular course. 
 
 *Student Class will contain private data members consisting of the students 
  information (name, grades, letter grade, etc) 
    -Student() will construct the course
    -get_student_scores() will  obtain the student's name, project grades, two
     exam grades, five quiz grades, and the final exam grade from the user. 
    -compute_student_stats() will  compute a students project average, the exam 
     average, the quiz average, and the semester average. The semester average 
     will be rounded to the nearest tenth. 
    -determine_student_grade() will determine the student letter grade in the
     course.
    -display_student_name_gpa_grade() will display a student’s name, semester 
     average, and letter grade to both the screen and to the external text file, 
     "student.txt"
    -student_average() will return the student’s semester average.
         
 *Course Class will act as part of the program that will manage the entire 
  class accordingly. 
    -Course() will initialize the data members, excluding the objects of Class 
     Student       
    -~Course() will dealloct the Course object
    -get_grades() will get the student grades for the course by calling the
     get_student_scores() public member function of the Student class to get the
     grades of each student.
    -evaluate_class() will, for each student object, compute the student's stats
     using compute_student_stats(), and  determine the student's grade using
     determine_student_grade().
    -determine_index_of_highest_lowest() will determine the subscript of the 
     student who has the highest semester average and the subscript of the
     student who has the lowest semester average and set each of these 
     subscripts appropriately.      
    -display_highest() will send to both the screen and to the external text 
     file, "student.txt ", the name, semester average and grade of the student 
     who has the highest semester average.
    -display_lowest() will send to both the display and to the external text 
     file, "student.txt ", the name, semester average, and grade of the student
     who has the lowest semester average
    -display_stats() will display to both the screen and to an external text 
     file, "student.txt ", the name, semester average, and letter grade for each
     student in the course.
 =============================================================================*/
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <string>
using namespace std;
class Student
{
     private:
        string name;
        int project[6];
        int exam[2];
        int quiz[5];
        double project_avg;
        double exam_avg;
        double quiz_avg;
        int finalExam;
        double average;
        string grade;
     public: 
        Student();
        void get_student_scores();
        void compute_student_stats();
        void determine_student_grade();
        void display_student_name_gpa_grade();
        double student_average();
};
 
Student::Student()
{
    name = " ";
    
    for(int i = 0; i<6; i++)
        project[i] = 0;
    
    for(int i = 0; i<2; i++)
        exam[i] = 0;
    
    for(int i = 0; i<5; i++)
        quiz[i] = 0;
        
    average, project_avg, exam_avg, quiz_avg = 0;
    
    finalExam = 0;
    
        grade = " ";
}

void Student::get_student_scores()
{
    //Test try catch heavily
    try
    {
        cout << "\n Enter Student Name: \n";
        cin>>name;

        for(int i = 0; i<6; i++)
        {
            cout<<"Enter Student project grade #"<<i<<":\n";
            cin>>project[i];
        }

        for(int i = 0; i<2; i++)
        {
            cout<<"Enter Student exam grade #"<<i<<":\n";
            cin>>exam[i];
        }

        for(int i = 0; i<5; i++)
        {
            cout<<"Enter Student quiz grade #"<<i<<":\n";
            cin>>quiz[i];
        }

        cout << "Enter final exam grade:";
        cin>>finalExam;    
    }
    
    catch(...)
    {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
        cout<<"Error, invalid input entered. \n";
    }
    return;
}

void Student::compute_student_stats()
{
    int sum = 0;
    double projPercentage, examPercentage, quizPercentage, finalPercentage; 
    
    for(int i = 0; i<6; i++)
        sum += project[i]; 
    project_avg = sum/6;
    projPercentage = (project_avg/100) * (25/100);
    projPercentage *= 100;
    sum = 0;

    for(int i = 0; i<2; i++)
        sum += exam[i]; 
    exam_avg = sum/2;
    examPercentage = (exam_avg/100) * (40/100);
    examPercentage *= 100;
    sum = 0;
    
    for(int i = 0; i<5; i++)
        sum += quiz[i]; 
    quiz_avg = sum/5;
    quizPercentage = (quiz_avg/100) * (10/100);
    quizPercentage *= 100;
    
    finalPercentage = (finalExam/100) * (25/100) ;
    finalPercentage *= 100;
    
    average = projPercentage + examPercentage + quizPercentage + finalPercentage;
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout << "Quiz Average = " << quiz_avg;
    cout << "Exam Average = " << exam_avg;
    cout << "Project Average = " << project_avg;
    cout << "Semester Average = " << average;   
    return;
}

void Student::determine_student_grade()
{
    if(average <= 100 || average >= 93)
    {
        grade = "A";
        cout << "Letter Grade = " << grade;
    }
    
    else if(average <= 92 || average >= 89)
    {
        grade = "A-";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 88 || average >= 87)
    {
        grade = "B+";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 86 || average >= 83)
    {
        grade = "B";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 82 || average >= 79)
    {
        grade = "B-";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 78 || average >= 77)
    {
        grade = "C+";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 76 || average >= 73)
    {
        grade = "C";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 72 || average >= 69)
    {
        grade = "C-";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 68 || average >= 67)
    {
        grade = "D+";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 66 || average >= 63)
    {
        grade = "D";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 62 || average >= 57)
    {
        grade = "D-";
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 57)
    {
        grade = "F";
        cout << "Letter Grade = " << grade;
    }
    return;
}
void Student::display_student_name_gpa_grade()
{
    const int width1 = 30;
    const int width2 = 20;
    fstream toFile;
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout << left << setw(width1) << "Student = " << name;
    cout << right << setw(width2) << "Average = " << average;
    cout << right << setw(width2) << "Letter Grade = " << grade;
    
    toFile.open("student.txt",ios::app);
    toFile<<fixed<<showpoint<<setprecision(2);
    toFile << left << setw(width1) << "Student = " << name;
    toFile << right << setw(width2) << "Average = " << average;
    toFile << right << setw(width2) << "Letter Grade = " << grade;
    toFile.close();
    return;
}

double Student::student_average()
{
    //remeber to round to nearest tenth in main
    return average;
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
    index_of_highest = 0;
    index_of_highest = 0;
}
Course::~Course()
{
    cout << "Course Object is going out of existence.";
}
void Course::get_grades()
{
    for(int i=0; i<7; i++)
        student[i].get_student_scores();    
    return;
}

void Course::evaluate_class()
{
    for(int i=0; i<7; i++)
    {
        student[i].compute_student_stats();
    }

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

