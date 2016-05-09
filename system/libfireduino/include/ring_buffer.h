 /**
 * @file ring_buffer.h
 * @brief Definitions ring_buffer for Fireduino
 * @author jiang<jdz@t-chip.com.cn> 
 * @version V1.0
 * @date 2016.02
 * 
 * @par Copyright:
 * Copyright (c) 2016 T-CHIP INTELLIGENCE TECHNOLOGY CO.,LTD. \n\n
 *
 * For more information, please visit website <http://www.t-firefly.com/>, \n\n
 * or email to <service@t-firefly.com>.
 */
#ifndef _LIBMAPLE_RING_BUFFER_H_
#define _LIBMAPLE_RING_BUFFER_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "typedef.h"

/**
 * Ring buffer type.
 *
 * The buffer is empty when head == tail.
 *
 * The buffer is full when the head is one byte in front of the tail,
 * modulo buffer length.
 *
 * One byte is left free to distinguish empty from full. */
typedef struct ring_buffer {
    volatile uint8 *buf; /**< Buffer items are stored into */
    uint16 head;         /**< Index of the next item to remove */
    uint16 tail;         /**< Index where the next item will get inserted */
    uint16 size;         /**< Buffer capacity minus one */
} ring_buffer;

/**
 * Initialise a ring buffer.
 *
 *  @param rb   Instance to initialise
 *
 *  @param size Number of items in buf.  The ring buffer will always
 *              leave one element unoccupied, so the maximum number of
 *              elements it can store will be size - 1.  Thus, size
 *              must be at least 2.
 *
 *  @param buf  Buffer to store items into
 */
static inline void rb_init(ring_buffer *rb, uint16 size, uint8 *buf) {
    rb->head = 0;
    rb->tail = 0;
    rb->size = size - 1;
    rb->buf = buf;
}

/**
 * @brief Return the number of elements stored in the ring buffer.
 * @param rb Buffer whose elements to count.
 */
static inline uint16 rb_full_count(ring_buffer *rb) {
    __io ring_buffer *arb = rb;
    int32 size = arb->tail - arb->head;
    if (arb->tail < arb->head) {
        size += arb->size + 1;
    }
    return (uint16)size;
}

/**
 * @brief Returns true if and only if the ring buffer is full.
 * @param rb Buffer to test.
 */
static inline int rb_is_full(ring_buffer *rb) {
    return (rb->tail + 1 == rb->head) ||
        (rb->tail == rb->size && rb->head == 0);
}

/**
 * @brief Returns true if and only if the ring buffer is empty.
 * @param rb Buffer to test.
 */
static inline int rb_is_empty(ring_buffer *rb) {
    return rb->head == rb->tail;
}

/**
 * Append element onto the end of a ring buffer.
 * @param rb Buffer to append onto.
 * @param element Value to append.
 */
static inline void rb_insert(ring_buffer *rb, uint8 element) {
    rb->buf[rb->tail] = element;
    rb->tail = (rb->tail == rb->size) ? 0 : rb->tail + 1;
}

/**
 * @brief Remove and return the first item from a ring buffer.
 * @param rb Buffer to remove from, must contain at least one element.
 */
static inline uint8 rb_remove(ring_buffer *rb) {
    uint8 ch = rb->buf[rb->head];
    rb->head = (rb->head == rb->size) ? 0 : rb->head + 1;
    return ch;
}

/*
 * Roger Clark. 20141125, 
 * added peek function.
 * @brief Return the first item from a ring buffer, without removing it
 * @param rb Buffer to remove from, must contain at least one element.
 */

static inline int rb_peek(ring_buffer *rb) 
{  
	if (rb->head == rb->tail)
	{
		return -1;
	}
	else
	{
		return rb->buf[rb->head];
	}
}


/**
 * @brief Attempt to remove the first item from a ring buffer.
 *
 * If the ring buffer is nonempty, removes and returns its first item.
 * If it is empty, does nothing and returns a negative value.
 *
 * @param rb Buffer to attempt to remove from.
 */
static inline int16 rb_safe_remove(ring_buffer *rb) {
    return rb_is_empty(rb) ? -1 : rb_remove(rb);
}

/**
 * @brief Attempt to insert an element into a ring buffer.
 *
 * @param rb Buffer to insert into.
 * @param element Value to insert into rb.
 * @sideeffect If rb is not full, appends element onto buffer.
 * @return If element was appended, then true; otherwise, false. */
static inline int rb_safe_insert(ring_buffer *rb, uint8 element) {
    if (rb_is_full(rb)) {
        return 0;
    }
    rb_insert(rb, element);
    return 1;
}

/**
 * @brief Append an item onto the end of a non-full ring buffer.
 *
 * If the buffer is full, removes its first item, then inserts the new
 * element at the end.
 *
 * @param rb Ring buffer to insert into.
 * @param element Value to insert into ring buffer.
 * @return On success, returns -1.  If an element was popped, returns
 *         the popped value.
 */
static inline int rb_push_insert(ring_buffer *rb, uint8 element) {
    int ret = -1;
    if (rb_is_full(rb)) {
        ret = rb_remove(rb);
    }
    rb_insert(rb, element);
    return ret;
}

/**
 * @brief Discard all items from a ring buffer.
 * @param rb Ring buffer to discard all items from.
 */
static inline void rb_reset(ring_buffer *rb) {
    rb->tail = rb->head;
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif
