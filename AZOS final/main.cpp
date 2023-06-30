#include<iostream>
#include<cmath>
#include <mutex>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include <semaphore.h>
using namespace std;

double f(double x)
{
    double a=(pow(x,3)/3) -3*sin(x);
    return a;
}

int main()
{
    sem_t my_semaphore;
    int value;
    int n,i;
    double a,b,h,sum=0,integral;
    cout<<"Enter the limits of integration,\nInitial limit,a=";
    cin>>a;
    cout<<"Final limit, b=";
    cin>>b;
    cout<<"Enter the no. of subintervals, n=";
    cin>>n;
    double x[n+1],y[n+1];
    h=(b-a)/n;                //get the width of the subintervals


    for (i=0;i<=n;i++)
    {
        sem_init(&my_semaphore, 0, 1);
        sem_getvalue(&my_semaphore, &value);
        sem_wait(&my_semaphore);
        sem_getvalue(&my_semaphore, &value);


        x[i]=a+i*h;            //and store them in arrays
        y[i]=f(x[i]);

    }
    for (i=1;i<n;i++)            //loop to evaluate h*(y1+...+yn-1)
    {
        sem_init(&my_semaphore, 0, 1);
        sem_getvalue(&my_semaphore, &value);
        sem_wait(&my_semaphore);
        sem_getvalue(&my_semaphore, &value);


        sum=sum+h*y[i];

    }
    sem_init(&my_semaphore, 0, 1);
    sem_getvalue(&my_semaphore, &value);
    sem_wait(&my_semaphore);
    sem_getvalue(&my_semaphore, &value);
    integral=h/2.0*(y[0]+y[n])+sum;
    cout<<"The definite integral  is "<<integral<<endl;
    return 0;
}
