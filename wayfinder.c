#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include "compas.h"

double start_lad;
double start_long;

double end_lad;
double end_long;
// idea why dont we just over write with one string 
char input_coor[100];


double input_control(char *str)
{
	double coor;
	bool input_letter = false;
	while(input_letter == false)
	{
		fgets(str, 100, stdin);

		int lenth = strlen(str);
		char heading = str[lenth - 2];

	
		coor = strtod(str, NULL);
		if(heading == 's' || heading == 'S' || heading == 'w' || heading == 'W')
		{
			coor = -coor;
		}
		input_letter = true;
		// make sure to use and(&&) and not or(||) i sure didnt make that mistake
		if(heading != 'n' && heading != 'N' && heading != 's' && heading != 'S' && heading != 'w' && heading != 'W' && heading != 'e' && heading != 'E')
		{
			printf("\nplease re-enter your coordinate with a letter of diretion:");
			input_letter = false;
		}
	}
	return coor;
	
}

void init_coordinates()
{
	printf("starting latatude: ");
	start_lad = input_control(input_coor);

	printf("\nstarting longatude: ");
	start_long = input_control(input_coor);
	
	printf("\nending latatude: ");
	end_lad = input_control(input_coor);

	printf("\nending longatude: ");
	end_long = input_control(input_coor);
}

double boaring_math(double longatude_differnce, double latatude_difference)
{
	double compas_heading = atan2(longatude_differnce, latatude_difference);
	compas_heading *= 180.0 / 3.145961;
	return compas_heading;
}

int main()
{
	init_coordinates();
	
	printf("\n%lf\n%lf\n%lf\n%lf\n", start_lad, start_long, end_lad, end_long);

	double compas_heading = boaring_math(end_long - start_long, end_lad - start_lad);
	
	if(compas_heading > 360 || compas_heading < 0)
	{
		compas_heading += 360;
	}

	printf("you need to go %lf\n", compas_heading);

	print_compas();

	point_nedal(compas_heading);


}
