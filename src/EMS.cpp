#include <iostream>
#include "../header/EmployeeManager.h"  // 引入职工管理类头文件
using namespace std;

int main() {

    EmployeeManager employeeManager;    // 创建职工管理类
    employeeManager.showMenu();         // 调用展示菜单函数

    cout << "请输入回车继续..." << endl;
    system("read");
    return 0;
}