#include <stdio.h>
#include <stdlib.h>
void set_zombies(int n, char fredMap[n][n])
{
  int i = 0, j = 0;
  while (scanf("%i", &i) == 1 && scanf("%i",  &j) == 1)
  {
    fredMap[i][j] = 'Z';
  }
}
void print_zombies(int n, char fredMap[n][n])
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      printf("%c ", fredMap[i][j]);
    }
    printf("\n");
  }
}
void block_zombies(int n, char fredMap[n][n])
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if (fredMap[i][j] == 'Z')
      {
          if (fredMap[i + 1][j] == '.' && i + 1 < n)
          {
            fredMap[i + 1][j] = 'B';
          }
          if (fredMap[i - 1][j] == '.' && i - 1 >= 0)
          {
            fredMap[i - 1][j] = 'B';
          }
          if (fredMap[i][j + 1] == '.' && j + 1 < n)
          {
            fredMap[i][j + 1] = 'B';
          }
          if (fredMap[i][j - 1] == '.' && j - 1 >= 0)
          {
            fredMap[i][j - 1] = 'B';
          }
      }
    }
  }
  printf("\n");
}

int main(){
int mapSize = 0, i, j, k = 0, length = 0;
scanf("%d", &mapSize);
char map[mapSize][mapSize];

for (i = 0; i < mapSize; i++)
{
  for(j = 0; j < mapSize; j++)
  {
    map[i][j] = '.';
  }
}
i = 0;
j = 0;

set_zombies(mapSize, map);
printf("Original Map: \n");
print_zombies(mapSize, map);
block_zombies(mapSize, map);
printf("Map with blocking info: \n");
print_zombies(mapSize, map);

return EXIT_SUCCESS;
}
