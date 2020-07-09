//Ryan W. Writz (c) 2020 ECE 373 Hw1

#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

float FartoCel(float TempVar)
{
	float CelCal;
	CelCal = (((TempVar - 32) *5)/9);
	return CelCal;
}

float FartoKel(float CelCal)
{
	float KelCal;
	KelCal = CelCal + 273.15;
	return KelCal;	
}


int main()
{
	float TempVar;
	float CelCal;
	float KelCal;

	printf("How hot is it in Farenheit?\n");
	scanf("%f",&TempVar);
	printf("You entered that it is %f F\n",TempVar);	
	CelCal = FartoCel(TempVar);
	KelCal = FartoKel(CelCal);
	printf("The equivalent temperatures for this are %f C, %f K.\n",CelCal,KelCal);
		
	return 0;
}

