/*
    Name : Loc Nguyen
    Date : 08/26/2021
    Function: Convert Teperature From F to C
*/

#include<stdio.h> 
#include<math.h> 

int main()
{
    float f, c;
    char a, b;
    
    printf("Please select the current temperature unit: \na.Fahrenheit \nb.Celsius \n");
    scanf("%c", &a);
    switch (a)
    {
        case 'a': 
        printf("Please input the Current temperature: \n");
        scanf("%f", &f);
        float fahren = ((f-32)*5)/9;
        printf("The temperature %.2f is %.2f in Celcius\n", f, fahren); 
        break;
        case 'b':
        printf("Please input the Current temperature: \n");
        scanf("%f", &c);
        float celsiu = ((1.8*c)+32);
        printf("The temperature %.2f is %.2f in Fahrenheit", c, celsiu);
        break;
    }
    
    return 0;
}
