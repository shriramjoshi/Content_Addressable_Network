#**********************
#*
#* Progam Name: CAN Protocol.
#*
#* Current file: Makefile
#* About this file: Build Script.
#* 

CFLAGS = -Wall -Wextra -std=c++11

DLLS = -lboost_system-mt -lboost_thread-mt -lboost_chrono-mt -lpthread 

MONGO_DLL = -lmongoc-1.0 -lbson-1.0

MONGO_HEADER = -I/usr/local/include/libmongoc-1.0 -I/usr/local/include/libbson-1.0

LOG_DLLS = -DBOOST_LOG_DYN_LINK -lboost_log-mt

all: can_server

can_server: zone.o memberlistentry.o member.o logger.o server_session.o server.o client.o file_processor.o
	g++ zone.o server_session.o server.o memberlistentry.o member.o client.o logger.o file_processor.o Node.cpp -o server ${MONGO_DLL} ${DLLS} ${LOG_DLLS} ${CFLAGS}

server_session.o: Server_Session.cpp Message.hpp
	g++ Server_Session.cpp -c -o server_session.o ${CFLAGS}

server.o: Server.hpp Server.cpp Message.hpp
	g++ Server.cpp -c -o server.o ${CFLAGS}

client.o: Client.hpp
	g++ Client.cpp -c -o client.o ${BOOST_SYSTEM} ${CFLAGS}

member.o: Member.cpp memberlistentry.o zone.o 
	g++ Member.cpp -c -o member.o ${CFLAGS}
	
memberlistentry.o: MemberListEntry.cpp MemberListEntry.hpp
	g++ MemberListEntry.cpp -c -o memberlistentry.o ${CFLAGS}
	
zone.o: Zone.cpp Zone.hpp
	g++ Zone.cpp -c -o zone.o ${CFLAGS}
	
logger.o: Logger.cpp Logger.hpp
	g++ Logger.cpp -c -o logger.o ${CFLAGS}


file_processor.o: FileProcessor.cpp FileProcessor.hpp
	g++ FileProcessor.cpp -c -o file_processor.o ${MONGO_HEADER} ${MONGO_DLL}

clean:
	rm *.o
	rm server

