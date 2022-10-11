#include <stdio.h>
#include <string.h>
#include <math.h>
#define BASE 2
/** conversion from hexadecimal  to octal **/
void ABC (char hex[17])
{
    long long decimal=0, place=1 ,octal=0,N;
    int i = 0, val, len,Y, remY, placeY = 1;
    len = strlen(hex);
    len--;
    for(i=0; hex[i]!='\0'; i++)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }
        N=decimal;
        while(N > 0)
    {
        remY = N % 8;
        octal += (remY * placeY);
        N /= 8;
        placeY *= 10;
    }
    printf("Octal number = %lld", octal);
}
/** conversion from octal  to hexadecimal **/
void OCTAHEX (long long octal)
{
    int OCTALVALUES[] = {0, 1, 10, 11, 100, 101, 110, 111};
    long long  binary=0, place=1;
    char hex[65] = "";
    int rem;
    while(octal > 0)
    {
        rem = octal % 10;
        binary = (OCTALVALUES[rem] * place) + binary;
        octal /= 10;
        place *= 1000;
    }
    while(binary > 0)
    {
        rem = binary % 10000;
        switch(rem)
        {
            case 0   :strcat(hex, "0");break;
            case 1   :strcat(hex, "1");break;
            case 10  :strcat(hex, "2");break;
            case 11  :strcat(hex, "3");break;
            case 100 :strcat(hex, "4");break;
            case 101 :strcat(hex, "5");break;
            case 110 :strcat(hex, "6");break;
            case 111 :strcat(hex, "7");break;
            case 1000:strcat(hex, "8");break;
            case 1001:strcat(hex, "9");break;
            case 1010:strcat(hex, "A");break;
            case 1011:strcat(hex, "B");break;
            case 1100:strcat(hex, "C");break;
            case 1101:strcat(hex, "D");break;
            case 1110:strcat(hex, "E");break;
            case 1111:strcat(hex, "F");break;
        }
        binary /= 10000;
    }
    strrev(hex);
    printf("Hexadecimal number: %s", hex);
}
/** conversion from Binary to hexadecimal **/
void BINHEXA (  long long binary)
{
    int hexConstant[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000,
                         1001, 1010, 1011, 1100, 1101, 1110, 1111};
    char hex[20];
    int index=0, i, digit;
    while(binary!=0)
    {
        digit = binary % 10000;
        for(i=0; i<16; i++)
        {
            if(hexConstant[i] == digit)
            {
                if(i<10)
                {
                    hex[index] = (char)(i + 48);
                }
                else
                {
                    hex[index] = (char)((i-10) + 65);
                }
                index++;
                break;
            }
        }
        binary /= 10000;
    }
    hex[index] = '\0';
    strrev(hex);
    printf("Hexadecimal number = %s", hex);
}
/**conversion from decimal  to octal   **/
void DCOCTA ( long long decimal)
{
    long long  octal=0;
    int i, rem, place = 1;
    while(decimal > 0)
    {
        rem = decimal % 8;
        octal += (rem * place);
        decimal /= 8;
        place *= 10;
    }

    printf("Octal number = %lld", octal);
}
/** conversion from octal  to decimal **/
void OCTADC ( long long octal)
{
     long long decimal=0;
    int rem, place=0;
    while(octal > 0)
    {
        rem = octal % 10;
        decimal+= pow(8, place) * rem;
        octal /= 10;
        place++;
    }
    printf("Decimal number = %lld", decimal);
}
 /** conversion from hexadecimal to binary  **/
void hexobin ( char hex[17])
{
    char bin[65] = "";
    int i = 0;
    for(i=0; hex[i]!='\0'; i++)
    {
        switch(hex[i])
        {
            case '0':strcat(bin, "0000");break;
            case '1':strcat(bin, "0001");break;
            case '2':strcat(bin, "0010");break;
            case '3':strcat(bin, "0011");break;
            case '4':strcat(bin, "0100");break;
            case '5':strcat(bin, "0101");break;
            case '6':strcat(bin, "0110");break;
            case '7':strcat(bin, "0111");break;
            case '8':strcat(bin, "1000");break;
            case '9':strcat(bin, "1001");break;
            case 'a':
            case 'A':strcat(bin, "1010");break;
            case 'b':
            case 'B':strcat(bin, "1011");break;
            case 'c':
            case 'C':strcat(bin, "1100");break;
            case 'd':
            case 'D':strcat(bin, "1101");break;
            case 'e':
            case 'E':strcat(bin, "1110");break;
            case 'f':
            case 'F':strcat(bin, "1111");break;
            default:printf("Invalid hexadecimal input.");
        }
    }
    printf("Binary number = %s", bin);
}

/** conversion from decimal to hexadecimal **/
void dchexo ( long long decimal)
{
    char HEXVALUE[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char hex[65];
    int index=0, rem;
    while(decimal !=0)
    {
        rem = decimal % 16;
        hex[index] = HEXVALUE[rem];
        decimal /= 16;
        index++;
    }
    hex[index] = '\0';
    strrev(hex);
    printf("Hexadecimal number = %s", hex);
}
/** conversion from hexadecimal to decimal  **/
void hexodec (char hex[17])
{
    long long decimal=0, place=1;
    int i = 0, val, len;
    len = strlen(hex);
    len--;
    for(i=0; hex[i]!='\0'; i++)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }
    printf("Decimal number = %lld", decimal);
}
/** conversion from octal  to binary  **/
   void ocbin (long long octal)
{
    int OCTALVALUES[] = {0, 1, 10, 11, 100, 101, 110, 111};
    long long tempOctal, binary=0, place=1;
    int rem;
    tempOctal = octal;
    while(tempOctal > 0)
    {
        rem = tempOctal % 10;
        binary += (OCTALVALUES[rem] * place) ;
        tempOctal /= 10;
        place *= 1000;
    }
    printf("Binary number = %lld", binary);
}
 /**conversion from Binary to octal  **/
