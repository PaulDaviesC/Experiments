#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#define MAX_MSG_SIZE 1000
int main()
{
	int sockfd;
	struct sockaddr_in server,client;
	int c,client_sock,port;
	char inbox[MAX_MSG_SIZE],outbox[MAX_MSG_SIZE];
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
		perror("Error in socket creation");
	else{
		server.sin_family=AF_INET;
		server.sin_addr.s_addr=INADDR_ANY;
		printf("Enter the port number : ");
		scanf("%d",&port);
		server.sin_port=htons(port);
		if((bind(sockfd,(struct sockakaddr*)&server,sizeof(server)))==-1)
			perror("Error in binding");
		else{
			if(listen(sockfd,0)==-1)
				perror("Error in listening");
			else{
				printf("waiting for connection :\n");
				c=sizeof(struct sockaddr_in);
				while(1){
					if((client_sock=accept(sockfd,(struct sockaddr*)&client,(struct socklen_t *)&c))==-1)
						perror("Error in accepting ");
					else{
						printf("Connected");
						while(recv(client_sock,inbox,MAX_MSG_SIZE,0)!=0){
							printf("Client : %s\n",inbox);
							printf("You :");
							gets(outbox);
							if(send(client_sock,outbox,MAX_MSG_SIZE,0)==-1)
								perror("Send failed");
						}
						printf("\t---Connection closed---\n");
					}
				}
					
			}
		}
	}
	close(sockfd);
}
