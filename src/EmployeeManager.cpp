#include "../header/EmployeeManager.h"  // 引入职工管理类头文件
#include "../header/Staff.h"            // 引入普通员工类头文件
#include "../header/Manager.h"          // 引入经理类头文件
#include "../header/Boss.h"             // 引入老板类头文件

// ----------------------------(析)构造函数---------------------------------

// 实现职工管理类构造函数 /*,并使用初始化列表方式初始化职工数量为0,职工指针数组指向NULL*/
EmployeeManager ::EmployeeManager()/* : employeeNumber(0),pEmployees(NULL)*/ {
    ifstream ifs;                       // 获取操作文件流对象
    ifs.open(FILENAME, ios::in);        // 打开指定文件

    // 1.文件不存在的情况
    if (!ifs.is_open()){                // 不存在,初始化
        cout << "文件不存在" << endl;
        this->employeeNumber = 0;       // 初始化职工人数为0
        this->isEMSFileEmpty = true;    // 初始化文件标志为true,文件为空
        this->pEmployees = NULL;        // 初始话职工指针数组为NULL
        ifs.close();
        return ;
    }

    // 2.文件存在,并且没有记录
    char ch;
    ifs >> ch;      // 2.1 先从文件中读取一个字符
    if(ifs.eof()){  // 2.2 如果这一个字符为eof的标志(文件尾部标志),说明文件为空
        cout << "文件为空" << endl;
        this->employeeNumber = 0;
        this->isEMSFileEmpty = true;
        this->pEmployees = NULL;
        ifs.close();
        return ;
    }

    // 3.当文件存在,并且存在数据
    int employeeNumber = this->getEmployeeNumberFromFile(); // 获取文件内的职工人数
    this->employeeNumber = employeeNumber;                  // 初始化职工人数
    this->isEMSFileEmpty = false;                           // 初始化文件标志为false,文件不为空
    this->pEmployees = new Employee*[this->employeeNumber]; // 初始化职工指针数组,指向堆区开辟指针数组的内存空间
    this->initEmployeeManager();                            // 初始化职工管理类数据

    ifs.close();
}

// 实现职工管理类析构函数
EmployeeManager ::~EmployeeManager() {
    if (this->pEmployees != NULL) {     // 释放堆区数据
        delete[] this->pEmployees;
        this->pEmployees = NULL;
    }
}

// ----------------------------功能函数-------------------------------------

// 实现展示菜单函数
void EmployeeManager ::showMenu() {
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

// 实现退出系统函数
void EmployeeManager ::exitSystem() {
    cout << "欢迎下次使用\n请输入回车继续..." << endl;
    system("read");
    exit(0);
}

// 实现增加职工函数
int EmployeeManager ::addEmployee() {
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

        // 8.保存数据
        this->saveFile();

        // 9.修改文件是否为空标志
        this->isEMSFileEmpty = false;

        // 10.增加成功,返回1
        cout << "成功添加 " << addNumber << " 名员工\n请输入回车接续..." << endl;
        system("read");
        return 1;
    } else {
        cout << "输入有误\n请输入回车继续..." << endl;
        system("read");
        return 0;   // 增加失败,返回0
    }
}

// 实现保存文件函数
int EmployeeManager ::saveFile() {
    // 1.创建流对象
    ofstream ofs;
    // 2.打开需要操作的文件
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->employeeNumber; ++i) {
        ofs << (*(this->pEmployees + i))->employeeId << " "     // 二级指针偏移:相当于this->pEmployees[i]->employeeId
            << (*(this->pEmployees + i))->employeeName << " "   // pEmployees一级指针偏移,即指向数组的位置偏移
            << (*(this->pEmployees + i))->departmentId          // *取偏移后位置的内容,即数组中的指针
                << endl;
    }
    // 3.关闭文件
    ofs.close();
    // 保存成功,返回1
    return 1;
}

// 实现从文件统计职工人数函数
int EmployeeManager::getEmployeeNumberFromFile() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int employeeId;
    string employeeName;
    int departmentId;
    int employeeNumber = 0;

    // 存入的时候以空格分割,取的时候也可以进行空格分割的方式读回
    // 如果第一行数据读完了,读下一行,当数据都读完之后,退出while循环
    while(ifs >> employeeId && ifs >> employeeName && ifs >> departmentId){
        employeeNumber++;   // 记录文件中有多少职工
    }

    ifs.close();
    return employeeNumber;
}

