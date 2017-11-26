// THUY TIEN NGUYEN
// CSCI 3334 - PHASE I
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    
    char input[100];
    
    printf("Hello user! Welcome to Penelope's interpreter. Please enter inputs:\n");
    
    fgets(input, 100, stdin);
    
    // get length of input and remove trail new line char for later parsing
    int len = strlen(input) - 1;
    if (input[len] == '\n')
        input[len] = '\0';
    
    
    while (strcmp("exit", input) != 0) {
        
        // for legibility of output
        printf("\n");
        
        // First compare entirety of input with single-word commands.
        // If there's a match, no need for parsing - just execute.
        
        if (strcmp("help", input) == 0) {
            printf("The inputs available are...\nload filename\nexecute \ndebug \ndump start end \nhelp \nassemble filename \ndirectory \nexit");
        }
        
        else if (strcmp("execute", input) == 0) {
            printf("Execute input is correct, yet to be executed.");
        }
        
        else if (strcmp("debug", input) == 0) {
            printf("Debug input is correct, yet to be executed.");
        }
        
        else if (strcmp("directory", input) == 0) {
            system("ls");
        }
        
        // If there's no match, user entered a command with multiple
        // parameters, or they used a single-word command with
        // unecessary parameters. Begin parsing.
        
        else {
            // parsed_input contains words once the command has been broken up
            // while word_len contains the length of each word
            
            // 3 is the max number of words any command can be, but 4
            // is used as the array size for storage purposes
            char parsed_input[4][50];
            int word_len[4] = {0, 0, 0, 0};
            
            int num_words = 0;
            int position = 0;
            
            // loop while there is still input to be parsed or maximum
            // of 3 words has been reached.
            for (int i = 0; i < len; i++) {
                
                if (num_words == 4)
                    break;
                
                // space represents seperation of two words, so don't add
                // to the word array, just increment its position
                if (input[i] == ' ') {
                    word_len[num_words] = position;
                    num_words += 1;
                    position = 0;
                }
                else {
                    parsed_input[num_words][position] = input[i];
                    position += 1;
                }
            }
            
            // fixing one-off errors. if the max word-count wasn't reached, there is
            // still one word that needs to be added to the word array
            if (num_words < 4 ) {
                word_len[num_words] = position;
                num_words += 1;
            }
            
            // known single-word commands, so if they weren't immediately caught
            // in earlier comparisons, there is an excessive amount of parameters
            if (strcmp("execute", parsed_input[0]) == 0 || strcmp("debug", parsed_input[0]) == 0 || strcmp("help", parsed_input[0]) == 0 || strcmp("directory", parsed_input[0]) == 0 || strcmp("exit", parsed_input[0]) == 0) {
                printf("Command has too many parameters.");
            }
            
            else if (strcmp("load", parsed_input[0]) == 0) {
                if (num_words < 2)
                    printf("input requires FILENAME parameter.");
                else if (num_words > 2)
                    printf("input has too many parameters.");
                else
                    printf("Load command is correct, yet to be executed.");
                
            }
            
            else if (strcmp("assemble", parsed_input[0]) == 0) {
                if (num_words < 2)
                    printf("input requires FILENAME parameter.");
                else if (num_words > 2)
                    printf("input has too many parameters.");
                else
                    printf("Assemble command is correct, yet to be executed.");
                
            }
            
            else if (strcmp("dump", parsed_input[0]) == 0) {
                if (num_words < 3)
                    printf("Command requires START and END parameters.");
                else if (num_words > 3)
                    printf("Command has too many parameters.");
                else
                    printf("Dump command is correct, yet to be executed.");
            }
            
            else {
                printf("Command not recognized");
            }
            
            // FLUSH VARIABLES USED FOR INPUT PARSING
            // If not done, they can contain letters from the
            // previous word arrays.
            for (int i = 0; i < num_words; i++) {
                for (int j = 0; j < word_len[i]; j++)
                    parsed_input[i][j] = '\0';
            }
        }
        
        printf("\n\nPlease enter inputs: \n");
        fgets(input, 100, stdin);
        
        // must remove new line or 'exit\n' never triggers the end of the loop
        len = strlen(input) - 1;
        if (input[len] == '\n')
            input[len] = '\0';
    }
    
    printf("\nThanks for using my interpreter!\n");
    
    return 0;
}

