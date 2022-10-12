# Task 1b)

## Assosiativiteten i C++ gjør at uttrykket blir regnet ut som:
## ((((5-3) - fraction1) - 7) - fraction2)

## Vi får altså følgende versjoner av '-' operatoren:

## Opersjon:                                           Versjon:

## 1: (5 - 3)                                          std int 
## 2: ((5 - 3) - fraction1)                            Fraction operator-(int integer, const Fraction &other) {...} 
## 3: (((5 - 3) - fraction1) - 7)                      Fraction Fraction::operator-(int integer) const {...} 
## 4: ((((5 - 3) - fraction1) - 7) - fraction2)        Fraction Fraction::operator-(const Fraction &other) const