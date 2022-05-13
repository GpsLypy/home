多线程打印奇偶数
时间限制： 1000MS
内存限制： 524288KB
题目描述：
假设有这么一个类：

class ZeroAndEvenOdd {
  public ZeroAndEvenOdd(int n) { ... }      // 构造函数
  public void printZero(printNumber) { ... }  // 仅打印出 0
  public void printEven(printNumber) { ... }  // 仅打印出 偶数
  public void printOdd(printNumber) { ... }   // 仅打印出 奇数
}
相同的一个 ZeroAndEvenOdd类实例将会传递给三个不同的线程：

线程 A 将调用 printZero()，它只输出 0 。

线程 B 将调用 printEven()，它只输出偶数。

线程 C 将调用 printOdd()，它只输出奇数。

每个线程都有一个 printNumber 方法来输出一个整数。请修改给出的代码以输出整数序列 010203040506... ，其中序列的长度必须为 2n。



输入描述
整数n

输出描述
输出整数序列 010203040506... ，输出整数序列 010203040506... ，其中序列的长度必须为 2n


样例输入
5
样例输出
0102030405

提示
使用C++的同学注意，本题的编译命令为：g++ Main.cc -o Main -O2 -fno-asm -Wall -lm -static -std=c++11 -lrt -Wl,--whole-archive -lpthread -Wl,--no-whole-archive












#include <condition_variable>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

class ZeroAndEvenOdd {
    private:
    bool ze;
    bool other;
    int n;
    std::condition_variable cv;
    std::mutex mtx;

    public:
    ZeroAndEvenOdd(int m) : ze(false), other(true), n(m) {
    }

    // printNumber(x) outputs "x", where x is an integer.
    void printZero(std::function<void(int)> printNumber) {
      //待实现
    }

    void printEven(std::function<void(int)> printNumber) {
      //待实现
    }

    void printOdd(std::function<void(int)> printNumber) {
      //待实现
    }
};

void printNumber(int i) {
    std::cout << i;                           
}

int main(int argc, char** argv) {
   int n = 0;
   std::cin >> n;
   ZeroAndEvenOdd zeo(n);
   std::thread th1 = std::thread(std::bind(&ZeroAndEvenOdd::printZero, &zeo, std::placeholders::_1), printNumber);
   std::thread th2 = std::thread(std::bind(&ZeroAndEvenOdd::printEven, &zeo, std::placeholders::_1), printNumber);
   std::thread th3 = std::thread(std::bind(&ZeroAndEvenOdd::printOdd, &zeo, std::placeholders::_1), printNumber);
   th1.join();
   th2.join();
   th3.join();


   std::cout << std::endl;
   return 0;
}