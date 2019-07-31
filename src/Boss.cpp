#include "../header/Boss.h"

Boss::Boss(int bossId, string bossName, int departmentId) { // 实现老板类构造函数
    this->employeeId = bossId;       // 赋值老板Id
    this->employeeName = bossName;   // 赋值老板姓名
    this->departmentId = departmentId;
}

void Boss::showInfo() {
    cout << "职工编号:" << this->employeeId
         << "\n\t职工姓名:" << this->employeeName
         << "\n\t岗位:" << this->getDepartmentName()
         << "\n\t岗位职责:" << "负责公司所有事务" << endl;
}

string Boss::getDepartmentName() {
    return string("老板");
}

