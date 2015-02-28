// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PlayerStatus.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "PlayerStatus.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* PlayerStatus_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PlayerStatus_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_PlayerStatus_2eproto() {
  protobuf_AddDesc_PlayerStatus_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "PlayerStatus.proto");
  GOOGLE_CHECK(file != NULL);
  PlayerStatus_descriptor_ = file->message_type(0);
  static const int PlayerStatus_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerStatus, num_of_player_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerStatus, playerpoints_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerStatus, isdead_),
  };
  PlayerStatus_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      PlayerStatus_descriptor_,
      PlayerStatus::default_instance_,
      PlayerStatus_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerStatus, _has_bits_[0]),
      -1,
      -1,
      sizeof(PlayerStatus),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerStatus, _internal_metadata_),
      -1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_PlayerStatus_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      PlayerStatus_descriptor_, &PlayerStatus::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_PlayerStatus_2eproto() {
  delete PlayerStatus::default_instance_;
  delete PlayerStatus_reflection_;
}

void protobuf_AddDesc_PlayerStatus_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022PlayerStatus.proto\"K\n\014PlayerStatus\022\025\n\r"
    "NUM_OF_PLAYER\030\001 \002(\005\022\024\n\014playerPoints\030\002 \002("
    "\005\022\016\n\006isDead\030\003 \002(\010", 97);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "PlayerStatus.proto", &protobuf_RegisterTypes);
  PlayerStatus::default_instance_ = new PlayerStatus();
  PlayerStatus::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_PlayerStatus_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_PlayerStatus_2eproto {
  StaticDescriptorInitializer_PlayerStatus_2eproto() {
    protobuf_AddDesc_PlayerStatus_2eproto();
  }
} static_descriptor_initializer_PlayerStatus_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#ifndef _MSC_VER
const int PlayerStatus::kNUMOFPLAYERFieldNumber;
const int PlayerStatus::kPlayerPointsFieldNumber;
const int PlayerStatus::kIsDeadFieldNumber;
#endif  // !_MSC_VER

PlayerStatus::PlayerStatus()
  : ::google::protobuf::Message() , _internal_metadata_(NULL)  {
  SharedCtor();
  // @@protoc_insertion_point(constructor:PlayerStatus)
}

void PlayerStatus::InitAsDefaultInstance() {
}

PlayerStatus::PlayerStatus(const PlayerStatus& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:PlayerStatus)
}

void PlayerStatus::SharedCtor() {
  _cached_size_ = 0;
  num_of_player_ = 0;
  playerpoints_ = 0;
  isdead_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PlayerStatus::~PlayerStatus() {
  // @@protoc_insertion_point(destructor:PlayerStatus)
  SharedDtor();
}

void PlayerStatus::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PlayerStatus::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PlayerStatus::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PlayerStatus_descriptor_;
}

const PlayerStatus& PlayerStatus::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_PlayerStatus_2eproto();
  return *default_instance_;
}

PlayerStatus* PlayerStatus::default_instance_ = NULL;

PlayerStatus* PlayerStatus::New(::google::protobuf::Arena* arena) const {
  PlayerStatus* n = new PlayerStatus;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PlayerStatus::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<PlayerStatus*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(num_of_player_, isdead_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool PlayerStatus::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PlayerStatus)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 NUM_OF_PLAYER = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &num_of_player_)));
          set_has_num_of_player();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_playerPoints;
        break;
      }

      // required int32 playerPoints = 2;
      case 2: {
        if (tag == 16) {
         parse_playerPoints:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &playerpoints_)));
          set_has_playerpoints();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_isDead;
        break;
      }

      // required bool isDead = 3;
      case 3: {
        if (tag == 24) {
         parse_isDead:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &isdead_)));
          set_has_isdead();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:PlayerStatus)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PlayerStatus)
  return false;
#undef DO_
}

void PlayerStatus::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PlayerStatus)
  // required int32 NUM_OF_PLAYER = 1;
  if (has_num_of_player()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->num_of_player(), output);
  }

  // required int32 playerPoints = 2;
  if (has_playerpoints()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->playerpoints(), output);
  }

  // required bool isDead = 3;
  if (has_isdead()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(3, this->isdead(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:PlayerStatus)
}

::google::protobuf::uint8* PlayerStatus::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:PlayerStatus)
  // required int32 NUM_OF_PLAYER = 1;
  if (has_num_of_player()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->num_of_player(), target);
  }

  // required int32 playerPoints = 2;
  if (has_playerpoints()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->playerpoints(), target);
  }

  // required bool isDead = 3;
  if (has_isdead()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(3, this->isdead(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PlayerStatus)
  return target;
}

int PlayerStatus::RequiredFieldsByteSizeFallback() const {
  int total_size = 0;

  if (has_num_of_player()) {
    // required int32 NUM_OF_PLAYER = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->num_of_player());
  }

  if (has_playerpoints()) {
    // required int32 playerPoints = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->playerpoints());
  }

  if (has_isdead()) {
    // required bool isDead = 3;
    total_size += 1 + 1;
  }

  return total_size;
}
int PlayerStatus::ByteSize() const {
  int total_size = 0;

  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required int32 NUM_OF_PLAYER = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->num_of_player());

    // required int32 playerPoints = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->playerpoints());

    // required bool isDead = 3;
    total_size += 1 + 1;

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PlayerStatus::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const PlayerStatus* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PlayerStatus*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PlayerStatus::MergeFrom(const PlayerStatus& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_num_of_player()) {
      set_num_of_player(from.num_of_player());
    }
    if (from.has_playerpoints()) {
      set_playerpoints(from.playerpoints());
    }
    if (from.has_isdead()) {
      set_isdead(from.isdead());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void PlayerStatus::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PlayerStatus::CopyFrom(const PlayerStatus& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayerStatus::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void PlayerStatus::Swap(PlayerStatus* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PlayerStatus::InternalSwap(PlayerStatus* other) {
  std::swap(num_of_player_, other->num_of_player_);
  std::swap(playerpoints_, other->playerpoints_);
  std::swap(isdead_, other->isdead_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PlayerStatus::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PlayerStatus_descriptor_;
  metadata.reflection = PlayerStatus_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
