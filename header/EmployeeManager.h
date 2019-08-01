#pragma once            // 防止头文件重复包含
#include <iostream>     // 包含输入输出流头文件
#include <fstream>      // 引入文件操作流头文件
#include "Employee.h"
using namespace std;    // 使用标准命名空间

//#define FILENAME "EMS.txt"  //宏定义需要操作的文件的文件名(相对地址)
#define FILENAME "/Users/brownten_boy/Documents/exercise/CLionProjects/EmployeeManagementSystem/cmake-build-debug/EMS.txt" // 绝对地址
// 如果使用相对地址,可执行文件启动后建立在相对于用户目录下;而编译器建立在相对Cmakefile下
// fopen函数使用过程发现,当fopen要打开的文件路径中,包含一个不存在路径,不管fopen函数的第二参数设成什么,都无法建立该文件。

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
    int getEmployeeNumberFromFile();    // 声明从文件统计职工人数函数
    int initEmployeeManager();          // 声明职工管理类初始化函数
    void showEmployeeInfo();            // 声明显示职工信息函数
    int isEmployeeExist(int employeeId);// 声明判断职工是否存在
    int deleteEmp();        // 声明判断职工是否存在函数

    ~EmployeeManager();     // 声明职工管理析构函数

    EmployeeManager & setEmployeeNumber(int employeeNumber);      // 声明设置职工人数函数
    int getEmployeeNumber();        // 声明获得职工人数函数

    EmployeeManager & setPEmployees(Employee ** pEmployees);      // 声明设置员工数组指针指向函数
    Employee ** getPEmployees();    // 声明获取员工数组指针指向函数
};