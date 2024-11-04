#include <iostream>
#include <vector>

using namespace std;

// 행렬의 요소를 입력받는 함수
// matrix: 입력받을 행렬 (vector 컨테이너)
// rows: 행의 개수
// cols: 열의 개수
void inputMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    cout << "행렬의 요소를 입력해주세요 " << rows << " x " << cols << " :\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j]; // 각 행렬 요소를 입력받음
        }
    }
}

// 행렬을 출력하는 함수
// matrix: 출력할 행렬 (vector 컨테이너)
// rows: 행의 개수
// cols: 열의 개수
void printMatrix(const vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " "; // 각 요소를 출력
        }
        cout << endl; // 각 행이 끝날 때 줄바꿈
    }
}

int main() {
    int rows, cols;
   
    // 행렬의 크기를 사용자로부터 입력받음
    cout << "행렬의 크기를 입력해주세요: ";
    cin >> rows >> cols;
   
    // 행렬 동적 할당 (vector 컨테이너 사용)
    vector<vector<int>> matrix1(rows, vector<int>(cols)); // 첫 번째 행렬
    vector<vector<int>> matrix2(rows, vector<int>(cols)); // 두 번째 행렬
    vector<vector<int>> result(rows, vector<int>(cols));  // 결과 행렬
   
    // 첫 번째 행렬 입력
    cout << "행렬 1:\n";
    inputMatrix(matrix1, rows, cols);
   
    // 두 번째 행렬 입력
    cout << "행렬 2:\n";
    inputMatrix(matrix2, rows, cols);

    // 두 행렬의 덧셈을 수행하여 결과 행렬에 저장
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j]; // 각 요소를 더하여 결과 행렬에 저장
        }
    }
   
    // 결과 행렬 출력
    cout << "결과 :\n";
    printMatrix(result, rows, cols);
   
    return 0;
}
