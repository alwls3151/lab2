#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*add)(int, int), (*subtract)(int, int), (*multiply)(int, int);
    double (*divide)(int, int);
    char *error;

    handle = dlopen("./lib/libarith.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    add = dlsym(handle, "add");
    subtract = dlsym(handle, "subtract");
    multiply = dlsym(handle, "multiply");
    divide = dlsym(handle, "divide");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    int a = 20, b = 10;

    printf("Add: %d\n", add(a, b));
    printf("Subtract: %d\n", subtract(a, b));
    printf("Multiply: %d\n", multiply(a, b));
    printf("Divide: %.2f\n", divide(a, b));

    dlclose(handle);
    return 0;
}
