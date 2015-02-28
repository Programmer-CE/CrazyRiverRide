// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PlayerIsCreated.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "PlayerIsCreated.pb.h"

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

const ::google::protobuf::Descriptor* PlayerIsCreated_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PlayerIsCreated_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_PlayerIsCreated_2eproto() {
  protobuf_AddDesc_PlayerIsCreated_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "PlayerIsCreated.proto");
  GOOGLE_CHECK(file != NULL);
  PlayerIsCreated_descriptor_ = file->message_type(0);
  static const int PlayerIsCreated_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerIsCreated, player_),
  };
  PlayerIsCreated_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      PlayerIsCreated_descriptor_,
      PlayerIsCreated::default_instance_,
      PlayerIsCreated_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerIsCreated, _has_bits_[0]),
      -1,
      -1,
      sizeof(PlayerIsCreated),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PlayerIsCreated, _internal_metadata_),
      -1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_PlayerIsCreated_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      PlayerIsCreated_descriptor_, &PlayerIsCreated::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_PlayerIsCreated_2eproto() {
  delete PlayerIsCreated::default_instance_;
  delete PlayerIsCreated_reflection_;
}

void protobuf_AddDesc_PlayerIsCreated_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025PlayerIsCreated.proto\"!\n\017PlayerIsCreat"
    "ed\022\016\n\006Player\030\001 \002(\010", 58);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "PlayerIsCreated.proto", &protobuf_RegisterTypes);
  PlayerIsCreated::default_instance_ = new PlayerIsCreated();
  PlayerIsCreated::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_PlayerIsCreated_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_PlayerIsCreated_2eproto {
  StaticDescriptorInitializer_PlayerIsCreated_2eproto() {
    protobuf_AddDesc_PlayerIsCreated_2eproto();
  }
} static_descriptor_initializer_PlayerIsCreated_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#ifndef _MSC_VER
const int PlayerIsCreated::kPlayerFieldNumber;
#endif  // !_MSC_VER

PlayerIsCreated::PlayerIsCreated()
  : ::google::protobuf::Message() , _internal_metadata_(NULL)  {
  SharedCtor();
  // @@protoc_insertion_point(constructor:PlayerIsCreated)
}

void PlayerIsCreated::InitAsDefaultInstance() {
}

PlayerIsCreated::PlayerIsCreated(const PlayerIsCreated& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:PlayerIsCreated)
}

void PlayerIsCreated::SharedCtor() {
  _cached_size_ = 0;
  player_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PlayerIsCreated::~PlayerIsCreated() {
  // @@protoc_insertion_point(destructor:PlayerIsCreated)
  SharedDtor();
}

void PlayerIsCreated::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PlayerIsCreated::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PlayerIsCreated::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PlayerIsCreated_descriptor_;
}

const PlayerIsCreated& PlayerIsCreated::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_PlayerIsCreated_2eproto();
  return *default_instance_;
}

PlayerIsCreated* PlayerIsCreated::default_instance_ = NULL;

PlayerIsCreated* PlayerIsCreated::New(::google::protobuf::Arena* arena) const {
  PlayerIsCreated* n = new PlayerIsCreated;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PlayerIsCreated::Clear() {
  player_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool PlayerIsCreated::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:PlayerIsCreated)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bool Player = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &player_)));
          set_has_player();
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
  // @@protoc_insertion_point(parse_success:PlayerIsCreated)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:PlayerIsCreated)
  return false;
#undef DO_
}

void PlayerIsCreated::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:PlayerIsCreated)
  // required bool Player = 1;
  if (has_player()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->player(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:PlayerIsCreated)
}

::google::protobuf::uint8* PlayerIsCreated::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:PlayerIsCreated)
  // required bool Player = 1;
  if (has_player()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->player(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:PlayerIsCreated)
  return target;
}

int PlayerIsCreated::ByteSize() const {
  int total_size = 0;

  // required bool Player = 1;
  if (has_player()) {
    total_size += 1 + 1;
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

void PlayerIsCreated::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const PlayerIsCreated* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PlayerIsCreated*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PlayerIsCreated::MergeFrom(const PlayerIsCreated& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_player()) {
      set_player(from.player());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void PlayerIsCreated::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PlayerIsCreated::CopyFrom(const PlayerIsCreated& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayerIsCreated::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void PlayerIsCreated::Swap(PlayerIsCreated* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PlayerIsCreated::InternalSwap(PlayerIsCreated* other) {
  std::swap(player_, other->player_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata PlayerIsCreated::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PlayerIsCreated_descriptor_;
  metadata.reflection = PlayerIsCreated_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
