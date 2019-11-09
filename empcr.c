#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX_SIZE 10000
#define MAX_STRING_SIZE 50
#define MAX_EMP_ID 99999
#define MAX_LONG_WIDTH 6

void dump_raw_bytes(void *databuf, int size) {
    if (size<0 || size>MAX_SIZE) return;
    
    for (int i=0; i<size; i++) {
        putchar(*(char*)databuf);
        databuf++;
    }
}

void dump_mem(const void *mem , size_t len) {
    const char *buffer = mem; // Cast to char *
    size_t i;

    for (i = 0; i < len; i++) {
        if (i > 0 && i % 8 == 0) {
            printf("\n");
        }
        // the bitwise & is needed because buffer[i] is interpretted as a hex integer
        // value by printf and so if the most-significant bit is 1, it will be
        // sign-extended,  it won't appear for 0s as the format string is 02x.
        printf("%02x ", buffer[i]); // & 0xff);
    }
    
    if (i > 1 && i % 8 != 1) {
        puts("");
    }
}

/* Read the comma-separated employee table from the 'text' parameter
 * and create a corresponding data structure in memory that emps is
 * pointing at, according to the format in the README.
 * 
 * You may assume that the parameter 'text' points to a  NULL terminated 
 * buffer and that the buffer 'emps' points to is large enough to hold the 
 * information about all the employees in the buffer 'text' points to.
 *
 * You may also assume that any non-digits in the Employee_ID and
 * Salary columns make the data invalid. Also all characters including 
 * lagging/leading speces in the other columns will be part of the 
 * column value.   
 *
 * The data in the character fields in emps should be null ('\0') terminated.
 *
 * Returns -1, if the data is invalid, otherwise 0. 
 */
int create_emps(void *emps, char *text) {
    /* Your implementation should appear here */
    while(*text != '\0'){
        char temp1[MAX_LONG_WIDTH + 1];
        int l1;
        for(l1 = 0; *(text + l1) != ','; l1++){
            *(temp1 + l1) = *(text + l1);
        }
    
        long id = atol(temp1);
        *(long *)emps = id;
        emps = emps + sizeof(long);
        text = text + l1 + 1;
        for(int t = 0; t < 4; t++){
            int i;
            for(i = 0; *(text + i) != ','; i++){
                *(char *)(emps + i) = *(text + i);
            }
            emps = emps + MAX_STRING_SIZE;
            text = text + i + 1;
        }
    
        char temp2[MAX_LONG_WIDTH + 1];
        int l2;
        for(l2 = 0; *(text + l2) != '\n'; l2++){
            *(temp2 + l2) = *(text + l2);
        }
        long sal = atol(temp2);
        *(long *)emps = sal;
        emps = emps + sizeof(long);
        text = text + l2 + 1;
//        *(char *)emps++ = '\n';
    }
    return 0;
}

int main(int argc, char *argv[]) {

    void *text = malloc(MAX_SIZE);
    void *emps = malloc(MAX_SIZE);

    int c;
    char *temp = (char *)text;
    while ( (c=getchar()) != EOF ) {
        *temp = (unsigned char)c;
        temp++;
    }
    *temp = '\0';

    int ret = create_emps(emps, text);
    if ( ret == -1 ) {
        printf("\n Failed: invalid input data.\n");
        return -1;
    }

//    dump_mem(emps, MAX_SIZE);
    dump_raw_bytes(emps, MAX_SIZE);
}
