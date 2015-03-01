// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PlayerStatus.proto

#ifndef PROTOBUF_PlayerStatus_2eproto__INCLUDED
#define PROTOBUF_PlayerStatus_2eproto__INCLUDED

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
void protobuf_AddDesc_PlayerStatus_2eproto();
void protobuf_AssignDesc_PlayerStatus_2eproto();
void protobuf_ShutdownFile_PlayerStatus_2eproto();

class PlayerStatus;

// ===================================================================

class PlayerStatus : public ::google::protobuf::Message {
 public:
  PlayerStatus();
  virtual ~PlayerStatus();

  PlayerStatus(const PlayerStatus& from);

  inline PlayerStatus& operator=(const PlayerStatus& from) {
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
  static const PlayerStatus& default_instance();

  void Swap(PlayerStatus* other);

  // implements Message ----------------------------------------------

  inline PlayerStatus* New() const { return New(NULL); }

  PlayerStatus* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PlayerStatus& from);
  void MergeFrom(const PlayerStatus& from);
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
  void InternalSwap(PlayerStatus* other);
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

  // required int32 NUM_OF_PLAYER = 1;
  inline bool has_num_of_player() const;
  inline void clear_num_of_player();
  static const int kNUMOFPLAYERFieldNumber = 1;
  inline ::google::protobuf::int32 num_of_player() const;
  inline void set_num_of_player(::google::protobuf::int32 value);

  // required int32 playerPoints = 2;
  inline bool has_playerpoints() const;
  inline void clear_playerpoints();
  static const int kPlayerPointsFieldNumber = 2;
  inline ::google::protobuf::int32 playerpoints() const;
  inline void set_playerpoints(::google::protobuf::int32 value);

  // required int32 playerLife = 3;
  inline bool has_playerlife() const;
  inline void clear_playerlife();
  static const int kPlayerLifeFieldNumber = 3;
  inline ::google::protobuf::int32 playerlife() const;
  inline void set_playerlife(::google::protobuf::int32 value);

  // required bool isDead = 4;
  inline bool has_isdead() const;
  inline void clear_isdead();
  static const int kIsDeadFieldNumber = 4;
  inline bool isdead() const;
  inline void set_isdead(bool value);

  // required int32 NumOfMunition = 5;
  inline bool has_numofmunition() const;
  inline void clear_numofmunition();
  static const int kNumOfMunitionFieldNumber = 5;
  inline ::google::protobuf::int32 numofmunition() const;
  inline void set_numofmunition(::google::protobuf::int32 value);

  // required int32 TypeOfMunition = 6;
  inline bool has_typeofmunition() const;
  inline void clear_typeofmunition();
  static const int kTypeOfMunitionFieldNumber = 6;
  inline ::google::protobuf::int32 typeofmunition() const;
  inline void set_typeofmunition(::google::protobuf::int32 value);

  // required int32 Combustible = 7;
  inline bool has_combustible() const;
  inline void clear_combustible();
  static const int kCombustibleFieldNumber = 7;
  inline ::google::protobuf::int32 combustible() const;
  inline void set_combustible(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:PlayerStatus)
 private:
  inline void set_has_num_of_player();
  inline void clear_has_num_of_player();
  inline void set_has_playerpoints();
  inline void clear_has_playerpoints();
  inline void set_has_playerlife();
  inline void clear_has_playerlife();
  inline void set_has_isdead();
  inline void clear_has_isdead();
  inline void set_has_numofmunition();
  inline void clear_has_numofmunition();
  inline void set_has_typeofmunition();
  inline void clear_has_typeofmunition();
  inline void set_has_combustible();
  inline void clear_has_combustible();

  // helper for ByteSize()
  int RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 num_of_player_;
  ::google::protobuf::int32 playerpoints_;
  ::google::protobuf::int32 playerlife_;
  bool isdead_;
  ::google::protobuf::int32 numofmunition_;
  ::google::protobuf::int32 typeofmunition_;
  ::google::protobuf::int32 combustible_;
  friend void  protobuf_AddDesc_PlayerStatus_2eproto();
  friend void protobuf_AssignDesc_PlayerStatus_2eproto();
  friend void protobuf_ShutdownFile_PlayerStatus_2eproto();

  void InitAsDefaultInstance();
  static PlayerStatus* default_instance_;
};
// ===================================================================


// ===================================================================

// PlayerStatus

// required int32 NUM_OF_PLAYER = 1;
inline bool PlayerStatus::has_num_of_player() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PlayerStatus::set_has_num_of_player() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PlayerStatus::clear_has_num_of_player() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PlayerStatus::clear_num_of_player() {
  num_of_player_ = 0;
  clear_has_num_of_player();
}
inline ::google::protobuf::int32 PlayerStatus::num_of_player() const {
  // @@protoc_insertion_point(field_get:PlayerStatus.NUM_OF_PLAYER)
  return num_of_player_;
}
inline void PlayerStatus::set_num_of_player(::google::protobuf::int32 value) {
  set_has_num_of_player();
  num_of_player_ = value;
  // @@protoc_insertion_point(field_set:PlayerStatus.NUM_OF_PLAYER)
}

