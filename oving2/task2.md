# Task 2

Når vi kjører denne koden, får vi følgende feilmelding:
    
    segmentation fault (core dumped)

Dette skjer fordi *line peker til null-pointeren, altså adresse 0x0,
så når 
    
    strcpy(line, "Dette er en tekst");

prøver å lagre strengen "Dette er en tekst" der *line peker får vi
memory-feilmelding (ettersom 0-adressen ikke er en gyldig adresse for
lagring av data) og programmet kræsjer.