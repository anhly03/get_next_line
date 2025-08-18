#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[BUFFER_SIZE];
	ssize_t		bytes_read;
	char		*line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while //true??
		if
}

function get_next_line(fd):
	static leftover = NULL   // giữ phần dư từ lần trước
	if fd < 0 or BUFFER_SIZE <= 0:
		return NULL
	while true:
		if leftover có chứa '\n':
			// Tìm vị trí \n
			// Cắt từ đầu đến \n => line_to_return
			// Phần sau \n => cập nhật leftover
			return line_to_return

		// Nếu không có \n, đọc thêm dữ liệu
		bytes_read = read(fd, buffer, BUFFER_SIZE)
		if bytes_read == -1:
			// Lỗi khi đọc
			return NULL

		if bytes_read == 0:
			// Hết file
			if leftover không rỗng:
				line_to_return = leftover
				leftover = NULL
				return line_to_return
			else:
				return NULL

		// Ghép buffer vừa đọc vào leftover
		leftover = leftover + buffer
