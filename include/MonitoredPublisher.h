#pragma once

#include <EventListener.h>
#include <capnzero/Publisher.h>

class MonitoredPublisher
{
public:
  explicit MonitoredPublisher(void* zmqContext, EventListener* listener);

  ~MonitoredPublisher();

  void bind(capnzero::CommType commType, const std::string& address);

  void send(const std::string& message, const std::string& groupName);

private:
  capnzero::Publisher publisher;
  EventListener* eventListener;
};
