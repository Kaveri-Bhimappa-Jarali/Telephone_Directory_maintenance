# Telephone Directory Maintenance System

## Overview
This is a **console-based Telephone Directory Maintenance System** that uses **file management concepts** to store and manage department, employee, and telephone records.  
The system allows users to **add, view, search, update, and delete records**.

---

## Features
- Add and view **departments**
- Add and view **employees**
- Add and manage **telephone numbers**
- Search by **employee name** or **telephone number**
- Persistent storage using **text files**

---

## Files
- `FileFunctions.c` / `FileFunctions.h` – Functions for file operations  
- `DeptMaint.c` – Department maintenance code  
- `TelDir.c` – Main program with menus  
- `dept.txt` / `emp.txt` – Data files (do not edit manually)

---

## How to Run
1. Clone the repository
```bash
git clone https://github.com/yourusername/Telephone-Directory.git
gcc TelDir.c FileFunctions.c -o TelephoneDirectory
./TelephoneDirectory
