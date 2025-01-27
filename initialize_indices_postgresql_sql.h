// Copyright 2011-2019 Google LLC. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INITIALIZE_INDICES_POSTGRESQL_SQL_H_
#define INITIALIZE_INDICES_POSTGRESQL_SQL_H_

#include "third_party/absl/strings/string_view.h"

inline absl::string_view GetPostgreSqlInitializeIndices() {
  static constexpr char kPostgreSqlInitializeIndices[] = R"raw(
CREATE UNIQUE INDEX "ex_?_functions_address_idx"
    ON "ex_?_functions" ("address");

CREATE UNIQUE INDEX "ex_?_basic_blocks_id_idx" ON "ex_?_basic_blocks" ("id");

CREATE INDEX "ex_?_basic_blocks_address_idx"
    ON "ex_?_basic_blocks" ("address");

CREATE UNIQUE INDEX "ex_?_instructions_address_idx"
    ON "ex_?_instructions" ("address");
CREATE UNIQUE INDEX "ex_?_expression_trees_id_idx"
    ON "ex_?_expression_trees" ("id");
CREATE UNIQUE INDEX "ex_?_expression_nodes_id_idx"
    ON "ex_?_expression_nodes" ("id");
)raw";
  return kPostgreSqlInitializeIndices;
}

#endif  // INITIALIZE_INDICES_POSTGRESQL_SQL_H_
