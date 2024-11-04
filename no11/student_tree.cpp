#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Student {
    int midterm;
    int final;
};

int main() {
    int n;
    cout << "학생 수를 입력해주세요: ";
    cin >> n;

    map<string, Student> studentMap;
    for (int i = 0; i < n; i++) {
        string name;
        Student student;
        cout << "학생의 이름, 중간고사, 기말고사 성적을 입력해주세요. " << i + 1 << ": ";
        cin >> ws; 
        getline(cin, name);
        cin >> student.midterm >> student.final;
       
        studentMap[name] = student;
    }

    string searchName;
    cout << "검색할 이름을 작성해주세요.: ";
    cin >> ws; 
    getline(cin, searchName);

    auto it = studentMap.find(searchName);
    if (it != studentMap.end()) {
        cout << "이름: " << it->first << ", 중간고사: " << it->second.midterm << ", 기말고사: " << it->second.final << endl;
    } else {
        cout << "학생을 찾을 수 없습니다." << endl;
    }

    return 0;
}
