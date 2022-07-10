// Copyright 2022 Alexey Timin
#include <CLI/CLI.hpp>

#include <cstring>

#include "reduct_cli/app.h"

int main(int argc, char* argv[]) {
  auto app = reduct::cli::IApp::Build();
  std::vector<std::string> args(argc - 1);
  for (int i = 1; i < argc; ++i) {
    args[i - 1] = std::string(argv[i], std::strlen(argv[i]));
  }

  auto ret = app->Parse(std::move(args));
  if (ret > 0) {
    return ret;
  }
  return app->Run();
}
