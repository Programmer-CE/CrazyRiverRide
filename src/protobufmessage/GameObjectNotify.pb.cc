// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GameObjectNotify.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "GameObjectNotify.pb.h"

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

const ::google::protobuf::Descriptor* GameObjectNotify_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameObjectNotify_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_GameObjectNotify_2eproto() {
  protobuf_AddDesc_GameObjectNotify_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "GameObjectNotify.proto");
  GOOGLE_CHECK(file != NULL);
  GameObjectNotify_descriptor_ = file->message_type(0);
  static const int GameObjectNotify_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameObjectNotify, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameObjectNotify, x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameObjectNotify, y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameObjectNotify, width_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameObjectNotify, height_),
  };
  GameObjectNotify_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      GameObjectNotify_descriptor_,
      GameObjectNotify::default_instance_,
      GameObjectNotify_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameObjectNotify, _has_bits_[0]),
      -1,
      -1,
      sizeof(GameObjectNotify),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameObjectNotify, _internal_metadata_),
      -1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_GameObjectNotify_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      GameObjectNotify_descriptor_, &GameObjectNotify::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_GameObjectNotify_2eproto() {
  delete GameObjectNotify::default_instance_;
  delete GameObjectNotify_reflection_;
}

void protobuf_AddDesc_GameObjectNotify_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026GameObjectNotify.proto\"U\n\020GameObjectNo"
    "tify\022\014\n\004TYPE\030\001 \002(\005\022\t\n\001x\030\002 \002(\005\022\t\n\001y\030\003 \002(\005"
    "\022\r\n\005width\030\004 \002(\005\022\016\n\006height\030\005 \002(\005", 111);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "GameObjectNotify.proto", &protobuf_RegisterTypes);
  GameObjectNotify::default_instance_ = new GameObjectNotify();
  GameObjectNotify::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_GameObjectNotify_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_GameObjectNotify_2eproto {
  StaticDescriptorInitializer_GameObjectNotify_2eproto() {
    protobuf_AddDesc_GameObjectNotify_2eproto();
  }
} static_descriptor_initializer_GameObjectNotify_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#ifndef _MSC_VER
const int GameObjectNotify::kTYPEFieldNumber;
const int GameObjectNotify::kXFieldNumber;
const int GameObjectNotify::kYFieldNumber;
const int GameObjectNotify::kWidthFieldNumber;
const int GameObjectNotify::kHeightFieldNumber;
#endif  // !_MSC_VER

GameObjectNotify::GameObjectNotify()
  : ::google::protobuf::Message() , _internal_metadata_(NULL)  {
  SharedCtor();
  // @@protoc_insertion_point(constructor:GameObjectNotify)
}

void GameObjectNotify::InitAsDefaultInstance() {
}

GameObjectNotify::GameObjectNotify(const GameObjectNotify& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:GameObjectNotify)
}

void GameObjectNotify::SharedCtor() {
  _cached_size_ = 0;
  type_ = 0;
  x_ = 0;
  y_ = 0;
  width_ = 0;
  height_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameObjectNotify::~GameObjectNotify() {
  // @@protoc_insertion_point(destructor:GameObjectNotify)
  SharedDtor();
}

void GameObjectNotify::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameObjectNotify::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameObjectNotify::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameObjectNotify_descriptor_;
}

const GameObjectNotify& GameObjectNotify::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_GameObjectNotify_2eproto();
  return *default_instance_;
}

GameObjectNotify* GameObjectNotify::default_instance_ = NULL;

GameObjectNotify* GameObjectNotify::New(::google::protobuf::Arena* arena) const {
  GameObjectNotify* n = new GameObjectNotify;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void GameObjectNotify::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameObjectNotify*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 31) {
    ZR_(type_, height_);
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool GameObjectNotify::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:GameObjectNotify)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 TYPE = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &type_)));
          set_has_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_x;
        break;
      }

      // required int32 x = 2;
      case 2: {
        if (tag == 16) {
         parse_x:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &x_)));
          set_has_x();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_y;
        break;
      }

      // required int32 y = 3;
      case 3: {
        if (tag == 24) {
         parse_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &y_)));
          set_has_y();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_width;
        break;
      }

      // required int32 width = 4;
      case 4: {
        if (tag == 32) {
         parse_width:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &width_)));
          set_has_width();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_height;
        break;
      }

      // required int32 height = 5;
      case 5: {
        if (tag == 40) {
         parse_height:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &height_)));
          set_has_height();
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
  // @@protoc_insertion_point(parse_success:GameObjectNotify)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:GameObjectNotify)
  return false;
#undef DO_
}

void GameObjectNotify::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:GameObjectNotify)
  // required int32 TYPE = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->type(), output);
  }

  // required int32 x = 2;
  if (has_x()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->x(), output);
  }

  // required int32 y = 3;
  if (has_y()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->y(), output);
  }

  // required int32 width = 4;
  if (has_width()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->width(), output);
  }

  // required int32 height = 5;
  if (has_height()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->height(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:GameObjectNotify)
}

::google::protobuf::uint8* GameObjectNotify::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:GameObjectNotify)
  // required int32 TYPE = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->type(), target);
  }

  // required int32 x = 2;
  if (has_x()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->x(), target);
  }

  // required int32 y = 3;
  if (has_y()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->y(), target);
  }

  // required int32 width = 4;
  if (has_width()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->width(), target);
  }

  // required int32 height = 5;
  if (has_height()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->height(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:GameObjectNotify)
  return target;
}

int GameObjectNotify::RequiredFieldsByteSizeFallback() const {
  int total_size = 0;

  if (has_type()) {
    // required int32 TYPE = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->type());
  }

  if (has_x()) {
    // required int32 x = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->x());
  }

  if (has_y()) {
    // required int32 y = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->y());
  }

  if (has_width()) {
    // required int32 width = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->width());
  }

  if (has_height()) {
    // required int32 height = 5;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->height());
  }

  return total_size;
}
int GameObjectNotify::ByteSize() const {
  int total_size = 0;

  if (((_has_bits_[0] & 0x0000001f) ^ 0x0000001f) == 0) {  // All required fields are present.
    // required int32 TYPE = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->type());

    // required int32 x = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->x());

    // required int32 y = 3;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->y());

    // required int32 width = 4;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->width());

    // required int32 height = 5;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->height());

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

void GameObjectNotify::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const GameObjectNotify* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameObjectNotify*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameObjectNotify::MergeFrom(const GameObjectNotify& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_x()) {
      set_x(from.x());
    }
    if (from.has_y()) {
      set_y(from.y());
    }
    if (from.has_width()) {
      set_width(from.width());
    }
    if (from.has_height()) {
      set_height(from.height());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void GameObjectNotify::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameObjectNotify::CopyFrom(const GameObjectNotify& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameObjectNotify::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;

  return true;
}

void GameObjectNotify::Swap(GameObjectNotify* other) {
  if (other == this) return;
  InternalSwap(other);
}
void GameObjectNotify::InternalSwap(GameObjectNotify* other) {
  std::swap(type_, other->type_);
  std::swap(x_, other->x_);
  std::swap(y_, other->y_);
  std::swap(width_, other->width_);
  std::swap(height_, other->height_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata GameObjectNotify::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameObjectNotify_descriptor_;
  metadata.reflection = GameObjectNotify_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