// required int32 playerPoints = 2;
inline bool PlayerStatus::has_playerpoints() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PlayerStatus::set_has_playerpoints() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PlayerStatus::clear_has_playerpoints() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PlayerStatus::clear_playerpoints() {
  playerpoints_ = 0;
  clear_has_playerpoints();
}
inline ::google::protobuf::int32 PlayerStatus::playerpoints() const {
  // @@protoc_insertion_point(field_get:PlayerStatus.playerPoints)
  return playerpoints_;
}
inline void PlayerStatus::set_playerpoints(::google::protobuf::int32 value) {
  set_has_playerpoints();
  playerpoints_ = value;
  // @@protoc_insertion_point(field_set:PlayerStatus.playerPoints)
}

// required int32 playerLife = 3;
inline bool PlayerStatus::has_playerlife() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PlayerStatus::set_has_playerlife() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PlayerStatus::clear_has_playerlife() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PlayerStatus::clear_playerlife() {
  playerlife_ = 0;
  clear_has_playerlife();
}
inline ::google::protobuf::int32 PlayerStatus::playerlife() const {
  // @@protoc_insertion_point(field_get:PlayerStatus.playerLife)
  return playerlife_;
}
inline void PlayerStatus::set_playerlife(::google::protobuf::int32 value) {
  set_has_playerlife();
  playerlife_ = value;
  // @@protoc_insertion_point(field_set:PlayerStatus.playerLife)
}

// required bool isDead = 4;
inline bool PlayerStatus::has_isdead() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void PlayerStatus::set_has_isdead() {
  _has_bits_[0] |= 0x00000008u;
}
inline void PlayerStatus::clear_has_isdead() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void PlayerStatus::clear_isdead() {
  isdead_ = false;
  clear_has_isdead();
}
inline bool PlayerStatus::isdead() const {
  // @@protoc_insertion_point(field_get:PlayerStatus.isDead)
  return isdead_;
}
inline void PlayerStatus::set_isdead(bool value) {
  set_has_isdead();
  isdead_ = value;
  // @@protoc_insertion_point(field_set:PlayerStatus.isDead)
}

// required int32 NumOfMunition = 5;
inline bool PlayerStatus::has_numofmunition() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void PlayerStatus::set_has_numofmunition() {
  _has_bits_[0] |= 0x00000010u;
}
inline void PlayerStatus::clear_has_numofmunition() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void PlayerStatus::clear_numofmunition() {
  numofmunition_ = 0;
  clear_has_numofmunition();
}
inline ::google::protobuf::int32 PlayerStatus::numofmunition() const {
  // @@protoc_insertion_point(field_get:PlayerStatus.NumOfMunition)
  return numofmunition_;
}
inline void PlayerStatus::set_numofmunition(::google::protobuf::int32 value) {
  set_has_numofmunition();
  numofmunition_ = value;
  // @@protoc_insertion_point(field_set:PlayerStatus.NumOfMunition)
}

// required int32 TypeOfMunition = 6;
inline bool PlayerStatus::has_typeofmunition() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void PlayerStatus::set_has_typeofmunition() {
  _has_bits_[0] |= 0x00000020u;
}
inline void PlayerStatus::clear_has_typeofmunition() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void PlayerStatus::clear_typeofmunition() {
  typeofmunition_ = 0;
  clear_has_typeofmunition();
}
inline ::google::protobuf::int32 PlayerStatus::typeofmunition() const {
  // @@protoc_insertion_point(field_get:PlayerStatus.TypeOfMunition)
  return typeofmunition_;
}
inline void PlayerStatus::set_typeofmunition(::google::protobuf::int32 value) {
  set_has_typeofmunition();
  typeofmunition_ = value;
  // @@protoc_insertion_point(field_set:PlayerStatus.TypeOfMunition)
}

// required int32 Combustible = 7;
inline bool PlayerStatus::has_combustible() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void PlayerStatus::set_has_combustible() {
  _has_bits_[0] |= 0x00000040u;
}
inline void PlayerStatus::clear_has_combustible() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void PlayerStatus::clear_combustible() {
  combustible_ = 0;
  clear_has_combustible();
}
inline ::google::protobuf::int32 PlayerStatus::combustible() const {
  // @@protoc_insertion_point(field_get:PlayerStatus.Combustible)
  return combustible_;
}
inline void PlayerStatus::set_combustible(::google::protobuf::int32 value) {
  set_has_combustible();
  combustible_ = value;
  // @@protoc_insertion_point(field_set:PlayerStatus.Combustible)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_PlayerStatus_2eproto__INCLUDED
