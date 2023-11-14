#include <stdio.h>
#include <time.h>

void performanceTestFunction() {
    // 这里放置你要测试性能的代码
    // 例如，可以进行一些数学运算或者循环操作
    int result = 0;
    for (int i = 0; i < 1000000000; i++) {
        result += i;
    }
}

double measurePerformance() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // 记录开始时间

    // 调用性能测试函数
    performanceTestFunction();

    end = clock(); // 记录结束时间

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // 计算执行时间

    return cpu_time_used;
}

void main(char* args) {
    double executionTime = measurePerformance();
    printf("性能测试函数执行时间: %f 秒\n", executionTime);
    //return 0;
}
