#include "Employee.h"

// 老板类
class Boss : public Employee {
public:
    Boss(int bossId, string bossName, int departmentId); // 声明老板类构造函数,初始化基本属性
    void showInfo();
    string getDepartmentName();
};