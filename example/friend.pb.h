// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: friend.proto

#ifndef PROTOBUF_friend_2eproto__INCLUDED
#define PROTOBUF_friend_2eproto__INCLUDED

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
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace fixbug {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_friend_2eproto();
void protobuf_AssignDesc_friend_2eproto();
void protobuf_ShutdownFile_friend_2eproto();

class GetFriendListRequest;
class GetFriendListResponse;
class ResultCode;

// ===================================================================

class ResultCode : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fixbug.ResultCode) */ {
 public:
  ResultCode();
  virtual ~ResultCode();

  ResultCode(const ResultCode& from);

  inline ResultCode& operator=(const ResultCode& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ResultCode& default_instance();

  void Swap(ResultCode* other);

  // implements Message ----------------------------------------------

  inline ResultCode* New() const { return New(NULL); }

  ResultCode* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ResultCode& from);
  void MergeFrom(const ResultCode& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ResultCode* other);
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

  // optional int32 errcode = 1;
  void clear_errcode();
  static const int kErrcodeFieldNumber = 1;
  ::google::protobuf::int32 errcode() const;
  void set_errcode(::google::protobuf::int32 value);

  // optional bytes errrmsg = 2;
  void clear_errrmsg();
  static const int kErrrmsgFieldNumber = 2;
  const ::std::string& errrmsg() const;
  void set_errrmsg(const ::std::string& value);
  void set_errrmsg(const char* value);
  void set_errrmsg(const void* value, size_t size);
  ::std::string* mutable_errrmsg();
  ::std::string* release_errrmsg();
  void set_allocated_errrmsg(::std::string* errrmsg);

  // @@protoc_insertion_point(class_scope:fixbug.ResultCode)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr errrmsg_;
  ::google::protobuf::int32 errcode_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_friend_2eproto();
  friend void protobuf_AssignDesc_friend_2eproto();
  friend void protobuf_ShutdownFile_friend_2eproto();

  void InitAsDefaultInstance();
  static ResultCode* default_instance_;
};
// -------------------------------------------------------------------

class GetFriendListRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fixbug.GetFriendListRequest) */ {
 public:
  GetFriendListRequest();
  virtual ~GetFriendListRequest();

  GetFriendListRequest(const GetFriendListRequest& from);

  inline GetFriendListRequest& operator=(const GetFriendListRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetFriendListRequest& default_instance();

  void Swap(GetFriendListRequest* other);

  // implements Message ----------------------------------------------

  inline GetFriendListRequest* New() const { return New(NULL); }

  GetFriendListRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetFriendListRequest& from);
  void MergeFrom(const GetFriendListRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GetFriendListRequest* other);
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

  // optional uint32 userid = 1;
  void clear_userid();
  static const int kUseridFieldNumber = 1;
  ::google::protobuf::uint32 userid() const;
  void set_userid(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:fixbug.GetFriendListRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::uint32 userid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_friend_2eproto();
  friend void protobuf_AssignDesc_friend_2eproto();
  friend void protobuf_ShutdownFile_friend_2eproto();

  void InitAsDefaultInstance();
  static GetFriendListRequest* default_instance_;
};
// -------------------------------------------------------------------

class GetFriendListResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fixbug.GetFriendListResponse) */ {
 public:
  GetFriendListResponse();
  virtual ~GetFriendListResponse();

  GetFriendListResponse(const GetFriendListResponse& from);

  inline GetFriendListResponse& operator=(const GetFriendListResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetFriendListResponse& default_instance();

  void Swap(GetFriendListResponse* other);

  // implements Message ----------------------------------------------

  inline GetFriendListResponse* New() const { return New(NULL); }

  GetFriendListResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetFriendListResponse& from);
  void MergeFrom(const GetFriendListResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GetFriendListResponse* other);
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

  // optional .fixbug.ResultCode result = 1;
  bool has_result() const;
  void clear_result();
  static const int kResultFieldNumber = 1;
  const ::fixbug::ResultCode& result() const;
  ::fixbug::ResultCode* mutable_result();
  ::fixbug::ResultCode* release_result();
  void set_allocated_result(::fixbug::ResultCode* result);

