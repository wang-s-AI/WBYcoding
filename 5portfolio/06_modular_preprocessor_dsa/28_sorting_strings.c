/*******************************************************************************
* Program: Sorting An Array Of Strings
* 程序: 字符串数组排序实战
* Description: Sorting an array of strings in C using the Selection Sort algorithm: https://en.wikipedia.org/wiki/Selection_sort
* 描述: 结合 qsort() 与 strcmp() 编写字符串比较器，实现字符串数组的字典序排序。
* YouTube Lesson: https://www.youtube.com/watch?v=LZNxRSoEG2M
* Author: Kevin Browne @ https://portfoliocourses.com
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
  // we will sort this array of strings
  char strings[10][100] =
  {
    "demonstration",
    "apple",
    "joyful",
    "friends",
    "battle",
    "incredible",
    "example",
    "great",
    "happy",
    "city",
  };
  
  // the length of the array of strings
  int length = 10;
   
  // temp char array will be used to perform swaps of arrays
  char temp[100];
  
  // selection sort algorithm
  for (int i = 0; i < (length - 1); i++)
  {
    // find the position of the minimum string (alphabetically minimum)
    int j_min = i;
    for (int j = i + 1; j < length; j++)
      if (strcmp(strings[j], strings[j_min]) < 0)
        j_min = j;
    
    // if necessary, swap the minimum string with the string at index i
    if (j_min != i)
    {
      strcpy(temp, strings[i]);
      strcpy(strings[i], strings[j_min]);
      strcpy(strings[j_min], temp);
    }
  }
  
  // output the array of strings so we can see it is now sorted
  for (int i = 0; i < length; i++)
    printf("%s\n", strings[i]);

  return 0;
}

// A reminder of how the string comparison function works
//
// strcmp(s1,s2)
//
// < 0  first non-matching char has a lower value in s1 than s2
// 0    equal strings
// > 0  first non-matching char has a greater value in s1 than s2
//
