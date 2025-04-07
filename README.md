# BookManager Book Management System

## Project Overview
BookManager is a simple book management system developed in C, supporting functions such as adding, deleting, modifying, searching, and displaying books. The system interacts with users through a command-line interface and supports data storage in both binary and text formats.

---

## Feature List
1. **Add a Book**: Enter the book's ID, name, author, publisher, and price to add the book information to the system.
2. **Display Books**: Show all book information in a tabular format.
3. **Search for a Book**: Find a specific book by its name, author, or ID.
4. **Modify a Book**: Update the price of a book based on its ID.
5. **Delete a Book**: Remove a book by its name, author, or ID.
6. **Save and Load**: Support saving book information to a file and loading it when the program starts.

---

## Usage

### Compilation and Execution
1. Ensure that GCC compiler is installed on your system.
2. In the project root directory, compile the code using the following command:
   ```bash
   gcc -o bookmanager yoxi.c bookmanager.c SeqList.c Book.c

copyright (c) in https://www.bilibili.com/video/BV1Vh41197uE/

# BookManager 书目管理系统

## 项目简介
BookManager 是一个基于 C 语言开发的简单书目管理系统，支持书籍的添加、删除、修改、查找和打印等功能。系统通过命令行界面与用户交互，数据存储支持二进制和文本格式。

---

## 功能列表
1. **添加书籍**：输入书籍的 ID、名称、作者、出版社和价格，将书籍信息添加到系统中。
2. **显示书籍**：以表格形式展示所有书籍的信息。
3. **查找书籍**：通过书籍名称、作者或 ID 查找特定书籍。
4. **修改书籍**：根据书籍 ID 修改书籍的价格。
5. **删除书籍**：通过书籍名称、作者或 ID 删除指定书籍。
6. **保存与加载**：支持将书籍信息保存到文件，并在程序启动时加载。

---

## 使用方法

### 编译与运行
1. 确保系统已安装 GCC 编译器。
2. 在项目根目录下执行以下命令编译代码：
   ```bash
   gcc -o bookmanager yoxi.c bookmanager.c SeqList.c Book.c