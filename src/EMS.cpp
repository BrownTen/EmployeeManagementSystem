#include <iostream>
#include "../header/EmployeeManager.h"  // 引入职工管理类头文件
using namespace std;

int main() {

    EmployeeManager employeeManager;    // 创建职工管理类

    int userSelectNumber;               // 用户功能数字选择

    while(true) {
        system("clear");                // 每次返回菜单清屏
        employeeManager.showMenu();     // 调用展示菜单函数
        cout << "请输入您的选择(0-7):";
        cin >> userSelectNumber;        // 用户输入功能选项
        switch (userSelectNumber){
            case 0:     // 退出系统
                employeeManager.exitSystem();
                break;
            case 1:     // 添加职工
                employeeManager.addEmployee();
                break;
            case 2:     // 显示职工
                break;
            case 3:     // 删除职工
                break;
            case 4:     // 修改职工
                break;
            case 5:     // 查找职工
                break;
            case 6:     // 排序职工
                break;
            case 7:     // 清空文件
                break;
            default:
                break;
        }
    }
}