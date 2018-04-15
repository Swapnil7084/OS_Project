#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdbool.h>
#define MAX_RESOURCES 10
int avl_resources=MAX_RESOURCES;
sem_t sema,dema,mema;
bool pro[5]={false};
//decrement funtion
int decrease_count(int count,int *wcount)
{
	if(avl_resources<count)
	{	int zx=*wcount;
		++zx;*wcount=zx;
		return -1;}
	else
	{	
		avl_resources-=count;
		return 0;
	}
}
//increment function
int increase_count(int count)
{	
	avl_resources+=count;
	return 1;
}

void *fun1(void *a)
{
int licenses=*(int *)a;int k;
int francy=licenses;
int wcount=0;

while(!pro[0])
{
sem_wait(&sema);
goto even;
even:
	
	k=decrease_count(francy,&wcount);
	if(k==0)
	{sem_wait(&dema);	licenses=licenses-francy;
	
	printf("\n\napplication1          acquired   %15d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	if(licenses==0 ) pro[0]=true;
	sleep(4);sem_post(&dema);
	int mx=increase_count(francy);
	if(mx==1) printf("\n\napplication1          released   %15d  %15d %15d ",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	francy=licenses;
	sem_post(&sema);
	}
	else
	{	
		if(wcount>3) sleep(5);
		printf("\n\napplication1   denied(cant run cocurrently)  %d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
		sem_wait(&dema);
		if(avl_resources>0 && licenses>avl_resources)
		{
			francy=avl_resources;sem_post(&dema);
			goto even;
		}
		else{sem_post(&dema);
		sem_post(&sema);}
	}
}
printf("\n\napplication1 completed");
pthread_exit(NULL);

}

void *fun2(void *a)
{
int licenses=*(int *)a;int k;
int francy=licenses;
int wcount=0;
while(!pro[1])
{
sem_wait(&sema);
goto even;
even:
	
	k=decrease_count(francy,&wcount);
	if(k==0)
	{sem_wait(&dema);	licenses=licenses-francy;
	
	printf("\n\napplication2          acquired   %15d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	if(licenses==0 ) pro[1]=true;
	sem_post(&dema);sleep(4);
	int mx=increase_count(francy);
	if(mx==1) printf("\n\napplication2          released   %15d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	francy=licenses;
	sem_post(&sema);
	}
	else
	{	
		if(wcount>3) sleep(5);
		printf("\n\napplication2  denied(cant run cocurrently)  %d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
		sem_wait(&dema);
		if(avl_resources>0 && licenses>avl_resources)
		{
			francy=avl_resources;sem_post(&dema);
			goto even;
		}
		else
		{	sem_post(&dema);
		sem_post(&sema);}
	}
}
printf("\n\napplication2 completed");
pthread_exit(NULL);

}

void *fun3(void *a)
{
int licenses=*(int *)a;int k;
int francy=licenses;
int wcount=0;
while(!pro[2])
{
sem_wait(&sema);
goto even;
even:
	
	k=decrease_count(francy,&wcount);
	if(k==0)
	{sem_wait(&dema);	licenses=licenses-francy;
	printf("\n\napplication3          acquired   %15d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	if(licenses==0 ) pro[2]=true;
	sem_post(&dema);sleep(4);
	int mx=increase_count(francy);
	if(mx==1) printf("\n\napplication3          released   %15d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	francy=licenses;
	sem_post(&sema);
	}
	else
	{	
		if(wcount>3) sleep(5);	
	printf("\n\napplication3    denied(cant run cocurrently)   %d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES,avl_resources));
		sem_wait(&dema);
		if(avl_resources>0 && licenses>avl_resources)
		{
			francy=avl_resources;sem_post(&dema);
			goto even;
		}
		else
		{	sem_post(&dema);
		sem_post(&sema);}
	}
}
printf("\n\napplication3 completed");
pthread_exit(NULL);

}

void *fun4(void *a)
{
int licenses=*(int *)a;int k;
int francy=licenses;
int wcount=0;
while(!pro[3])
{
sem_wait(&sema);
goto even;
even:
	
	k=decrease_count(francy,&wcount);
	if(k==0)
	{sem_wait(&dema);	licenses=licenses-francy;
	printf("\n\napplication4          acquired   %15d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	if(licenses==0 ) pro[3]=true;
	sem_post(&dema);sleep(4);
	int mx=increase_count(francy);
	if(mx==1) printf("\n\napplication4          released   %15d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	francy=licenses;
	sem_post(&sema);
	}
	else
	{	if(wcount>3) sleep(5);
	printf("\n\napplication4    denied(cant run cocurrently)   %d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES,avl_resources));
		sem_wait(&dema);
		if(avl_resources>0 && licenses>avl_resources)
		{
			francy=avl_resources;sem_post(&dema);
			goto even;
		}
		else
		{	sem_post(&dema);
		sem_post(&sema);}
	}
}
printf("\n\napplication4 completed");
pthread_exit(NULL);

}

void *fun5(void *a)
{
int licenses=*(int *)a;int k;
int francy=licenses;
int wcount=0;
while(!pro[4])
{
sem_wait(&sema);
goto even;
even:
	
	k=decrease_count(francy,&wcount);
	if(k==0)
	{sem_wait(&dema);	licenses=licenses-francy;
	printf("\n\napplication5          acquired   %15d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	if(licenses==0 ) pro[4]=true;
	sem_post(&dema);sleep(4);
	int mx=increase_count(francy);
	if(mx==1) printf("\n\napplication5          released   %15d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES-avl_resources));
	francy=licenses;
	sem_post(&sema);
	}
	else
	{	if(wcount>3) sleep(5);
	printf("\n\napplication5    denied(cant run cocurrently)   %d  %15d %15d",licenses,avl_resources,(MAX_RESOURCES,avl_resources));
		sem_wait(&dema);
		if(avl_resources>0 && licenses>avl_resources)
		{
			francy=avl_resources;sem_post(&dema);
			goto even;
		}
		else
		{	sem_post(&dema);
		sem_post(&sema);}
	}
}
printf("\n\napplication5 completed");
pthread_exit(NULL);

}


			
int main()
{
sem_init(&sema,5,5);
sem_init(&dema,5,5);
pthread_t t1,t2,t3,t4,t5;		//creating  threads
int licenses[5];
printf("\n%s\n","enter the number of resources you want to allocate to the applications to run concurrently or singly");
printf("\nThere are only %d resources so provide input 1<=x<=%d",MAX_RESOURCES,MAX_RESOURCES);
for(int i=1;i<=5;i++)
{
	printf("\napplication %d :",i);scanf("%d",&licenses[i-1]);
	if(licenses[i-1]>MAX_RESOURCES)
	{
		printf("\nsorry you have entered wrong value enter again");
		i=i-1;
	}
}
printf("\n\nprocess----------- status----------required resources------ available ------ busy resources ");

pthread_create(&t1,NULL,fun1,(void *)&licenses[0]);
pthread_create(&t2,NULL,fun2,(void *)&licenses[1]);
pthread_create(&t3,NULL,fun3,(void *)&licenses[2]);
pthread_create(&t4,NULL,fun4,(void *)&licenses[3]);
pthread_create(&t5,NULL,fun5,(void *)&licenses[4]);

pthread_join(t1,NULL);
pthread_join(t2,NULL);

pthread_join(t3,NULL);
pthread_join(t4,NULL);
pthread_join(t5,NULL);
}

