#include "../header/Employee.h"
#include "../header/Staff.h"
#include "../header/Manager.h"
#include "../header/Boss.h"

// 测试多态,以及各个职工类
void test01(){
    Employee * employee = NULL;
    employee = new Staff(1 ,"张三", 1);
    employee->showInfo();
    if (employee!=NULL){
        delete employee;
        employee = NULL;
    }

    employee = new Manager(2, "李四", 2);
    employee->showInfo();
    delete employee;

    employee = new Boss(3, "王五", 3);
    employee->showInfo();
    delete employee;
}

int main() {
    test01();
    return 0;
}
