//
//  Server.hpp
//  Content_Addressable_Network
//
//  Created by Shriram Joshi on 4/29/17.
//  Copyright © 2017 Balakrishna. All rights reserved.
//

#ifndef Server_hpp
#define Server_hpp

#include "Server_Session.hpp"
#include "Member.hpp"
#include <queue>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <boost/array.hpp>
#include <list>

using boost::asio::ip::tcp;

class Server
{
private:
    tcp::endpoint endpoint;
    tcp::acceptor acc;
    tcp::socket socket;
    std::list<std::pair<std::string, int>> member_list;
    void run(std::queue<q_elt>* mesQ);
    
public:
    Server(boost::asio::io_service& io_service, int port, std::queue<q_elt>* mesQ);
    Server(Server&) = delete;
    virtual ~Server(void);
    inline std::list<std::pair<std::string, int>> getMemberList(void) { return member_list; }
};

#endif /* Server_hpp */