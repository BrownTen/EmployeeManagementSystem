#pragma once
#include <iostream>
#include <string>   //包含字符串操作
using namespace std;

// 职工基类(抽象类)
class Employee{
public:
    int employeeId;         // 职工ID
    string employeeName;    // 职工姓名
    int departmentId;       // 部门ID

    virtual ~Employee(){};                  // 声明虚析构函数

    // 显示个人信息函数
    virtual void showInfo() = 0;            // 使用纯虚函数,规定让子类实现

    // 获取岗位名称函数
    virtual string getDepartmentName() = 0; // 使用纯虚函数,规定让子类实现
};