# Tên tệp thực thi
TARGET = BINARY_TREE

# Thư mục chứa tệp nguồn và header
SRC_DIR = src
INC_DIR = include

# Tệp nguồn và tệp đối tượng
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Trình biên dịch và cờ biên dịch
CC = gcc
CFLAGS = -I$(INC_DIR) -Wall -g

# Quy tắc mặc định
all: $(TARGET)

# Tạo chương trình thực thi từ các tệp .o
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Biên dịch từng tệp .c thành .o trong thư mục src/
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dọn dẹp các tệp đối tượng và tệp thực thi
clean:
	del /Q src\*.o $(TARGET)

# Phony targets
.PHONY: all clean
