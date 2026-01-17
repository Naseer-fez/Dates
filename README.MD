
# 📅 Date and Time (C-Optimized)

**A high-performance Date and Time manipulation library built with Python and C**  
*Leverages the speed of C for backend logic while exposing a clean Pythonic interface via `ctypes`.*

---

## 📖 Project Overview

This library focuses on **efficient date storage and manipulation** by pushing core logic into **C-based dynamic libraries**. Unlike standard Python date libraries, this project manually manages memory using `malloc`, exposing raw C pointers to Python for maximum control and performance.

This is not a wrapper around existing libraries — it’s a ground-up implementation.

---

## 🚀 Core Features

- **Hybrid Architecture**  
  Python for API design, C for raw execution speed.

- **Manual Memory Management**  
  Dates are stored in heap-allocated C arrays and passed to Python as pointers.

- **Smart Date Parsing**  
  Handles partial or compact inputs (e.g. `29032005`, `2903`) with intelligent inference.

- **Zeller’s Congruence**  
  Optimized C implementation to compute the day of the week.

- **Format Flexibility**  
  Optimized for **DD-MM-YYYY (Indian Standard)** with a structure ready for:
  - MM-DD-YYYY (US)
  - YYYY-MM-DD (ISO)

---
## Future Updates



At the present Time , the Libary is not fully complete yet, it requires a few minor tweeks , and addition fetures need to be added to make it a efficent and powerfull libary , For now u can acces the Source code, Many huge Nameing changes are yet to come and also the Implemention of Time Libary , which is the essentail part of the Project, after completion of all this the project will be realesed in a pip format so that anyone can access this libary .


## ⚙️ Technical Architecture

The system is split into a **Python controller** and multiple **specialized C modules**.

### 1️⃣ Python Wrapper 

The `Date_Time` class is the public interface.

**Key APIs**
- `Date(date: str, format=1)`  
  Validates input and returns a C pointer to the stored date.
- `Day_of_the_year(date_ptr)`  
  Accepts a C pointer and returns the weekday name.

---

### 2️⃣ C Backend (Dynamic Libraries)

- **`memory_Date.c`**  
  Allocates memory for an integer array:
  This is a private function which cannot be accesed by the end user.

```

[Format, Day, Month, Year]

````

- **`Datecheck.c`**  
Validates that the input string contains only numeric data.

- **`Date_Filler.c`**  
Core logic module:
- `datearrangment` – orchestrates parsing
- `less_values` – intelligent handling of short inputs
- `datevalidater` – validates day/month/year constraints (leap years included)

- **`Day_of_Year.c`**  
Computes the weekday using mathematical congruence.

---

## 🛠️ Installation & Compilation

### Prerequisites
- Python 3.12
- GCC Compiler  
- **Windows**: MinGW  
- **Linux/macOS**: GCC / Clang

---

### Build Instructions

#### Windows
```bash
gcc -shared -o memory_Date.dll -fPIC memory_Date.c
gcc -shared -o Datecheck.dll -fPIC Datecheck.c
gcc -shared -o Date_Filler.dll -fPIC Date_Filler.c
gcc -shared -o Day_of_Year.dll -fPIC Day_of_Year.c
````

#### Linux / macOS

Replace `.dll` with `.so`

```bash
gcc -shared -o memory_Date.so -fPIC memory_Date.c
gcc -shared -o Datecheck.so -fPIC Datecheck.c
gcc -shared -o Date_Filler.so -fPIC Date_Filler.c
gcc -shared -o Day_of_Year.so -fPIC Day_of_Year.c
```

---

## 💻 Usage Example

```python
import Main as mp

# Initialize
z = mp.Date_Time()

try:
    # Parse date
    date_ptr = z.Date("29-03-2005")

    # Get weekday
    weekday = z.Day_of_the_year(date_ptr)
    print(f"Day: {weekday}")

    # Access raw C memory
    print(f"Stored Year: {date_ptr[3]}")

except TypeError as err:
    print(f"Date Error: {err}")
```

---

## 🚧 Development Roadmap

### ✅ Completed

* Manual heap allocation via `malloc`
* Memory leak fixes
* Core logic rewrite (non-standard approach)
* Day-of-week computation

### 🔜 Upcoming

* Smarter default format correction
* Additional Functionalty
* Codebase cleanup & naming standardization

---

###  Built by Naseer 

