## EmployeeManagementSystem    
### 职工管理系统(C++实现)   
EmployeeManagementSystem(Designed By Cpp)     
### 系统开发 / 运行 / 测试环境   
System:MacOS; IDE:CLion; Language:C++   
### 使用技术   
C++OOP(封装,继承,多态);多文件结构;文件存储 / 读取;指针(指针数组,指针偏移 / 取值);堆区数据开辟(new)与销毁(delete)    
### 系统功能  
退出管理系统 / 增加职工信息 / 显示职工信息 / 删除离职职工 / 修改职工信息 / 查找职工信息 / 按照编号排序 / 清空所有文档    
### 基本描述  
公司中职工分为三类:普通员工 / 经理 / 老板   
显示信息时,需要显示:职工编号 / 职工姓名 / 职工岗位 / 职工职责   
普通职工职责:完成经理交给的任务   
经理职责:完成老板交给的任务,并下发任务给员工   
老板职责:管理公司所有事务   
### 问题解决   
#### 问题1:在继承关系中,delete对象时报错   
解决1:在基类添加(纯)虚析构函数   
#### 问题2:文件操作,文件创建在本地什么位置   
解决2:   
* 关于相对路径   
  * CLionIDE将文件创建在CMakeFiles,即与编译连接后的可执行文件同一目录   
  * Unix可执行文件将文件创建在用户根目录下(即~下 或 /Users/"用户名"/下)
* 关于绝对路径   
  * 在绝对路径中,若包含不存在的路径,将无法创建文件   
  
#### 问题3:关于指针偏移(Demo中二级指针(指针数组)偏移)   
解决3:   
* 指针数组:数组里存放的都是指针   
* 本Demo常见指针偏移   
  * this->pEmployees;获取到指向指针数组的指针,初始指向指针数组首地址位置   
  * this->pEmployees + i;将指向向下偏移i个位置,指向指针数组第i个位置   
  * *(this->pEmployees + i);取出指针数组第i个位置的指针   
  * (*(this->pEmployees + i))->employeeId;取出指针数组第i个位置的指针所指向的类中的内容   
  ```java
   (*(this->pEmployees + i))->employeeId;
   // 相当于
   this->pEmployees[i]->employeeId;
  ```
  
  