#define BITSLICE(x, a, b) ((x) >> (b)) & ((1 << ((a)-(b)+1)) - 1)
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int action_run;

int packet_dropped = 0;
int traverse_update_flow_retx_3dupack_0_468578 = 0;
int compare1 = -1;
int compare2 = -1;
int traverse_get_sender_ip = 0;
int ack_packet = -1;
int traverse_record_IP = 0;


void flow_sent_460737();
void NoAction_27_458598();
void use_sample_rtt_0_469380();
void lookup_flow_map_reverse_0_460200();
void accept();
void update_flow_rcvd_0_468448();
void NoAction_31_458602();
void debug_460499();
void _drop_0_458439();
void use_sample_rtt_first_0_468287();
void record_IP_0_469118();
void NoAction_29_458600();
void sample_new_rtt_0_460456();
void NoAction_22_458593();
void parse_sack();
void rewrite_mac_0_458421();
void flow_dupack_460601();
void parse_tcp();
void save_source_IP_0_458891();
void update_flow_dupack_0_468387();
void increase_cwnd_460830();
void flow_retx_3dupack_460669();
void start();
void flow_rcvd_460635();
void set_nhop_0_460102();
void reject();
void lookup_reverse_460991();
void update_flow_sent_0_468831();
void parse_ethernet();
void set_dmac_0_459931();
void update_flow_retx_timeout_0_468731();
void NoAction_19_458590();
void get_sender_IP_0_468102();
void parse_mss();
void parse_ts();
void NoAction_0_458411();
void parse_end();
void NoAction_26_458597();
void init_460864();
void NoAction_32_458603();
void lookup_460957();
void NoAction_23_458594();
void lookup_flow_map_0_460138();
void parse_ipv4();
void _drop_4_459965();
void NoAction_25_458596();
void sample_rtt_rcvd_461025();
void _drop_1_459949();
void first_rtt_sample_460567();
void NoAction_30_458601();
void NoAction_1_458589();
void NoAction_21_458592();
void sample_rtt_sent_461059();
void NoAction_24_458595();
void update_flow_retx_3dupack_0_468578();
void direction_460533();
void NoAction_28_458599();
void increase_mincwnd_0_459972();
void parse_tcp_options();
void ipv4_lpm_460898();
void send_frame_458455();
void parse_nop();
void parse_wscale();
void forward_460771();
void NoAction_33_458604();
void flow_retx_timeout_460703();
void NoAction_20_458591();
typedef struct {
	uint32_t ingress_port : 9;
	uint32_t egress_spec : 9;
	uint32_t egress_port : 9;
	uint32_t clone_spec : 32;
	uint32_t instance_type : 32;
	uint8_t drop : 1;
	uint32_t recirculate_port : 16;
	uint32_t packet_length : 32;
	uint32_t enq_timestamp : 32;
	uint32_t enq_qdepth : 19;
	uint32_t deq_timedelta : 32;
	uint32_t deq_qdepth : 19;
	uint64_t ingress_global_timestamp : 48;
	uint32_t lf_field_list : 32;
	uint32_t mcast_grp : 16;
	uint8_t resubmit_flag : 1;
	uint32_t egress_rid : 16;
} standard_metadata_t;

void mark_to_drop() {
	packet_dropped = 1;
	end_assertions();
	exit(0);
}

typedef struct {
	uint64_t ingress_global_timestamp : 48;
	uint32_t lf_field_list : 32;
	uint32_t mcast_grp : 16;
	uint32_t egress_rid : 16;
} intrinsic_metadata_t;

typedef struct {
	uint8_t parse_tcp_options_counter : 8;
} my_metadata_t;

typedef struct {
	uint32_t nhop_ipv4 : 32;
} routing_metadata_t;

typedef struct {
	uint32_t dummy : 32;
	uint32_t dummy2 : 32;
	uint8_t flow_map_index : 2;
	uint32_t senderIP : 32;
	uint32_t seqNo : 32;
	uint32_t ackNo : 32;
	uint32_t sample_rtt_seq : 32;
	uint32_t rtt_samples : 32;
	uint32_t mincwnd : 32;
	uint32_t dupack : 32;
} stats_metadata_t;

