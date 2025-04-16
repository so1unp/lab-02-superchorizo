#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int total = 0;                   
    int cActual;             
    char nroTemp[20];          
    int pos = 0;  

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            total += atoi(argv[i]); 
        } 
    } else {
        while ((cActual = getchar()) != EOF) {
            if ((cActual >= '0' && cActual <= '9') || (cActual == '-' && pos == 0)) {
                nroTemp[pos++] = (char)cActual;  // Guarda dígito o '-' si es el primer carácter
            } 
            else if (cActual == ' ' || cActual == '\n') {
                if (pos > 0) {
                    nroTemp[pos] = '\0'; 
                    total += atoi(nroTemp);  
                    pos = 0; 
                }
            }
        }  
        if (pos > 0) {
            nroTemp[pos] = '\0';  
            total += atoi(nroTemp);  
        }
    }

    printf("%d\n", total);
    return EXIT_SUCCESS;
}
