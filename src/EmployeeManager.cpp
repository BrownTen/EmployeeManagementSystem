#include "../header/EmployeeManager.h"  // 引入职工管理类头文件

EmployeeManager::EmployeeManager() {}   // 实现职工管理类构造函数

void EmployeeManager::showMenu() {      // 实现展示菜单
    cout << "*****************************" << endl;
    cout << "*** 欢迎使用职工管理系统  ***" << endl;
    cout << "*****\t0.退出管理系统\t*****" << endl;
    cout << "*****\t1.增加职工信息\t*****" << endl;
    cout << "*****\t2.显示职工信息\t*****" << endl;
    cout << "*****\t3.删除离职职工\t*****" << endl;
    cout << "*****\t4.修改职工信息\t*****" << endl;
    cout << "*****\t5.查找职工信息\t*****" << endl;
    cout << "*****\t6.按照编号排序\t*****" << endl;
    cout << "*****\t7.清空所有文档\t*****" << endl;
    cout << "*****************************" << endl;
    cout << endl;
}

void EmployeeManager::exitSystem() {    // 实现退出系统
    cout << "欢迎下次使用\n请输入回车继续..." << endl;
    system("read");
    exit(0);
}

EmployeeManager::~EmployeeManager() {}  // 实现职工管理类析构函数
