// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#include "host/host_function_crypto/cryptomodule.h"
#include "host/host_function_crypto/cryptofunc.h"

namespace WasmEdge {
namespace Host {

/// Register your functions in module.
HostFuncCryptoModule::HostFuncCryptoModule()
    : ModuleInstance("host_function_crypto") {
  addHostFunc("host_function_crypto_set_key_no",
              std::make_unique<HostFuncCryptoSetKeyNo>(Env));
  addHostFunc("host_function_crypto_encrypt",
              std::make_unique<HostFuncCryptoEncrypt>(Env));
  addHostFunc("host_function_crypto_decrypt",
              std::make_unique<HostFuncCryptoDecrypt>(Env));
}

} // namespace Host
} // namespace WasmEdge
