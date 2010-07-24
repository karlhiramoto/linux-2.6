#ifndef _NF_CONNTRACK_QUEUE_H
#define _NF_CONNTRACK_QUEUE_H


#if defined(CONFIG_NF_QUEUE_CONNBYTES_BYPASS)
#include <net/netfilter/nf_conntrack_extend.h>

struct nf_conntrack_queue {
	spinlock_t lock;
	union {
		u32     connbytes;
		u32     tcp_seq; /* TCP sequence number */
	} dir[IP_CT_DIR_MAX];
};

#endif
#endif /* _NF_CONNTRACK_QUEUE_H */
