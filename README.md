# Libft

Libft is the first project at [42 School](https://42.fr/) where students create their own C library.  
The goal is to reimplement standard C library functions and gain a deeper understanding of how they work internally.  
This library will later be reused in other 42 projects.

---

## 📚 Overview

The library contains re-implementations of standard C functions such as:
- Character checks (`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, …)
- String operations (`ft_strlen`, `ft_strchr`, `ft_strncmp`, …)
- Memory management (`ft_memset`, `ft_memcpy`, `ft_bzero`, …)
- Conversion functions (`ft_atoi`, `ft_strdup`, …)
- Allocation functions (`ft_calloc`, …)

Later, additional functions will be added:
- Linked list utilities (bonus part)

---

## ⚙️ Usage

### 1. Compile the library
```bash
make
This will compile all .c files into object files and create the library archive:

Copy code
libft.a
2. Clean object files
bash
Copy code
make clean
3. Remove all generated files (including libft.a)
bash
Copy code
make fclean
4. Recompile everything from scratch
bash
Copy code
make re
🚀 Example
You can use libft in your own C project:

c
Copy code
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char str[] = "Hello 42!";
    printf("Length: %zu\n", ft_strlen(str));
    return 0;
}
Compile with:

bash
Copy code
gcc main.c -L. -lft -o test
📂 Project Structure
Copy code
libft/
├── includes/
│   └── libft.h
├── srcs/
│   ├── ft_strlen.c
│   ├── ft_memset.c
│   ├── ...
├── obj/
├── Makefile
└── README.md
