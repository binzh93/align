CC = g++

CFLAGS += -std=c++11  -g -O3 -Wall
INC += -I. `pkg-config --cflags opencv`
LIBS += `pkg-config --libs opencv`

TARGET = main.bin
OBJS += test.o#align.o  #main.o

all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(INC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)
$(OBJS):%.o:%.cpp
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm -r *.o $(TARGET)
