#include "Employee.h"

// 经理类
class Manager : public Employee {
public:
    Manager(int managerId, string managerName, int departmentId); // 声明经理类构造函数,初始化基本属性
    void showInfo();
    string getDepartmentName();
};