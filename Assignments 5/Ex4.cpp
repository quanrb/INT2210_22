#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Student {
public:
    int ID;
    string Name;
    string Class;
    Student() {

    }
    Student(int id, string name, string Class) {
        this->ID = id;
        this->Name = name;
        this->Class = Class;
    }
};

class StudentManagement {
private:
    map<int, Student> students;

public:
    void insert(int ID, string Name, string Class) {
        Student student(ID, Name, Class);
        students[ID] = student;
    }
    void remove(int ID) {
        if(students.find(ID) != students.end()) {
            students.erase(ID);
        }
        else return;
    }
    void info(int ID) {
        if(students.find(ID) != students.end()) {
            Student student = students[ID];
            cout << student.Name << "," << student.Class;
        } 
        else cout << "NA,NA";
        cout << endl;
    }
};

string splitAction(string operation) {
    string res = "";
    int i = 0;
    while(operation[i] != '(') {
        res += operation[i];
        ++i;
    }
    return res;
}

int splitID(string operation) {
    int i = 0;
    while(operation[i] != '(') {
        ++i;
    }
    return operation[i+1] - '0';
}

pair<string, string> splitInfo(string operation) {
    string name = "";
    string Class = "";
    int i = 0;
    while(operation[i] != ',') {
        ++i;
    }
    ++i;
    while(operation[i] != ',') {
        name += operation[i];
        ++i;
    }
    ++i;
    while(operation[i] != ')') {
        Class += operation[i];
        ++i;
    }
    return make_pair(name, Class);
}

int main() {
    StudentManagement studentManager;
    while(true) {
        string operation;
        cin >> operation;
        string action = splitAction(operation);
        int id = splitID(operation);
        if(action == "Insert") {
            pair<string, string> info = splitInfo(operation);
            studentManager.insert(id, info.first, info.second);
        }
        else if(action == "Delete") {
            studentManager.remove(id);
        }
        else if(action == "Infor") {
            studentManager.info(id);
        }
        else break;
    }
    return 0;
}
