#include "../header/EmployeeManager.h"  // 引入职工管理类头文件
#include "../header/Staff.h"            // 引入普通员工类头文件
#include "../header/Manager.h"          // 引入经理类头文件
#include "../header/Boss.h"             // 引入老板类头文件

// 实现职工管理类构造函数,并使用初始化列表方式初始化职工数量为0,职工指针数组指向NULL
EmployeeManager ::EmployeeManager() : employeeNumber(0),pEmployees(NULL) {}

void EmployeeManager ::showMenu() {      // 实现展示菜单
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

void EmployeeManager ::exitSystem() {    // 实现退出系统
    cout << "欢迎下次使用\n请输入回车继续..." << endl;
    system("read");
    exit(0);
}

int EmployeeManager ::addEmployee() {   // 实现增加职工
    cout << "请输入需要增加职工的数量:";
    int addNumber;      // 需要增加的员工数量
    cin >> addNumber;
    if (addNumber > 0){ // 判断需要增加的员工是否合法
        // 1.计算新空间大小
        int newSize = this->employeeNumber + addNumber;

        // 2.在堆区开辟一个新的newSize大小的指针数组
        Employee ** newPEmployees = new Employee*[newSize];

        // 3.将原来的指针数组的内容存放到新的新的指针数组中
        if (this->pEmployees != NULL) {
            for (int i = 0; i < this->employeeNumber; ++i) {
                *(newPEmployees+i) = *(this->pEmployees+i);
                // 指针偏移相当与newPEmployees[i] = this->pEmployees[i];
            }
        }

        // 4.输入新数据(批量增加)
        for (int i = 0; i < addNumber; ++i) {   // 循环输入需要新增员工的信息
            // 4.1 录入基本信息
            int employeeId;         // 职工Id
            string employeeName;    // 职工姓名
            int departmentId;       // 部门Id
            cout << "请输入第 " << i + 1 + this->employeeNumber
                << " 个职工( " << i + 1 + this->employeeNumber << " / " << newSize << " )的信息:" << endl;
            cout << "\t职工编号:";
            cin >> employeeId;
            cout << "\t职工姓名:";
            cin >> employeeName;
            cout << "\t请选择职工的岗位:" << endl;
            cout << "\t\t1.普通员工" << endl;
            cout << "\t\t2.经理" << endl;
            cout << "\t\t3.老板" << endl;
            cout << "\t请选择(1-3):";
            cin >> departmentId;

            // 4.2 创建对象(多态)
            Employee *employee = NULL;
            switch (departmentId){
                case 1:
                    employee = new Staff(employeeId, employeeName, departmentId);
                    break;
                case 2:
                    employee = new Manager(employeeId, employeeName, departmentId);
                    break;
                case 3:
                    employee = new Boss(employeeId, employeeName, departmentId);
                    break;
                default:
                    cout << "该条记录创建失败" << endl;
                    cout << "输入有误\n请输入回车继续..." << endl;
                    system("read");
                    break;
            }

            // 4.3 将创建好的对象插入指针数组中
            *(newPEmployees + i + this->employeeNumber) = employee;
            // 指针偏移相当与newPEmployees[i + this->employeeNumber] = employee;
        }

        // 5.释放原来的指针数组空间
        if (this->pEmployees != NULL) {
            delete[] pEmployees;
            this->pEmployees = NULL;
        }

        // 6.更改指针数组指向
        this->pEmployees = newPEmployees;

        // 7.更改员工数量
        this->employeeNumber = newSize;

        // 8.增加成功,返回1
        cout << "成功添加 " << addNumber << " 名员工\n请输入回车接续..." << endl;
        system("read");
        return 1;
    } else {
        cout << "输入有误\n请输入回车继续..." << endl;
        system("read");
        return 0;   // 增加失败,返回0
    }
}

EmployeeManager ::~EmployeeManager() {}  // 实现职工管理类析构函数

EmployeeManager EmployeeManager ::setEmployeeNumber(int employeeNumber) {   // 实现设置职工人数函数
    this->employeeNumber = employeeNumber;
    return *this;
}
int EmployeeManager ::getEmployeeNumber() {     // 实现获得职工人数函数
    return this->employeeNumber;
}

EmployeeManager EmployeeManager ::setPEmployees(Employee **pEmployees) {    // 实现设置员工数组指针指向函数
    this->pEmployees = pEmployees;
    return *this;
}
Employee** EmployeeManager ::getPEmployees() {  // 实现获取员工数组指针指向函数
    return this->pEmployees;
}

