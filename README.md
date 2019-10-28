Pointer Arithmetic to create/query data structures - Practice
===

In this practice, you will implement a function to create an employee
data structure from a comma-separated text file containing
employee information.

Requirements
---

You must implement the `create_emps()` function in `empcr.c`.  This
function will be passed a buffer of type `char *` containing text data
called 'text' and a 'void *' named 'emps' that you will fill with
bytes based on the input text.

Each line in the commma-separated employee table holds info 
about a single employee as follows:

Employee_ID, Name, Title, Boss, Department, Salary


The information from the table needs to be stored in a data structue.
The format of the data structure to store details of a particular
employee is as follows:

| long | char[50] | char[50] | char[50] | char[50] | long |

The structure above is repeated for each row in the table. End of data
should be indicated by an Employee_id value of 0. 

You will need to validate the following about the employee information in
each of the rows in the comma-separated input text:

 1. Employee_ID should be between 1 and MAX_EMP_ID (inclusive)
 2. All character data should be less than MAX_STRING_SIZE
 3. Salary should be between MIN_SALARY and MAX_SALARY (inclusive)


Building, Running, and Testing
---

The command `make` will build a binary called `empcr` that you can
run using the command:

./empcr < employees.txt > employees.out

If your function works correctly, employees.out would show the encoded bytes 
when encoding the employee information for the 4 employees in the 'employees.txt'
table. To verify it is correct, study the text in employees.txt and the output
in emplployees.out and verify that the output confirms to the format described
above.

NOTE: One could use the output file from the encode program as the input
file for programs that select from or manipulate the data. To do this,
comment-out the last line that calls 'dump_mem' and instead uncomment the
call to 'dump_raw_bytes'. 


Hints
---

You will want to use the 'atol' function to convert the Employee_id and
Salary column text data to long for storing in the data structure. Notice
that the columns are comm-separated rather than NULL terminated and so
one option is to copy the data into a temporary buffer that is NULL
terminated and then use that buffer to call 'atol'.

Remember that pointer math on a `void *` pointer is in terms of _bytes_,
while many data types (such as `size_t`!) are larger than one byte.  You
can add increments of `sizeof(type)` to adjust a `void` pointer by the
size of another type.

Pointer casting works like casting of any other type.  For example:

```C
int readptr(void *ptr) {
    return *(int *)ptr;
}
```

This function accepts a `void` pointer argument, but interprets the data
stored at the pointer as an `int` pointer.  A `void` pointer _cannot be
directly dereferenced_, you will _have_ to cast it in order to read the
data to which it points.

