#include <iostream>
#include <vector>
#include <iomanip>  // 控制小数点输出
using namespace std;

class Student {
private:
    string name;
    int score;
public:
    Student(string n, int s)  //构造函数
    {
        name = n;
        score = s;        
    }
    string getName() { return name; }
    int getScore() { return score; }
    void show() {
        cout << name << ": " << score << endl;
    }
   ~Student (){}
};
class StudentManager {
private:
    vector<Student> students;  // 存储学生对象的列表
public:
    void addStudent(string name, int score) {
        students.push_back(Student(name, score));
    }
    void printStudents() {
        if (students.empty()) {
            cout << "There's no student data.\n";
            return;
        }
        for (auto &s : students)
            s.show();
    }
    void calcAverage() {
        if (students.empty()) {
            cout << "There's no student data. We cannot calculate the average grade.\n";
            return;
        }
        double sum = 0;
        for (auto &s : students) {
            sum += s.getScore();
        }
        cout << "Average grade: " << fixed << setprecision(2) << sum / students.size() << endl;
    }
};

int main() {
    StudentManager manager;
    int choice;
    string name;
    int score;

    while (true) {
        cout << "\n1. adding\n2. display all students\n3. show the average grade\n4. exit\nPlease select: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the name and score: ";
                cin >> name >> score;
                manager.addStudent(name, score);
                break;
            case 2:
                manager.printStudents();
                break;
            case 3:
                manager.calcAverage();
                break;
            case 4:
                cout << "Exit the program\n";
                return 0;
            default:
                cout << "Invalid input\n";
        }
    }
}


