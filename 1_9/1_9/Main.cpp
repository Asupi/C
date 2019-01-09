#if 0

void demo() {
	高精度计时	计时器;
	计时器.开始();
	// 执行耗时函数
	计时器.结束();

	printf("执行时间 %f 毫秒\n", 计时器.间隔毫秒());
}

#endif

#include "Sort.h"

int main() {
	TestSortSpeed();
	//TestSort();
}