typedef struct {
	uint8_t isValid : 1;
	uint64_t dstAddr : 48;
	uint64_t srcAddr : 48;
	uint32_t etherType : 16;
	uint8_t $valid$ : 1;
} ethernet_t;

typedef struct {
	uint8_t isValid : 1;
	uint8_t version : 4;
	uint8_t ihl : 4;
	uint8_t diffserv : 8;
	uint32_t totalLen : 16;
	uint32_t identification : 16;
	uint8_t flags : 3;
	uint32_t fragOffset : 13;
	uint8_t ttl : 8;
	uint8_t protocol : 8;
	uint32_t hdrChecksum : 16;
	uint32_t srcAddr : 32;
	uint32_t dstAddr : 32;
	uint8_t $valid$ : 1;
} ipv4_t;

typedef struct {
	uint8_t isValid : 1;
	uint8_t kind : 8;
	uint8_t $valid$ : 1;
} options_end_t;

typedef struct {
	uint8_t isValid : 1;
	uint8_t kind : 8;
	uint8_t len : 8;
	uint32_t MSS : 16;
	uint8_t $valid$ : 1;
} options_mss_t;

typedef struct {
	uint8_t isValid : 1;
	uint8_t kind : 8;
	uint8_t len : 8;
	uint8_t $valid$ : 1;
} options_sack_t;

typedef struct {
	uint8_t isValid : 1;
	uint8_t kind : 8;
	uint8_t len : 8;
	uint64_t ttee : 64;
	uint8_t $valid$ : 1;
} options_ts_t;

typedef struct {
	uint8_t isValid : 1;
	uint8_t kind : 8;
	uint8_t len : 8;
	uint8_t wscale : 8;
	uint8_t $valid$ : 1;
} options_wscale_t;

typedef struct {
	uint8_t isValid : 1;
	uint32_t srcPort : 16;
	uint32_t dstPort : 16;
	uint32_t seqNo : 32;
	uint32_t ackNo : 32;
	uint8_t dataOffset : 4;
	uint8_t res : 3;
	uint8_t ecn : 3;
	uint8_t urg : 1;
	uint8_t ack : 1;
	uint8_t push : 1;
	uint8_t rst : 1;
	uint8_t syn : 1;
	uint8_t fin : 1;
	uint32_t window : 16;
	uint32_t checksum : 16;
	uint32_t urgentPtr : 16;
	uint8_t $valid$ : 1;
} tcp_t;

tcp_t const_tcp;

typedef struct {
	uint8_t isValid : 1;
	uint8_t kind : 8;
	uint8_t $valid$ : 1;
} options_nop_t;

typedef struct {
	intrinsic_metadata_t intrinsic_metadata;
	my_metadata_t my_metadata;
	routing_metadata_t routing_metadata;
	stats_metadata_t stats_metadata;
} metadata;

typedef struct {
	ethernet_t ethernet;
	ipv4_t ipv4;
	options_end_t options_end;
	options_mss_t options_mss;
	options_sack_t options_sack;
	options_ts_t options_ts;
	options_wscale_t options_wscale;
	tcp_t tcp;
	int options_nop_index;
	options_nop_t options_nop[3];
} headers;

headers hdr;
metadata meta;
standard_metadata_t standard_metadata;

uint8_t tmp_45;

void parse_end() {
	hdr.options_end.isValid = 1;
	meta.my_metadata.parse_tcp_options_counter = meta.my_metadata.parse_tcp_options_counter + 255;
	parse_tcp_options();
}


void parse_ethernet() {
	hdr.ethernet.isValid = 1;
	switch(hdr.ethernet.etherType){
		case 2048:	parse_ipv4(); break;
		default:	accept(); break;
	}
}


void parse_ipv4() {
	hdr.ipv4.isValid = 1;
	switch(hdr.ipv4.protocol){
		case 6:	parse_tcp(); break;
		default:	accept(); break;
	}
}


void parse_mss() {
	hdr.options_mss.isValid = 1;
	meta.my_metadata.parse_tcp_options_counter = meta.my_metadata.parse_tcp_options_counter + 252;
	parse_tcp_options();
}


