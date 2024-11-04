#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int midterm;
    int final;
} Student;

typedef struct TreeNode {
    Student student;
    struct TreeNode *left, *right;
} TreeNode;

// 트리에 학생을 삽입하는 함수
TreeNode* insert(TreeNode *node, Student student) {
    if (node == NULL) {
        TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
        newNode->student = student;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (strcmp(student.name, node->student.name) < 0) {
        node->left = insert(node->left, student);
    } else {
        node->right = insert(node->right, student);
    }
    return node;
}

// 학생 이름을 검색하여 출력하는 함수
void search(TreeNode *node, char *name) {
    if (node == NULL) {
        printf("학생을 찾을 수 없습니다.\n");
        return;
    }

    if (strcmp(name, node->student.name) == 0) {
        printf("이름: %s, 중간고사: %d, 기말고사: %d\n", node->student.name, node->student.midterm, node->student.final);
    } else if (strcmp(name, node->student.name) < 0) {
        search(node->left, name);
    } else {
        search(node->right, name);
    }
}

// 트리의 메모리를 해제하는 함수
void freeTree(TreeNode *node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    int n;
    printf("학생 수를 입력해 주세요: ");
    scanf("%d", &n);
    getchar();  // input buffer에서 new line 캐릭터 삭제함

    TreeNode *root = NULL;
    for (int i = 0; i < n; i++) {
        Student student;
        printf("이름, 중간고사, 기말고사 성적을 입력해주세요. %d: ", i + 1);
        fgets(student.name, 50, stdin);
        student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline character
        scanf("%d %d", &student.midterm, &student.final);
        getchar();

        root = insert(root, student);
    }

    char searchName[50];
    printf("검색할 이름을 작성해주세요.: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline character
    search(root, searchName);

    freeTree(root);
    return 0;
}
