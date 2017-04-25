////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2016 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Jan Christoph Uhde
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGODB_APPLICATION_FEATURES_ROCKSDB_OPTION_FEATURE_H
#define ARANGODB_APPLICATION_FEATURES_ROCKSDB_OPTION_FEATURE_H 1

#include "ApplicationFeatures/ApplicationFeature.h"
#include "Basics/Common.h"
#include "VocBase/voc-types.h"

namespace arangodb {

// This feature is used to configure RocksDB in a central place.
//
// The RocksDB-Storage-Engine and the MMFiles-Persistent-Index
// that are never activated at the same time take options set
// in this feature

class RocksDBOptionFeature final : public application_features::ApplicationFeature {
 public:
  explicit RocksDBOptionFeature(application_features::ApplicationServer* server);
  ~RocksDBOptionFeature() {}

  void collectOptions(std::shared_ptr<options::ProgramOptions>) override final;
  void validateOptions(std::shared_ptr<options::ProgramOptions>) override final;
  void prepare() override final {};
  void start() override final {}
  void unprepare() override final {}

  uint64_t _writeBufferSize;
  uint64_t _maxWriteBufferNumber;
  uint64_t _delayedWriteRate;
  uint64_t _minWriteBufferNumberToMerge;
  uint64_t _numLevels;
  uint64_t _maxBytesForLevelBase;
  uint64_t _maxBytesForLevelMultiplier;
  uint64_t _baseBackgroundCompactions;
  uint64_t _maxBackgroundCompactions;
  uint64_t _maxLogFileSize;
  uint64_t _keepLogFileNum;
  uint64_t _recycleLogFileNum;
  uint64_t _logFileTimeToRoll;
  uint64_t _compactionReadaheadSize;
  bool _verifyChecksumsInCompaction;
  bool _optimizeFiltersForHits;
  bool _useDirectReads;
  bool _useDirectWrites;
  bool _skipCorrupted;
};

}

#endif
