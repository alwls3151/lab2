# 변수 정의
CC = gcc
CFLAGS = -Wall -I./lib -g -pg
LDFLAGS = -L./lib
LIB_DIR = lib
SRC_DIR = src
TARGET_STATIC = main_static
TARGET_SHARED = main_shared
TARGET_DYNAMIC = main_dynamic

# 기본 목표
all: $(TARGET_STATIC) $(TARGET_SHARED) $(TARGET_DYNAMIC)

# 정적 라이브러리 빌드
$(LIB_DIR)/libarith.a: $(LIB_DIR)/arith.o
	ar rcs $@ $^

# 공유 라이브러리 빌드
$(LIB_DIR)/libarith.so: $(LIB_DIR)/arith.o
	$(CC) -shared -o $@ $^

# 라이브러리 목적 파일 생성
$(LIB_DIR)/arith.o: $(LIB_DIR)/arith.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# 메인 프로그램 컴파일 - 정적 라이브러리 링크
$(TARGET_STATIC): $(SRC_DIR)/main.c $(LIB_DIR)/libarith.a
	$(CC) $(CFLAGS) $< $(LDFLAGS) -larith -o $@

# 메인 프로그램 컴파일 - 공유 라이브러리 링크
$(TARGET_SHARED): $(SRC_DIR)/main.c $(LIB_DIR)/libarith.so
	$(CC) $(CFLAGS) $< $(LDFLAGS) -larith -o $@

# 메인 프로그램 컴파일 - 동적 로딩 방식
$(TARGET_DYNAMIC): $(SRC_DIR)/main_dynamic.c $(LIB_DIR)/libarith.so
	$(CC) $(CFLAGS) $< -ldl -o $@

# 청소
clean:
	rm -f $(LIB_DIR)/*.o $(TARGET_STATIC) $(TARGET_SHARED) $(TARGET_DYNAMIC) $(LIB_DIR)/libarith.a $(LIB_DIR)/libarith.so
