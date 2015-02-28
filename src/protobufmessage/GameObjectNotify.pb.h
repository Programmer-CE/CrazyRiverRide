// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GameObjectNotify.proto

#ifndef PROTOBUF_GameObjectNotify_2eproto__INCLUDED
#define PROTOBUF_GameObjectNotify_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_GameObjectNotify_2eproto();
void protobuf_AssignDesc_GameObjectNotify_2eproto();
void protobuf_ShutdownFile_GameObjectNotify_2eproto();

class GameObjectNotify;

// ===================================================================

class GameObjectNotify : public ::google::protobuf::Message {
 public:
  GameObjectNotify();
  virtual ~GameObjectNotify();

  GameObjectNotify(const GameObjectNotify& from);

  inline GameObjectNotify& operator=(const GameObjectNotify& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GameObjectNotify& default_instance();

  void Swap(GameObjectNotify* other);

  // implements Message ----------------------------------------------

  inline GameObjectNotify* New() const { return New(NULL); }

  GameObjectNotify* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GameObjectNotify& from);
  void MergeFrom(const GameObjectNotify& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GameObjectNotify* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 TYPE = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTYPEFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // required int32 x = 2;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 2;
  inline ::google::protobuf::int32 x() const;
  inline void set_x(::google::protobuf::int32 value);

  // required int32 y = 3;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 3;
  inline ::google::protobuf::int32 y() const;
  inline void set_y(::google::protobuf::int32 value);

  // required int32 width = 4;
  inline bool has_width() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 4;
  inline ::google::protobuf::int32 width() const;
  inline void set_width(::google::protobuf::int32 value);

  // required int32 height = 5;
  inline bool has_height() const;
  inline void clear_height();
  static const int kHeightFieldNumber = 5;
  inline ::google::protobuf::int32 height() const;
  inline void set_height(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:GameObjectNotify)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_x();
  inline void clear_has_x();
  inline void set_has_y();
  inline void clear_has_y();
  inline void set_has_width();
  inline void clear_has_width();
  inline void set_has_height();
  inline void clear_has_height();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 type_;
  ::google::protobuf::int32 x_;
  ::google::protobuf::int32 y_;
  ::google::protobuf::int32 width_;
  ::google::protobuf::int32 height_;
  friend void  protobuf_AddDesc_GameObjectNotify_2eproto();
  friend void protobuf_AssignDesc_GameObjectNotify_2eproto();
  friend void protobuf_ShutdownFile_GameObjectNotify_2eproto();

  void InitAsDefaultInstance();
  static GameObjectNotify* default_instance_;
};
// ===================================================================


// ===================================================================

// GameObjectNotify

// required int32 TYPE = 1;
inline bool GameObjectNotify::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GameObjectNotify::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GameObjectNotify::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GameObjectNotify::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 GameObjectNotify::type() const {
  // @@protoc_insertion_point(field_get:GameObjectNotify.TYPE)
  return type_;
}
inline void GameObjectNotify::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:GameObjectNotify.TYPE)
}

// required int32 x = 2;
inline bool GameObjectNotify::has_x() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GameObjectNotify::set_has_x() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GameObjectNotify::clear_has_x() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GameObjectNotify::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline ::google::protobuf::int32 GameObjectNotify::x() const {
  // @@protoc_insertion_point(field_get:GameObjectNotify.x)
  return x_;
}
inline void GameObjectNotify::set_x(::google::protobuf::int32 value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:GameObjectNotify.x)
}

// required int32 y = 3;
inline bool GameObjectNotify::has_y() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void GameObjectNotify::set_has_y() {
  _has_bits_[0] |= 0x00000004u;
}
inline void GameObjectNotify::clear_has_y() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void GameObjectNotify::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline ::google::protobuf::int32 GameObjectNotify::y() const {
  // @@protoc_insertion_point(field_get:GameObjectNotify.y)
  return y_;
}
inline void GameObjectNotify::set_y(::google::protobuf::int32 value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:GameObjectNotify.y)
}

// required int32 width = 4;
inline bool GameObjectNotify::has_width() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void GameObjectNotify::set_has_width() {
  _has_bits_[0] |= 0x00000008u;
}
inline void GameObjectNotify::clear_has_width() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void GameObjectNotify::clear_width() {
  width_ = 0;
  clear_has_width();
}
inline ::google::protobuf::int32 GameObjectNotify::width() const {
  // @@protoc_insertion_point(field_get:GameObjectNotify.width)
  return width_;
}
inline void GameObjectNotify::set_width(::google::protobuf::int32 value) {
  set_has_width();
  width_ = value;
  // @@protoc_insertion_point(field_set:GameObjectNotify.width)
}

// required int32 height = 5;
inline bool GameObjectNotify::has_height() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void GameObjectNotify::set_has_height() {
  _has_bits_[0] |= 0x00000010u;
}
inline void GameObjectNotify::clear_has_height() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void GameObjectNotify::clear_height() {
  height_ = 0;
  clear_has_height();
}
inline ::google::protobuf::int32 GameObjectNotify::height() const {
  // @@protoc_insertion_point(field_get:GameObjectNotify.height)
  return height_;
}
inline void GameObjectNotify::set_height(::google::protobuf::int32 value) {
  set_has_height();
  height_ = value;
  // @@protoc_insertion_point(field_set:GameObjectNotify.height)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_GameObjectNotify_2eproto__INCLUDED
