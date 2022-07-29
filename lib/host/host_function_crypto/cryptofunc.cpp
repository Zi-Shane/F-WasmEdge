// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#include "host/host_function_crypto/cryptofunc.h"

#include <iostream>

namespace WasmEdge {
namespace Host {

Expect<void> HostFuncCryptoSetKeyNo::body(
    [[maybe_unused]] Runtime::Instance::MemoryInstance *MemInst, uint32_t Key) {
  Env.KeyNo = Key;
  return {};
}

Expect<void> HostFuncCryptoEncrypt::body(Runtime::Instance::MemoryInstance *MemInst, 
                                            uint32_t ContentPtr, 
                                            uint32_t ContentLen) {
  // Check memory instance from module.
  if (MemInst == nullptr) {
    return Unexpect(ErrCode::ExecutionFailed);
  }

  char *Content = MemInst->getPointer<char *>(ContentPtr);
  std::cout << Content << std::endl;
  std::string CipheredText = "";
  for (uint32_t i = 0; i < ContentLen; i++) {
    char shift = ((Content[i] - 33 + Env.KeyNo) % 94) + 33;
    CipheredText.push_back(shift);
  }

  std::cout << CipheredText << std::endl;
  return {};
}

Expect<void> HostFuncCryptoDecrypt::body(Runtime::Instance::MemoryInstance *MemInst, 
                                            uint32_t ContentPtr, 
                                            uint32_t ContentLen) {
  // Check memory instance from module.
  if (MemInst == nullptr) {
    return Unexpect(ErrCode::ExecutionFailed);
  }

  char *Content = MemInst->getPointer<char *>(ContentPtr);
  std::cout << Content << std::endl;
  std::string PlainText = "";
  for (uint32_t i = 0; i < ContentLen; i++) {
    int shift = Env.KeyNo % 94;
    if (shift > (Content[i] - 33)) {
      PlainText.push_back(127 - (shift - (Content[i] - 33)));
    } else {
      PlainText.push_back(Content[i] - shift);
    }
  }

  std::cout << PlainText << std::endl;
  return {};
}

// Expect<void> HostFuncCryptoDo::body([
//     [maybe_unused]] Runtime::Instance::MemoryInstance *MemInst) {
//   std::cout << "-" << Env.Content << "-" << std::endl;
//   return {};
// }

// Expect<uint32_t>
// HostFuncExampleAddStudent::body(Runtime::Instance::MemoryInstance *MemInst,
//                                 uint32_t StudentPtr, uint32_t StudentLen) {
//   // Check memory instance from module.
//   if (MemInst == nullptr) {
//     return Unexpect(ErrCode::ExecutionFailed);
//   }

//   char *Student = MemInst->getPointer<char *>(StudentPtr);
//   std::string NewStudent;
//   std::copy_n(Student, StudentLen, std::back_inserter(NewStudent));
//   Env.Students.push_back(std::move(NewStudent));
//   return Env.Students.size();
// }

// Expect<void>
// HostFuncExampleSetClassName::body(Runtime::Instance::MemoryInstance *MemInst,
//                                   uint32_t ClassNamePtr,
//                                   uint32_t ClassNameLen) {
//   // Check memory instance from module.
//   if (MemInst == nullptr) {
//     return Unexpect(ErrCode::ExecutionFailed);
//   }

//   char *ClassName = MemInst->getPointer<char *>(ClassNamePtr);
//   std::string NewClassName;
//   std::copy_n(ClassName, ClassNameLen, std::back_inserter(NewClassName));
//   Env.ClassName = std::move(NewClassName);
//   return {};
// }

// Expect<void> HostFuncExamplePrint::body([
//     [maybe_unused]] Runtime::Instance::MemoryInstance *MemInst) {
//   std::cout << "Class ID: " << Env.ClassID << std::endl;
//   std::cout << "Class Name: " << Env.ClassName << std::endl;
//   for (auto &Student : Env.Students) {
//     std::cout << "Student: " << Student << std::endl;
//   }
//   return {};
// }

} // namespace Host
} // namespace WasmEdge
