#include<stdio.h>
#include<math.h>
#include "compas.h"

void print_compas()
{
	puts("|<><><><><><><><><><><><><><><><><><><><><><><>|");
	puts("|                      *                       |");
	puts("|   /\\~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~/\\    |");
	puts("|  (o )                .                ( o)   |");
	puts("|   \\/               .` `.               \\/    |");
	puts("|   /\\             .`     `.             /\\    |");
	puts("|  (             .`         `.             )   |");
	puts("|   )          .`      N      `.          (    |");
	puts("|  (         .`        |        `.         )   |");
	puts("|   )      .`         )|(         `.      (    |");
	puts("|  (     .`         )  |  (         `.     )   |");
	puts("|   )  .`         )    |    (         `.  (    |");
	puts("|    .`         )      |      (         `.     |");
	puts("|  .`     W---)--------O--------(---E     `.   |");
	puts("|   `.          )      |      (          .`    |");
	puts("|   ) `.          )    |    (          .` (    |");
	puts("|  (    `.          )  |  (          .`    )   |");
	puts("|   )     `.          )|(          .`     (    |");
	puts("|  (        `.         |         .`        )   |");
	puts("|   )         `.       S       .`         (    |");
	puts("|  (            `.           .`            )   |");
	puts("|   \\/            `.       .`            \\/    |");
	puts("|   /\\              `.   .`              /\\    |");
	puts("|  (o )               `.`               ( o)   |");
	puts("|   \\/~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~\\/    |");
	puts("|                     -|-                   LGB|");
	puts("|<><><><><><><><><><><><><><><><><><><><><><><>|");
}

void point_nedal(double compas_heading)
{
	// this is here to move the cuser and print the heading to take
	printf("\033[2A");
	printf("\033[37C");
	
	printf("\033[33m%lf", compas_heading);

	int travil = round(compas_heading / 18);


	printf("\033[17A");
	printf("\033[23D");
	
	for(int i = 0; i < travil; i++)
	{
		if(i >= 15 && i < 20)
		{
			printf("\033[1A");
			printf("\033[2C");
		}
		if(i >= 10 && i < 15)
		{
			printf("\033[1A");
			printf("\033[2D");
		}
		if(i >= 5 && i < 10)
		{
			printf("\033[1B");
			printf("\033[2D");
		}
		if(i >= 0 && i < 5)
		{
			printf("\033[1B");
			printf("\033[2C");
		}
	}
	

	printf("\033[33m%%");

	printf("\033[20B");
	printf("\033[30D");

}


