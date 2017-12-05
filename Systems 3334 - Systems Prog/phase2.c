// THUY TIEN NGUYEN
// CSCI 3334 - PHASE II 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TRUE    1 
#define FALSE   0 

typedef struct { 
    char MNEMONIC[7];
    char OPCODE[3];
    const int SIZE; 
} OPCODES; 

OPCODES * makeOPTABLE() {
    
    static OPCODES TABLE [] = { 
        {"ADD", "18"}, {"AND", "58"}, {"COMP", "28"}, {"DIV", "24"}, {"J", "3C"},
        {"JEQ", "30"}, {"JGT", "34"}, {"JLT", "38"}, {"JSUB", "48"}, {"LDA", "00"},
        {"LDCH", "50"}, {"LDL", "08"}, {"LDX", "04"}, {"MUL", "20"}, {"OR", "44"},
        {"RD", "D8"}, {"RSUB", "4C"}, {"STA", "0C"}, {"STCH", "54"}, {"STL", "14"},
        {"STX", "10"}, {"SUB", "1C"}, {"TD", "E0"}, {"TIX", "2C"}, {"WD", "DC"},
    };
    
    return TABLE;
} 

bool isValid(OPCODES * table, char word[], int SIZE, char mnem_op []) {
    bool found = FALSE;
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(table[i].MNEMONIC, word) == 0) {
            found = TRUE;
            for (int j = 0; j < 2; j++)
                mnem_op[j] = table[i].OPCODE[j];
        }
    }
    return found;
}

typedef struct {
    char LABEL[6];
    int PC;
} SYMBOL;

typedef struct {
    SYMBOL TABLE[500];
    int SIZE;
} SYMTABLE;


bool addSymbol(SYMTABLE * SYMBOLS, char word[], int PC) { 
    
    bool found = false;
    
    for (int i = 0; i < SYMBOLS->SIZE; i++) { 
        if (strcmp(SYMBOLS->TABLE[i].LABEL, word) == 0) {
            found = true; 
            break; 
        }
    }

    if (!found) {
        
        int WORD_SIZE = strlen(word);
        
        if (WORD_SIZE > 6)
            WORD_SIZE = 6; 
        else 
            SYMBOLS->TABLE[SYMBOLS->SIZE].LABEL[WORD_SIZE] = '\0';
            
        for (int j = 0; j < WORD_SIZE; j++) { 
            SYMBOLS->TABLE[SYMBOLS->SIZE].LABEL[j] = word[j];
        }
        
        SYMBOLS->TABLE[SYMBOLS->SIZE].PC =PC; 
        SYMBOLS->SIZE += 1; 
    } 
    return found;
}

