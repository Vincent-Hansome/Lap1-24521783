#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct Student {
    string name;
    float math;
    float literature;
    float english;
    float average;
    string classification;
};

bool isValidName(const string& name) {
    for (char c : name) {
        if (isdigit(c)) return false;
    }
    return true;
}

bool isValidScore(float score) {
    return score >= 0 && score <= 10;
}

void inputStudentInfo(Student& student) {
    cout << "Nhap ho ten: ";
    while (true) {
        getline(cin, student.name);
        if (isValidName(student.name)) break;
        cout << "Ho ten khong hop le. Nhap lai: ";
    }

    cout << "Nhap diem Toan: ";
    while (!(cin >> student.math) || !isValidScore(student.math)) {
        cout << "Diem Toan khong hop le. Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Nhap diem Van: ";
    while (!(cin >> student.literature) || !isValidScore(student.literature)) {
        cout << "Diem Van khong hop le. Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Nhap diem Anh: ";
    while (!(cin >> student.english) || !isValidScore(student.english)) {
        cout << "Diem Anh khong hop le. Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void calculateAverage(Student& student) {
    student.average = (2 * student.math + student.literature + student.english) / 4;
}

void classifyStudent(Student& student) {
    if (student.average >= 9) {
        student.classification = "Xuat sac";
    }
    else if (student.average >= 8) {
        student.classification = "Gioi";
    }
    else if (student.average >= 6.5) {
        student.classification = "Kha";
    }
    else if (student.average >= 5) {
        student.classification = "Trung binh";
    }
    else {
        student.classification = "Yeu";
    }
}

Student findTopStudent(const vector<Student>& students) {
    return *max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.average < b.average;
        });
}

vector<Student> searchStudentsByName(const vector<Student>& students, const string& keyword) {
    vector<Student> result;
    for (const Student& student : students) {
        string name = student.name;
        string lowerName, lowerKeyword;
        transform(name.begin(), name.end(), back_inserter(lowerName), ::tolower);
        transform(keyword.begin(), keyword.end(), back_inserter(lowerKeyword), ::tolower);
        if (lowerName.find(lowerKeyword) != string::npos) {
            result.push_back(student);
        }
    }
    return result;
}

vector<Student> findLowestMathScoreStudents(const vector<Student>& students) {
    float minMathScore = min_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.math < b.math;
        })->math;

    vector<Student> result;
    for (const Student& student : students) {
        if (student.math == minMathScore) {
            result.push_back(student);
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        inputStudentInfo(students[i]);
        calculateAverage(students[i]);
        classifyStudent(students[i]);
    }

    Student topStudent = findTopStudent(students);
    cout << "\nHoc sinh co diem trung binh cao nhat:\n";
    cout << "Ho ten: " << topStudent.name << ", Diem TB: " << topStudent.average << ", Phan loai: " << topStudent.classification << endl;

    string keyword;
    cout << "\nNhap ten hoc sinh can tim: ";
    getline(cin, keyword);
    vector<Student> foundStudents = searchStudentsByName(students, keyword);
    cout << "\nKet qua tim kiem:\n";
    for (const Student& student : foundStudents) {
        cout << "Ho ten: " << student.name << ", Diem TB: " << student.average << ", Phan loai: " << student.classification << endl;
    }

    vector<Student> lowestMathScoreStudents = findLowestMathScoreStudents(students);
    cout << "\nDanh sach hoc sinh co diem Toan thap nhat:\n";
    for (const Student& student : lowestMathScoreStudents) {
        cout << "Ho ten: " << student.name << ", Diem Toan: " << student.math << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct Student {
    string name;
    float math;
    float literature;
    float english;
    float average;
    string classification;
};

bool isValidName(const string& name) {
    for (char c : name) {
        if (isdigit(c)) return false;
    }
    return true;
}

bool isValidScore(float score) {
    return score >= 0 && score <= 10;
}

void inputStudentInfo(Student& student) {
    cout << "Nhap ho ten: ";
    while (true) {
        getline(cin, student.name);
        if (isValidName(student.name)) break;
        cout << "Ho ten khong hop le. Nhap lai: ";
    }

    cout << "Nhap diem Toan: ";
    while (!(cin >> student.math) || !isValidScore(student.math)) {
        cout << "Diem Toan khong hop le. Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Nhap diem Van: ";
    while (!(cin >> student.literature) || !isValidScore(student.literature)) {
        cout << "Diem Van khong hop le. Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Nhap diem Anh: ";
    while (!(cin >> student.english) || !isValidScore(student.english)) {
        cout << "Diem Anh khong hop le. Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void calculateAverage(Student& student) {
    student.average = (2 * student.math + student.literature + student.english) / 4;
}

void classifyStudent(Student& student) {
    if (student.average >= 9) {
        student.classification = "Xuat sac";
    }
    else if (student.average >= 8) {
        student.classification = "Gioi";
    }
    else if (student.average >= 6.5) {
        student.classification = "Kha";
    }
    else if (student.average >= 5) {
        student.classification = "Trung binh";
    }
    else {
        student.classification = "Yeu";
    }
}

Student findTopStudent(const vector<Student>& students) {
    return *max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.average < b.average;
        });
}

vector<Student> searchStudentsByName(const vector<Student>& students, const string& keyword) {
    vector<Student> result;
    for (const Student& student : students) {
        string name = student.name;
        string lowerName, lowerKeyword;
        transform(name.begin(), name.end(), back_inserter(lowerName), ::tolower);
        transform(keyword.begin(), keyword.end(), back_inserter(lowerKeyword), ::tolower);
        if (lowerName.find(lowerKeyword) != string::npos) {
            result.push_back(student);
        }
    }
    return result;
}

vector<Student> findLowestMathScoreStudents(const vector<Student>& students) {
    float minMathScore = min_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.math < b.math;
        })->math;

    vector<Student> result;
    for (const Student& student : students) {
        if (student.math == minMathScore) {
            result.push_back(student);
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        inputStudentInfo(students[i]);
        calculateAverage(students[i]);
        classifyStudent(students[i]);
    }

    Student topStudent = findTopStudent(students);
    cout << "\nHoc sinh co diem trung binh cao nhat:\n";
    cout << "Ho ten: " << topStudent.name << ", Diem TB: " << topStudent.average << ", Phan loai: " << topStudent.classification << endl;

    string keyword;
    cout << "\nNhap ten hoc sinh can tim: ";
    getline(cin, keyword);
    vector<Student> foundStudents = searchStudentsByName(students, keyword);
    cout << "\nKet qua tim kiem:\n";
    for (const Student& student : foundStudents) {
        cout << "Ho ten: " << student.name << ", Diem TB: " << student.average << ", Phan loai: " << student.classification << endl;
    }

    vector<Student> lowestMathScoreStudents = findLowestMathScoreStudents(students);
    cout << "\nDanh sach hoc sinh co diem Toan thap nhat:\n";
    for (const Student& student : lowestMathScoreStudents) {
        cout << "Ho ten: " << student.name << ", Diem Toan: " << student.math << endl;
    }

    return 0;
}