void parse_nop() {
	hdr.options_nop[hdr.options_nop_index].isValid = 1;
	hdr.options_nop_index++;
	meta.my_metadata.parse_tcp_options_counter = meta.my_metadata.parse_tcp_options_counter + 255;
	parse_tcp_options();
}


void parse_sack() {
	hdr.options_sack.isValid = 1;
	meta.my_metadata.parse_tcp_options_counter = meta.my_metadata.parse_tcp_options_counter + 254;
	parse_tcp_options();
}


void parse_tcp() {
	hdr.tcp.isValid = 1;
	meta.my_metadata.parse_tcp_options_counter = (uint8_t) hdr.tcp.dataOffset << 2 + 12;
	switch(hdr.tcp.syn){
		case 1:	parse_tcp_options(); break;
		default:	accept(); break;
	}
}


void parse_tcp_options() {
		klee_make_symbolic(&tmp_45, sizeof(tmp_45), "tmp_45");

	if(((meta.my_metadata.parse_tcp_options_counter & 255) == (0 & 255)) && ((BITSLICE(tmp_45, 7, 0) & 0) == (0 & 0))) {
		accept();
	} else if(((meta.my_metadata.parse_tcp_options_counter & 0) == (0 & 0)) && ((BITSLICE(tmp_45, 7, 0) & 255) == (0 & 255))) {
		parse_end();
	} else if(((meta.my_metadata.parse_tcp_options_counter & 0) == (0 & 0)) && ((BITSLICE(tmp_45, 7, 0) & 255) == (1 & 255))) {
		parse_nop();
	} else if(((meta.my_metadata.parse_tcp_options_counter & 0) == (0 & 0)) && ((BITSLICE(tmp_45, 7, 0) & 255) == (2 & 255))) {
		parse_mss();
	} else if(((meta.my_metadata.parse_tcp_options_counter & 0) == (0 & 0)) && ((BITSLICE(tmp_45, 7, 0) & 255) == (3 & 255))) {
		parse_wscale();
	} else if(((meta.my_metadata.parse_tcp_options_counter & 0) == (0 & 0)) && ((BITSLICE(tmp_45, 7, 0) & 255) == (4 & 255))) {
		parse_sack();
	} else if(((meta.my_metadata.parse_tcp_options_counter & 0) == (0 & 0)) && ((BITSLICE(tmp_45, 7, 0) & 255) == (8 & 255))) {
		parse_ts();
	}
}


void parse_ts() {
	hdr.options_ts.isValid = 1;
	meta.my_metadata.parse_tcp_options_counter = meta.my_metadata.parse_tcp_options_counter + 246;
	parse_tcp_options();
}


void parse_wscale() {
	hdr.options_wscale.isValid = 1;
	meta.my_metadata.parse_tcp_options_counter = meta.my_metadata.parse_tcp_options_counter + 253;
	parse_tcp_options();
}


void start() {
	parse_ethernet();
}


void accept() {
	
}


void reject() {
	packet_dropped = 1;
	end_assertions();
	exit(0);
}


void ParserImpl() {
	klee_make_symbolic(&hdr, sizeof(hdr), "hdr");
	klee_make_symbolic(&meta, sizeof(meta), "meta");
	klee_make_symbolic(&standard_metadata, sizeof(standard_metadata), "standard_metadata");

	start();
}

//Control

void egress() {
	send_frame_458455();
}

// Action
void NoAction_0_458411() {
	action_run = 458411;
	
}


// Action
void rewrite_mac_0_458421() {
	action_run = 458421;
	uint64_t smac;
	klee_make_symbolic(&smac, sizeof(smac), "smac");
	hdr.ethernet.srcAddr = smac;

}


// Action
void _drop_0_458439() {
	action_run = 458439;
		mark_to_drop();

}


//Table
void send_frame_458455() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: rewrite_mac_0_458421(); break;
		case 1: _drop_0_458439(); break;
		default: NoAction_0_458411(); break;
	}
	// keys: standard_metadata.egress_port:exact
	// size 256
	// default_action NoAction_0();

}



typedef struct {
	uint32_t field : 32;
	uint32_t field_0 : 32;
	uint8_t field_1 : 8;
	uint32_t field_2 : 16;
	uint32_t field_3 : 16;
} tuple_0;

