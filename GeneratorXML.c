#include <stdio.h>
#include <string.h>

void generateXML(char input[]) {
    char functionName[100];
    char argumentName[100];

    // Razdvajanje ulaznog stringa na ime funkcije i argument
    sscanf(input, "Rte_Read_%[^(](&%[^)])", functionName, argumentName);

    // Generisanje XML koda
    printf("<RequiredFunction Name=\"Rte_Read_%s\">\n", functionName);
    printf("\t<InputParameter Name=\"%s\" Type=\"uint8\" Passing=\"byReference\">\n", argumentName);
    printf("\t\t<InputSignal Name=\"%s\" BasicType=\"uint8\" />\n", functionName);
    printf("\t</InputParameter>\n");
    printf("\t<Return Type=\"Std_ReturnType\" Passing=\"byValue\" Value=\"RTE_E_OK\" />\n");
    printf("</RequiredFunction>\n");
}

int main() {
    // Ulazni string koji sadrži funkciju i argument
    char inputString[] = "Rte_Read_FUNKCIJA_rp_FUNKCIJA(&argument)";

    // Generisanje XML-a
    generateXML(inputString);

    return 0;
}
