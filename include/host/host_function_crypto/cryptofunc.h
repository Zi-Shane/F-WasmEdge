// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#pragma once

#include "common/defines.h"
#include "host/host_function_crypto/cryptobase.h"

namespace WasmEdge {
namespace Host {

class HostFuncCryptoSetKeyNo
    : public HostFuncCrypto<HostFuncCryptoSetKeyNo> {
public:
  HostFuncCryptoSetKeyNo(HostFuncCryptoEnvironment &CryptoEnv)
      : HostFuncCrypto(CryptoEnv) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst, uint32_t Key);
};

class HostFuncCryptoEncrypt
    : public HostFuncCrypto<HostFuncCryptoEncrypt> {
public:
  HostFuncCryptoEncrypt(HostFuncCryptoEnvironment &CryptoEnv)
      : HostFuncCrypto(CryptoEnv) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst,
                    uint32_t ContentPtr, uint32_t ContentLen);
};

class HostFuncCryptoDecrypt
    : public HostFuncCrypto<HostFuncCryptoDecrypt> {
public:
  HostFuncCryptoDecrypt(HostFuncCryptoEnvironment &CryptoEnv)
      : HostFuncCrypto(CryptoEnv) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst,
                    uint32_t ContentPtr, uint32_t ContentLen);
};

} // namespace Host
} // namespace WasmEdge