//Control
uint32_t tmp_46;
uint32_t tmp_48;
uint32_t tmp_50;
uint32_t tmp_52;
uint32_t tmp_54;
uint32_t tmp_56;
uint32_t tmp_58;
uint32_t tmp_60;
uint32_t tmp_62;
uint32_t tmp_64;
uint32_t tmp_66;
uint32_t tmp_68;
uint32_t tmp_70;
uint32_t tmp_72;
uint32_t tmp_74;
uint32_t tmp_76;
uint32_t tmp_78;
uint32_t tmp_80;
uint32_t tmp_82;
uint32_t tmp_84;
uint32_t tmp_86;

void ingress() {

	compare2 = (hdr.ipv4.ttl == 0);
	const_tcp = hdr.tcp;
	
	if((hdr.ipv4.protocol == 6)) {
		if(hdr.ipv4.srcAddr > hdr.ipv4.dstAddr) {
	lookup_460957();
} else {
	lookup_reverse_460991();
}
	if((hdr.tcp.syn == 1) && (hdr.tcp.ack == 0)) {
	init_460864();
} else {
	direction_460533();
}
	if((hdr.ipv4.srcAddr == meta.stats_metadata.senderIP)) {
	if(hdr.tcp.seqNo > meta.stats_metadata.seqNo) {
		flow_sent_460737();
	if((meta.stats_metadata.sample_rtt_seq == 0)) {
	sample_rtt_sent_461059();
}
	if(meta.stats_metadata.dummy > meta.stats_metadata.mincwnd) {
	increase_cwnd_460830();
}

} else {
	if((meta.stats_metadata.dupack == 3)) {
	flow_retx_3dupack_460669();
} else {
	flow_retx_timeout_460703();
}
}
} else {
	if((hdr.ipv4.dstAddr == meta.stats_metadata.senderIP)) {
	if(hdr.tcp.ackNo > meta.stats_metadata.ackNo) {
		flow_rcvd_460635();
	if(hdr.tcp.ackNo >= meta.stats_metadata.sample_rtt_seq && meta.stats_metadata.sample_rtt_seq > 0) {
	if((meta.stats_metadata.rtt_samples == 0)) {
	first_rtt_sample_460567();
} else {
	sample_rtt_rcvd_461025();
}
}

} else {
	flow_dupack_460601();
}
} else {
	debug_460499();
}
}

}
	ipv4_lpm_460898();
	forward_460771();
}

// Action
void NoAction_1_458589() {
	action_run = 458589;
	
}


// Action
void NoAction_19_458590() {
	action_run = 458590;
	
}


// Action
void NoAction_20_458591() {
	action_run = 458591;
	
}


// Action
void NoAction_21_458592() {
	action_run = 458592;
	
}


// Action
void NoAction_22_458593() {
	action_run = 458593;
	
}


// Action
void NoAction_23_458594() {
	action_run = 458594;
	
}


// Action
void NoAction_24_458595() {
	action_run = 458595;
	
}


// Action
void NoAction_25_458596() {
	action_run = 458596;
	
}


// Action
void NoAction_26_458597() {
	action_run = 458597;
	
}


// Action
void NoAction_27_458598() {
	action_run = 458598;
	
}


// Action
void NoAction_28_458599() {
	action_run = 458599;
	
}


// Action
void NoAction_29_458600() {
	action_run = 458600;
	
}


// Action
void NoAction_30_458601() {
	action_run = 458601;
	
}


// Action
void NoAction_31_458602() {
	action_run = 458602;
	
}


// Action
void NoAction_32_458603() {
	action_run = 458603;
	
}


// Action
void NoAction_33_458604() {
	action_run = 458604;
	
}


// Action
void save_source_IP_0_458891() {
	action_run = 458891;
	
}


