#include "../header/Manager.h"

Manager::Manager(int managerId, string managerName, int departmentId) { // 实现经理类构造函数
    this->employeeId = managerId;       // 赋值经理Id
    this->employeeName = managerName;   // 赋值经理姓名
    this->departmentId = departmentId;
}

void Manager::showInfo() {
    cout << "职工编号:" << this->employeeId
         << "\n\t职工姓名:" << this->employeeName
         << "\n\t岗位:" << this->getDepartmentName()
         << "\n\t岗位职责:" << "完成老板交给的任务,并分发任务给员工" << endl;
}

string Manager::getDepartmentName() {
    return string("经理");
}
