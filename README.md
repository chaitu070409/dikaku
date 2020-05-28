# dikaku
packet forward with pf ring 

This library is used for forwarding packets from one NIC to another NIC using PF_RING

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
| dkku_sub_set_intval1 | |
| dkku_sub_set_intval2 | |
| dkku_sub_set_intval3 | |
| dkku_sub_get_intval1 | |
| dkku_sub_get_intval2 | |
| dkku_sub_get_intval3 | |
| dkku_sub_set_obj1 | |
| dkku_sub_set_obj2 | |
| dkku_sub_get_obj1 | |
| dkku_sub_get_obj2 | |
| dkku_sub_flow_set_intval1 | |
| dkku_sub_flow_set_intval2 | |
| dkku_sub_flow_set_intval3 | |
| dkku_sub_flow_get_intval1 | |
| dkku_sub_flow_get_intval2 | |
| dkku_sub_flow_get_intval3 | |
| dkku_sub_flow_set_obj1 | |
| dkku_sub_flow_set_obj2 | |
| dkku_sub_flow_get_obj1 | |
| dkku_sub_flow_get_obj2 | |




