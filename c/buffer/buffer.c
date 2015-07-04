#include <errno.h>:



int buffer_init(struct buffer *buffer, size_t size)
{
	buffer->readerIndex_ = kCheapPrepend;
	buffer->writerIndex_ = kCheapPrepend;
	buffer->size_ = size;

	buffer->buffer_ = (unsigned char *)malloc(size);

	if (NULL == buffer->buffer_){
		printf("buffer alloc failed!\n")
		return -1;
	}

	return 0;
}







