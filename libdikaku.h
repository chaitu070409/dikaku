#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <net/ethernet.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <pcap.h>

#ifndef LIB_DEKAKU_H
#define LIB_DEKAKU_H

typedef struct d_sub_flow
{
	struct d_sub_flow * Next;
	
	char dst_ddr[50];
	uint8_t allowed;		//0 - Not Set, 1 - Allowed, 2 - drop
} dkku_sub_flow_t;

typedef struct d_sub_flows
{
	dkku_sub_flow_t * head;
	dkku_sub_flow_t * current;
	int count;
} dkku_sub_flows_t;


//---------------------------------------------------------------------------------------
uint8_t * dkku_malloc( size_t);
void dkku_free( uint8_t *);
//---------------------------------------------------------------------------------------
void dkku_sub_set_intval1( char * subIp, int istatus);
void dkku_sub_set_intval2( char * subIp, int istatus);
void dkku_sub_set_intval3( char * subIp, int istatus);

int dkku_sub_get_intval1( char * subIp);
int dkku_sub_get_intval2( char * subIp);
int dkku_sub_get_intval3( char * subIp);
//---------------------------------------------------------------------------------------
void dkku_sub_set_obj1( char * subIp, uint8_t * dataPtr);
void dkku_sub_set_obj2( char * subIp, uint8_t * dataPtr);

uint8_t * dkku_sub_get_obj1( char * subIp);
uint8_t * dkku_sub_get_obj2( char * subIp);
//---------------------------------------------------------------------------------------
void dkku_sub_flow_set_intval1( char * subIp, char * destIp, int istatus);
void dkku_sub_flow_set_intval2( char * subIp, char * destIp, int istatus);
void dkku_sub_flow_set_intval3( char * subIp, char * destIp, int istatus);

int dkku_sub_flow_get_intval1( char * subIp, char * destIp);
int dkku_sub_flow_get_intval2( char * subIp, char * destIp);
int dkku_sub_flow_get_intval3( char * subIp, char * destIp);
//---------------------------------------------------------------------------------------
void dkku_sub_flow_set_obj1( char * subIp, char * destIp, uint8_t * dataPtr);
void dkku_sub_flow_set_obj2( char * subIp, char * destIp, uint8_t * dataPtr);

uint8_t * dkku_sub_flow_get_obj1( char * subIp, char * destIp);
uint8_t * dkku_sub_flow_get_obj2( char * subIp, char * destIp);
//---------------------------------------------------------------------------------------
void dkku_set_sub_flow( char * subIp, char * destIp, uint8_t allow, int bCf);	//0 Not Set, 1 Allowed, 2 Deny
uint8_t dkku_get_sub_flow_val( char * subIp, char * destIp);

void dkku_set_sub_allflows( char * subIp, uint8_t allow, int bCf); 				//0 Not Set, 1 Allowed, 2 Deny
uint8_t dkku_get_sub_allflows_val( char * subIp, char * destIp);
//---------------------------------------------------------------------------------------
dkku_sub_flows_t * dkku_get_sub_flows( char * subIp);
void dkku_free_sub_flows_results( dkku_sub_flows_t *);
void dkku_purge_sub_flows( char * subIp);
//---------------------------------------------------------------------------------------

typedef void (*f_dkku_on_packet_recv)( u_char * pkt, int len, uint8_t * pktItem, int direction);

void dkku_default_forward_allow();
void dkku_default_forward_deny();
void dkku_set_onpacketrecv_handler( f_dkku_on_packet_recv pkt_handler);
void dkku_set_packet_status( uint8_t * pkt, uint8_t allow);
int  dkku_get_packet_info( uint8_t * upkt, char ** subIp, char ** dstIp, uint32_t * dstV4add, uint16_t * sport, uint16_t * dport, uint8_t * ipv, uint8_t * protcol, int * uv1, int * uv2);
void dkku_start( char * confFileName);
void dkku_wait();

char * dkku_get_config_param( char *);

#endif










