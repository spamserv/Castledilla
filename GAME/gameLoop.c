#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include "../TCP_IP_CONNECTION/server.h"
#include "../TCP_IP_CONNECTION/client.h"

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

void drawHostMenu();
void drawJoinMenu();
char* getIpAddress();

int main(){
	struct winsize size;
	ioctl( 0, TIOCGWINSZ, (char *) &size );
	int choice;

	clear();
	gotoxy(size.ws_col/8,size.ws_row+8);
	printf("Castledilla\n");
	gotoxy(size.ws_col/6,size.ws_row+10);
	printf("(1)HOST\n");
	gotoxy(size.ws_col/5,size.ws_row+10);
	printf("(2)JOIN\n");
	do{
	scanf("%d",&choice);
	}
	while(choice<1 || choice>2);
	if(choice==1){
		drawHostMenu();
	}
	else{
		drawJoinMenu();
	}
	return 0;
}

void drawHostMenu(){
	clear();
	struct winsize size;
	ioctl( 0, TIOCGWINSZ, (char *) &size );

	int choice;
	gotoxy(size.ws_col/8,size.ws_row+8);
	printf("Castledilla\n");
	gotoxy(size.ws_col/6,size.ws_row+5);
	printf("PRESS (1) TO START\n");
	do{
	scanf("%d",&choice);
	}
	while(choice!=1);
	printf("HOST ADDRESS: %s\n",getIpAddress());
	createConnection();
	clear();
}

void drawJoinMenu(){
	clear();
	struct winsize size;
	ioctl( 0, TIOCGWINSZ, (char *) &size );
	int i;
	char ip[100]="";
	do{
		clear();
		gotoxy(size.ws_col/8,size.ws_row+8);
		printf("Castledilla\n");
		gotoxy(size.ws_col/6,size.ws_row+5);
		printf("ENTER HOSTS IP ADDRESS\n");
		scanf("%s",&ip);
		i=connectToHost(ip);
	}
	while(i!=0);
	clear();
}

char* getIpAddress(){
	 int fd;
	 struct ifreq ifr;

	 char *ipAddress="";

	 fd = socket(AF_INET, SOCK_DGRAM, 0);

	 /* I want to get an IPv4 IP address */
	 ifr.ifr_addr.sa_family = AF_INET;

	 /* I want IP address attached to "eth0" */
	 strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);

	 ioctl(fd, SIOCGIFADDR, &ifr);

	 ipAddress=inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);

	 close(fd);

	 return ipAddress;

}

