#ifndef _BUFFER_H_
#define _BUFFER_H_


#include <assert.h>
#include <string.h>
#include <arpa/inet.h>
//#include <unistd.h>  // ssize_t

//base type define
typedef unsigned char								uint8;
typedef signed char								int8;
typedef unsigned short int						uint16;
typedef short signed int							int16;
typedef unsigned int								uint32;
typedef int										int32;
typedef unsigned long long int				    uint64;
typedef long long signed int						int64;
typedef unsigned char								uint8_t;
typedef signed char								int8_t;
typedef unsigned short int						uint16_t;
typedef short signed int							int16_t;
typedef unsigned int								uint32_t;
typedef int										int32_t;
typedef unsigned long long int				    uint64_t;
typedef long long signed int						int64_t;

typedef float										fp32_t;
typedef double									fp64_t;

typedef uint8byte;
typedef uint16										hword;
typedef uint32										word;
typedef uint64										dword;

typedef int                                        portBASE_TYPE;
typedef unsigned int                              portuBASE_TYPE;

///
/// @code
/// +-------------------+------------------+------------------+
/// | prependable bytes |  readable bytes  |  writable bytes  |
/// |                   |     (CONTENT)    |                  |
/// +-------------------+------------------+------------------+
/// |                   |                  |                  |
/// 0      <=      readerIndex   <=   writerIndex    <=     size
/// @endcode

static const size_t kCheapPrepend = 8;
static const size_t kInitialSize = 1024;
const char kCRLF[] = "\r\n";

#define BUFFER_LEN    1024

struct buffer
{
	size_t readerIndex_;
	size_t writerIndex_;
	size_t size_;
	int8_t *buffer_;
};

int buffer_init(struct buffer *buffer, size_t size);

inline size_t buffer_readableBytes(struct buffer *buffer)
{
	return (buffer->writerIndex_ - buffer->readerIndex_);
}

inline size_t buffer_writableBytes(struct buffer *buffer)
{
	return (buffer->size_ - buffer->writerIndex_);
}

inline size_t buffer_prependableBytes(struct buffer *buffer)
{
	return (buffer->readerIndex_);
}

inline size_t buffer_peek(struct buffer *buffer)
{
	return (buffer->buffer_ + buffer->readerIndex_);
}

inline size_t buffer_retrieve(struct buffer *buffer, size_t len)
{
	if (len < buffer->readableBytes()){
		buffer->readerIndex_ += len;
	}else {
		buffer->retrieveAll();
	}
}

void buffer_retrieveInt32(struct buffer *buffer)
{
	retrieve(sizeof(int32_t));
}

void buffer_retrieveInt16(struct buffer *buffer)
{
	retrieve(sizeof(int16_t));
}

void buffer_retrieveInt8(struct buffer *buffer)
{
	retrieve(sizeof(int8_t));
}

void buffer_retrieveAll(struct buffer *buffer)
{
	buffer->readerIndex_ = kCheapPrepend;
	buffer->writerIndex_ = kCheapPrepend;
}


int buffer_append(struct buffer *buffer, const char* data, size_t len)
{
	if (buffer_ensureWritableBytes(buffer, len)){
		return -1;
	}
	strcpy(buffer_beginWrite(buffer), data, len);
	buffer_hasWritten(buffer, len);
}

void buffer_ensureWritableBytes(struct buffer *buffer, size_t len)
{
	if (buffer_writableBytes(buffer) < len){
		buffer_makeSpace(buffer, len);
	}
	assert(buffer_writableBytes(buffer) >= len);
}

char* buffer_beginWrite(struct buffer *buffer)
{ 
	return buffer_begin(buffer) + buffer->writerIndex_; 
}

void buffer_hasWritten(struct buffer *buffer, size_t len)
{
	assert(len <= buffer_writableBytes(buffer));
	buffer->writerIndex_ += len;
}