// Action
void get_sender_IP_0_468102() {
	traverse_get_sender_ip = 1;

	action_run = 468102;
			klee_make_symbolic(&tmp_46, sizeof(tmp_46), "tmp_46");

	meta.stats_metadata.senderIP = tmp_46;
		klee_make_symbolic(&tmp_48, sizeof(tmp_48), "tmp_48");

	meta.stats_metadata.seqNo = tmp_48;
		klee_make_symbolic(&tmp_50, sizeof(tmp_50), "tmp_50");

	meta.stats_metadata.ackNo = tmp_50;
		klee_make_symbolic(&tmp_52, sizeof(tmp_52), "tmp_52");

	meta.stats_metadata.sample_rtt_seq = tmp_52;
		klee_make_symbolic(&tmp_54, sizeof(tmp_54), "tmp_54");

	meta.stats_metadata.rtt_samples = tmp_54;
		klee_make_symbolic(&tmp_56, sizeof(tmp_56), "tmp_56");

	meta.stats_metadata.mincwnd = tmp_56;
		klee_make_symbolic(&tmp_58, sizeof(tmp_58), "tmp_58");

	meta.stats_metadata.dupack = tmp_58;

}


// Action
void use_sample_rtt_first_0_468287() {
	action_run = 468287;
			klee_make_symbolic(&tmp_60, sizeof(tmp_60), "tmp_60");

	meta.stats_metadata.dummy = tmp_60;
	meta.stats_metadata.dummy2 = (uint32_t) meta.intrinsic_metadata.ingress_global_timestamp;
	meta.stats_metadata.dummy2 = meta.stats_metadata.dummy2 - meta.stats_metadata.dummy;

}


// Action
void update_flow_dupack_0_468387() {
	action_run = 468387;
			klee_make_symbolic(&tmp_62, sizeof(tmp_62), "tmp_62");

	meta.stats_metadata.dummy = tmp_62;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy + 1;

}


// Action
void update_flow_rcvd_0_468448() {
	action_run = 468448;
			klee_make_symbolic(&tmp_64, sizeof(tmp_64), "tmp_64");

	meta.stats_metadata.dummy = tmp_64;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy + 1;

}


// Action
void update_flow_retx_3dupack_0_468578() {

	compare1 = (meta.stats_metadata.dupack < 3);
    traverse_update_flow_retx_3dupack_0_468578 = 1;

	action_run = 468578;
			klee_make_symbolic(&tmp_66, sizeof(tmp_66), "tmp_66");

	meta.stats_metadata.dummy = tmp_66;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy + 1;
		klee_make_symbolic(&tmp_68, sizeof(tmp_68), "tmp_68");

	meta.stats_metadata.dummy = tmp_68;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy >> 1;

}


// Action
void update_flow_retx_timeout_0_468731() {
	action_run = 468731;
			klee_make_symbolic(&tmp_70, sizeof(tmp_70), "tmp_70");

	meta.stats_metadata.dummy = tmp_70;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy + 1;

}


// Action
void update_flow_sent_0_468831() {
	action_run = 468831;
			klee_make_symbolic(&tmp_72, sizeof(tmp_72), "tmp_72");

	meta.stats_metadata.dummy = tmp_72;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy + 1;
	meta.stats_metadata.dummy = (uint32_t) meta.intrinsic_metadata.ingress_global_timestamp;
		klee_make_symbolic(&tmp_74, sizeof(tmp_74), "tmp_74");

	meta.stats_metadata.dummy2 = tmp_74;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy - meta.stats_metadata.dummy2;
		klee_make_symbolic(&tmp_76, sizeof(tmp_76), "tmp_76");

	meta.stats_metadata.dummy = tmp_76;
		klee_make_symbolic(&tmp_78, sizeof(tmp_78), "tmp_78");

	meta.stats_metadata.dummy2 = tmp_78;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy - meta.stats_metadata.dummy2;

}


// Action
void set_dmac_0_459931() {
	action_run = 459931;
	uint64_t dmac;
	klee_make_symbolic(&dmac, sizeof(dmac), "dmac");
	hdr.ethernet.dstAddr = dmac;

}


// Action
void _drop_1_459949() {
	action_run = 459949;
		mark_to_drop();

}


// Action
void _drop_4_459965() {
	action_run = 459965;
		mark_to_drop();

}


// Action
void increase_mincwnd_0_459972() {
	action_run = 459972;
	
}


// Action
void record_IP_0_469118() {
	action_run = 469118;
			klee_make_symbolic(&tmp_80, sizeof(tmp_80), "tmp_80");
			traverse_record_IP = 1;
	meta.stats_metadata.senderIP = tmp_80;

}


