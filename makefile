TARGET := server

# The C/C++ program compiler.
CC=gcc

# 编译器在编译时的参数设置,包含头文件路径设置
CFLAGS:=-Wall -O2 -g
CFLAGS+=-I $(shell pwd)

# 库文件添加
LDFLAGS:=
LDFLAGS+=-lstdc++ -lpthread

# 指定源程序存放位置
SRCDIRS:=.

# 设置程序中使用文件类型
SRCEXTS:=.cpp

# 设置运行程序名
PROGRAM:=hello

CFLAGS:=-Wall -O2 -g
CFLAGS+=-I $(shell pwd)

SOURCES=$(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*,$(SRCEXTS))))
OBJS=$(foreach x,$(SRCEXTS),$(patsubst %$(x),%.o,$(filter %$(x),$(SOURCES))))

.PHONY: all clean

%.o: %.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS) $(LDFLAGS)

all:
	@echo $(OBJS)

clean:
	rm -rf $(PROGRAM) *.o