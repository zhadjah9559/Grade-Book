/*==============================================================================
  
  
  
  
 
 =============================================================================*/
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <limits>

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
        int finalExam;
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
 
Student::Student()
{
    //name = " ";
    
    for(int i = 0; i<sizeof(project); i++)
        project[i] = 0;
    
    for(int i = 0; i<sizeof(exam); i++)
        exam[i] = 0;
    
    for(int i = 0; i<sizeof(quiz); i++)
        quiz[i] = 0;
        
    average, project_avg, exam_avg, quiz_avg = 0;
    
    finalExam = 0;
    
    for(int i = 0; i<sizeof(grade); i++)
        grade[i] = 0;
    
}

void Student::get_student_scores()
{
    //Test try catch heavily
    try
    {
        cout << "\n Enter Student Name: \n";
        cin>>name;

        for(int i = 0; i<sizeof(project); i++)
        {
            cout<<"Enter Student project grade #"<<i<<"\n";
            cin>>project[i];
        }

        for(int i = 0; i<sizeof(exam); i++)
        {
            cout<<"Enter Student exam grade #"<<i<<"\n";
            cin>>exam[i];
        }

        for(int i = 0; i<sizeof(quiz); i++)
        {
            cout<<"Enter Student quiz grade #"<<i<<"\n";
            cin>>quiz[i];
        }

        cout << "Enter final exam grade";
        cin>>finalExam;    
    }
    
    catch(...)
    {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
        cout<<"Error, invalid input entered. \n";
    }
}

void Student::compute_student_stats()
{
    int sum = 0;
    double projPercentage, examPercentage, quizPercentage, finalPercentage; 
    
    for(int i = 0; i<sizeof(project); i++)
    {
        project[i] += sum; 
        project_avg = sum/sizeof(project);
        cout << "Project Average = " << project_avg;
        sum = 0;
    }
    
    for(int i = 0; i<sizeof(exam); i++)
    {
        exam[i] += sum; 
        exam_avg = sum/sizeof(exam);
        cout << "Exam Average = " << exam_avg;
        sum = 0;
    }
    
    for(int i = 0; i<sizeof(quiz); i++)
    {
        quiz[i] += sum; 
        quiz_avg = sum/sizeof(quiz);
        cout << "Quiz Average = " << quiz_avg;
        sum = 0;
    }
    
    projPercentage = (project_avg/100) * (25/100);
    projPercentage *= 100;
    
    examPercentage = (exam_avg/100) * (40/100);
    examPercentage *= 100;
    
    quizPercentage = (quiz_avg/100) * (10/100);
    quizPercentage *= 100;
    
    finalPercentage = (finalExam/100) * (25/100) ;
    finalPercentage *= 100;
    
    average = projPercentage + examPercentage + quizPercentage + finalPercentage;
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout << "Semester Average = " << average;   
}
void Student::determine_student_grade()
{
    if(average <= 100 || average >= 93)
    {
        grade = 'A';
        cout << "Letter Grade = " << grade;
    }
    
    else if(average <= 92 || average >= 89)
    {
        grade = 'A-';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 88 || average >= 87)
    {
        grade = 'B+';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 86 || average >= 83)
    {
        grade = 'B';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 82 || average >= 79)
    {
        grade = 'B-';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 78 || average >= 77)
    {
        grade = 'C+';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 76 || average >= 73)
    {
        grade = 'C';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 72 || average >= 69)
    {
        grade = 'C-';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 68 || average >= 67)
    {
        grade = 'D+';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 66 || average >= 63)
    {
        grade = 'D';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 62 || average >= 57)
    {
        grade = 'D-';
        cout << "Letter Grade = " << grade;
    }
    else if(average <= 57)
    {
        grade = 'F';
        cout << "Letter Grade = " << grade;
    }
}
void Student::display_student_name_gpa_grade()
{
    const int width1 = 30;
    const int width2 = 20;
    fstream toFile;
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout << left << setw(width1) << "Student: " << name;
    cout << right << setw(width2) << "Average = " << average;
    cout << right << setw(width2) << "Letter Grade = " << grade;
    
    toFile.open("student.txt",ios::app);
    toFile<<fixed<<showpoint<<setprecision(2);
    toFile<<left<<setw(width1)<<name;
    toFile<<right<<setw(width2)<<average;
    toFile<<right<<setw(width2)<<grade;

}

double Student::student_average()
{
    //round to nearest tenth
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