// Action
void set_nhop_0_460102() {
	action_run = 460102;
	uint32_t nhop_ipv4;
	klee_make_symbolic(&nhop_ipv4, sizeof(nhop_ipv4), "nhop_ipv4");
uint32_t port;
	klee_make_symbolic(&port, sizeof(port), "port");
	meta.routing_metadata.nhop_ipv4 = nhop_ipv4;
	standard_metadata.egress_spec = port;
	hdr.ipv4.ttl = hdr.ipv4.ttl + 255;

}


// Action
void lookup_flow_map_0_460138() {
	action_run = 460138;

}


// Action
void lookup_flow_map_reverse_0_460200() {
	action_run = 460200;

}


// Action
void use_sample_rtt_0_469380() {
	action_run = 469380;
			klee_make_symbolic(&tmp_82, sizeof(tmp_82), "tmp_82");

	meta.stats_metadata.dummy = tmp_82;
	meta.stats_metadata.dummy2 = (uint32_t) meta.intrinsic_metadata.ingress_global_timestamp;
	meta.stats_metadata.dummy2 = meta.stats_metadata.dummy2 - meta.stats_metadata.dummy;
		klee_make_symbolic(&tmp_84, sizeof(tmp_84), "tmp_84");

	meta.stats_metadata.dummy = tmp_84;
	meta.stats_metadata.dummy = 7 * meta.stats_metadata.dummy + meta.stats_metadata.dummy2;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy >> 3;
		klee_make_symbolic(&tmp_86, sizeof(tmp_86), "tmp_86");

	meta.stats_metadata.dummy = tmp_86;
	meta.stats_metadata.dummy = meta.stats_metadata.dummy + 1;

}


// Action
void sample_new_rtt_0_460456() {
	action_run = 460456;
	
}


//Table
void debug_460499() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: save_source_IP_0_458891(); break;
		default: NoAction_1_458589(); break;
	}
	// default_action NoAction_1();

}


//Table
void direction_460533() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: get_sender_IP_0_468102(); break;
		default: NoAction_19_458590(); break;
	}
	// default_action NoAction_19();

}


//Table
void first_rtt_sample_460567() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: use_sample_rtt_first_0_468287(); break;
		default: NoAction_20_458591(); break;
	}
	// default_action NoAction_20();

}


//Table
void flow_dupack_460601() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: update_flow_dupack_0_468387(); break;
		default: NoAction_21_458592(); break;
	}
	// default_action NoAction_21();

}


//Table
void flow_rcvd_460635() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: update_flow_rcvd_0_468448(); break;
		default: NoAction_22_458593(); break;
	}
	// default_action NoAction_22();

}


//Table
void flow_retx_3dupack_460669() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: update_flow_retx_3dupack_0_468578(); break;
		default: NoAction_23_458594(); break;
	}
	// default_action NoAction_23();

}


//Table
void flow_retx_timeout_460703() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: update_flow_retx_timeout_0_468731(); break;
		default: NoAction_24_458595(); break;
	}
	// default_action NoAction_24();

}


//Table
void flow_sent_460737() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: update_flow_sent_0_468831(); break;
		default: NoAction_25_458596(); break;
	}
	// default_action NoAction_25();

}


//Table
void forward_460771() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: set_dmac_0_459931(); break;
		case 1: _drop_1_459949(); break;
		default: NoAction_26_458597(); break;
	}
	// keys: meta.routing_metadata.nhop_ipv4:exact
	// size 512
	// default_action NoAction_26();

}


//Table
void increase_cwnd_460830() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: increase_mincwnd_0_459972(); break;
		default: NoAction_27_458598(); break;
	}
	// default_action NoAction_27();

}


//Table
void init_460864() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: record_IP_0_469118(); break;
		default: NoAction_28_458599(); break;
	}
	// default_action NoAction_28();

}


//Table
void ipv4_lpm_460898() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: set_nhop_0_460102(); break;
		case 1: _drop_4_459965(); break;
		default: NoAction_29_458600(); break;
	}
	// keys: hdr.ipv4.dstAddr:lpm
	// size 1024
	// default_action NoAction_29();

}


//Table
void lookup_460957() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: lookup_flow_map_0_460138(); break;
		default: NoAction_30_458601(); break;
	}
	// default_action NoAction_30();

}