// 实现职工管理类初始化函数
int EmployeeManager ::initEmployeeManager() {
    ifstream ifs(FILENAME, ios::in);    // 创建流对象并打开文件
    int employeeId;
    string employeeName;
    int departmentId;
    int i = 0;  // 数组角标 / 循环标识
    while (ifs >> employeeId && ifs >> employeeName && ifs >> departmentId){
        Employee *employee = NULL;
        // 根据不同的部门Id创建不同的对象
        if (departmentId == 1) {
            employee = new Staff(employeeId, employeeName, departmentId);
        } else if (departmentId == 2) {
            employee = new Manager(employeeId, employeeName, departmentId);
        } else {
            employee = new Boss(employeeId, employeeName, departmentId);
        }
        *(this->pEmployees + i) = employee;
        // 指针偏移,相当与this->pEmployees[i] = employee;
        i++;
    }
    ifs.close();
    return 1;   // 初始化成功,返回1
}

// 实现显示职工信息函数
void EmployeeManager ::showEmployeeInfo() {
    if (this->isEMSFileEmpty){
        cout << "文件不存在或记录为空" << endl;
    } else {
        for (int i = 0; i < this->employeeNumber; ++i) {
            // 利用多态调用接口
            (*(this->pEmployees + i))->showInfo();
            // 指针偏移,相当与this->pEmployees[i]->showInfo();
        }
    }
    cout << "请输入回车继续..." << endl;
    system("read");
}

// 实现判断职工是否存在函数
int EmployeeManager ::isEmployeeExist(int employeeId) {
    for (int i = 0; i < this->employeeNumber; ++i) {    // 遍历所有职工
        if ((*(this->pEmployees + i))->employeeId == employeeId){   // 判断employeeId是否相同
            // 指针偏移,相当于this->pEmployees[i]->employeeId
            return i + 1;   // 相同则返回第几个(即序号),非下标
        }
    }
        return 0;   //没有找到,返回0
}

// 实现删除职工函数
int EmployeeManager ::deleteEmp() {
    if (this->isEMSFileEmpty){  // 判断文件是否为空
        cout << "文件不存在或记录为空\n请输入回车继续..." << endl;
        system("read");
        return 0;   // 删除失败,返回0
    }
    int employeeId; // 需要删除的员工编号
    int res;        // 若员工存在返回的员工序号,不存在为0
    cout << "请输入需要删除的职工编号:";
    cin >> employeeId;
    res = this->isEmployeeExist(employeeId);
    if (res){
        if (this->employeeNumber == 1){     // 只剩最后一名职工的时候
            this->employeeNumber = 0;       // 职工人数清零
            delete[] this->pEmployees;      // 职工指针数组清零
            this->pEmployees = NULL;
            this->isEMSFileEmpty = true;    // 文件标识置为空
            cout << "删除成功\n请输入回车继续..." << endl;
            return 1; // 删除成功,返回1
        }
        for (int i = res - 1; i < this->employeeNumber - 1; ++i) {
            *(this->pEmployees + i) = *(this->pEmployees + i + 1);
            // 指针偏移,相当于this->pEmployees[i] = this->pEmployees[i+1];
        }
        this->employeeNumber--; // 更新职工人数
        this->saveFile();       // 更新文件
        cout << "删除成功\n请输入回车继续..." << endl;
        system("read");
        return 1;   // 删除成功,返回1
    } else {
        cout << "删除失败,职工不存在\n请输入回车继续..." << endl;
        system("read");
        return 0;   // 删除失败,返回0
    }
}

// -----------------------Getter / Setter函数--------------------------------

// 实现设置职工人数函数
EmployeeManager & EmployeeManager ::setEmployeeNumber(int employeeNumber) {
    this->employeeNumber = employeeNumber;
    return *this;
}
// 实现获得职工人数函数
int EmployeeManager ::getEmployeeNumber() {
    return this->employeeNumber;
}

// 实现设置员工数组指针指向函数
EmployeeManager & EmployeeManager ::setPEmployees(Employee **pEmployees) {
    this->pEmployees = pEmployees;
    return *this;
}
// 实现获取员工数组指针指向函数
Employee** EmployeeManager ::getPEmployees() {
    return this->pEmployees;
}

