#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

main(){

    FILE *fp = fopen("data.txt","r");
    int arr[10][2], count=0, i=0, j=0;
    char line[20],line1[20],c;

    while((c=fgetc(fp)) != EOF)
    {
        if(c=='\n')
            count++;
    }
    count++;
    rewind(fp);

    float sdx, sdy, meanx, meany, tempx=0, tempy=0;
    float datax[count], datay[count], sumx=0, sumy=0;

    printf("\n---------------Original Data------------------\n\n");
    printf(" X feature | Y feature\n\t   |\n");
    //retrieving data from file
    while(!feof(fp))
    {
        fscanf(fp,"%s %s",line,line1);
        datax[i] = atof(line);
        datay[i] = atof(line1);
        printf(" %f | %f\n",datax[i],datay[i]);
        sumx += datax[i];
        sumy += datay[i];
        i++;
    }

    //mean of x and y feature
    meanx = sumx/count;
    meany = sumy/count;

    //calculation of summation(data-mean)^2
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

    //preparing the standardized data
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