  // repeated bytes friends = 2;
  int friends_size() const;
  void clear_friends();
  static const int kFriendsFieldNumber = 2;
  const ::std::string& friends(int index) const;
  ::std::string* mutable_friends(int index);
  void set_friends(int index, const ::std::string& value);
  void set_friends(int index, const char* value);
  void set_friends(int index, const void* value, size_t size);
  ::std::string* add_friends();
  void add_friends(const ::std::string& value);
  void add_friends(const char* value);
  void add_friends(const void* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& friends() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_friends();

  // @@protoc_insertion_point(class_scope:fixbug.GetFriendListResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::fixbug::ResultCode* result_;
  ::google::protobuf::RepeatedPtrField< ::std::string> friends_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_friend_2eproto();
  friend void protobuf_AssignDesc_friend_2eproto();
  friend void protobuf_ShutdownFile_friend_2eproto();

  void InitAsDefaultInstance();
  static GetFriendListResponse* default_instance_;
};
// ===================================================================

class FriendServiceRpc_Stub;

class FriendServiceRpc : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline FriendServiceRpc() {};
 public:
  virtual ~FriendServiceRpc();

  typedef FriendServiceRpc_Stub Stub;

  static const ::google::protobuf::ServiceDescriptor* descriptor();

  virtual void GetFriendList(::google::protobuf::RpcController* controller,
                       const ::fixbug::GetFriendListRequest* request,
                       ::fixbug::GetFriendListResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendServiceRpc);
};

class FriendServiceRpc_Stub : public FriendServiceRpc {
 public:
  FriendServiceRpc_Stub(::google::protobuf::RpcChannel* channel);
  FriendServiceRpc_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~FriendServiceRpc_Stub();

  inline ::google::protobuf::RpcChannel* channel() { return channel_; }

  // implements FriendServiceRpc ------------------------------------------

  void GetFriendList(::google::protobuf::RpcController* controller,
                       const ::fixbug::GetFriendListRequest* request,
                       ::fixbug::GetFriendListResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ResultCode

// optional int32 errcode = 1;
inline void ResultCode::clear_errcode() {
  errcode_ = 0;
}
inline ::google::protobuf::int32 ResultCode::errcode() const {
  // @@protoc_insertion_point(field_get:fixbug.ResultCode.errcode)
  return errcode_;
}
inline void ResultCode::set_errcode(::google::protobuf::int32 value) {
  
  errcode_ = value;
  // @@protoc_insertion_point(field_set:fixbug.ResultCode.errcode)
}

// optional bytes errrmsg = 2;
inline void ResultCode::clear_errrmsg() {
  errrmsg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ResultCode::errrmsg() const {
  // @@protoc_insertion_point(field_get:fixbug.ResultCode.errrmsg)
  return errrmsg_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ResultCode::set_errrmsg(const ::std::string& value) {
  
  errrmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:fixbug.ResultCode.errrmsg)
}
inline void ResultCode::set_errrmsg(const char* value) {
  
  errrmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:fixbug.ResultCode.errrmsg)
}
inline void ResultCode::set_errrmsg(const void* value, size_t size) {
  
  errrmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:fixbug.ResultCode.errrmsg)
}
inline ::std::string* ResultCode::mutable_errrmsg() {
  
  // @@protoc_insertion_point(field_mutable:fixbug.ResultCode.errrmsg)
  return errrmsg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ResultCode::release_errrmsg() {
  // @@protoc_insertion_point(field_release:fixbug.ResultCode.errrmsg)
  
  return errrmsg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ResultCode::set_allocated_errrmsg(::std::string* errrmsg) {
  if (errrmsg != NULL) {
    
  } else {
    
  }
  errrmsg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), errrmsg);
  // @@protoc_insertion_point(field_set_allocated:fixbug.ResultCode.errrmsg)
}

// -------------------------------------------------------------------

// GetFriendListRequest

// optional uint32 userid = 1;
inline void GetFriendListRequest::clear_userid() {
  userid_ = 0u;
}
inline ::google::protobuf::uint32 GetFriendListRequest::userid() const {
  // @@protoc_insertion_point(field_get:fixbug.GetFriendListRequest.userid)
  return userid_;
}
inline void GetFriendListRequest::set_userid(::google::protobuf::uint32 value) {
  
  userid_ = value;
  // @@protoc_insertion_point(field_set:fixbug.GetFriendListRequest.userid)
}

// -------------------------------------------------------------------

// GetFriendListResponse

// optional .fixbug.ResultCode result = 1;
inline bool GetFriendListResponse::has_result() const {
  return !_is_default_instance_ && result_ != NULL;
}
inline void GetFriendListResponse::clear_result() {
  if (GetArenaNoVirtual() == NULL && result_ != NULL) delete result_;
  result_ = NULL;
}
inline const ::fixbug::ResultCode& GetFriendListResponse::result() const {
  // @@protoc_insertion_point(field_get:fixbug.GetFriendListResponse.result)
  return result_ != NULL ? *result_ : *default_instance_->result_;
}
inline ::fixbug::ResultCode* GetFriendListResponse::mutable_result() {
  
  if (result_ == NULL) {
    result_ = new ::fixbug::ResultCode;
  }
  // @@protoc_insertion_point(field_mutable:fixbug.GetFriendListResponse.result)
  return result_;
}
inline ::fixbug::ResultCode* GetFriendListResponse::release_result() {
  // @@protoc_insertion_point(field_release:fixbug.GetFriendListResponse.result)
  
  ::fixbug::ResultCode* temp = result_;
  result_ = NULL;
  return temp;
}
inline void GetFriendListResponse::set_allocated_result(::fixbug::ResultCode* result) {
  delete result_;
  result_ = result;
  if (result) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:fixbug.GetFriendListResponse.result)
}