void convertToHex(int num, char hex [16]) {
    
    // UNGODLY FUNCTION DO NOT TOUCH 
    // OR TRY TO UNDERSTAND 
    // WILL COMMENT LATER 
    
    int quotient, remainder;
    char remainders[16];
    int i =0, j = 0;
    quotient = num;

    while (quotient != 0) { 
        remainder = quotient % 16;
        if (remainder < 10)
            remainders[j++] = 48+ remainder;
        else
            remainders[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    
    j--;
    for (j; j >= 0; j--) { 
        hex[i] = remainders[j];
        i++;
    }
    hex[i] = '\0';
}

void parseLine(char inLine [], char lbl[], char opcde[], char oprand []) { 
    for (int i = 0; i < 24; i++) { 
        lbl[i] = '\0';
        opcde[i] = '\0';
        oprand[i] = '\0';
    }
    
    int len = strlen(inLine);
    int position = 0; 
    
    // LOOP FOR FINDING LABEL 
   for (position; position < len; position++) { 
        if (inLine[position] == ' ' || inLine[position] == '\t') 
            break;
        else
            lbl[position] = inLine[position];
   }

    position += 1;
    
    // MOVE TO FIND THE OPCODE 
    for (position; position < len; position++) { 
        if (inLine[position] !=' ' && inLine[position] != '\t') 
            break;
    }
    
    // PROCESSING OPCODE 
    // RESET POSITION OF OPCODE 
    int var_pos = 0; 
    for (position; position < len; position++) { 
        if (inLine[position] == ' ' || inLine[position] == '\t') 
            break;
            
        opcde[var_pos] = inLine[position];
        var_pos++;
   }
   
   //MOVE TO FIND OPERAND IGNORING SPACES 
   for (position; position < len; position++) { 
        if (inLine[position] !=' ' && inLine[position] != '\t') 
            break;
    }
    
   // RESET POSITION OF OPERAND 
   // CREATE TEMP ARRAY TO STORE THE CHARS BEFORE CONVERTING TO INT 
   var_pos = 0; 
   for (position; position < len; position++) { 
               
        if (inLine[position] == ' ' || inLine[position] == '\t') { 
            break;
        }
            
        oprand[var_pos] = inLine[position];

        var_pos+=1;
    }
}

int reserveBYTE(char OP []) { 
    
    int MAX_LEN;
    // LOOP THROUGH OPERAND 
    
    if (OP[0] == 'C')
        MAX_LEN = 32;
    else if (OP[0] == 'X')
        MAX_LEN = 30;
    else 
        return 0;
        
    int len = strlen(OP);
    char char_string[MAX_LEN];
    int pos = 0;
    
    for (int i = 1; i < len; i++) {
        if (OP[i] != '\'' && OP[i]  != '’' && OP[i] != '‘' && OP[i] != '\n')
            char_string[pos++] = OP[i];
    }
    
    char_string[pos] = '\0';
    int char_string_len = strlen(char_string);
    
    // NO SIZE 
    if (char_string_len == 0)
        return 0;
        
    // TOO BIG 
    if (char_string_len  > MAX_LEN)
        return -1;
    
    if (OP[0] == 'X') { 
        // CHECK FOR ILLEGAL SIZE, MUST BE EVEN 
        if (char_string_len % 2 != 0)
            return -1;
        else 
            return char_string_len / 2;
    }
    
    else 
        return char_string_len;
}
void resetErrorCode(char * ERROR_CODE) { 
    for (int i = 0; i < 10; i++) 
        ERROR_CODE[i] = '0';
}

bool hasErrors(char * ERROR_CODE) {
    
    for (int i = 0; i < 10; i++) {
        if (ERROR_CODE[i] == '1')
            return true; 
    }
    
    return false;
}
int main() {
    
    // MAKE SURE FILE CAN ACTUALLY BE READ 
    
    char filename[64] = "source";
    FILE *infile;
    infile = fopen(filename, "r");
    if (!infile) {
        printf("Unable to read file: %s", filename);
        return 1; 
    }
    
    FILE *intermed = fopen("intermediate", "w");
    FILE *intermedErr = fopen("intermediateErr", "w");
    FILE *symfile = fopen("symboltable", "w");

    ////////////////////// 
    
    char line[128];
    char LABEL[24], OPCODE[24], OPERAND[24]; 
    char START_CODE[16] = {'\0'};
    
    char LOCCTR_HEX[16];
    int LOCCTR = 0;
    int START = 0; 
    
    OPCODES * OPTABLE = makeOPTABLE(); 
    int OPTABLE_SIZE = 25; 
    
    SYMTABLE SYMBOL_TABLE;
    SYMBOL_TABLE.SIZE = 0; 
    
    char ERRORS[] = "0000000000";
    // 0 = DUP LABELS
    // 1 = ILLEGAL LABEL
    // 2 = MISSING OPERAND ON DATA STORAGE
    // 3 = ILLEGAL OPERAND ON DATA STORAGE
    // 4 = MISSING OPERAND ON START 
    // 5 = ILLEGAL OPERAND ON START 
    // 6 = MISSING OPERAND ON END 
    // 7 = ILLEGAL OPERAND ON END 
    // 8 = TOO MANY SYMBOLS 
    // 9 = PROGRAM TOO LONG 
    
    /////////////////////

    
    // READ FIRST INPUT LINE
    
    fgets(line, 128, infile);
    parseLine(line, LABEL, OPCODE, OPERAND);
    
    // FILE ERROR 
    bool opIsValid = false;
    char MNEM_OPCODE[2];
    
    //IF OPCODE = 'START', SET LOCCTR = OPERAND 
    // ELSE, SET LOCCTR = 0 
    if (strcmp(OPCODE, "START") == 0) { 
        LOCCTR = (int)strtol(OPERAND, NULL, 16);
        START = LOCCTR; 
        convertToHex(LOCCTR, LOCCTR_HEX);
        if (OPERAND[0] == '\0')
            ERRORS[4] = '1';
        fprintf(intermed, "%s", line);
        fprintf(intermed, "%s %s 0 %s %s\n", LOCCTR_HEX, ERRORS, OPCODE, OPERAND);
    }    
    
    while (!feof(infile)) {
        
        
        fgets(line, 128, infile);
        
        // IF LINE IS A COMMENT LINE, IGNORE 
        if (line[0] == '.')
            continue;
            
        parseLine(line, LABEL, OPCODE, OPERAND);
        char LOCCTR_HEX[16];
        convertToHex(LOCCTR, LOCCTR_HEX);

        int PC = 0; 

        resetErrorCode(ERRORS);
        
        // IF LABEL FOUND, SEARCH SYMBOL TABLE 
                    
        if (LABEL[0] != '\0') { 
            if (SYMBOL_TABLE.SIZE > 500) {
                ERRORS[8]= '1';
            }
                
            else {  
                bool duplicate_symbol = addSymbol(&SYMBOL_TABLE, LABEL, LOCCTR);

                if (duplicate_symbol) 
                    ERRORS[0]= '1';             
                else 
                    fprintf(symfile, "%s %s\n", LABEL, LOCCTR_HEX);
            }
        }
        
        if (strcmp(OPCODE,"END") == 0) { 
            convertToHex(LOCCTR, LOCCTR_HEX);

            fprintf(intermed, "%s", line);
            
            if (OPERAND[0] == '\0')
                ERRORS[6] = '1';
                
            else if (strcmp(OPERAND, START_CODE) != 0)
                ERRORS[7] = '1';
            
            if (!hasErrors(ERRORS)) {
                fprintf(intermed, "%s\n%s %s 0 %s %s", line, LOCCTR_HEX, ERRORS, OPCODE, OPERAND);
                fprintf(intermedErr, "%s\n%s %s 0 %s %s", line, LOCCTR_HEX, ERRORS, OPCODE, OPERAND);
            } 
            else { 
                if (opIsValid)
                    fprintf(intermedErr, "%s\n%s %s 0 %s %s", line, LOCCTR_HEX, ERRORS, OPCODE, OPERAND);
                else 
                    fprintf(intermedErr, "%s%s 0 %s", line, LOCCTR_HEX, ERRORS);
            }

            break;

        }
        
        else if (strcmp(OPCODE,"WORD") == 0) { 
            PC = 3; 
        }
        
        else if (strcmp(OPCODE,"RESB") == 0) { 
            PC = atoi(OPERAND);
        }

        else if (strcmp(OPCODE,"RESW") == 0) {
            PC = (3 * atoi(OPERAND));
        }
        
        else if (strcmp(OPCODE,"BYTE") == 0) {
            int RESERVE = reserveBYTE(OPERAND);
            if (RESERVE > 0) { 
                PC = RESERVE; 
            }
            // DO SOME ERROR CHECKING 
            
            else 
            {
                // MISSING OPERANDS FOR DATA STORAGE 
                if (RESERVE == 0)
                    ERRORS[2] = '1';
                // ILLEGAL OPERANDS FOR DATA STRORAGE 
                else if (RESERVE == -1)
                    ERRORS[3] = '1';
                PC = 0;
            }
        }
        
        else if(isValid(OPTABLE, OPCODE, OPTABLE_SIZE, MNEM_OPCODE)) { 
            opIsValid = true;
            PC = 3;
        }
        else { 
            // ILLEGAL OPERATION 
            ERRORS[1] = '1';
        }
                
        if (START_CODE[0] == '\0') {
            strcpy(START_CODE, LABEL);
        }
                
        if (!hasErrors(ERRORS)) {
            fprintf(intermed, "%s%s %s 1 %s %s\n", line, LOCCTR_HEX, ERRORS, OPCODE, MNEM_OPCODE);
            fprintf(intermedErr, "%s %s 1 %s %s\n", line, LOCCTR_HEX, ERRORS, OPCODE, MNEM_OPCODE);
            LOCCTR += PC;
        }
        else {             
            if (opIsValid)
                fprintf(intermedErr, "%s %s 1 %s %s\n", line, LOCCTR_HEX, ERRORS, OPCODE, MNEM_OPCODE);
            else 
                fprintf(intermedErr, "%s %s 0 %s", line, LOCCTR_HEX, ERRORS, OPCODE);
        }
    }   
        
    fclose(infile);
    fclose(intermed);
    fclose(intermedErr);
    fclose(symfile);
    char LENGTH[16];
    convertToHex((LOCCTR - START), LENGTH);
    return 0; 

}