//Table
void lookup_reverse_460991() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: lookup_flow_map_reverse_0_460200(); break;
		default: NoAction_31_458602(); break;
	}
	// default_action NoAction_31();

}


//Table
void sample_rtt_rcvd_461025() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: use_sample_rtt_0_469380(); break;
		default: NoAction_32_458603(); break;
	}
	// default_action NoAction_32();

}


//Table
void sample_rtt_sent_461059() {
	int symbol;
	klee_make_symbolic(&symbol, sizeof(symbol), "symbol");
	switch(symbol) {
		case 0: sample_new_rtt_0_460456(); break;
		default: NoAction_33_458604(); break;
	}
	// default_action NoAction_33();

}



//Control

void DeparserImpl() {
	//Emit hdr.ethernet
	
	//Emit hdr.ipv4
	
	//Emit hdr.tcp
	
	//Emit hdr.options_end
	
	//Emit hdr.options_nop_0
	
	//Emit hdr.options_nop_1
	
	//Emit hdr.options_nop_2
	
	//Emit hdr.options_mss
	
	//Emit hdr.options_wscale
	
	//Emit hdr.options_sack
	
	//Emit hdr.options_ts
	
}


typedef struct {
	uint8_t field_4 : 4;
	uint8_t field_5 : 4;
	uint8_t field_6 : 8;
	uint32_t field_7 : 16;
	uint32_t field_8 : 16;
	uint8_t field_9 : 3;
	uint32_t field_10 : 13;
	uint8_t field_11 : 8;
	uint8_t field_12 : 8;
	uint32_t field_13 : 32;
	uint32_t field_14 : 32;
} tuple_1;

//Control
uint32_t tmp_88;

void verifyChecksum() {
		klee_make_symbolic(&tmp_88, sizeof(tmp_88), "tmp_88");

	if((hdr.ipv4.hdrChecksum == tmp_88)) {
	mark_to_drop();
}
}


//Control
uint32_t tmp_90;

void computeChecksum() {
		klee_make_symbolic(&tmp_90, sizeof(tmp_90), "tmp_90");

	hdr.ipv4.hdrChecksum = tmp_90;
}


int main() {
	ParserImpl();
	ingress();
	egress();
	DeparserImpl();
	end_assertions();
	return 0;
}

void end_assertions(){
	if(compare1 == 1 && traverse_update_flow_retx_3dupack_0_468578){
		klee_warning_once("Assert error: if(meta.stats_metadata.dupack < 3, !traverse)" );
		klee_assert(0);
	}

	if(compare2 == 1 && !packet_dropped){
		klee_warning_once("packet forwarded with ttl == 0");
		klee_assert(0);
	}

	if(const_tcp.srcPort != hdr.tcp.srcPort ||
		const_tcp.dstPort != hdr.tcp.dstPort ||
		const_tcp.seqNo != hdr.tcp.seqNo ||
		const_tcp.ackNo != hdr.tcp.ackNo ||
		const_tcp.dataOffset != hdr.tcp.dataOffset ||
		const_tcp.res != hdr.tcp.res ||
		const_tcp.ecn != hdr.tcp.ecn ||
		const_tcp.urg != hdr.tcp.urg ||
		const_tcp.ack != hdr.tcp.ack ||
		const_tcp.push != hdr.tcp.push ||
		const_tcp.rst != hdr.tcp.rst ||
		const_tcp.syn != hdr.tcp.syn ||
		const_tcp.fin != hdr.tcp.fin ||
		const_tcp.window != hdr.tcp.window ||
		const_tcp.checksum != hdr.tcp.checksum ||
		const_tcp.urgentPtr != hdr.tcp.urgentPtr) {

			klee_warning_once("TCP header not constant");
			klee_assert(0);
		}

	if((hdr.tcp.ack && !packet_dropped && hdr.tcp.isValid) && !traverse_get_sender_ip){
		klee_warning_once("ack packet does not traverse get_sender_ip");
		klee_assert(0);
	}

	if(traverse_record_IP && hdr.tcp.ack){
		klee_warning_once("record_IP of ack packet");
		klee_assert(0);
	}

}
