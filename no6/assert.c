#include <stdio.h>      // 표준 입출력 함수 사용을 위한 헤더 파일
#include <stdlib.h>     // exit(), atoi() 함수 사용을 위한 헤더 파일

// 사용자 정의 assert 함수의 선언
void my_assert(int a, const char *message);

// 사용자 정의 assert 함수
void my_assert(int a, const char *message) {
    // 조건이 false일 경우 오류 메시지 출력 및 프로그램 종료
    if (!a) {
        fprintf(stderr, "failed: %s\n", message);
        exit(1);
    }
}

// num이 0에서 100 사이인지 체크하는 함수
void foo(int num) {
    // my_assert를 통해 조건 확인
    my_assert((num >= 0 && num <= 100), "failed");

    // 조건을 통과하면 num 출력
    printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[]) {
    int num;

    // 인자가 부족할 경우 사용법 출력
    if (argc < 2) {
        fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <= 100)\n");
        exit(1);  // 프로그램 종료
    }

    // 입력된 문자열을 정수로 변환
    num = atoi(argv[1]);
    // foo 함수 호출
    foo(num);
}

