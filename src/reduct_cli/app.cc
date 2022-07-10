// Copyright 2022 Alexey Timin
#include "reduct_cli/app.h"


#include <CLI/CLI.hpp>
#include <fmt/format.h>

#include "reduct_cli/config.h"

namespace reduct::cli {

class App : public IApp {
 public:
  App() : app_{"CLI client for Reduct Storage"} {
    app_.add_flag("-v,--version", "Show version");
  }

  int Parse(std::vector<std::string>&& args) override {
    try {
      app_.parse(std::move(args));
    } catch (const CLI::ParseError &e) {
      return app_.exit(e);
    }

    return 0;
  }
  [[nodiscard]] int Run(std::ostream& os) const override {
    if (app_.count("--version")) {
      os << fmt::format("{}", kVersion);  // Just example. There is a better way - set_version_flag
      return 0;
    }

    return -1;
  }

  CLI::App app_;
};

std::unique_ptr<IApp> IApp::Build() { return std::make_unique<App>(); }

}  // namespace reduct::cli