 /******************************************************************************
 * Copyright (C) 2016-2017
 * file:    tableio.h
 * author:  mr.yg99 <young.khaled99@gmail.com>
 * created: 2017-02-24 11:20
 * updated: --
 ===> This is an open source product you can add your own modifications.
 ******************************************************************************/

#ifndef __tableio.h__
#define __tableio.h__

	int printTab(int table[], int size);
	int scanTab(int table[], int size);
	int TriTransposion(int table[], int size);
	int permute(int *num1, int *num2);
	int ValMax(int table[], int size);
	int ValMin(int table[], int size);




//*******************************************************//

	int printTab(int table[], int size)
	{
		int i;
		for(i=0 ; i < size ; i++)
			printf("%d   ", table[i]);
		printf("  \n");
		return 0;
	}

	///////////////////////////////////////

	int scanTab(int table[], int size)
	{
		int i;
		for(i=0 ; i < size ; i++)
		{
			printf("table[%d] = ", i);
			scanf("%d", &table[i]);
			printf(" \n");
		}
		return 0;
	}

	///////////////////////////////////////

	int permute(int *num1, int *num2)
	{
		int save;
		save = *num1;
		*num1 = *num2;
		*num2 = save;
		return 0;
	}

	///////////////////////////////////////


	int TriTransposion(int table[], int size)
	{
		int i = 0;
		int j, index;
		while(i < size-1)
		{
			if(table[i] > table[i+1])
			{
				permute(&table[i], &table[i+1]);
				j = i;
				while((j > 0) && (table[j] < table[j-1]))
				{
					permute(&table[j], &table[j-1]);
					j--;
				}
			}
			i++;
		}
		return 0;

	}

	///////////////////////////////////////

	int ValMax(int table[], int size)
	{
		int i;
		int max = table[0];
		for(i = 1 ; i < size ; i++)
		{
			if(table[i] >= max)
				max = table[i];

		}
		return max;

	}

	//////////////////////////////////////

	int ValMin(int table[], int size)
	{
		int i;
		int min = table[0];
		for(i = 1 ; i < size ; i++)
		{
			if(table[i] <= min)
				min = table[i];
		}
		return min;
	}

#endif
