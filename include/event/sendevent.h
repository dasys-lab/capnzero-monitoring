#pragma once

#include <event/event.h>

class SendEvent : public Event
{
public:
  SendEvent();

  SendEvent(const std::string& id, const std::string& message);

  const std::string toYaml() const override;

private:
  std::string message;
};
