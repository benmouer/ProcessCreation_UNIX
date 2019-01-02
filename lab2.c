//Benjamin Mouer
//CSC 241
//Tuesday October 2nd

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*This is a const char pointer to an immutable string. this ensures that my file name wont be altered somehow while my processes executes*/
const char * inputFile = "lab2.txt";


int main() {



    /*Here , *fp, is my file pointer for the text file that I want to read from */
    FILE * fp;
    /*In order to open the file, I use the function fopen() and pass it the file name and "r" specifies that I want to read for the file*/
    fp = fopen(inputFile, "r");
    /*This is just an exception handler to make sure that if there is no file to read then I automatically exit the program.*/
    if (fp == NULL) {
        fprintf(stderr, "input file ’%s’ not found.\n", inputFile);
        exit(1);
    }




    /*This int will represent the current process ID*/
    int pid = 0;
    /*I need to declare a pointer to an address of where the line will be held when it is gotten*/
    char *buffer;
    /*This is just to empty my buffer to ensure no random chars are inside that memory space that would look like a file*/
    buffer = NULL;
    /*This is what my getline() func is writing to to make sure that I exit the process loop if I reach the end of the text file.*/
    ssize_t EOFCheck = 0;
    /*Size is what I am going to use to specify the size of the input buffer*/
    unsigned long size = 0;




    /*if pid==0 then the process executing is the child
     * I used this way to fork because it requires less code*/
    if (fork() == 0){
        /*Here I am making sure that I have not reached the end of my text file*/
        while (EOFCheck != EOF){
            /*if I have not reached the end of the file, then I will get the next line and insert the line into the buffer while returning the number of characters to the EOFCheck variable*/
            EOFCheck =  getline(&buffer, &size, fp);
            if (EOFCheck != EOF) {
                /*Now I just print the current process ID, which is 0, and the line read to the console*/
                printf("%d     %s", pid, buffer);
            }
        }
    }



    /*If the child process is NOT running in the CPU, then the program will execute the parent process*/
    else{
        while (EOFCheck != EOF){
            /*if I have not reached the end of the file, then I will get the next line and insert the line into the buffer while returning the number of characters to the EOFCheck variable*/
            EOFCheck =  getline(&buffer, &size, fp );
            if (EOFCheck != EOF) {
                /*Now I just print the current process ID and the line read to the console*/
                printf("%d %s", getpid(), buffer);
            }
        }
    }




    /*This is to make sure my program doesnt terminate before the child and parent are both finished*/
    int parent = getpid();
    parent = wait(NULL);

    /*Then, I close my file and exit*/
    fclose(fp);

}