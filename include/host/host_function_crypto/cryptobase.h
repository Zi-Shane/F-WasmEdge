// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#pragma once

#include "common/errcode.h"
#include "host/host_function_crypto/cryptoenv.h"
#include "runtime/hostfunc.h"

namespace WasmEdge {
namespace Host {

template <typename T> class HostFuncCrypto : public Runtime::HostFunction<T> {
public:
  HostFuncCrypto(HostFuncCryptoEnvironment &CryptoEnv)
      : Runtime::HostFunction<T>(0), Env(CryptoEnv) {}

protected:
  HostFuncCryptoEnvironment &Env;
};

} // namespace Host
} // namespace WasmEdge
