#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 

    char line[256];
    int num_nice_string = 0;

    FILE *in_file = fopen("input.txt", "r");

    if(in_file == NULL) {
        printf("Error! Could not open file!\n"); 
        exit(-1);
    }

    while(fgets(line, sizeof(line), in_file)) {

        int pairing_count = 0;
        int reapearing_count = 0;

        size_t len = strlen(line); 

        if(line[len - 1] == '\n') { 
            line[len - 1] = '\0';
            len--;
        }

        for(int i = 0; i < len; i++) { 
            char ch1 = line[i];
            char ch2 = line[i+1];
            char ch5 = line[i+2];

            if(ch1 == ch5 && ch1 != ch2 && pairing_count == 0) {
                pairing_count++;
            }

            for(int j = i+2; j < len; j++) {
                char ch3 = line[j];
                char ch4 = line[j+1];

                if(ch1 == ch3 && ch2 == ch4 && reapearing_count == 0) { 
                    reapearing_count++;
                }

                if(reapearing_count == 1 && pairing_count == 1) {
                    num_nice_string++;
                    reapearing_count = 0;
                    pairing_count = 0;
                    /* printf("This string is nice: ");
                       for(int k = 0; k < len; k++) {
                       char ch5 = line[k];
                       printf("%c", ch5);
                       }
                       printf("\n Num_nice_string = %i \n", num_nice_string);
                       printf("\n\n");*/
                    break;
                }
            }

        }
    }
    printf("The number of nice strings is: %i", num_nice_string);   
}

