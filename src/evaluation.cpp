#include <dlfcn.h>

#include <iostream>

#include "usecase.hpp"

int main(int argc, char** argv)
{
  const auto usecase_lib = dlopen("./libUsecaseDryRun.so", RTLD_LAZY);
  auto usecase_func = (UsecaseInterfaceCreateFunction*)(dlsym(usecase_lib, "makeObject"));

  int source_int = 334;
  {
    const auto& usecase = usecase_func();
    std::cout << "lib = " << usecase->libID() << std::endl;
    std::cout << "evaluate = " << usecase->evaluate(source_int) << std::endl;
  }
  dlclose(usecase_lib);
}
