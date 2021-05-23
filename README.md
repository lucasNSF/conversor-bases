# conversor-bases
Este é um programa que converte números para as bases binário, hexadecimal e octal.

O programa foi construído utilizando funções e procedimentos que possam ser reutilizadas ao longo das outras conversões existentes no programa. Um exemplo desses procedimentos é:

<pre>
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
</pre>

O programa possui também funções responsáveis pela validação do número digitado. Por exemplo, em números binários só são aceitos os números "0" e "1", logo, foram construídas funções que detectam a presença de caracteres inválidos (como ":" , "," , "/", ".", etc) e se o formato condiz com a conversão selecionada. Um exemplo dessas funções é:

<pre>
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
</pre>

O programa também conta com um menu interativo para encaminhar as escolhas do usuário.
