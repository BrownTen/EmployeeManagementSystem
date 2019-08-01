#include "../header/Employee.h"
#include "../header/Staff.h"
#include "../header/Manager.h"
#include "../header/Boss.h"
#include "../header/EmployeeManager.h"

// 测试获取数据
void test03(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    ofs << 1 << " " << "老大" << " " << 3 << endl;
    ofs << 2 << " " << "老二" << " " << 2 << endl;
    ofs << 3 << " " << "老三" << " " << 1 << endl;
    ofs << 4 << " " << "老四" << " " << 2 << endl;
    ofs << 5 << " " << "老五" << " " << 1 << endl;
    ofs.close();

    EmployeeManager employeeManager;

    employeeManager.setEmployeeNumber(employeeManager.getEmployeeNumberFromFile())
                    .setPEmployees(new Employee*[employeeManager.getEmployeeNumber()])
                    .initEmployeeManager();

    for (int i = 0; i < employeeManager.getEmployeeNumber(); ++i) {
        cout << "职工Id:" << (*(employeeManager.getPEmployees() + i))->employeeId << " "
            << "姓名:" << (*(employeeManager.getPEmployees() + i))->employeeName << " "
            << "部门:" << (*(employeeManager.getPEmployees() + i))->getDepartmentName() << endl;
    }
};

// 测试获取职工数量函数
void test02(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    ofs << 1 << " " << "老大" << " " << 3 << endl;
    ofs << 2 << " " << "老二" << " " << 2 << endl;
    ofs << 3 << " " << "老三" << " " << 1 << endl;
    ofs << 4 << " " << "老四" << " " << 2 << endl;
    ofs << 5 << " " << "老五" << " " << 1 << endl;
    ofs.close();

    EmployeeManager employeeManager;
    int employeeNumber = employeeManager.getEmployeeNumberFromFile();
    cout << "职工个数为:" << employeeNumber << endl;
}

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
    test03();
//    test02();
//    test01();
    return 0;
}
