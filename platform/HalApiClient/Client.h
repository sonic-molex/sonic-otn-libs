#pragma once
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "HalApi.h"
#include "HalApiData.h"


class Client
{
public:
    Client() : m_socket(new apache::thrift::transport::TSocket(DEF_THRIFT_ADDR, DEF_THRIFT_PORT)),
               m_transport(new apache::thrift::transport::TBufferedTransport(m_socket)),
               m_protocol(new apache::thrift::protocol::TBinaryProtocol(m_transport)),
               m_client(m_protocol)
    {
        m_transport->open();
    }

    ~Client()
    {
        m_transport->close();
    }

private:
    std::shared_ptr<apache::thrift::transport::TTransport> m_socket;
    std::shared_ptr<apache::thrift::transport::TTransport> m_transport;
    std::shared_ptr<apache::thrift::protocol::TProtocol> m_protocol;
public:
    HalApiClient m_client;
};