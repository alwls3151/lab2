#include <stdio.h>
#include <stdlib.h>

// 행렬의 요소를 입력받는 함수
// matrix: 입력받을 행렬 포인터
// rows: 행의 개수
// cols: 열의 개수
void inputMatrix(int **matrix, int rows, int cols) {
    printf("행렬의 값을 입력하세요. %d x %d :\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]); // 각 행렬 요소를 입력받음
        }
    }
}

// 행렬을 출력하는 함수
// matrix: 출력할 행렬 포인터
// rows: 행의 개수
// cols: 열의 개수
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]); // 각 요소를 출력
        }
        printf("\n"); // 각 행이 끝날 때 줄바꿈
    }
}

int main() {
    int rows, cols;
   
    // 행렬의 크기를 입력받음
    printf("행렬의 크기를 입력하세요 a x b: ");
    scanf("%d %d", &rows, &cols);
   
    // 행렬 동적 메모리 할당
    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    int **result = (int **)malloc(rows * sizeof(int *));
   
    // 각 행에 대해 메모리 할당 (열의 크기만큼)
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));
    }
   
    // 첫 번째 행렬 입력
    printf("행렬 1 1:\n");
    inputMatrix(matrix1, rows, cols);

    // 두 번째 행렬 입력
    printf("행렬 2:\n");
    inputMatrix(matrix2, rows, cols);

    // 두 행렬의 덧셈을 수행하여 결과 행렬에 저장
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
   
    // 결과 행렬 출력
    printf("결과 :\n");
    printMatrix(result, rows, cols);
   
    // 동적으로 할당된 메모리 해제
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
   
    return 0;
}
