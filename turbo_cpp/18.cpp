//////////////////////////////////////
//       By AL Bara Ramli           //
//       opencpp@yahoo.com          //
//       Copyright (C) 2007         //
//       Tripoli Libya              //
//////////////////////////////////////
//this program is distributed under //
//the GNU General Public License.   //
//////////////////////////////////////

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
void draw_arrow(int x, int y);
int main()
{
int gdriver = DETECT, gmode, errorcode;
void *arrow;
int x, y, E=10, i=0;
unsigned int size;
initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
x = 45;
y = 60;
draw_arrow(x, y);
size = imagesize(x-E, y- E, x+ E, y+ E);
arrow = malloc(size);
getimage(x-E, y- E, x+ E, y+ E, arrow);
while (!kbhit())
{
putimage(x-E, y- E, arrow, XOR_PUT);
x += 1;
if (i==100) x = 45;
putimage(x-E, y- E, arrow, XOR_PUT);
delay(50);
i+=1;
}
free(arrow);
closegraph();
return 0;
}
void draw_arrow(int x, int y)
{
int h=3;
circle(x,y,h);
}

