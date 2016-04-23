#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#define R_ARROW 77
#define U_ARROW 72
#define L_ARROW 75
#define D_ARROW 80
#define R_BOUND 75
#define U_BOUND 5
#define L_BOUND 5
#define D_BOUND 45
#define TRUE 1
#define ESC 27
#define SPACE printf(" ");
#define SNAKE printf("%c",219);
#define SQUARE printf("%c",254);
#define DIAMOND printf("%c",4);
#define FOOD printf("%c",4);
#define PRINT_SCORE gotoxy( 66,4 ); printf("Score: %d",score1);
int i, j, a, b, x, y, x_food, y_food, cursor, size, s_timer, t_timer=200, score1, food_check, check, x_f_quan[100], y_f_quan[100], x_cord[1000], y_cord[1000];
char key, ch, ch2, choice;
void maker(void);
void title(void);
void snake(void);
void welcome(void);
void melody(void);
void ratings(void);
void initialize(void);
int game(void);
void instructions(void);
void boundary(void);
void score(void);
void food(void);
int pause(void);
void goodbye(void);

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void main(void)
{
clrscr();

randomize();
maker();
delay(500);
title();
snake();
welcome();
melody();

do
 {
  clrscr();
  initialize();
  gotoxy(34,5);
  for( i=1 ; i<=13 ; i++ )
   printf("%c",249);
  gotoxy(34,7);
  for( i=1 ; i<=13 ; i++ )
   printf("%c",249);
  gotoxy(36,6);
  printf("Main Menu");
  gotoxy(25,18);
  printf("Select any option from following");
  gotoxy(31,22);
  printf("1 -- Start game");
  gotoxy(30,24);
  printf("2 -- Instructions");
  gotoxy(29,26);
  printf("3 -- Exit To Windows");
  gotoxy(31,28);
  printf("Enter your choice");
  gotoxy(39,30);

  switch( choice = getch()  )
   {
    case '1':
     {
      clrscr();
      gotoxy(2,49);
      printf("LOADING");
      for( i=1 ; i<=73 ; i++ )
       {
	printf("%c",222);
	delay(30);
       }
      game();
      break;
     }

    case '2':
     {
      instructions();
      break;
     }

    case '3':
     {
      t_timer=0;
      ratings();
      clrscr();
      gotoxy(68,49);
      printf("CLOSING...");
      title();
      delay(500);
      goodbye();
      melody();
      exit(0);
      break;
     }
   }
 }
while( choice != 3 );
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void instructions(void)
{
clrscr();
gotoxy(33,5);
for( i=1 ; i<=14 ; i++ )
 printf("%c",249);
gotoxy(33,7);
for( i=1 ; i<=14 ; i++ )
 printf("%c",249);
gotoxy(34,6);
printf("Instructions");
gotoxy(22,18);
printf("Use Arrow Keys to control the snake");
gotoxy(18,21);
printf("Eat the food without colliding with its body");
gotoxy(3,24);
printf("Each time you eat the food, you will get 20 points and your speed increases");
gotoxy(2,48);
printf("Press any key to continue...");

getch();
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void ratings(void)
{
clrscr();
gotoxy(27,23);
printf("Do you like this game ???");
gotoxy(26,25);
printf("Press Y for Yes or N for No");
gotoxy(40,27);
ch2 = getch();
if( ch2 == 'y' || ch2 == 'Y' )
 {
  gotoxy( 18,30 );
  printf("Ohh you make me so HAPPY, thanks for liking it");
 }

else if( ch2 == 'n' || ch2 == 'N' )
 {
  gotoxy( 13,30 );
  printf("Don't like?? but I think most of the people are liking it");
 }

else
 {
  gotoxy( 20,30);
  printf("You press wrong key, come back next time");
 }
delay(2000);
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void maker(void)
{
gotoxy(2,49);
printf("Made By: Muhammad Hassan Altaf");
gotoxy(68,49);
printf("LOADING...");
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void title(void)
{
/*----------E----------*/
for( i=10 ; i<16 ; i++ )
 { gotoxy( i,2 ); DIAMOND }

for( i=10 ; i<14 ; i++ )
 { gotoxy( i,7 ); DIAMOND }

for( i=10 ; i<16 ; i++ )
 { gotoxy( i,11 ); DIAMOND }

for( j=2 ; j<12 ; j++ )
 { gotoxy( 10,j ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------A----------*/
for( i=17,j=11 ; i<23,j>5 ; i++,j-- )
 { gotoxy( i,j ); DIAMOND }

for( i=22,j=6 ; i<28,j<12 ; i++,j++ )
 { gotoxy( i,j ); DIAMOND }

for( i=21 ; i<24 ; i++ )
 { gotoxy( i,9 ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------T----------*/
for( i=28 ; i<35 ; i++ )
 { gotoxy( i,6 ); DIAMOND }

for( j=6 ; j<12 ; j++ )
 { gotoxy( 31,j ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------_----------*/
for( i=36 ; i<40 ; i++ )
 { gotoxy( i,8 ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------M----------*/
gotoxy(45,6); DIAMOND

for( j=2 ; j<12 ; j++ )
 { gotoxy( 42,j ); DIAMOND }

for( i=42,j=2 ; i<46,j<6 ; i++,j++ )
 { gotoxy( i,j ); DIAMOND }

for( i=45,j=5 ; i<49,j>1 ; i++,j-- )
 { gotoxy( i,j ); DIAMOND }

for( j=2 ; j<12 ; j++ )
 { gotoxy( 48,j ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------O----------*/
gotoxy(51,7); DIAMOND
gotoxy(51,10); DIAMOND
gotoxy(55,7); DIAMOND
gotoxy(55,10); DIAMOND

for( j=8 ; j<10 ; j++ )
 { gotoxy( 50,j ); DIAMOND }

for( j=8 ; j<10 ; j++ )
 { gotoxy( 56,j ); DIAMOND }

for( i=52 ; i<55 ; i++ )
 { gotoxy( i,6 ); DIAMOND }

for( i=52 ; i<55 ; i++ )
 { gotoxy( i,11 ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------R----------*/
for( j=6 ; j<12 ; j++ )
 { gotoxy( 58,j ); DIAMOND }

for( i=58 ; i<62 ; i++ )
 { gotoxy( i,6 ); DIAMOND }

for( i=58 ; i<62 ; i++ )
 { gotoxy( i,9 ); DIAMOND }

for( j=7 ; j<9 ; j++ )
 { gotoxy( 62,j ); DIAMOND }

for( i=61,j=9 ; i<64,j<12 ; i++,j++ )
 { gotoxy( i,j ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------E----------*/
for( i=65 ; i<70 ; i++ )
 { gotoxy( i,6 ); DIAMOND }

for( i=65 ; i<69 ; i++ )
 { gotoxy( i,9 ); DIAMOND }

for( i=65 ; i<70 ; i++ )
 { gotoxy( i,11 ); DIAMOND }

for( j=6 ; j<11 ; j++ )
 { gotoxy( 65,j ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------S----------*/
gotoxy(29,17); DIAMOND
gotoxy(25,17); DIAMOND
gotoxy(25,21); DIAMOND
gotoxy(28,23); DIAMOND
gotoxy(28,27); DIAMOND
gotoxy(24,27); DIAMOND

for( i=26 ; i<29 ; i++ )
 { gotoxy( i,16 ); DIAMOND }

for( j=18 ; j<21 ; j++ )
 { gotoxy( 24,j ); DIAMOND }

for( i=26 ; i<28 ; i++ )
 { gotoxy( i,22 ); DIAMOND }

for( j=24 ; j<27 ; j++ )
 { gotoxy( 29,j ); DIAMOND }

for( i=25 ; i<28 ; i++ )
 { gotoxy( i,28 ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------N----------*/
for( j=21 ; j<29 ; j++ )
 { gotoxy( 31,j ); DIAMOND }

for( j=21 ; j<29 ; j++ )
 { gotoxy( 36,j ); DIAMOND }

for( i=31,j=21 ; i<36,j<26 ; i++,j++ )
 { gotoxy( i,j ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------A----------*/
for( i=38,j=24 ; i<42,j>20 ; i++,j-- )
 { gotoxy( i,j ); DIAMOND }

for( i=41,j=21 ; i<45,j<25 ; i++,j++ )
 { gotoxy( i,j ); DIAMOND }

for( j=24 ; j<29 ; j++ )
 { gotoxy( 38,j ); DIAMOND }

for( j=24 ; j<29 ; j++ )
 { gotoxy( 44,j ); DIAMOND }

for( i=38 ; i<45 ; i++ )
 { gotoxy( i,26 ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------K----------*/
gotoxy(49,21); DIAMOND

for( j=21 ; j<29 ; j++ )
 { gotoxy( 46,j ); DIAMOND }

for( i=46,j=25 ; i<50,j>21 ; i++,j-- )
 { gotoxy( i,j ); DIAMOND }

for( i=46,j=25 ; i<50,j<29 ; i++,j++ )
 { gotoxy( i,j ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------E----------*/
for( i=52 ; i<58 ; i++ )
 { gotoxy( i,21 ); DIAMOND }

for( i=52 ; i<56 ; i++ )
 { gotoxy( i,25 ); DIAMOND }

for( i=52 ; i<58 ; i++ )
 { gotoxy( i,28 ); DIAMOND }

for( j=21 ; j<29 ; j++ )
 { gotoxy( 52,j ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------G----------*/
gotoxy(32,32); DIAMOND
gotoxy(27,32); DIAMOND
gotoxy(27,42); DIAMOND
gotoxy(31,42); DIAMOND

for( i=28 ; i<32 ; i++ )
 { gotoxy( i,31 ); DIAMOND }

for( j=33 ; j<42 ; j++ )
 { gotoxy( 26,j ); DIAMOND }

for( i=28 ; i<31 ; i++ )
 { gotoxy( i,43 ); DIAMOND }

for( j=37 ; j<42 ; j++ )
 { gotoxy( 32,j ); DIAMOND }

for( i=29 ; i<33 ; i++ )
 { gotoxy( i,37 ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------A----------*/
for( i=34,j=39 ; i<38,j>35 ; i++,j-- )
 { gotoxy( i,j ); DIAMOND }

for( i=37,j=36 ; i<41,j<40 ; i++,j++ )
 { gotoxy( i,j ); DIAMOND }

for( j=39 ; j<44 ; j++ )
 { gotoxy( 34,j ); DIAMOND }

for( j=39 ; j<44 ; j++ )
 { gotoxy( 40,j ); DIAMOND }

for( i=34 ; i<41 ; i++ )
 { gotoxy( i,41 ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------M----------*/
for( j=36 ; j<44 ; j++ )
 { gotoxy( 42,j ); DIAMOND }

for( j=36 ; j<44 ; j++ )
 { gotoxy( 48,j ); DIAMOND }

for( i=45,j=39 ; i<49,j>35 ; i++,j-- )
 { gotoxy( i,j ); DIAMOND }

for( i=42,j=36 ; i<46,j<40 ; i++,j++ )
 { gotoxy( i,j ); DIAMOND }

gotoxy(78,49);
delay(t_timer);

/*----------E----------*/
for( i=50 ; i<56 ; i++ )
 { gotoxy( i,36 ); DIAMOND }

for( i=50 ; i<54 ; i++ )
 { gotoxy( i,40 ); DIAMOND }

for( i=50 ; i<56 ; i++ )
 { gotoxy( i,43 ); DIAMOND }

for( j=36 ; j<44 ; j++ )
 { gotoxy( 50,j ); DIAMOND }

gotoxy(78,49);
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void snake(void)
{
for( j=47 ; j>1 ; j-- )
 { gotoxy( 2,j ); SNAKE gotoxy(78,49); delay(50); }

for( i=2 ; i<7 ; i++ )
 { gotoxy( i,2 ); SNAKE gotoxy(78,49); delay(50); }

for( j=2 ; j<14 ; j++ )
 { gotoxy( 6,j ); SNAKE gotoxy(78,49); delay(50); }

for( i=6 ; i<20 ; i++ )
 { gotoxy( i,13 ); SNAKE gotoxy(78,49); delay(50); }

for( j=13 ; j<46 ; j++ )
 { gotoxy( 19,j ); SNAKE gotoxy(78,49); delay(50); }

for( i=19 ; i<80 ; i++ )
 { gotoxy( i,45 ); SNAKE gotoxy(78,49); delay(50); }

gotoxy(78,49);
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void welcome(void)
{
for( i=1 ; i<=48 ; i++ )
 for ( j=1 ; j<=80 ; j++ )
  {
   gotoxy( j,i ); SPACE
   if( i == 24 && j == 35 )
    {
     printf("Welcome!!!");
     j+=10;
    }
   gotoxy( 78,49 );
   delay(1);
  }
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void goodbye(void)
{
for( i=1 ; i<=48 ; i++ )
 for ( j=1 ; j<=80 ; j++ )
  {
   gotoxy( j,i ); SPACE
   if( i == 24 && j == 35 )
    {
     printf("Goodbye!!!");
     j+=10;
    }
   gotoxy( 78,49 );
   delay(1);
  }
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void melody(void)
{
sound(880); delay(500); nosound();
sound(780); delay(300); nosound();
sound(780); delay(500); nosound();
sound(780); delay(250); nosound();
sound(880); delay(250); nosound();
sound(920); delay(250); nosound();
sound(880); delay(250); nosound();
sound(780); delay(250); nosound();
sound(687); delay(250); nosound();
sound(687); delay(250);
sound(780); delay(250);
sound(880); delay(250);
sound(920); delay(250);
sound(880); delay(250);
sound(780); delay(250);
sound(687); delay(250);
sound(780); delay(250);
sound(687); delay(250);
sound(586); delay(500); nosound();
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

int game(void)
{
clrscr();
boundary();

while( TRUE )
 {
  if( kbhit() )
   {
    key = getch();
    if( key == 0 )
     {
      switch( getch() )
       {
	case R_ARROW:
	 {
	  if( cursor != L_ARROW )
	   cursor = 77;
	  break;
	 }
	case U_ARROW:
	 {
	  if( cursor != D_ARROW )
	   cursor = 72;
	  break;
	 }
	case L_ARROW:
	 {
	  if( cursor != R_ARROW )
	   cursor = 75;
	  break;
	 }
	case D_ARROW:
	 {
	  if( cursor != U_ARROW )
	   cursor = 80;
	  break;
	 }
       }
     }

    else if( key == ESC )
     {
      check = pause();
      if( check == 1 )
       return(0);
     }
   }

  else if( cursor == R_ARROW )
   {
    if( food_check == 0 )  /* if there is no food present on the screen */
     food();

    x = x_cord[0];  y = y_cord[0];

    x_cord[size+1] = x_cord[size]+1;  /* increase the snake position */
    y_cord[size+1] = y_cord[size];

    if( x_cord[size+1] == R_BOUND )  /* if collides with right boundary */
     x_cord[size+1] = 6;

    if( x_cord[size+1] == x_food && y_cord[size+1] == y_food )  /* if snake eats food */
     {
      food_check=0;
      score1+=20;
      if( s_timer > 39 )
       s_timer-=8;
      PRINT_SCORE
     }
    else
     food_check=1;

    for( i=0 ; i<=size ; i++ )
     if( x_cord[size+1] == x_cord[i] && y_cord[size+1] == y_cord[i] )  /* if snake collides with itself */
      {
       score();
       return(0);
      }

    if( x_cord[0] == x_f_quan[b] && y_cord[0] == y_f_quan[b] )  /* increase the snake size */
     {
      size++;
      b++;
     }

     else  /* change the snake position */
      {
       i=0;
       while( i<=size )
	{
	 x_cord[i] = x_cord[i+1];
	 y_cord[i] = y_cord[i+1];
	 i++;
	}
       gotoxy( x,y ); SPACE
      }

     for( i=0 ; i<=size ; i++ )  /* print snake */
      { gotoxy( x_cord[i],y_cord[i] ); SNAKE }

     gotoxy( 76,46 );
     delay(s_timer);
    }

  else if( cursor == U_ARROW )
   {
    if( food_check == 0 )  /* if there is no food present on the screen */
     food();

    x = x_cord[0];  y = y_cord[0];

    x_cord[size+1] = x_cord[size];  /* increase the snake position */
    y_cord[size+1] = y_cord[size]-1;

    if( y_cord[size+1] == U_BOUND )  /* If collides with upper boundary*/
     y_cord[size+1] = 44;

    if( x_cord[size+1] == x_food && y_cord[size+1] == y_food )  /* if snake eats food */
     {
      food_check=0;
      score1+=20;
      if( s_timer > 39 )
       s_timer-=8;
      PRINT_SCORE
     }
    else
     food_check=1;

    for( i=0 ; i<=size ; i++ )
     if( x_cord[size+1] == x_cord[i] && y_cord[size+1] == y_cord[i] )  /* if snake collides with itself */
      {
       score();
       return(0);
      }

     if( x_cord[0] == x_f_quan[b] && y_cord[0] == y_f_quan[b] )  /* increase the snake size */
      {
       size++;
       b++;
      }

     else  /* change the snake position */
      {
       i=0;
       while( i<=size )
	{
	 x_cord[i] = x_cord[i+1];
	 y_cord[i] = y_cord[i+1];
	 i++;
	}
       gotoxy( x,y ); SPACE
      }

     for( i=0 ; i<=size ; i++ )  /* print snake */
      { gotoxy( x_cord[i],y_cord[i] ); SNAKE }

     gotoxy( 76,46 );
     delay(s_timer);
    }

  else if( cursor == L_ARROW )
   {
    if( food_check == 0 )  /* if there is no food present on the screen */
     food();

    x = x_cord[0];  y = y_cord[0];

    x_cord[size+1] = x_cord[size]-1;  /* increase the snake position */
    y_cord[size+1] = y_cord[size];

    if( x_cord[size+1] == L_BOUND )  /* If collides with left boundary*/
     x_cord[size+1] = 74;

    if( x_cord[size+1] == x_food && y_cord[size+1] == y_food )  /* if snake eats food */
     {
      food_check=0;
      score1+=20;
      if( s_timer > 39 )
       s_timer-=8;
      PRINT_SCORE
     }

    else
     food_check=1;

    for( i=0 ; i<=size ; i++ )
     if( x_cord[size+1] == x_cord[i] && y_cord[size+1] == y_cord[i] )  /* if snake collides with itself */
      {
       score();
       return(0);
      }

     if( x_cord[0] == x_f_quan[b] && y_cord[0] == y_f_quan[b] )  /* increase the snake size */
      {
       size++;
       b++;
      }

     else  /* change the snake position */
      {
       i=0;
       while( i<=size )
	{
	 x_cord[i] = x_cord[i+1];
	 y_cord[i] = y_cord[i+1];
	 i++;
	}
       gotoxy( x,y ); SPACE
      }

     for( i=0 ; i<=size ; i++ )  /* print snake */
      { gotoxy( x_cord[i],y_cord[i] ); SNAKE }

     gotoxy( 76,46 );
     delay(s_timer);
    }

  else if( cursor == D_ARROW )
   {
    if( food_check == 0 )  /* if there is no food present on the screen */
     food();

    x = x_cord[0];  y = y_cord[0];

    x_cord[size+1] = x_cord[size];  /* increase the snake position */
    y_cord[size+1] = y_cord[size]+1;

    if( y_cord[size+1] == D_BOUND )  /* If collides with down boundary*/
     y_cord[size+1] = 6;

    if( x_cord[size+1] == x_food && y_cord[size+1] == y_food )  /* if snake eats food */
     {
      food_check=0;
      score1+=20;
      if( s_timer > 39 )
       s_timer-=8;
      PRINT_SCORE
     }

    else
     food_check=1;

    for( i=0 ; i<=size ; i++ )
     if( x_cord[size+1] == x_cord[i] && y_cord[size+1] == y_cord[i] )  /* if snake collides with itself */
      {
       score();
       return(0);
      }

     if( x_cord[0] == x_f_quan[b] && y_cord[0] == y_f_quan[b] )  /* increase the snake size */
      {
       size++;
       b++;
      }

     else  /* change the snake position */
      {
       i=0;
       while( i<=size )
	{
	 x_cord[i] = x_cord[i+1];
	 y_cord[i] = y_cord[i+1];
	 i++;
	}
       gotoxy( x,y ); SPACE
      }

     for( i=0 ; i<=size ; i++ )  /* print snake */
      { gotoxy( x_cord[i],y_cord[i] ); SNAKE }

     gotoxy( 76,46 );
     delay(s_timer);
    }
 }
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

int pause(void)
{
printf("\nPress 'e' To End The Current Game\nPress Any Other Key To Return To Game");
ch = getch();
if( ch=='e' || ch=='E' )
 {
  score();
  return(1);
 }
else
 {
  for( i=1 ; i<40 ; i++ )
   { gotoxy( i,47 ); SPACE }

  for( i=1 ; i<40 ; i++ )
   { gotoxy( i,48 ); SPACE }

  return(0);
 }
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void score(void)
{
clrscr();

if( score1 == 0 )
 {
  gotoxy(32,23);
  printf("Playing like a Kid");
  gotoxy(10,24);
  printf("Very Bad! Dear, I hope next time you will be scoring more");
 }

else if( score1 > 0 && score1 <= 140 )
 {
  gotoxy(30,23);
  printf("Playing like a Beginner");
  gotoxy(10,24);
  printf("Not Bad! Dear, I hope next time you will be scoring more");
 }

else if( score1 > 140 && score1 <=480 )
 {
  gotoxy(28,23);
  printf("Playing like a Professional");
  gotoxy(10,24);
  printf("Well Done! Dear, I hope next time you will be scoring more");
 }

else if( score1 > 480 )
 {
  gotoxy(31,23);
  printf("Playing like a Master");
  gotoxy(10,24);
  printf("Wonderful! Dear, I hope next time you will be scoring more");
 }

gotoxy(35,26);
printf("You score %d",score1);
delay(1000);
gotoxy(2,48);
printf("Press any key to continue...");

getch();
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void boundary(void)
{
PRINT_SCORE
for( i=5 ; i<76 ; i++ )
 { gotoxy( i,5 ); SQUARE }

for(j=5 ; j<46 ; j++ )
 { gotoxy( 75,j ); SQUARE }

for( i=75 ; i>4 ; i-- )
 { gotoxy( i,45 ); SQUARE }

for( j=45 ; j>4 ; j-- )
 { gotoxy( 5,j ); SQUARE }

gotoxy(47,46);
printf("Press 'Esc' to pause the game");
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void food(void)
{
do
 {
  check=0;
  x_food = random(67)+6;
  y_food = random(38)+6;

  for( i=0 ; i<size ; i++ )
   if( x_food == x_cord[i] && y_food == y_cord[i] )
    check = 1;
 }
while( check == 1 );

x_f_quan[a] = x_food;
y_f_quan[a] = y_food;
a++;

gotoxy( x_food,y_food ); FOOD
}

  /*++++++++++++++++++++++++++++++++++++++++++++++++*/

void initialize(void)
{
for( i=0,j=6 ; i<=9,j<=15 ; i++,j++ )
 {
  x_cord[i] = j;
  y_cord[i] = 25;
 }
a=0, b=0, x_food=15, y_food=25, cursor=77, size=9, s_timer=200, t_timer=200, score1=0, food_check=0, check=0;
}