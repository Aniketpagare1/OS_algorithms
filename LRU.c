#include<stdio.h>
int findLRU(int time[] , int no_frames)
{
int minium = time[0] , pos = 0 ;
for(int i=1 ; i<no_frames ; i++)
{
if(time[i] < minium)
{
minium = time[i]; pos = i;
}
}
return pos;
}
int main()
{
int no_pages , no_frames ; printf("enter number of pages : ");
scanf("%d",&no_pages);
printf("enter number of frames : "); scanf("%d",&no_frames);
int pages[no_pages] , frames[no_frames] , time[no_frames] , counter=0 , faults=0 , pos;
printf("enter referance string : \n");
for(int i=0 ; i<no_pages ; i++)
{
scanf("%d",&pages[i]);
}
for(int i=0 ; i<no_frames ; i++)
{
frames[i] = -1 ;
}
printf("page \t f1 \t\t f2 \t\t f3 \t\t \n");
//outer loop
for(int i=0 ; i<no_pages ; i++)
{
int flag1 = 0 , flag2 = 0;
// if page presnet
for(int j=0 ; j<no_frames ; j++)
{
if(pages[i] == frames[j])
{
counter++; faults++;
time[j] = counter; flag1 = 1;
flag2 = 1; break;
}
}
// if frame is free if(flag1 == 0)
{
for(int j=0 ; j<no_frames ; j++)
{
if(frames[j] == -1)
{
counter++;
faults++;
frames[j] = pages[i]; time[j] = counter; flag2 = 1;
break;
}
}
}
// if frame is not free if(flag2 == 0)
{
pos = findLRU(time , no_frames); counter++;
faults++;
time[pos] = counter; frames[pos] = pages[i];
}
printf("%d \t ",pages[i]); for(int j=0 ; j<no_frames ; j++)
{
printf("%d \t \t",frames[j]);
}
printf("\n");
}
printf("no of faults are : %d \n",faults);
}
