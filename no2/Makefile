# Mackefile

# 변수 정의
CC = gcc
CFLAGS = -Wall -I./lib
LDFLAGS = -L./lib
LIB_DIR = lib
SRC_DIR = src
TARGET_STATIC = main_static
TARGET_SHARED = main_shared
TARGET_DYNAMIC = main_dynamic

# 파일 정의
LIB_STATIC = $(LIB_DIR)/libarith.a
LIB_SHARED = $(LIB_DIR)/libarith.so
LIB_OBJ = $(LIB_DIR)/no1.o
MAIN_SRC = $(SRC_DIR)/main.c
MAIN_OBJ = $(SRC_DIR)/main.o

# 기본 목표
all: $(TARGET_STATIC) $(TARGET_SHARED) $(TARGET_DYNAMIC)

# 정적 라이브러리 빌드
$(LIB_STATIC): $(LIB_OBJ)
	ar rcs $@ $^

# 공유 라이브러리 빌드
$(LIB_SHARED): $(LIB_OBJ)
	$(CC) -shared -o $@ $^

# 라이브러리 목적 파일 생성
$(LIB_OBJ): $(LIB_DIR)/no1.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# 메인 프로그램 컴파일 - 정적 라이브러리 링크
$(TARGET_STATIC): $(MAIN_SRC) $(LIB_STATIC)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(LDFLAGS) -larith -o $@

# 메인 프로그램 컴파일 - 공유 라이브러리 링크
$(TARGET_SHARED): $(MAIN_SRC) $(LIB_SHARED)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(LDFLAGS) -larith -o $@

# 동적 로딩을 위한 메인 프로그램 컴파일
$(TARGET_DYNAMIC): $(SRC_DIR)/main_dynamic.c $(LIB_SHARED)
	$(CC) $(CFLAGS) $< -ldl -o $@

# 청소
clean:
	rm -f $(LIB_OBJ) $(TARGET_STATIC) $(TARGET_SHARED) $(TARGET_DYNAMIC) $(LIB_STATIC) $(LIB_SHARED) $(SRC_DIR)/*.o
