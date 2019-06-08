#include <iostream>
#include <algorithm>

using namespace std;

class Student {
    public:
        string name;
        int score;
        Student(string name, int score) {
            this -> name = name;
            this -> score = score;
        }

        bool operator <(Student &student) {
            return this->score < student.score;
        }
};

int main(void) {
    Student students[] = {
        Student("Yong", 90),
        Student("Yeoung", 100),
        Student("Dae", 80),
        Student("Kim", 76),
        Student("Hwang", 86)
    };

    sort(students, students +5);
    for(int i = 0; i < 5; i++) {
        cout << students[i].score << ' ';
    }
}
