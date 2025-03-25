#include <iostream>
#include <vector>
using namespace std;

bool isSubArrayAtPosition(const vector<int>& A, const vector<int>& B, int pos) {
    for (int i = 0; i < A.size(); i++) {
        if (pos + i >= B.size() || A[i] != B[pos + i]) {
            return false;
        }
    }
    return true;
}

int countSubArrayOccurrences(const vector<int>& A, const vector<int>& B) {
    int count = 0;
    for (int i = 0; i <= B.size() - A.size(); i++) {
        if (isSubArrayAtPosition(A, B, i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    cout << "Nhap so phan tu cua mang A: ";
    cin >> n;
    vector<int> A(n);
    cout << "Nhap cac phan tu cua mang A: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Nhap so phan tu cua mang B: ";
    cin >> m;
    vector<int> B(m);
    cout << "Nhap cac phan tu cua mang B: ";
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    int occurrences = countSubArrayOccurrences(A, B);
    cout << "So lan mang A xuat hien lien tiep trong mang B: " << occurrences << endl;

    return 0;
}
