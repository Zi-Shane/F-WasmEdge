// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#pragma once

#include "host/host_function_crypto/cryptoenv.h"
#include "runtime/instance/module.h"

#include <cstdint>

namespace WasmEdge {
namespace Host {

class HostFuncCryptoModule : public Runtime::Instance::ModuleInstance {
public:
  HostFuncCryptoModule();

  HostFuncCryptoEnvironment &getEnv() { return Env; }

private:
  HostFuncCryptoEnvironment Env;
};

} // namespace Host
} // namespace WasmEdge
