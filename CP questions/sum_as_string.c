#include <stdio.h>
#include <stdlib.h>

int
length (char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; ++i);
  return i;
}

void
add (char *a, char *b, char *sum)
{
  int la = length (a), lb = length (b);
  int lmin = la > lb ? lb : la, d1, d2, s, c = 0, lmax = lb + la - lmin;
  for (int i = 1; i <= lmax; i++)
    {
      if (i <= lmin)
	{
	  d1 = a[la - i] - '0';
	  d2 = b[lb - i] - '0';
	}
      else
	{
	  if (lmin == lb)
	    {
	      d2 = 0;
	      d1 = a[la - i] - '0';
	    }
	  else
	    {
	      d1 = 0;
	      d2 = b[lb - i] - '0';
	    }
	}
      s = (d1 + d2 + c) % 10;
      c = (d1 + d2 + c) / 10;
      sum[lmax + 1 - i] = s + '0';	//converting int to char 
    }
  sum[0] = c + '0';
}

void
subtract (char *a, char *b, char *diff)
{
  int la = length (a), lb = length (b);
  int lmin = la > lb ? lb : la, d1, d2, s, br = 0, lmax = lb + la - lmin;
  for (int i = 1; i <= lmax; i++)
    {
      if (i <= lmin)
	{
	  d1 = a[la - i] - '0';
	  d2 = b[lb - i] - '0';
	}
      else
	{
	  if (lmin == lb)
	    {
	      d2 = 0;
	      d1 = a[la - i] - '0';
	    }
	  else
	    {
	      d1 = 0;
	      d2 = b[lb - i] - '0';
	    }
	}
      if (d1 - d2 - br >= 0)
	{
	  s = d1 - d2 - br;
	  br = 0;
	}
      else
	{
	  s = 10 + d1 - d2 - br;
	  br = 1;
	}
      diff[lmax - i] = s + '0';
    }
}

int
main ()
{
  char a[1000], b[1000], sum[2000];
  scanf ("%s %s", a, b);
  if (a[0] == '-')
    {
      subtract (b, a + 1, sum);
      for (int i = 0; sum[i] == '0'; i++)
	printf ("%s\n", sum + i);

    }
    else if(b[0]== '-'){
        subtract (a, b + 1, sum);
      for (int i = 0; sum[i] == '0'; i++)
	printf ("%s\n", sum + i);
    }
  else
    {
          if (sum[0] == '0')
    	{
    	  printf ("%s\n", sum + 1);
    	}
          else
    	{
    	  printf ("%s\n", sum);
    	}

    }
  return 0;
}