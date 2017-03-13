 /******************************************************************************
 * Copyright (C) 2016-2017
 * file:    tableio.h
 * author:  mr.yg99 <young.khaled99@gmail.com>
 * created: 24-02-2017 23:20
 * updated: 25-02-2017 13:07
 ===> This is an open source product you can add your own modifications.
 ******************************************************************************/

#ifndef __tableio.h__
#define __tableio.h__

/*1*/	int printTab(int table[], int size);
/*2*/	int scanTab(int table[], int size);
/*3*/	int TriTransposion(int table[], int size);
/*4*/	int permute(int *num1, int *num2);
/*5*/	int ValMax(int table[], int size);
/*6*/	int ValMin(int table[], int size);
/*7*/	int ExisteElem(int table[], int size, int element);
/*8*/	int DeleteElem(int table[], int *size, int element_index);
/*9*/   int vecteur_intersection(int vecteur1[], int size1, int vecteur2[], int size2, int vecteur3[], int *size3);

/*10*/ int scanMatrix(int matrix[][50], int lines, int columns);
/*11*/ int printMatrix(int matrix[][50], int lines, int columns);





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
		system("cls");
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

	///////////////////////////////////

	int ExisteElem(int table[], int size, int element)
	{
	    #define EXIST 1
	    #define NO_EXIST 0
		int i;
		if(size == 0)
			return NO_EXIST;
		else
		{
			for(i = 0 ; i < size ; i++)
			{
				if(table[i] == element)
					return EXIST;
			}
			return NO_EXIST;

		}
	}

	///////////////////////////////////////

	int DeleteElem(int table[], int *size, int element_index)
	{
		int i, tab[100];
		if(element_index >= *size)
			return 0;
		else
		{
			for(i = 0 ; i < element_index ; i++)
				tab[i] = table[i];
			for(i = element_index+1 ; i < *size ; i++)
				tab[i-1] = table[i];
            for(i = 0 ; i < *size-1 ; i++)
                table[i] = tab[i];
            *size-=1;
		}
		return 0;
	}

	//////////////////////////////////////////////

	int vecteur_intersection(int vecteur1[], int size1, int vecteur2[], int size2, int vecteur3[], int *size3)
{
    int i;
	int j = 0;
	int test = 1;
	int k = 0;

	for(i = 0 ; i < size1 ; i++)
	{
		while((j < size2) && (test == 1))
		{
			if(vecteur1[i] == vecteur2[j])
			{
				vecteur3[k] = vecteur1[i];
				test = 0;
				k++;
			}
            j++;
		}
		j = 0;
		test = 1;
	}

	for(i = 0 ; i < k ; i++) // to delete all the repeated elements
	{
		if(ExisteElem(vecteur3, k, vecteur3[i+1]))
			DeleteElem(vecteur3, &k, i+1);
	}
	*size3 = k;
	return 0;
}

/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////

    int scanMatrix(int matrix[][50], int lines, int columns)
    {
        #define CLEAR system("cls")
        int i,j;
        for(i = 0 ; i < lines ; i++)
        {
            for(j = 0 ; j < columns ; j++)
            {
                printf("Matrix[%d][%d] = ", i, j);
                scanf("%d", &matrix[i][j]);
            }
        }
        CLEAR;
        return ;
    }

////////////////////////////////////////////////

    int printMatrix(int matrix[][50], int lines, int columns)
    {
        int i,j;
        for(i = 0 ; i < lines ; i++)
        {
            for(j = 0 ; j < columns ; j++)
            {
                printf("%d   ", matrix[i][j]);
            }
            printf("\n");
        }
        return ;
    }



#endif
