// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#define ESCHER_DISALLOW_COPY(TypeName)                                         \
  TypeName(const TypeName&) = delete

#define ESCHER_DISALLOW_ASSIGN(TypeName)                                       \
  void operator=(const TypeName&) = delete

#define ESCHER_DISALLOW_COPY_AND_ASSIGN(TypeName)                              \
  TypeName(const TypeName&) = delete;                                          \
  void operator=(const TypeName&) = delete

#define ESCHER_DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName)                        \
  TypeName() = delete;                                                         \
  DISALLOW_COPY_AND_ASSIGN(TypeName)
