#ifndef LOGSIM_USECASE_HPP_
#define LOGSIM_USECASE_HPP_

#include <memory>

class UsecaseInterface
{
public:
  virtual ~UsecaseInterface() = default;
  virtual std::string libID() =0;
  virtual std::string evaluate(int source_int)=0;
};

typedef std::unique_ptr<UsecaseInterface> UsecaseInterfaceCreateFunction();

#endif  // LOGSIM_USECASE_HPP_
