// DO NOT EDIT : This file is generated by chevron
/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

// This file is generated DO NOT EDIT @generated

#include <cstdint>
#include <map>
#include <regex>
#include <string>

#include "presto_cpp/external/json/nlohmann/json.hpp"
#include "presto_cpp/presto_protocol/core/presto_protocol_core.h"

namespace facebook::presto::protocol::hive {
enum class ColumnType { PARTITION_KEY, REGULAR, SYNTHESIZED, AGGREGATED };
extern void to_json(json& j, const ColumnType& e);
extern void from_json(const json& j, ColumnType& e);
} // namespace facebook::presto::protocol::hive
/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// HiveColumnHandle is special since it needs an implementation of
// operator<().

namespace facebook::presto::protocol::hive {

struct HiveColumnHandle : public ColumnHandle {
  String name = {};
  HiveType hiveType = {};
  TypeSignature typeSignature = {};
  int hiveColumnIndex = {};
  hive::ColumnType columnType = {};
  std::shared_ptr<String> comment = {};
  List<Subfield> requiredSubfields = {};
  std::shared_ptr<Aggregation> partialAggregation = {};

  HiveColumnHandle() noexcept;

  bool operator<(const ColumnHandle& o) const override {
    return name < dynamic_cast<const HiveColumnHandle&>(o).name;
  }
};

void to_json(json& j, const HiveColumnHandle& p);
void from_json(const json& j, HiveColumnHandle& p);

} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct BucketConversion {
  int tableBucketCount = {};
  int partitionBucketCount = {};
  List<HiveColumnHandle> bucketColumnHandles = {};
};
void to_json(json& j, const BucketConversion& p);
void from_json(const json& j, BucketConversion& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct DwrfEncryptionMetadata {
  Map<String, String> fieldToKeyData = {};
  Map<String, String> extraMetadata = {};
  String encryptionAlgorithm = {};
  String encryptionProvider = {};
};
void to_json(json& j, const DwrfEncryptionMetadata& p);
void from_json(const json& j, DwrfEncryptionMetadata& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct EncryptionInformation {
  std::shared_ptr<DwrfEncryptionMetadata> dwrfEncryptionMetadata = {};
};
void to_json(json& j, const EncryptionInformation& p);
void from_json(const json& j, EncryptionInformation& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveBucketFilter {
  List<Integer> bucketsToKeep = {};
};
void to_json(json& j, const HiveBucketFilter& p);
void from_json(const json& j, HiveBucketFilter& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveBucketHandle {
  List<HiveColumnHandle> columns = {};
  int tableBucketCount = {};
  int readBucketCount = {};
};
void to_json(json& j, const HiveBucketHandle& p);
void from_json(const json& j, HiveBucketHandle& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
enum class BucketFunctionType { HIVE_COMPATIBLE, PRESTO_NATIVE };
extern void to_json(json& j, const BucketFunctionType& e);
extern void from_json(const json& j, BucketFunctionType& e);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
enum class Order { ASCENDING, DESCENDING };
extern void to_json(json& j, const Order& e);
extern void from_json(const json& j, Order& e);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct SortingColumn {
  String columnName = {};
  Order order = {};
};
void to_json(json& j, const SortingColumn& p);
void from_json(const json& j, SortingColumn& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveBucketProperty {
  List<String> bucketedBy = {};
  int bucketCount = {};
  List<SortingColumn> sortedBy = {};
  BucketFunctionType bucketFunctionType = {};
  std::shared_ptr<List<Type>> types = {};
};
void to_json(json& j, const HiveBucketProperty& p);
void from_json(const json& j, HiveBucketProperty& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveFileSplit {
  String path = {};
  int64_t start = {};
  int64_t length = {};
  int64_t fileSize = {};
  int64_t fileModifiedTime = {};
  std::shared_ptr<String> extraFileInfo = {};
  Map<String, String> customSplitInfo = {};
  int64_t affinitySchedulingFileSectionIndex = {};
};
void to_json(json& j, const HiveFileSplit& p);
void from_json(const json& j, HiveFileSplit& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
enum class HiveCompressionCodec { NONE, SNAPPY, GZIP, LZ4, ZSTD };
extern void to_json(json& j, const HiveCompressionCodec& e);
extern void from_json(const json& j, HiveCompressionCodec& e);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
enum class PrestoTableType {
  MANAGED_TABLE,
  EXTERNAL_TABLE,
  VIRTUAL_VIEW,
  MATERIALIZED_VIEW,
  TEMPORARY_TABLE,
  OTHER
};
extern void to_json(json& j, const PrestoTableType& e);
extern void from_json(const json& j, PrestoTableType& e);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct StorageFormat {
  String serDe = {};
  String inputFormat = {};
  String outputFormat = {};
};
void to_json(json& j, const StorageFormat& p);
void from_json(const json& j, StorageFormat& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct Storage {
  StorageFormat storageFormat = {};
  String location = {};
  std::shared_ptr<HiveBucketProperty> bucketProperty = {};
  bool skewed = {};
  Map<String, String> serdeParameters = {};
  Map<String, String> parameters = {};
};
void to_json(json& j, const Storage& p);
void from_json(const json& j, Storage& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct Table {
  String databaseName = {};
  String tableName = {};
  String owner = {};
  PrestoTableType tableType = {};
  Storage storage = {};
  List<Column> dataColumns = {};
  List<Column> partitionColumns = {};
  Map<String, String> parameters = {};
  std::shared_ptr<String> viewOriginalText = {};
  std::shared_ptr<String> viewExpandedText = {};
};
void to_json(json& j, const Table& p);
void from_json(const json& j, Table& p);
} // namespace facebook::presto::protocol::hive
/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// dependency Table
// dependency SchemaTableName

namespace facebook::presto::protocol::hive {

struct HivePageSinkMetadata {
  SchemaTableName schemaTableName = {};
  std::shared_ptr<hive::Table> table = {};
  // TODO Add modifiedPartitions
};
void to_json(json& j, const HivePageSinkMetadata& p);
void from_json(const json& j, HivePageSinkMetadata& p);

} // namespace facebook::presto::protocol::hive
/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

namespace facebook::presto::protocol::hive {

enum class HiveStorageFormat {
  ORC,
  DWRF,
  ALPHA,
  PARQUET,
  AVRO,
  RCBINARY,
  RCTEXT,
  SEQUENCEFILE,
  JSON,
  TEXTFILE,
  CSV,
  PAGEFILE
};

void to_json(json& j, const HiveStorageFormat& p);
void from_json(const json& j, HiveStorageFormat& p);

} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
enum class TableType { NEW, EXISTING, TEMPORARY };
extern void to_json(json& j, const TableType& e);
extern void from_json(const json& j, TableType& e);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
enum class WriteMode {
  STAGE_AND_MOVE_TO_TARGET_DIRECTORY,
  DIRECT_TO_TARGET_NEW_DIRECTORY,
  DIRECT_TO_TARGET_EXISTING_DIRECTORY
};
extern void to_json(json& j, const WriteMode& e);
extern void from_json(const json& j, WriteMode& e);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct LocationHandle {
  String targetPath = {};
  String writePath = {};
  std::shared_ptr<String> tempPath = {};
  TableType tableType = {};
  WriteMode writeMode = {};
};
void to_json(json& j, const LocationHandle& p);
void from_json(const json& j, LocationHandle& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveInsertTableHandle : public ConnectorInsertTableHandle {
  String schemaName = {};
  String tableName = {};
  List<HiveColumnHandle> inputColumns = {};
  HivePageSinkMetadata pageSinkMetadata = {};
  LocationHandle locationHandle = {};
  std::shared_ptr<HiveBucketProperty> bucketProperty = {};
  List<SortingColumn> preferredOrderingColumns = {};
  HiveStorageFormat tableStorageFormat = {};
  HiveStorageFormat partitionStorageFormat = {};
  HiveStorageFormat actualStorageFormat = {};
  HiveCompressionCodec compressionCodec = {};
  std::shared_ptr<EncryptionInformation> encryptionInformation = {};

  HiveInsertTableHandle() noexcept;
};
void to_json(json& j, const HiveInsertTableHandle& p);
void from_json(const json& j, HiveInsertTableHandle& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveMetadataUpdateHandle : public ConnectorMetadataUpdateHandle {
  UUID requestId = {};
  SchemaTableName schemaTableName = {};
  std::shared_ptr<String> partitionName = {};
  std::shared_ptr<String> fileName = {};

  HiveMetadataUpdateHandle() noexcept;
};
void to_json(json& j, const HiveMetadataUpdateHandle& p);
void from_json(const json& j, HiveMetadataUpdateHandle& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveOutputTableHandle : public ConnectorOutputTableHandle {
  String schemaName = {};
  String tableName = {};
  List<HiveColumnHandle> inputColumns = {};
  HivePageSinkMetadata pageSinkMetadata = {};
  LocationHandle locationHandle = {};
  HiveStorageFormat tableStorageFormat = {};
  HiveStorageFormat partitionStorageFormat = {};
  HiveStorageFormat actualStorageFormat = {};
  HiveCompressionCodec compressionCodec = {};
  List<String> partitionedBy = {};
  std::shared_ptr<HiveBucketProperty> bucketProperty = {};
  List<SortingColumn> preferredOrderingColumns = {};
  String tableOwner = {};
  Map<String, String> additionalTableParameters = {};
  std::shared_ptr<EncryptionInformation> encryptionInformation = {};

  HiveOutputTableHandle() noexcept;
};
void to_json(json& j, const HiveOutputTableHandle& p);
void from_json(const json& j, HiveOutputTableHandle& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HivePartitionKey {
  String name = {};
  std::shared_ptr<String> value = {};
};
void to_json(json& j, const HivePartitionKey& p);
void from_json(const json& j, HivePartitionKey& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HivePartitioningHandle : public ConnectorPartitioningHandle {
  int bucketCount = {};
  std::shared_ptr<int> maxCompatibleBucketCount = {};
  BucketFunctionType bucketFunctionType = {};
  std::shared_ptr<List<HiveType>> hiveTypes = {};
  std::shared_ptr<List<Type>> types = {};

  HivePartitioningHandle() noexcept;
};
void to_json(json& j, const HivePartitioningHandle& p);
void from_json(const json& j, HivePartitioningHandle& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct TableToPartitionMapping {
  std::shared_ptr<Map<Integer, Integer>> tableToPartitionColumns = {};
  Map<Integer, Column> partitionSchemaDifference = {};
};
void to_json(json& j, const TableToPartitionMapping& p);
void from_json(const json& j, TableToPartitionMapping& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveSplit : public ConnectorSplit {
  HiveFileSplit fileSplit = {};
  String database = {};
  String table = {};
  String partitionName = {};
  Storage storage = {};
  List<HivePartitionKey> partitionKeys = {};
  List<HostAddress> addresses = {};
  std::shared_ptr<int> readBucketNumber = {};
  std::shared_ptr<int> tableBucketNumber = {};
  NodeSelectionStrategy nodeSelectionStrategy = {};
  int partitionDataColumnCount = {};
  TableToPartitionMapping tableToPartitionMapping = {};
  std::shared_ptr<BucketConversion> bucketConversion = {};
  bool s3SelectPushdownEnabled = {};
  CacheQuotaRequirement cacheQuota = {};
  std::shared_ptr<EncryptionInformation> encryptionMetadata = {};
  List<std::shared_ptr<ColumnHandle>> redundantColumnDomains = {};
  SplitWeight splitWeight = {};
  std::shared_ptr<String> rowIdPartitionComponent = {};

  HiveSplit() noexcept;
};
void to_json(json& j, const HiveSplit& p);
void from_json(const json& j, HiveSplit& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveTableHandle : public ConnectorTableHandle {
  String schemaName = {};
  String tableName = {};
  std::shared_ptr<List<List<String>>> analyzePartitionValues = {};

  HiveTableHandle() noexcept;
};
void to_json(json& j, const HiveTableHandle& p);
void from_json(const json& j, HiveTableHandle& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveTableLayoutHandle : public ConnectorTableLayoutHandle {
  SchemaTableName schemaTableName = {};
  String tablePath = {};
  List<HiveColumnHandle> partitionColumns = {};
  List<Column> dataColumns = {};
  Map<String, String> tableParameters = {};
  TupleDomain<Subfield> domainPredicate = {};
  std::shared_ptr<RowExpression> remainingPredicate = {};
  Map<String, HiveColumnHandle> predicateColumns = {};
  TupleDomain<std::shared_ptr<ColumnHandle>> partitionColumnPredicate = {};
  std::shared_ptr<HiveBucketHandle> bucketHandle = {};
  std::shared_ptr<HiveBucketFilter> bucketFilter = {};
  bool pushdownFilterEnabled = {};
  String layoutString = {};
  std::shared_ptr<List<HiveColumnHandle>> requestedColumns = {};
  bool partialAggregationsPushedDown = {};
  bool appendRowNumber = {};
  bool footerStatsUnreliable = {};

  HiveTableLayoutHandle() noexcept;
};
void to_json(json& j, const HiveTableLayoutHandle& p);
void from_json(const json& j, HiveTableLayoutHandle& p);
} // namespace facebook::presto::protocol::hive
namespace facebook::presto::protocol::hive {
struct HiveTransactionHandle : public ConnectorTransactionHandle {
  UUID uuid = {};

  HiveTransactionHandle() noexcept;
};
void to_json(json& j, const HiveTransactionHandle& p);
void from_json(const json& j, HiveTransactionHandle& p);
} // namespace facebook::presto::protocol::hive