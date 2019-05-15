#include <stdio.h>
#include <conio.h>
#include <string.h>

long conv(char s);

void main()
{
FILE *in1, *in2, *out;
char fname1[8], fname2[8], fname3[8], s1, s2, s3, s4;
int stroka, posit;
long adress=24576, s1_, s2_, s3_, s4_, slovo, CRC=0;

clrscr();

printf("Имя 1-го исходного файла: ");
scanf(%s, &fname1);
printf("Имя 2-го исходного файла: ");
scanf(%s, &fname2);
printf("Выходного файла: ");
scanf(%s, &fname3);

in1 = fopen(fname1, "rt");
in2 = fopen(fname2, "rt");
out = fopen(fname3, "wt");

fprintf(out, "adress|	00	02	04	06	10	12	14	16\n");
fprintf(out, "____________________________________________________________________\n");

for(stroka=1; stroka<512; stroka++)
	{
	fprintf(out, "%6o | ", adress);
	for(posit=1; posit<10; posit++)
		{
		getc(in1);
		getc(in2);
		}
	for(posit=10; posit<26; posit++)
		{
		s1 = getc(in1);
		s2 = getc(in1);
		s3 = getc(in2);
		s4 = getc(in2);
		s1_ = conv(s1);
		s2_ = conv(s2);
		s3_ = conv(s3);
		s4_ = conv(s4);
		slovo = s1_ * 16 * 16 * 16 + s2_ * 16 * 16 + s3_ * 16 + s4_;
		CRC = CRC + slovo;
		if (CRC >= 65536)
			{
			CRC = CRC - 65536;
			CRC++;
			}
		fprintf(out, "%6o", slovo);
		}
	for(posit=26; posit<=44; posit++)
		{
		getc(in1);
		getc(in2);
		}
	fprintf(out, "\n");
	adress = adress + 16;
	}

fprintf(out, "	CRC = %Xh\n", CRC);

fclose(out);
fclose(in1);
fclose(in2);
printf("\n");
printf("Файл успешно создан!");
printf("Контрольная сумма CRC = %Xh\n", CRC);
getch();
}

long conv(char s)
{
long s_;
switch(s)
	{
	case '0': s_ = 0; break;
	case '1': s_ = 1; break;
	case '2': s_ = 2; break;
	case '3': s_ = 3; break;
	case '4': s_ = 4; break;
	case '5': s_ = 5; break;
	case '6': s_ = 6; break;
	case '7': s_ = 7; break;
	case '8': s_ = 8; break;
	case '9': s_ = 9; break;
	case 'A': s_ = 10; break;
	case 'B': s_ = 11; break;
	case 'C': s_ = 12; break;
	case 'D': s_ = 13; break;
	case 'E': s_ = 14; break;
	case 'F': s_ = 15; break;
	}
return s_;
} 
