//
// Created by sst on 24.06.19.
//

#include <iostream>
#include <thread>
#include <capnp/serialize.h>
#include <capnzero-base-msgs/string.capnp.h>
#include <capnzero/Common.h>
#include <event/Event.h>
#include <yaml-cpp/yaml.h>
#include "MonitorClient.h"

static void callback(capnp::FlatArrayMessageReader& reader)
{
  const std::string message = reader.getRoot<capnzero::String>().getString();

  std::cout << "MONITOR_CLIENT got event:" << std::endl << message << std::endl << std::endl;
}

MonitorClient::MonitorClient(void* zmqContext, const std::string& monitoringAddress, const std::string& monitoringGroup) :
  subscriber(zmqContext, monitoringGroup), monitoringAddress {monitoringAddress}, monitoringGroup {monitoringGroup}
{

}

void MonitorClient::start()
{
  subscriber.connect(capnzero::CommType::UDP, monitoringAddress);

  std::cout << "MONITOR_CLIENT connected to " << monitoringAddress << std::endl;

  subscriber.subscribe(&callback);
}
