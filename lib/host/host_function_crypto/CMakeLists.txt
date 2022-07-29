# SPDX-License-Identifier: Apache-2.0
# SPDX-FileCopyrightText: 2019-2022 Second State INC

wasmedge_add_library(wasmedgeHostModuleHostHostFuncCrypto
  cryptofunc.cpp
  cryptomodule.cpp
)

target_link_libraries(wasmedgeHostModuleHostHostFuncCrypto
  PUBLIC
  wasmedgeCommon
  wasmedgeSystem
)
