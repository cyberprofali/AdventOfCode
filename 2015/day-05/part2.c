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
            if(len < 3) {
                break;
            }
            char ch1 = line[i];
            char ch2 = line[i+1];

            for(int j = i; j < len; j++) {
                char ch3 = line[j + 2];
                char ch4 = line[j+3];
                if(ch1 == ch3 && ch2 == ch4) { 
                    reapearing_count++;
                }

                if(ch1 == ch3 && ch1 != ch2) { 
                    pairing_count++;
                }

                if(reapearing_count > 0 && pairing_count > 0) {
                    num_nice_string++;
                    reapearing_count = 0;
                    pairing_count = 0;
                    break;
                }
            }

        }
    }
    printf("The number of nice strings is: %i", num_nice_string);   
}

