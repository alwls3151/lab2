#include <stdio.h>      // 표준 입출력 함수 사용을 위한 헤더 파일
#include <stdlib.h>     // exit() 함수 사용을 위한 헤더 파일
#include <string.h>     // 문자열 관련 함수 사용을 위한 헤더 파일
#include <errno.h>      // 오류 번호를 정의한 헤더 파일

// 사용자 정의 오류 출력 함수
void my_perror(const char *msg) {
    // 오류 메시지를 stderr에 출력
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

int main(int argc, char *argv[]) {
    FILE *f;  // 파일 포인터 선언

    // 인자가 충분하지 않은 경우 사용법 출력
    if (argc < 2) {
        printf("Usage: perror_use <filename>\n");
        exit(1);  // 프로그램 종료
    }

    // 파일을 읽기 모드로 열기
    if ((f = fopen(argv[1], "r")) == NULL) {
        my_perror("fopen");  // fopen 실패 시 오류 메시지 출력
        exit(1);  // 프로그램 종료
    }

    // 파일이 성공적으로 열렸음을 출력
    printf("Opened file \"%s\".\n", argv[1]);

    fclose(f);  // 파일 닫기
}
