/*
 * client.h
 *
 *  Created on: Dec 5, 2016
 *      Author: rtrk
 */

#ifndef TCP_IP_CONNECTION_CLIENT_H_
#define TCP_IP_CONNECTION_CLIENT_H_

void * receiveClientMessage(void * socket);
int connectToHost(char * serverAddr);

#endif /* TCP_IP_CONNECTION_CLIENT_H_ */
