// Copyright 2022 Alexey Timin

#ifndef CLI_CLIENT_APP_H
#define CLI_CLIENT_APP_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace reduct::cli {

class IApp {
 public:
  virtual ~IApp() = default;

  virtual int Parse(std::vector<std::string>&& args) = 0;

  virtual int Run(std::ostream& os = std::cout) const = 0;

  static std::unique_ptr<IApp> Build();
};

}  // namespace reduct::cli

#endif  // CLI_CLIENT_APP_H