// repeated bytes friends = 2;
inline int GetFriendListResponse::friends_size() const {
  return friends_.size();
}
inline void GetFriendListResponse::clear_friends() {
  friends_.Clear();
}
inline const ::std::string& GetFriendListResponse::friends(int index) const {
  // @@protoc_insertion_point(field_get:fixbug.GetFriendListResponse.friends)
  return friends_.Get(index);
}
inline ::std::string* GetFriendListResponse::mutable_friends(int index) {
  // @@protoc_insertion_point(field_mutable:fixbug.GetFriendListResponse.friends)
  return friends_.Mutable(index);
}
inline void GetFriendListResponse::set_friends(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:fixbug.GetFriendListResponse.friends)
  friends_.Mutable(index)->assign(value);
}
inline void GetFriendListResponse::set_friends(int index, const char* value) {
  friends_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:fixbug.GetFriendListResponse.friends)
}
inline void GetFriendListResponse::set_friends(int index, const void* value, size_t size) {
  friends_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:fixbug.GetFriendListResponse.friends)
}
inline ::std::string* GetFriendListResponse::add_friends() {
  // @@protoc_insertion_point(field_add_mutable:fixbug.GetFriendListResponse.friends)
  return friends_.Add();
}
inline void GetFriendListResponse::add_friends(const ::std::string& value) {
  friends_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:fixbug.GetFriendListResponse.friends)
}
inline void GetFriendListResponse::add_friends(const char* value) {
  friends_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:fixbug.GetFriendListResponse.friends)
}
inline void GetFriendListResponse::add_friends(const void* value, size_t size) {
  friends_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:fixbug.GetFriendListResponse.friends)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
GetFriendListResponse::friends() const {
  // @@protoc_insertion_point(field_list:fixbug.GetFriendListResponse.friends)
  return friends_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
GetFriendListResponse::mutable_friends() {
  // @@protoc_insertion_point(field_mutable_list:fixbug.GetFriendListResponse.friends)
  return &friends_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace fixbug

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_friend_2eproto__INCLUDED