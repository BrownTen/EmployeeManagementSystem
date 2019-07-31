#include "Employee.h"   // 引入职工基类头文件

// 普通员工类
class Staff : public Employee {
public:
    Staff(int staffId, string staffName, int departmentId); // 声明普通员工类构造函数,初始化基本属性
    void showInfo();            // 声明显示个人信息函数
    string getDepartmentName(); // 声明获取岗位名称函数
};