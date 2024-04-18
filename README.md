# Grocery Counter
**What problem is being solved?**  
This program reads a list of grocery items (strings) from a file and counts
the occurrences of each item. The counts can then be displayed by item, as totals,
or as a histogram. The program allows the user to spot trends and analyze the data
from the given list of items.

This was a project for CS-210 and is written in C++ with features:
- Main Menu
- Use of a vector
- Use of a map
- String manipulators
- File input and output

**What did I do particularly well?**  
The program implements user input validation in a way that helps the user
navigate and use the program. In particular, the search function was implemented
to allow the user to search using a non-case-sensitive search word.

**Where could you enhance your code?**  
**How would these improvements make your code more efficient, secure, and so on?**  
Currently, the program uses hard-coded values for the input and backup files. One
enhancement that could be made is to prompt the user for a path/filename for both
files. This feature would enhance the user experience and make the program more
flexible.

**Which pieces of the code did you find most challenging to write, and how did you overcome this?**  
**What tools or resources are you adding to your support network?**  
I found the map implementation to be the most difficult for this project. This
is mostly because the map was a new concept for me in C++. To work through this
challenge, I read through the C++ documentation for maps and implemented a small
program to get familiar with the functionality. I bookmarked websites such as
stackoverflow.com and learn.microsoft.com/en-us/cpp to be used as tools for 
creating future projects.

**What skills from this project will be particularly transferable to other projects or course work?**  
Working with files, maps, vectors, and a user input menu in C++ are skills that
will be particularly useful for future projects at school and in my career.

**How did you make this program maintainable, readable, and adaptable?**  
I utilized file comments and inline comments in the code to make sure any programmer
viewing or updating the code in the future can clearly understand the intent of the
code. The code also utilizes member and class names that indicate the use of each
item. To make the program adaptable, similar functionality was grouped into classes.
These classes were written so that they could be transferred to another program if
similar functionality is needed.
