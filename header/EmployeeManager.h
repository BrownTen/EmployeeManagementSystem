#pragma once            // 防止头文件重复包含
#include <iostream>     // 包含输入输出流头文件
#include <fstream>      // 引入文件操作流头文件
#include "Employee.h"
using namespace std;    // 使用标准命名空间

#define FILENAME "EMS.txt"  //宏定义需要操作的文件的文件名

// 职工管理类
class EmployeeManager{
private:
    int employeeNumber;     // 职工人数
    Employee ** pEmployees; // 员工指针数组(二级指针/指针数组)
    bool isEMSFileEmpty;    // 判断文件是否为空
public:
    EmployeeManager();      // 声明职工管理构造函数

    void showMenu();        // 声明展示菜单函数
    void exitSystem();      // 声明退出系统函数
    int addEmployee();      // 声明增加职工函数
    int saveFile();         // 声明保存文件函数
    int getEmployeeNumberFromFile();    // 声明统计人数函数
    int initEmployeeManager();          // 声明职工管理类初始化函数

    ~EmployeeManager();     // 声明职工管理析构函数

    EmployeeManager & setEmployeeNumber(int employeeNumber);      // 声明设置职工人数函数
    int getEmployeeNumber();        // 声明获得职工人数函数

    EmployeeManager & setPEmployees(Employee ** pEmployees);      // 声明设置员工数组指针指向函数
    Employee ** getPEmployees();    // 声明获取员工数组指针指向函数
};