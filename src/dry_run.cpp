#include <iostream>
#include <memory>
#include <string>

#include "usecase.hpp"

class DryRun : public UsecaseInterface
{
public:
  DryRun()
  {
    std::cout << "DryRun was create." << std::endl;
  }
  ~DryRun()
  {
    std::cout << "DryRun delete." << std::endl;
  }
  std::string libID() override
  {
    return "dry_run";
  }

  std::string evaluate(int source_int) override
  {
    return "evaluate get: " + std::to_string(source_int);
  }
};
extern "C"
{
  std::unique_ptr<UsecaseInterface> makeObject()
  {
    return std::unique_ptr<UsecaseInterface>(new DryRun);
  }
}
