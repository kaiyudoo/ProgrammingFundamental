#include <iostream>
#include <string>

using namespace std;

struct Subject{
	string subname;
	double mark;
	char grade;
	double gradep;	
};

struct Student{
	string name;
	int age;
	int count;
	Subject sub[5];
	double cpa;	
};

char gradeCalculator(double mark) {
    if (mark >= 75){
        return 'A';
        
    }else if (mark >= 60){
        return 'B';

    } else if (mark >= 45){
        return 'C';

    } else if (mark >= 30){
        return 'D';

    } else return 'F';
}

double checkMark(double mark){
	
	while (mark < 0 || mark > 100){
		cout << "Marks cannot be a negative number or more than 100. Please enter marks again" << endl;
		
		cout << "Enter subject mark: " ;
		cin >> mark;
		
	}
}
	
void inputStudent(Student &s){
   
    cout << "Student name: ";
    cin >> s.name;

    cout << "Student age: ";
    cin >> s.age;

    cout << "Number of subjects (Max 5): ";
    cin >> s.count;
    

    double totalP = 0; 

    for (int i = 0; i < s.count; i++) {
        cout << endl;
        cout << "Subject " << i + 1 << " Name: ";
       	cin >> s.sub[i].subname;

        cout << "Enter subject mark: ";
        cin >> s.sub[i].mark;
        
        if (s.sub[i].mark < 0 || s.sub[i].mark > 100){
            checkMark(s.sub[i].mark);
        }
        
        cout << "Enter subject grade points: ";
        cin >> s.sub[i].gradep;

        
        s.sub[i].grade = gradeCalculator(s.sub[i].mark);

        
        totalP = totalP + s.sub[i].gradep;

    }
 
    
    s.cpa = totalP / s.count;
}


void displayStudent(Student s){
    cout << endl;
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "CPA: " << s.cpa << endl;

    cout << "Subjects:";
    cout << endl;

    for (int i = 0; i < s.count; i++) {
        cout << s.sub[i].subname << "   Mark: " << s.sub[i].mark << "   Grade: " << s.sub[i].grade << "   Grade Points: " << s.sub[i].gradep << endl;
    }
}


int main(){
	Student s[10];
    int count;
	
	cout << "Enter amount of students (Max10): " ;
	cin >> count;

    for (int i = 0; i < count; i++) {
        cout << endl;
        cout << "\n---- Enter student " << i + 1 << " details ----";
        cout << endl;

        inputStudent(s[i]);
    }

    cout << "\n\n---------Students---------" << endl;

    for (int i = 0; i < count; i++) {
        displayStudent(s[i]);
    }

    return 0;
}
