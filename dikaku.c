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
#include <poll.h>
#include <sys/epoll.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <error.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h> 

#include "libdikaku.h"

void dkku_on_packet( u_char * pkt, int len, uint8_t * pktItem)
{
	char * subIp = NULL;
	char * dstIp = NULL;
	uint32_t dstV4add = 0;
	uint16_t sport = 0;
	uint16_t dport = 0;
	uint8_t ipv = 0;
	uint8_t protcol = 0;
	
	if( dkku_get_packet_info( pktItem, &subIp, &dstIp, &dstV4add, &sport, &dport, &ipv, &protcol) == 1)
	{
		printf( "subIp=%s dstIp=%s dstV4add=%u sport=%u dport=%u ipv=%u protcol=%u \n", subIp, dstIp, dstV4add, sport, dport, ipv, protcol);
		
		if( protcol == 17 && ( sport == 53 || dport == 53))
		{
			dkku_set_packet_status( pktItem, 1);	//1 - allow
		}
	}
	else
	{
		dkku_set_packet_status( pktItem, 2);		//2 - drop
	}
}

int main( int argc, char* argv[])
{
	dkku_set_onpacketrecv_handler( dkku_on_packet);
	dkku_start( "./config/hpkt.config");
	
	
	sleep(5);
	
	dkku_set_sub_flow( "192.168.149.5", "10.10.21.25", 2, 1);	
	dkku_set_sub_flow( "192.168.149.5", "10.10.21.27", 1, 1);
	dkku_set_sub_flow( "192.168.149.5", "10.10.21.28", 2, 1);	
	
	uint8_t ax = 0;
	ax = dkku_get_sub_flow_val( "192.168.149.5", "10.10.21.24");
	printf( "ax = %u\n", ax);
	ax = dkku_get_sub_flow_val( "192.168.149.5", "10.10.21.27");
	printf( "ax = %u\n", ax);
	ax = dkku_get_sub_flow_val( "192.168.149.5", "10.10.21.28");
	printf( "ax = %u\n", ax);
	ax = dkku_get_sub_flow_val( "192.168.149.5", "10.10.21.25");
	printf( "ax = %u\n", ax);	
	
	dkku_sub_flows_t * flows = dkku_get_sub_flows( "192.168.149.5");
	
	printf("flows-count=%u\n", flows->count);
	
	dkku_sub_flow_t * item = flows->head;
	
	while( item)
	{
		printf( "    addr=%s allowed=%u\n", item->dst_ddr, item->allowed);		
		item = item->Next;
	}
	
	dkku_purge_sub_flows( "192.168.149.5");
	
	printf("2----------------------------\n");
	
	flows = dkku_get_sub_flows( "192.168.149.5");
	
	printf("flows-count=%u\n", flows->count);
	
	item = flows->head;
	
	while( item)
	{
		printf( "    addr=%s allowed=%u\n", item->dst_ddr, item->allowed);		
		item = item->Next;
	}
	
	
	printf("done\n");
	
	/**/
	
	
	dkku_wait();
	
	return 0;
}





