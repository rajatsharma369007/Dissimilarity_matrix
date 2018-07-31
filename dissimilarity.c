// this is a program to implement Dissimilarity matrix to find out similarity pair to pair
// between two sets.
// Author: Rajat Sharma
// Date: February, 2018

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

main(){
    
    FILE *fp = fopen("data.txt","r");
    int arr[10][2], count=0, i=0, j=0;
    char line[20],line1[20],c;

    //to get the number of data points in the file
    while((c=fgetc(fp)) != EOF)
    {
        if(c=='\n')
            count++;
    }
    count++;
    rewind(fp);     // to go to the start of the file again

    float sdx, sdy, meanx, meany, tempx=0, tempy=0;
    float datax[count], datay[count], sumx=0, sumy=0;

    printf("\n---------------Original Data------------------\n\n");
    printf(" X feature | Y feature\n\t   |\n");
    //retrieving data from file
    while(!feof(fp))
    {
        fscanf(fp,"%s %s",line,line1);            //retrieving the two data points
        datax[i] = atof(line);                    //conversion of text to number
        datay[i] = atof(line1);
        printf(" %f | %f\n",datax[i],datay[i]); 
        sumx += datax[i];                         //sumx, sumy to be used in mean cal.
        sumy += datay[i];
        i++;
    }

    //mean of x and y feature
    meanx = sumx/count;
    meany = sumy/count;

    //calculation of summation(data-mean)^2 to be used in standard deviation cal.
    i=0;
    while(i<count)
    {
        tempx += pow(abs(datax[i] - meanx), 2);
        tempy += pow(abs(datay[i] - meany), 2);
        i++;
    }

    //standard deviation of x, y feature
    sdx = sqrt(tempx/(count-1));
    sdy = sqrt(tempy/(count-1));

    //preparing the standardized data, summation((data - mean)/sd)
    i=0;
    while(i<count)
    {
        datax[i] = (datax[i]-meanx)/sdx;
        datay[i] = (datay[i]-meany)/sdy;
        i++;
    }

    printf("\n---------------Standardised Data----------------\n\n");
    printf(" X feature | Y feature\n\t   |\n");
    //printing the standardized data
    i=0;
    while(i<count)
    {
        printf(" %f | %f\n",datax[i], datay[i]);
        i++;
    }

    //calculation of dissimilarity matrix using euclidean distance
    float matrix[count][count];
    for(i=0;i<count;i++)
    {
        for(j=0;j<=i;j++)
        {
            matrix[i][j] = sqrt(pow(datax[i]-datax[j],2) + pow(datay[i]-datay[j],2));
        }
    }

    printf("\n---------------Dissimilarity matrix-------------\n\n");
    //for printing the matrix
    for(i=0;i<count;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf(" %f ",matrix[i][j]);
        }
        printf("\n\n");
    }

}


