<h1 align="center">
	42cursus' libft
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' libft project</i></b><br>
	For further information about 42 and its projects, please go to my <a href="https://github.com/psdiaspedro?tab=repositories"><b>repositories</b></a>.
</p>

# index
* [About](#about) 
*  [Functions Guide](#guide) 
*  [Compiling](#compile)

# <a name="about">About</a>
## Implementation of some of the Standard C Library functions

Libft is the first project in the study program at School 42 (UNIT Factory).
>_The purpose of the project is to introduce to students standard C functions that we will be able to use in our future projects._
>_To give a deeper understanding of functions we needed to create our own realization of standard functions._

All functions are created in accordance with Norm - the bunch of rules how code should be formatted.

**NOTE!** <br />
Because of 42 School norm requirements: <br />
* All variables are declared and aligned at the top of each function <br />
* Each function can't have more then 25 lines of code <br />
* C++ style code commenting is forbidden <br />
* Project should be created just with allowed functions otherwise it's cheating. <br />

#### The project consists of 3 main logical parts:
* Standart Libc functions
* Additional functions
* Bonus part functions

# <a name="guide">📑 Functions Guide</a>

### Functions from `<ctype.h>` library

* [`ft_isascii`](./src/ft_isascii.c)			- test for ASCII character.
* [`ft_isalnum`](./src/ft_isalnum.c)			- alphanumeric character test.
* [`ft_isalpha`](./src/ft_isalpha.c)			- alphabetic character test.
* [`ft_isdigit`](./src/ft_isdigit.c)			- decimal-digit character test.
* [`ft_isprint`](./src/ft_isprint.c)			- printing character test (space character inclusive).
* [`ft_tolower`](./src/ft_tolower.c)			- upper case to lower case letter conversion.
* [`ft_toupper`](./src/ft_toupper.c)			- lower case to upper case letter conversion.

### Functions from `<stdlib.h>` library

* [`ft_atoi`](./src/ft_atoi.c)		- convert ASCII string to integer.
* [`ft_calloc`](./src/ft_calloc.c)	- memory allocation.

### Functions from `<strings.h>` library

* [`ft_bzero`](./src/ft_bzero.c)		- write zeroes to a byte string.
* [`ft_memset`](./src/ft_memset.c)		- write a byte to a byte string.
* [`ft_memchr`](./src/ft_memchr.c)		- locate byte in byte string.
* [`ft_memcmp`](./src/ft_memcmp.c)		- compare byte string.
* [`ft_memmove`](./src/ft_memmove.c)	- copy byte string.
* [`ft_memcpy`](./src/ft_memcpy.c)		- copy memory area.

### Functions from `<string.h>` library

* [`ft_strlen`](./src/ft_strlen.c)				- find length of string.
* [`ft_strchr`](./src/ft_strchr.c)				- locate character in string (first occurrence).
* [`ft_strrchr`](./src/ft_strrchr.c)			- locate character in string (last occurence).
* [`ft_strnstr`](./src/ft_strnstr.c)			- locate a substring in a string (size-bounded).
* [`ft_strcmp`](./src/ft_strcmp.c) *		- compare strings.
* [`ft_strncmp`](./src/ft_strncmp.c) *			- compare strings (size-bounded).
* [`ft_strdup`](./src/ft_strdup.c)				- save a copy of a string (with malloc).
* [`ft_strlcpy`](./src/ft_strlcpy.c)			- size-bounded string copying.
* [`ft_strlcat`](./src/ft_strlcat.c)			- size-bounded string concatenation.

### Non-standard functions

* [`ft_putchar_fd`](./src/ft_putchar_fd.c)		- output a character to given file.
* [`ft_putstr_fd`](./src/ft_putstr_fd.c)		- output string to given file.
* [`ft_putendl_fd`](./src/ft_putendl_fd.c)		- output string to given file with newline.
* [`ft_putnbr_fd`](./src/ft_putnbr_fd.c)		- output integer to given file.
* [`ft_itoa`](./src/ft_itoa.c)					- convert integer to ASCII string.
* [`ft_substr`](./src/ft_substr.c)				- extract substring from string.
* [`ft_strtrim`](./src/ft_strtrim.c)			- trim beginning and end of string with the specified characters.
* [`ft_strjoin`](./src/ft_strjoin.c)			- concatenate two strings into a new string (with malloc).
* [`ft_split`](./src/ft_split.c)				- split string, with specified character as delimiter, into an array of strings.
* [`ft_strmapi`](./src/ft_strmapi.c)			- create new string from modifying string with specified function.
* [`ft_striteri`](./src/ft_strmapi.c)			- Applies the function f to each character of the string passed as argument.

### Linked list functions

* [`ft_lstnew`](./src/ft_lstnew.c)				- create new list.
* [`ft_lstsize`](./src/ft_lstsize.c)			- count elements of a list.
* [`ft_lstlast`](./src/ft_lstlast.c)			- find last element of list.
* [`ft_lstadd_back`](./src/ft_lstadd_back.c)	- add new element at end of list.
* [`ft_lstadd_front`](./src/ft_lstadd_front.c)	- add new element at beginning of list.
* [`ft_lstdelone`](./src/ft_lstdelone.c)		- delete element from list.
* [`ft_lstclear`](./src/ft_lstclear.c)			- delete sequence of elements of list from a starting point.
* [`ft_lstiter`](./src/ft_lstiter.c)			- apply function to content of all list's elements.
* [`ft_lstmap`](./src/ft_lstmap.c)				- apply function to content of all list's elements into new list.

_Note: functions marked with * are bonus functions (not mandatory by the project's subject)._

# <a name="compile">🛠️ How to compile library: </a>

Using Makefile you can create library file libft.a<br/>
Makefile has 4 main options:<br/>
* **make** - to compile C files - create object files and library libft.a<br/>
* **make clean** - to remove object files<br/>
* **make fclean** - remove libft.a file<br/>
* **make re** - recompile the library<br/>

#### More about School 42 you can find here: https://en.wikipedia.org/wiki/42_(school)
