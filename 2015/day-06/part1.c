#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 

    char line[256];
    int num_nice_string = 0;

    FILE *in_file = fopen("input.txt", "r"); 
    
    if(in_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }
    
    while(fgets(line, sizeof(line), in_file)) { 
        int vowel_count = 0;
        int has_double = 0;
        int is_naughty = 0;

        size_t len = strlen(line);
        
        if(line[len - 1] == '\n') { 
            line[len - 1] = '\0';
            len--; 
        }

        for(int i = 0; i < len; i++) { 
            char ch = line[i];
            
            // Count vowels
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') { 
                vowel_count++; 
            }
            
            // Check for double leter
            if(i < len - 1 && line[i] == line[i+1]) { 
                has_double = 1;
            }

            // Checks for disallowed substrings
            if(i < len - 1) { 
                if((ch == 'a' && line[i+1] == 'b') ||
                   (ch == 'c' && line[i+1] == 'd') ||
                   (ch == 'p' && line[i+1] == 'q') ||
                   (ch == 'x' && line[i+1] == 'y')) { 
                    is_naughty = 1;
                    break; 
                }
            }
        } 
        
        if(!is_naughty && vowel_count >= 3 && has_double) { 
            num_nice_string++;
        }
    }    
        printf("Number of nice strings: %i\n", num_nice_string);    
    // closing files
    fclose(in_file);
}

