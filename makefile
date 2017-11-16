MAIN=src/main.cpp
SRCS := $(filter-out $(MAIN),$(wildcard src/*.cpp))
CFLAGS=-g -I src/

all:
	g++ -o id-test $(CFLAGS) ${SRCS} ${MAIN}

%test:
	cxxtestgen --runner=ErrorPrinter -o test/test-runner.cpp test/$@.cpp ${SRCS}
	g++ ${CFLAGS} test/test-runner.cpp -o test-runner
	./test-runner

run: all
	./id-test
