# dikaku
packet forward with pf ring 

This library is used for forwarding packets from one NIC to another NIC using PF_RING

subscriber session based on subscriber ip address

configuration 
-------------
| KEY | Description |
| --- | --- |
| PACKET_OUT_DEVICE_NAME | Interface NAME of NIC PORT where packets need to send |
| PACKET_OUT_ETH_SRC_ADD | MAC Address of Interface of NIC OUT PORT, eg. b8ac6fcb499f |
| PACKET_OUT_ETH_DST_ADD | MAC Address of Target Destination of NIC OUT PORT |
| PACKET_IN_DEVICE_NAME  | Interface NAME of NIC PORT where packets will receive |
| PACKET_IN_ETH_SRC_ADD  | MAC Address of Interface of NIC IN PORT, eg. b8ac6fcb499f |
| PACKET_IN_ETH_DST_ADD  | MAC Address of Target Destination of NIC IN PORT (used when packets sending back) |
| PACKET_SEND_DISABLE    | value = 1, disable sending, other than 1 its enable | 
| PACKET_WORKER_THREADS  | no of working pthreads for processing |


api functions
---
| Name | Desctiption |
| --- | --- |
| dkku_get_config_param | gets the char * value from configuration file |
| dkku_sub_set_intval1 | save int 1 value in subscriber session |
| dkku_sub_set_intval2 | save int 2 value in subscriber session |
| dkku_sub_set_intval3 | save int 3 value in subscriber session |
| dkku_sub_get_intval1 | retrieve int 1 value from subscriber session |
| dkku_sub_get_intval2 | retrieve int 2 value from subscriber session |
| dkku_sub_get_intval3 | retrieve int 3 value from subscriber session |
| dkku_sub_set_obj1 | save pointer object 1 in subscriber session |
| dkku_sub_set_obj2 | save pointer object 2 in subscriber session |
| dkku_sub_get_obj1 | retrieve pointer object 1 from subscriber session |
| dkku_sub_get_obj2 | retrieve pointer object 2 from subscriber session |
| dkku_sub_flow_set_intval1 | save int 1 value in destination flow in subscriber session |
| dkku_sub_flow_set_intval2 | save int 2 value in destination flow in subscriber session |
| dkku_sub_flow_set_intval3 | save int 3 value in destination flow in subscriber session |
| dkku_sub_flow_get_intval1 | retrieve int 1 value from destination flow of subscriber session |
| dkku_sub_flow_get_intval2 | retrieve int 2 value from destination flow of subscriber session |
| dkku_sub_flow_get_intval3 | retrieve int 3 value from destination flow of subscriber session |
| dkku_sub_flow_set_obj1 | save pointer object 1 in destination flow in subscriber session |
| dkku_sub_flow_set_obj2 | save pointer object 2 in destination flow in subscriber session |
| dkku_sub_flow_get_obj1 | retrieve pointer object 1 value from destination flow of subscriber session |
| dkku_sub_flow_get_obj2 | retrieve pointer object 2 value from destination flow of subscriber session |

| dkku_set_sub_flow | |
| dkku_get_sub_flow_val | |
| dkku_set_sub_allflows | |
| dkku_get_sub_allflows_val | |
| dkku_get_sub_flows | |
| dkku_free_sub_flows_results | |
| dkku_purge_sub_flows | |






