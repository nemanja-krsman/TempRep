#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktura za čuvanje informacija o funkcijama
typedef struct {
    char name[100];
    char argumentName[100];
    char argumentType[100];
    char returnType[100];
    char passing[20];
} FunctionInfo;

// Funkcija za generisanje XML-a
void generateXML(FunctionInfo functions[], int numFunctions) {
    FILE *xmlFile = fopen("functions.xml", "w");
    if (xmlFile == NULL) {
        perror("Otvaranje XML fajla nije uspelo");
        exit(EXIT_FAILURE);
    }

    // Početak XML-a
    fprintf(xmlFile, "<Functions>\n");

    // Generisanje XML-a za svaku funkciju
    for (int i = 0; i < numFunctions; i++) {
        fprintf(xmlFile, "\t<RequiredFunction Name=\"%s\">\n", functions[i].name);
        fprintf(xmlFile, "\t\t<InputEvent Name=\"%s\" BasicType=\"%s\"/>\n", functions[i].argumentName, functions[i].argumentType);
        fprintf(xmlFile, "\t\t<Return Type=\"%s\" Passing=\"%s\">\n", functions[i].returnType, functions[i].passing);
        fprintf(xmlFile, "\t\t\t<InputSignal Name=\"%s_return\" BasicType=\"%s\"/>\n", functions[i].name, functions[i].returnType);
        fprintf(xmlFile, "\t\t</Return>\n");
        fprintf(xmlFile, "\t</RequiredFunction>\n");
    }

    // Kraj XML-a
    fprintf(xmlFile, "</Functions>\n");

    fclose(xmlFile);
    printf("XML fajl je uspešno generisan.\n");
}

int main() {
    // Definisanje informacija o funkcijama
    FunctionInfo functions[] = {
        {"Rte_Read_DELIVERY_MODE_INFORMATION_rp_DELIVERY_MODE_INFORMATION", "DELIVERY_MODE_INFORMATION_rp_DELIVERY_MODE_INFORMATION", "uint8", "uint8", "byValue"},
        // Dodajte ostale funkcije ovde
    };
    int numFunctions = sizeof(functions) / sizeof(FunctionInfo);

    // Generisanje XML-a
    generateXML(functions, numFunctions);

    return 0;
}
