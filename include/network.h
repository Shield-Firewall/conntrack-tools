#ifndef _NETWORK_H_
#define _NETWORK_H_

#include <sys/types.h>

struct nlnetwork {
	u_int16_t flags;
	u_int16_t padding;
	u_int32_t seq;
};

struct nlnetwork_ack {
	u_int16_t flags; 
	u_int16_t padding;
	u_int32_t seq;
	u_int32_t from;
	u_int32_t to;
};

enum {
	NET_HELLO_BIT = 0,
	NET_HELLO = (1 << NET_HELLO_BIT),

	NET_RESYNC_BIT = 1,
	NET_RESYNC = (1 << NET_RESYNC_BIT),

	NET_NACK_BIT = 2,
	NET_NACK = (1 << NET_NACK_BIT),

	NET_ACK_BIT = 3,
	NET_ACK = (1 << NET_ACK_BIT),
};

/* extracted from net/tcp.h */

/*
 * The next routines deal with comparing 32 bit unsigned ints
 * and worry about wraparound (automatic with unsigned arithmetic).
 */

static inline int before(__u32 seq1, __u32 seq2)
{
	return (__s32)(seq1-seq2) < 0;
}
#define after(seq2, seq1)       before(seq1, seq2)

/* is s2<=s1<=s3 ? */
static inline int between(__u32 seq1, __u32 seq2, __u32 seq3)
{
	return seq3 - seq2 >= seq1 - seq2;
}

#endif
