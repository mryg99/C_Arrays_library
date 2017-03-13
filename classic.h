/******************************************************************************
 * Copyright (C) 2016-2017
 * file:    classic.h
 * author:  mr.yg99 <young.khaled99@gmail.com>
 * created: 2017-02-25 15:07
 * updated: --
 ===> This is an open source product you can add your own modifications.
 ******************************************************************************/

#ifndef __CLASSIC__
#define __CLASSIC__

/*1*/ int premier(int number);
/*2*/ int perfect(int number);


int premier(int number)
{
    #define PREMIER 1
    #define NOT_PREMIER 0
    int i;
    for(i = 2 ; i <= number/2 ; i++)
    {
        if(number%i == 0)
            return NOT_PREMIER;
    }
    return PREMIER;
}

//////////////////////////////////

int perfect(int number)
{
    #define PERFECT 1
    #define NOT_PERFECT 0
    int i,somme = 0;
    for(i = 1 ; i <= number/2 ; i++)
    {
        if(number%i == 0)
            somme+=i;
    }
    if(somme == number)
        return PERFECT;
    else
        return NOT_PERFECT;

}

#endif // __CLASSIC__