void buffer_unwrite(struct buffer *buffer, size_t len)
{
	assert(len <= buffer_readableBytes(buffer));
	buffer->writerIndex_ -= len;
}

///
/// Append int32_t using network endian
///
void buffer_appendInt32(struct buffer *buffer, int32_t x)
{
	int32_t be32 = htonl(x);
	buffer_append(buffer, &be32, sizeof be32);
}

void buffer_appendInt16(struct buffer *buffer, int16_t x)
{
	int16_t be16 = htons(x);
	buffer_append(buffer, &be16, sizeof be16);
}

void buffer_appendInt8(struct buffer *buffer, int8_t x)
{
	buffer_append(buffer, &x, sizeof x);
}

///
/// Read int32_t from network endian
///
/// Require: buf->readableBytes() >= sizeof(int32_t)
int32_t buffer_readInt32(struct buffer *buffer)
{
	int32_t result = buffer_peekInt32();
	buffer_retrieveInt32(buffer);
	return result;
}

int16_t buffer_readInt16(struct buffer *buffer)
{
	int16_t result = buffer_peekInt16();
	buffer_retrieveInt16(buffer);
	return result;
}

int8_t buffer_readInt8(struct buffer *buffer)
{
	int8_t result = buffer_peekInt8();
	buffer_retrieveInt8(buffer);
	return result;
}

///
/// Peek int32_t from network endian
///
/// Require: buf->readableBytes() >= sizeof(int32_t)
int32_t buffer_peekInt32(struct buffer *buffer) const
{
	assert(buffer->readableBytes() >= sizeof(int32_t));
	int32_t be32 = 0;
	memcpy(&be32, buffer_peek(buffer), sizeof be32);
	return ntohl(be32);
}

int16_t buffer_peekInt16(struct buffer *buffer) const
{
	assert(buffer->readableBytes() >= sizeof(int16_t));
	int16_t be16 = 0;
	memcpy(&be16, buffer_peek(buffer), sizeof be16);
	return ntohs(be16);
}

int8_t buffer_peekInt8(struct buffer *buffer) const
{
	assert(buffer->readableBytes() >= sizeof(int8_t));
	int8_t x = *buffer_peek(buffer);
	return x;
}

///
/// Prepend int32_t using network endian
///
void buffer_prependInt32(struct buffer *buffer, int32_t x)
{
	int32_t be32 = htonl(x);
	buffer_prepend(buffer, &be32, sizeof be32);
}

void buffer_prependInt16(struct buffer *buffer, int16_t x)
{
	int16_t be16 = htons(x);
	buffer_prepend(buffer, &be16, sizeof be16);
}

void buffer_prependInt8(struct buffer *buffer, int8_t x)
{
	buffer_prepend(buffer, &x, sizeof x);
}

void buffer_prepend(struct buffer *buffer, const char* data, size_t len)
{
	assert(len <= buffer_prependableBytes(buffer));
	buffer->readerIndex_ -= len;
	memmove(buffer_begin(buffer) + buffer->readerIndex_, data, len);
}

inline char* buffer_begin(struct buffer *buffer)
{ 
	return buffer->buffer_;
}

int buffer_makeSpace(struct buffer *buffer, size_t len)
{
	if (buffer_writableBytes(buffer) + buffer_prependableBytes(buffer) < len + kCheapPrepend){
		return -1;
	}else {
		// move readable data to the front, make space inside buffer
		assert(kCheapPrepend < buffer->readerIndex_);
		size_t readable = buffer_readableBytes(buffer);
		char *begin = buffer_begin(buffer);

		memmove(begin + buffer->kCheapPrepend,
				begin + buffer->readerIndex_, readable
				);
		buffer->readerIndex_ = kCheapPrepend;
		buffer->writerIndex_ = buffer->readerIndex_ + readable;
		assert(buffer->readable == buffer_readableBytes(buffer));
	}
}

#endif  
