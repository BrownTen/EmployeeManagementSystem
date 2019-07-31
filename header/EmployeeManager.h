#pragma once            // 防止头文件重复包含
#include <iostream>     // 包含输入输出流头文件
using namespace std;    // 使用标准命名空间

// 职工管理类
class EmployeeManager{
public:
    EmployeeManager();      // 职工管理构造函数

    void showMenu();        // 展示菜单
    void exitSystem();      // 退出系统

    ~EmployeeManager();     // 职工管理析构函数
};