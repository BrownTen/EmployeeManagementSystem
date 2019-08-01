#include "../header/Staff.h"    // 引入普通员工类头文件

Staff ::Staff(int staffId, string staffName, int departmentId) {  // 实现普通员工类构造函数
    this->employeeId = staffId;         // 赋值普通员工Id
    this->employeeName = staffName;     // 赋值普通员工姓名
    this->departmentId = departmentId;  // 赋值部门Id
}

void Staff ::showInfo() {
    cout << "职工编号:" << this->employeeId
        << "\n\t职工姓名:" << this->employeeName
        << "\n\t岗位:" << this->getDepartmentName()
        << "\n\t岗位职责:" << "完成经理交给的任务" << endl;
}

string Staff ::getDepartmentName() {
    return string("员工");
}
