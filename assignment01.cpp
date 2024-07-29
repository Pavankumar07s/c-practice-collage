#include <iostream>
using namespace std;

struct Student
{
    string name;
    int rollNumber;
    float SGPA;
};

void StudentInput(int count, string studentName, int roll, float SGPA, Student *s[])
{
    s[count] = new Student;
    s[count]->name = studentName;
    s[count]->rollNumber = roll;
    s[count]->SGPA = SGPA;
    cout << "inserted" << endl;
}

void DisplayStruct(struct Student *s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "student name :" << s[i]->name << endl;
        cout << "Roll number :" << s[i]->rollNumber << endl;
        cout << "SGPA :" << s[i]->SGPA << endl;
        cout << "---------------" << endl;
    }
}
void bubbleSort(struct Student *s[],int length)
{
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(s[j]->rollNumber<s[i]->rollNumber){
                swap(s[i],s[j]);
            }

        }

    }

    DisplayStruct(s,length);
}
void InsertionSort(struct Student *s[],int length)
{
    for(int i=0;i<length;i++){
        for(int j=i;j>0;j--){
            if(s[j]->name<s[j-1]->name){
                swap(s[j-1],s[j]);
            }

        }

    }

    DisplayStruct(s,length);
}
void MergeSort(struct Student *s[],int length)
{
}
void operation(int input,Student *s[],int length)
{
    switch (input)
    {
    case 1:
        bubbleSort(s,length);
        break;
    case 2:
        InsertionSort(s,length);
        break;
    case 3:
        MergeSort(s,length);
        break;

    default:
        break;
    }
}
void DisplayUserOption(Student *s[], int lengthOfArr)
{  
    int input;
    cout << "To sort the information according to rollNumber enter 1" << endl;
    cout << "To sort the information according to Student name enter 2" << endl;
    cout << "To sort the information according to SGPA 3" << endl;
    cin >> input;
    operation(input,s,lengthOfArr);
}

// all code for sorting



// Driver Code
int main()
{
    Student *s[20];
    int count = 0, responce = 0;
    do
    {

        cout << "Enter the name of Student :";
        string studentName;
        cin >> studentName;
        cout << "Enter the roll number :";
        int roll;
        cin >> roll;
        cout << "Enter the SGPA of student :";
        float SGPA;
        cin >> SGPA;
        StudentInput(count, studentName, roll, SGPA, s);
        count++;
        cout << "If want to countine the insertion of student record ,give input 1 to insert and 0 to exit ";
        cin >> responce;
    } while (responce != 0);

    // just displaying the struct information

    // DisplayStruct(s, count);
    DisplayUserOption(s,count);

    return 0;
}
