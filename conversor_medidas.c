#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

// This procedure converts a decimal number to binary.
void DecToBin(int num) {
    int bin[max], count = 0;

    while (num != 0) {
        bin[count] = num % 2;
        num /= 2;
        count++;
    }
    --count;
    while (count >= 0) {
        printf("%d", bin[count]);
        count--;
    }
}

// This procedure converts a decimal number to hexadecimal.
void DecToHex(int num) {
    char letters[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int hex[max], count = 0;
    
    while (num >= 1) {
        hex[count] = num % 16;
        num /= 16;
        count++;
    }
    --count;
    while (count >= 0) {
        if (hex[count] >= 10)
            printf("%c", letters[hex[count] - 10]);
        else
            printf("%d", hex[count]);
        count--;
    }
}

//This procedure converts a decimal number to octal.
void DecToOct(int num) {
    int oct[max], count = 0;

    while (num >= 1) {
        oct[count] = num % 8;
        num /= 8;
        count++;
    }
    --count;
    while (count >= 0) {
        printf("%d", oct[count]);
        count--;
    }
}

// This function converts a binary number to decimal.
int BinToDec(char *num) {
    int bin[max], count = 0, i = 0;
    int value = 0;

    while (num[count] != '\0') {
        bin[count] = num[count] - '0';
        count++;
    }
    --count;
    while (count >= 0) {
        value += bin[i] * pow(2, count);
        i++;
        count--;
    }

    return value;
}

// This procedure converts a binary number to hexadecimal.
void BinToHex(char *num) {
    int value = BinToDec(num);
    DecToHex(value);
}

// This procedure converts a binary number to octal.
void BinToOct(char *num) {
    int value = BinToDec(num);
    DecToOct(value);
}

// This function converts a octal number to decimal.
int OctToDec(char *num) {
    int oct[max], count = 0, i = 0;
    int value = 0;

    while (num[count] != '\0') {
        oct[count] = num[count] - '0';
        count++;
    }
    --count;
    while (count >= 0) {
        value += oct[i] * pow(8, count);
        i++;
        count--;
    }

    return value;
}

// This procedure converts a octal number to hexadecimal.
void OctToHex(char *num) {
    int value = OctToDec(num);
    DecToHex(value);
}

// This procedure converts a octal number to binary.
void OctToBin(char *num) {
    int value = OctToDec(num);
    DecToBin(value);
}

// This function converts a hexadecimal number to decimal.
int HexToDec(char *num) {
    char letters[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int hex[max], count = 0, i = 0;
    int value = 0;
    int hasLetter;

    while (num[count] != '\0') {
        hasLetter = 0;
        for (int j = 0; j < 6; j++) {
            if (num[count] == letters[j]) {
                hex[count] = j + 10;
                hasLetter = 1;
                count++;
            }
        }
        if (hasLetter == 0) {
            hex[count] = num[count] - '0';
            count++;
        }
        hasLetter = 0;
    }
    --count;
    while (count >= 0) {
        value += hex[i] * pow(16, count);
        i++;
        count--;
    }

    return value;
}

// This procedure converts a hexadecimal number to binary.
void HexToBin(char *num) {
    int value = HexToDec(num);
    DecToBin(value);
}

//This procedure converts a hexadecimal number to octal.
void HexToOct(char *num) {
    int value = HexToDec(num);
    DecToOct(value);
}

// This function shows the menu.
int menu() {
    int option;
    
    do {
        
        printf("\n\t\t\t\t\tSELECT YOUR CONVERSION METHOD\n\n");
        printf("        Decimal base         |           Binary Base          |          Octal Base           |         Hexadecimal Base\n");
        printf("[1] Decimal -> Binary        |   [4] Binary -> Decimal        |   [7] Octal -> Decimal        |   [10] Hexadecimal -> Decimal\n");
        printf("[2] Decimal -> Hexadecimal   |   [5] Binary -> Hexadecimal    |   [8] Octal -> Hexadecimal    |   [11] Hexadecimal -> Binary\n");
        printf("[3] Decimal -> Octal         |   [6] Binary -> Octal          |   [9] Octal -> Binary         |   [12] Hexadecimal -> Octal\n");
        printf("\nYour option: ");
        scanf("%d", &option);

        if (option < 1 || option > 12)
            printf("Invalid option. Try again!\n");
    
    } while (option < 1 || option > 12);

    return option;
}

// This function scans if a hexadecimal or an octal number is on the correct pattern.
int scannerWORD(char *num) {
    int count = 0, error = 0;

    while (num[count] != '\0') {
        if ((num[count] < 48 || num[count] > 57) && (num[count] < 65 || num[count] > 70))
            error++;
        count++;
    }

    return error;
}

// This procedure scans a number.
int scannerNUM() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    return num;
}

// This function scans a binary number on the correct pattern.
int scannerBIN(char *num) {
    int count = 0, error = 0;
    
    while (num[count] != '\0') {
        if (num[count] < 48 || num[count] > 49)
            error++;
        count++;
    }

    return error;
}

int main() {
    char word[max] = {0};
    int option, number, error, entrance = 1;

    while (entrance == 1) {
        option = menu();
        switch (option) {
            case 1:
                number = scannerNUM();
                printf("%d in binary is: ", number);
                DecToBin(number); 
                break;
            case 2:
                number = scannerNUM();
                printf("%d in hexadecimal is: ", number);
                DecToHex(number);
                break;
            case 3:
                number = scannerNUM();
                printf("%d in octal is: ", number);
                DecToOct(number);
                break;
            case 4:
                do {
                    printf("Enter a number: ");
                    scanf("%s", word);
                    error = scannerBIN(word);
                    if (error > 0)
                        printf("The inserted number is in the incorrect format. Please, try again!\n");
                } while (error > 0);
                number = BinToDec(word);
                printf("%s in decimal is: %d", word, number);
                break;
            case 5:
                do {
                    printf("Enter a number: ");
                    scanf("%s", word);
                    error = scannerBIN(word);
                    if (error > 0)
                        printf("The inserted number is in the incorrect format. Please, try again!\n");
                } while (error > 0);
                printf("%s in hexadecimal is: ", word);
                BinToHex(word);
                break;
            case 6:
                do {
                    printf("Enter a number: ");
                    scanf("%s", word);
                    error = scannerBIN(word);
                    if (error > 0)
                        printf("The inserted number is in the incorrect format. Please, try again!\n");
                } while (error > 0);
                printf("%s in octal is: ");
                BinToOct(word);
                break;
            case 7:
                do {
                    printf("Enter a number: ");
                    scanf("%s", word);
                    error = scannerWORD(word);
                    if (error > 0)
                        printf("The inserted number is in the incorrect format. Please, try again!\n");
                } while (error > 0);
                number = OctToDec(word);
                printf("%s in decimal is: %d", word, number);
                break;
            case 8:
                do {
                    printf("Enter a number: ");
                    scanf("%s", word);
                    error = scannerWORD(word);
                    if (error > 0)
                        printf("The inserted number is in the incorrect format. Please, try again!\n");
                } while (error > 0);
                printf("%s in hexadecimal is: ", word);
                OctToHex(word);
                break;
            case 9:
                do {
                    printf("Enter a number: ");
                    scanf("%s", word);
                    error = scannerWORD(word);
                    if (error > 0)
                        printf("The inserted number is in the incorrect format. Please, try again!\n");
                } while (error > 0);
                printf("%s in binary is: ", word);
                OctToBin(word);
                break;
            case 10:
                do {
                    printf("Enter a number: ");
                    scanf("%s", word);
                    strupr(word);
                    error = scannerWORD(word);
                    if (error > 0)
                        printf("The inserted number is in the incorrect format. Please, try again!\n");
                } while (error > 0);
                number = HexToDec(word);
                printf("%s in decimal is: %d", word, number);
                break;
            case 11:
                do {
                    printf("Enter a number: ");
                    scanf("%s", word);
                    strupr(word);
                    error = scannerWORD(word);
                    if (error > 0)
                        printf("The inserted number is in the incorrect format. Please, try again!\n");
                } while (error > 0);
                printf("%s in binary is: ");
                HexToBin(word);
                break;
            default:
                do {
                    printf("Enter a number: ");
                    scanf("%s", word);
                    strupr(word);
                    error = scannerWORD(word);
                    if (error > 0)
                        printf("The inserted number is in the incorrect format. Please, try again!\n");
                } while (error > 0);
                printf("%s in octal is: ");
                HexToOct(word);
        }
        do {
            printf("\n\nWould you like to perform more one conversion?\n");
            printf("[1] Yes.  [2] No.\n");
            printf("Option: ");
            scanf("%d", &entrance);
            if (entrance < 1 || entrance > 2)
                printf("Invalid option. Try again!\n");
        } while (entrance < 1 || entrance > 2);
    }
    printf("\nFinalized program!");
    return 0;
}
