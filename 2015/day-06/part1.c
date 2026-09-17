#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int process_grid_instruction(const char *line) { 

    char action;
    int x1, y1, x2, y2;
    
    int num_lights_on;

    if(sscanf(line, "turn on %d,%d through %d,%d", &x1, &y1, &x2, &y2) == 4) {
        
    } else if (sscanf(line, "turn off %d,%d through %d,%d", &x1, &y1, &x2, &y2) == 4) { 

    } else if (sscanf(line, "toggle %d,%d through %d,%d", &x1, &y1, &x2, &y2) == 4) { 

    } else {
        printf("[ERROR] Unknown instruction: '%s'\n", line);
    }

    return num_lights_on;
}

int main() { 
    
    char line[256];
    
    int total_lights_on = 0;

    FILE *in_file = fopen("input.txt", "r"); 
    
    if(in_file == NULL) { 
        printf("Error! Count not open file!\n"); 
        exit(-1);             
    }
    
    while(fgets(line, sizeof(line), in_file) != NULL) { 
        // Removing trailing newline character (/n) if present
        line[strcspn(line, "\r\n")] = '\0';

        // Skipping empty lines
        if(strlen(line) == 0) { 
            continue;
        }

        // process and execute the command
        total_lights_on += process_grid_instruction(line); 
    }

    printf("Total number of lights on: %i", total_lights_on);

    // closing files
    fclose(in_file);
}