void binoc (long long binary)
{
    int octalConstant[] = {0, 1, 10, 11, 100, 101, 110, 111};
    long long octal=0;
    int digit, place=1, i;
    while(binary != 0)
    {
        digit = binary % 1000;
        for(i=0; i<8; i++)
        {
            if(octalConstant[i] == digit)
            {
                octal = (i * place) + octal;
                break;
            }
        }
        binary /= 1000;
        place *= 10;
    }
    printf("Octal number = %lld", octal);
}
/**conversion from Binary to Decimal**/
void bn ( long long binary)
{
    long long  decimal=0;
    int N=0;
    while(binary!=0)
    {
        if(binary % 10 == 1)
        {
            decimal += pow(BASE, N);
        }
        N++;
        binary /= 10;
    }
    printf("Decimal number= %lld", decimal);
}
/**conversion from Decimal to Binary **/
 void dc (long long  decimal)
 {
 long long  R =0, bin=0  ,N=1;
 while (decimal>0)
 {
    R=decimal%2 ;
    bin+=(R*N);
    decimal/=2 ;
    N*=10;
 }
   printf("Binary number = %lld\n\n", bin);
 }
int main()
{   long long  D=0 ,G=0,B1=0,O1=0,DC=0,DO=0,OD=0,BH=0,OH;
    int choi=0;
    char hey[17] ;
    char hexo[17];
    char heG[17];
       cg :
printf("  **********************************************************************\n");
printf("  ******************************** Affichage ***************************\n");
printf("  **********************************************************************\n\n\n");
printf("- > conversion from Decimal to Binary         :click 1  !\n");
printf("- > conversion from Binary to Decimal         :click 2  !\n");
printf("- > conversion from Binary to octal           :click 3  !\n");
printf("- > conversion from octal  to binary          :click 4  !\n");
printf("- > conversion from hexadecimal to decimal    :click 5  !\n");
printf("- > conversion from decimal to hexadecimal    :click 6  !\n");
printf("- > conversion from hexadecimal to binary     :click 7  !\n");
printf("- > conversion from octal  to decimal         :click 8  !\n");
printf("- > conversion from decimal  to octal         :click 9  !\n");
printf("- > conversion from Binary to hexadecimal     :click 10 !\n");
printf("- > conversion from octal  to hexadecimal     :click 11 !\n");
printf("- > conversion from hexadecimal  to octal     :click 12 !\n");
printf("\n- >  : ");
    scanf("%d",&choi);
    if (choi>0 && choi<13)
    {
         switch(choi)
    {
        case 1: //conversion from Decimal to Binary
        system ("cls");
        printf("Enter any decimal number: \n\n");
        scanf("%lld",&D);
        dc ( D ); break;
        case 2: //conversion from Binary to Decimal
        system ("cls");
        printf("Enter any binary number: ");
        scanf("%lld",&G);
        bn (G); break;
        case 3: //conversion from Binary to octal
        system ("cls");
        printf("Enter any binary number: ");
        scanf("%lld", &B1);
        binoc(B1); break;
        case 4://conversion from octal  to binary
        system ("cls");
        printf("Enter any Octal number: ");
        scanf("%lld", &O1);
        ocbin(O1); break;
        case 5://conversion from hexadecimal to decimal
        system ("cls");
        printf("Enter any hexadecimal number: ");
        scanf ("%s",&hey);
        hexodec(hey); break;
        case 6://conversion from decimal to hexadecimal
        system ("cls");
        printf("Enter any decimal number: ");
        scanf("%lld", &DC);
        dchexo (DC); break;
        case 7://conversion from hexadecimal to binary
        system ("cls");
        printf("Enter any hexadecimal number: ");
        scanf ("%s",&hexo);
        hexobin(hexo); break;
        case 8://conversion from octal  to decimal
        system ("cls");
        printf("Enter any octal number: ");
        scanf("%lld", &DO);
        OCTADC(DO); break;
        case 9://conversion from decimal  to octal
        system ("cls");
        printf("Enter any decimal number: ");
        scanf("%lld", &OD);
        DCOCTA (OD); break;
        case 10://conversion from Binary to hexadecimal
        system ("cls");
        printf("Enter binary number: ");
        scanf("%lld", &BH);
        BINHEXA (BH); break;
        case 11://conversion from octal  to hexadecimal
        system ("cls");
        printf("Enter any octal number: ");
        scanf("%lld", &OH);
        OCTAHEX (OH); break;
        case 12://conversion from hexadecimal  to octal
        system ("cls");
        printf("Enter any hexadecimal number: ");
        scanf ("%s",&heG);
        ABC(heG); break;
        default: system ("cls");
        goto cg ;
    }
    }
    else
        {
        system ("cls");
        goto cg ;
        }

    return 0;
}
