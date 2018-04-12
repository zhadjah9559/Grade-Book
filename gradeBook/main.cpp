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
ofstream toFile;



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
 
Student::Student()
{
    name = "";
    
    for(int i = 0; i<6; i++)
        project[i] = 0;
    
    for(int i = 0; i<2; i++)
        exam[i] = 0;
    
    for(int i = 0; i<5; i++)
        quiz[i] = 0;
        
    average, project_avg, exam_avg, quiz_avg = 0.0;
    finalExam = 0;
    grade = " ";
}

void Student::get_student_scores()
{
    try
    {
        cout << "\n Enter Student Name: \n";
        cin.ignore();
        getline(cin, name);
                
        for(int i = 0; i<6; i++)
        {
            cout<<"Enter Student project grade #"<<i+1<<":\n";
            cin>>project[i];
        }

        for(int i = 0; i<2; i++)
        {
            cout<<"Enter Student exam grade #"<<i+1<<":\n";
            cin>>exam[i];
        }

        for(int i = 0; i<5; i++)
        {
            cout<<"Enter Student quiz grade #"<<i+1<<":\n";
            cin>>quiz[i];
        }

        cout << "Enter final exam grade: \n";
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
    cout<<fixed<<showpoint<<setprecision(2);

    for(int i = 0; i<6; i++)
        project_avg += project[i]; 
    project_avg = project_avg/6;
    cout << "Project Average = " << project_avg << "\n";

    for(int i = 0; i<2; i++)
        exam_avg += exam[i]; 
    exam_avg = exam_avg/2;
    cout << "Exam average = " << exam_avg << "\n";
    
    for(int i = 0; i<5; i++)
        quiz_avg += quiz[i]; 
    quiz_avg = quiz_avg/5;
    cout << "Quiz average = " << quiz_avg << "\n";
        
    average = (project_avg*0.25) + (exam_avg*0.4) + (quiz_avg*0.1) + (finalExam*0.25);
    cout << "Semester average = " << average << "\n"; 
   
    return;
}

void Student::determine_student_grade()
{
    grade = "0";
    if(average <= 100 && average >= 93)
        grade = "A";
    //range from 92 - 89
    else if(average >= 89)
        grade = "A-";
    //range from 88 - 87
    else if(average >= 87)
        grade = "B+";
    //range from 89 - 83
    else if(average >= 83)
        grade = "B";
    //range from 82 - 79
    else if(average >= 79)
        grade = "B-";
    //range from 78 - 77
    else if(average >= 77)
        grade = "C+";
    //range from 76 - 73
    else if(average >= 73)
        grade = "C";
    //range from 72 - 69
    else if(average >= 69)
        grade = "C-";
    //range from 68 - 67
    else if(average >= 67)
        grade = "D+";
    //range from 66 - 63
    else if(average >= 63)
        grade = "D";
    //range from 62 - 57   
    else if(average >= 57)
        grade = "D-";
    //range below 57    
    else if(average <= 57)
        grade = "F";
        
    cout << "Letter Grade = " << grade << "\n";
    return;
}

void Student::display_student_name_gpa_grade()
{
    const int width1 = 19;
    const int width2 = 17;
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout << "\n" <<"Student = " << name << "\n";
    cout << "Average = " << average << "\n";
    cout << "Letter Grade = " << grade << "\n";
    
    toFile.open("student.txt",ios::app);
    toFile<<fixed<<showpoint<<setprecision(2);
    toFile << "\n" <<"Student = " << name << "\n";
    toFile << "Average = " << average << "\n";
    toFile << "Letter Grade = " << grade << "\n";
    toFile.close();
    return;
}

double Student::student_average()
{
    return average;
}
 

 
Course::Course()
{
    index_of_highest = 0;
    index_of_lowest = 0;
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
        student[i].determine_student_grade();
    }
    return;
}

void Course::determine_index_of_highest_lowest()
{
    int tempHighest = 0; 
    int tempLowest = 100;
    
    for(int i=0; i<7; i++)
    {
        if(student[i].student_average() > tempHighest)
        {
            tempHighest = student[i].student_average();
            index_of_highest = i;
        }
    }
    
    for(int i=0; i<7; i++)
    {
        if(student[i].student_average() < tempLowest)
        {
            tempLowest = student[i].student_average();
            index_of_lowest = i;
        }
    }
    return;
}

void Course::display_stats()
{    
    for (int i=0; i < 7; i++)
    {
        student[i].display_student_name_gpa_grade();
    }
}

void Course::display_highest()
{
    student[index_of_highest].display_student_name_gpa_grade();
        return;
}

void Course::display_lowest()
{    
    student[index_of_lowest].display_student_name_gpa_grade();
        return;
}

void describeProgram()
{
    cout<<"This program will serve as a grade book for seven students who are"
          " participating in a course, \n and will also analyze the performances"
          "of the students as well. Each student will have six projects (worth 25%"
          " collectively), \n two midterm exams (worth 20% each), and five quizzes (worth 10%"
          " collectively), and a final exam (worth 25%). \n The program will calculate"
          " the class average and will also display the student with the highest"
          " and lowest grade.";  
}

int main(int argc, char** argv) 
{
    Course courseObj;
    
    describeProgram();
    courseObj.get_grades();
    courseObj.evaluate_class();
    courseObj.determine_index_of_highest_lowest();
    
    toFile.open("student.txt",ios::out);
    
    toFile<<fixed<<showpoint<<setprecision(2)<<endl;
    cout<<fixed<<showpoint<<setprecision(2)<<endl;  
    
    courseObj.display_stats();
    //cout << "\n";
    //toFile << "\n";
    
    cout<<"The name, average, and grade of the best student in the class is:\n";
    toFile<<"The name, average, and grade of the best student in the class is:\n";	
    courseObj.display_highest();
    
    cout<<"The name, average, and grade of the poorest student in the class is:\n";
    toFile<<"The name, average, and grade of the poorest student in the class is:\n";
    courseObj.display_lowest();
    toFile.close();
    system("PAUSE");

    return 0;
}

