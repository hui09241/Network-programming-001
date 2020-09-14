#include <stdio.h>
#include <winsock.h>
#include<string.h>
int main(void){

char domain[100]="";
char domainf[100]="";

printf("請輸入起始IP位址:");
scanf("%s",domain);
printf("請輸入目的IP位址:");
scanf("%s",domainf);

int start=0,dot=0,tstart=0,num1=0,num2=0,temp=0,long1;
for(start;start<strlen(domain);start++)
{
     if(dot==3)
    {
    	tstart=start;
        for(tstart;tstart<strlen(domain);tstart++)
        {
        	temp=domain[tstart]-'0';
        	num1=num1*10+temp;
        }
		break;
    }
    else if(domain[start]=='.')
         {
             dot++;
         }

}
//printf("%d\n",num1);
start=0;tstart=0;temp=0;dot=0;
for(start;start<strlen(domain);start++)
{
     if(dot==3)
    {
    	tstart=start;
        for(tstart;tstart<strlen(domain);tstart++)
        {
        	domain[tstart]='\0';
        }
		break;
    }
    else if(domain[start]=='.')
         {
             dot++;
         }

}
start=0;tstart=0;temp=0;dot=0;
for(start;start<strlen(domainf);start++)
{
     if(dot==3)
    {
    	tstart=start;
        for(tstart;tstart<strlen(domainf);tstart++)
        {
        	temp=domainf[tstart]-'0';
        	num2=num2*10+temp;
        }
		break;
    }
    else if(domainf[start]=='.')
         {
             dot++;
         }

}
//printf("%d\n",num2);
long1=num2-num1;
//printf("%d\n",long1);
//int length=domainf[strlen(domainf)-1]-dom//ain[strlen(domain)-1];
//initial WSAStartup


int i=0;
for( i=0;i<=long1;i++)
{
	char temp1[3]="";
    itoa(num1,temp1,10);
    strcat(domain,temp1);

WSADATA 		wsadata;
int nResult=WSAStartup(0x101,(LPWSADATA) &wsadata);
if(nResult!=0)
{
	printf("WSA Initialization failed: %d\n",nResult);
	WSACleanup();
	return 0;
}

LPHOSTENT hp;
struct in_addr sAddr;
sAddr.s_addr=inet_addr(domain);

hp=gethostbyaddr((LPSTR) &sAddr, sizeof(sAddr),AF_INET);

if(hp==NULL)
    printf("none\n");
else{
	printf("%s's '",inet_ntoa(*(LPIN_ADDR)(hp->h_addr)));
    printf("host name:%s\n",hp->h_name);
    //printf("host nickname:%s\n",hp->h_aliases[0]);

}
 start=0;tstart=0;temp=0;dot=0;
    for(start;start<strlen(domain);start++)
    {
     if(dot==3)
    {
    	tstart=start;
        for(tstart;tstart<strlen(domain);tstart++)
        {
        	domain[tstart]='\0';
        }
		break;
    }
    else if(domain[start]=='.')
         {
             dot++;
         }
    }
    num1++;
}
}
