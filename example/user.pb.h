// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_user_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_user_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_user_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_user_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_user_2eproto;
namespace User_Proto {
class ErrorCode;
struct ErrorCodeDefaultTypeInternal;
extern ErrorCodeDefaultTypeInternal _ErrorCode_default_instance_;
class LoginRequest;
struct LoginRequestDefaultTypeInternal;
extern LoginRequestDefaultTypeInternal _LoginRequest_default_instance_;
class LoginResponse;
struct LoginResponseDefaultTypeInternal;
extern LoginResponseDefaultTypeInternal _LoginResponse_default_instance_;
}  // namespace User_Proto
PROTOBUF_NAMESPACE_OPEN
template<> ::User_Proto::ErrorCode* Arena::CreateMaybeMessage<::User_Proto::ErrorCode>(Arena*);
template<> ::User_Proto::LoginRequest* Arena::CreateMaybeMessage<::User_Proto::LoginRequest>(Arena*);
template<> ::User_Proto::LoginResponse* Arena::CreateMaybeMessage<::User_Proto::LoginResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace User_Proto {

// ===================================================================

class ErrorCode final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:User_Proto.ErrorCode) */ {
 public:
  inline ErrorCode() : ErrorCode(nullptr) {}
  ~ErrorCode() override;
  explicit constexpr ErrorCode(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ErrorCode(const ErrorCode& from);
  ErrorCode(ErrorCode&& from) noexcept
    : ErrorCode() {
    *this = ::std::move(from);
  }

  inline ErrorCode& operator=(const ErrorCode& from) {
    CopyFrom(from);
    return *this;
  }
  inline ErrorCode& operator=(ErrorCode&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ErrorCode& default_instance() {
    return *internal_default_instance();
  }
  static inline const ErrorCode* internal_default_instance() {
    return reinterpret_cast<const ErrorCode*>(
               &_ErrorCode_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ErrorCode& a, ErrorCode& b) {
    a.Swap(&b);
  }
  inline void Swap(ErrorCode* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ErrorCode* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ErrorCode* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ErrorCode>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ErrorCode& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const ErrorCode& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ErrorCode* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "User_Proto.ErrorCode";
  }
  protected:
  explicit ErrorCode(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrmsgFieldNumber = 2,
    kErrcodeFieldNumber = 1,
  };
  // bytes errmsg = 2;
  void clear_errmsg();
  const std::string& errmsg() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_errmsg(ArgT0&& arg0, ArgT... args);
  std::string* mutable_errmsg();
  PROTOBUF_NODISCARD std::string* release_errmsg();
  void set_allocated_errmsg(std::string* errmsg);
  private:
  const std::string& _internal_errmsg() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_errmsg(const std::string& value);
  std::string* _internal_mutable_errmsg();
  public:

  // int32 errcode = 1;
  void clear_errcode();
  int32_t errcode() const;
  void set_errcode(int32_t value);
  private:
  int32_t _internal_errcode() const;
  void _internal_set_errcode(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:User_Proto.ErrorCode)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
  int32_t errcode_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_user_2eproto;
};
// -------------------------------------------------------------------

class LoginRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:User_Proto.LoginRequest) */ {
 public:
  inline LoginRequest() : LoginRequest(nullptr) {}
  ~LoginRequest() override;
  explicit constexpr LoginRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  LoginRequest(const LoginRequest& from);
  LoginRequest(LoginRequest&& from) noexcept
    : LoginRequest() {
    *this = ::std::move(from);
  }

  inline LoginRequest& operator=(const LoginRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline LoginRequest& operator=(LoginRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const LoginRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const LoginRequest* internal_default_instance() {
    return reinterpret_cast<const LoginRequest*>(
               &_LoginRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(LoginRequest& a, LoginRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(LoginRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LoginRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  LoginRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<LoginRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const LoginRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const LoginRequest& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LoginRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "User_Proto.LoginRequest";
  }
  protected:
  explicit LoginRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kPwdFieldNumber = 2,
  };
  // bytes name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // bytes pwd = 2;
  void clear_pwd();
  const std::string& pwd() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_pwd(ArgT0&& arg0, ArgT... args);
  std::string* mutable_pwd();
  PROTOBUF_NODISCARD std::string* release_pwd();
  void set_allocated_pwd(std::string* pwd);
  private:
  const std::string& _internal_pwd() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_pwd(const std::string& value);
  std::string* _internal_mutable_pwd();
  public:

  // @@protoc_insertion_point(class_scope:User_Proto.LoginRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pwd_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_user_2eproto;
};
// -------------------------------------------------------------------

class LoginResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:User_Proto.LoginResponse) */ {
 public:
  inline LoginResponse() : LoginResponse(nullptr) {}
  ~LoginResponse() override;
  explicit constexpr LoginResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  LoginResponse(const LoginResponse& from);
  LoginResponse(LoginResponse&& from) noexcept
    : LoginResponse() {
    *this = ::std::move(from);
  }

  inline LoginResponse& operator=(const LoginResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline LoginResponse& operator=(LoginResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const LoginResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const LoginResponse* internal_default_instance() {
    return reinterpret_cast<const LoginResponse*>(
               &_LoginResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(LoginResponse& a, LoginResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(LoginResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LoginResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  LoginResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<LoginResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const LoginResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const LoginResponse& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LoginResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "User_Proto.LoginResponse";
  }
  protected:
  explicit LoginResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kResultFieldNumber = 1,
    kSuccessFieldNumber = 2,
  };
  // .User_Proto.ErrorCode result = 1;
  bool has_result() const;
  private:
  bool _internal_has_result() const;
  public:
  void clear_result();
  const ::User_Proto::ErrorCode& result() const;
  PROTOBUF_NODISCARD ::User_Proto::ErrorCode* release_result();
  ::User_Proto::ErrorCode* mutable_result();
  void set_allocated_result(::User_Proto::ErrorCode* result);
  private:
  const ::User_Proto::ErrorCode& _internal_result() const;
  ::User_Proto::ErrorCode* _internal_mutable_result();
  public:
  void unsafe_arena_set_allocated_result(
      ::User_Proto::ErrorCode* result);
  ::User_Proto::ErrorCode* unsafe_arena_release_result();

  // bool success = 2;
  void clear_success();
  bool success() const;
  void set_success(bool value);
  private:
  bool _internal_success() const;
  void _internal_set_success(bool value);
  public:

  // @@protoc_insertion_point(class_scope:User_Proto.LoginResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::User_Proto::ErrorCode* result_;
  bool success_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_user_2eproto;
};
// ===================================================================

class UserServiceRpc_Stub;

class UserServiceRpc : public ::PROTOBUF_NAMESPACE_ID::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline UserServiceRpc() {};
 public:
  virtual ~UserServiceRpc();

  typedef UserServiceRpc_Stub Stub;

  static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* descriptor();

  virtual void Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::User_Proto::LoginRequest* request,
                       ::User_Proto::LoginResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                  ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                  const ::PROTOBUF_NAMESPACE_ID::Message* request,
                  ::PROTOBUF_NAMESPACE_ID::Message* response,
                  ::google::protobuf::Closure* done);
  const ::PROTOBUF_NAMESPACE_ID::Message& GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;
  const ::PROTOBUF_NAMESPACE_ID::Message& GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(UserServiceRpc);
};

class UserServiceRpc_Stub : public UserServiceRpc {
 public:
  UserServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
  UserServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                   ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
  ~UserServiceRpc_Stub();

  inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }

  // implements UserServiceRpc ------------------------------------------

  void Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::User_Proto::LoginRequest* request,
                       ::User_Proto::LoginResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(UserServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ErrorCode

// int32 errcode = 1;
inline void ErrorCode::clear_errcode() {
  errcode_ = 0;
}
inline int32_t ErrorCode::_internal_errcode() const {
  return errcode_;
}
inline int32_t ErrorCode::errcode() const {
  // @@protoc_insertion_point(field_get:User_Proto.ErrorCode.errcode)
  return _internal_errcode();
}
inline void ErrorCode::_internal_set_errcode(int32_t value) {
  
  errcode_ = value;
}
inline void ErrorCode::set_errcode(int32_t value) {
  _internal_set_errcode(value);
  // @@protoc_insertion_point(field_set:User_Proto.ErrorCode.errcode)
}

// bytes errmsg = 2;
inline void ErrorCode::clear_errmsg() {
  errmsg_.ClearToEmpty();
}
inline const std::string& ErrorCode::errmsg() const {
  // @@protoc_insertion_point(field_get:User_Proto.ErrorCode.errmsg)
  return _internal_errmsg();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void ErrorCode::set_errmsg(ArgT0&& arg0, ArgT... args) {
 
 errmsg_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:User_Proto.ErrorCode.errmsg)
}
inline std::string* ErrorCode::mutable_errmsg() {
  std::string* _s = _internal_mutable_errmsg();
  // @@protoc_insertion_point(field_mutable:User_Proto.ErrorCode.errmsg)
  return _s;
}
inline const std::string& ErrorCode::_internal_errmsg() const {
  return errmsg_.Get();
}
inline void ErrorCode::_internal_set_errmsg(const std::string& value) {
  
  errmsg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* ErrorCode::_internal_mutable_errmsg() {
  
  return errmsg_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* ErrorCode::release_errmsg() {
  // @@protoc_insertion_point(field_release:User_Proto.ErrorCode.errmsg)
  return errmsg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void ErrorCode::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errmsg,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (errmsg_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:User_Proto.ErrorCode.errmsg)
}

// -------------------------------------------------------------------

// LoginRequest

// bytes name = 1;
inline void LoginRequest::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& LoginRequest::name() const {
  // @@protoc_insertion_point(field_get:User_Proto.LoginRequest.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LoginRequest::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:User_Proto.LoginRequest.name)
}
inline std::string* LoginRequest::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:User_Proto.LoginRequest.name)
  return _s;
}
inline const std::string& LoginRequest::_internal_name() const {
  return name_.Get();
}
inline void LoginRequest::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* LoginRequest::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* LoginRequest::release_name() {
  // @@protoc_insertion_point(field_release:User_Proto.LoginRequest.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void LoginRequest::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:User_Proto.LoginRequest.name)
}

// bytes pwd = 2;
inline void LoginRequest::clear_pwd() {
  pwd_.ClearToEmpty();
}
inline const std::string& LoginRequest::pwd() const {
  // @@protoc_insertion_point(field_get:User_Proto.LoginRequest.pwd)
  return _internal_pwd();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LoginRequest::set_pwd(ArgT0&& arg0, ArgT... args) {
 
 pwd_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:User_Proto.LoginRequest.pwd)
}
inline std::string* LoginRequest::mutable_pwd() {
  std::string* _s = _internal_mutable_pwd();
  // @@protoc_insertion_point(field_mutable:User_Proto.LoginRequest.pwd)
  return _s;
}
inline const std::string& LoginRequest::_internal_pwd() const {
  return pwd_.Get();
}
inline void LoginRequest::_internal_set_pwd(const std::string& value) {
  
  pwd_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* LoginRequest::_internal_mutable_pwd() {
  
  return pwd_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* LoginRequest::release_pwd() {
  // @@protoc_insertion_point(field_release:User_Proto.LoginRequest.pwd)
  return pwd_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void LoginRequest::set_allocated_pwd(std::string* pwd) {
  if (pwd != nullptr) {
    
  } else {
    
  }
  pwd_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), pwd,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (pwd_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    pwd_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:User_Proto.LoginRequest.pwd)
}

// -------------------------------------------------------------------

// LoginResponse

// .User_Proto.ErrorCode result = 1;
inline bool LoginResponse::_internal_has_result() const {
  return this != internal_default_instance() && result_ != nullptr;
}
inline bool LoginResponse::has_result() const {
  return _internal_has_result();
}
inline void LoginResponse::clear_result() {
  if (GetArenaForAllocation() == nullptr && result_ != nullptr) {
    delete result_;
  }
  result_ = nullptr;
}
inline const ::User_Proto::ErrorCode& LoginResponse::_internal_result() const {
  const ::User_Proto::ErrorCode* p = result_;
  return p != nullptr ? *p : reinterpret_cast<const ::User_Proto::ErrorCode&>(
      ::User_Proto::_ErrorCode_default_instance_);
}
inline const ::User_Proto::ErrorCode& LoginResponse::result() const {
  // @@protoc_insertion_point(field_get:User_Proto.LoginResponse.result)
  return _internal_result();
}
inline void LoginResponse::unsafe_arena_set_allocated_result(
    ::User_Proto::ErrorCode* result) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(result_);
  }
  result_ = result;
  if (result) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:User_Proto.LoginResponse.result)
}
inline ::User_Proto::ErrorCode* LoginResponse::release_result() {
  
  ::User_Proto::ErrorCode* temp = result_;
  result_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::User_Proto::ErrorCode* LoginResponse::unsafe_arena_release_result() {
  // @@protoc_insertion_point(field_release:User_Proto.LoginResponse.result)
  
  ::User_Proto::ErrorCode* temp = result_;
  result_ = nullptr;
  return temp;
}
inline ::User_Proto::ErrorCode* LoginResponse::_internal_mutable_result() {
  
  if (result_ == nullptr) {
    auto* p = CreateMaybeMessage<::User_Proto::ErrorCode>(GetArenaForAllocation());
    result_ = p;
  }
  return result_;
}
inline ::User_Proto::ErrorCode* LoginResponse::mutable_result() {
  ::User_Proto::ErrorCode* _msg = _internal_mutable_result();
  // @@protoc_insertion_point(field_mutable:User_Proto.LoginResponse.result)
  return _msg;
}
inline void LoginResponse::set_allocated_result(::User_Proto::ErrorCode* result) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete result_;
  }
  if (result) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<::User_Proto::ErrorCode>::GetOwningArena(result);
    if (message_arena != submessage_arena) {
      result = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, result, submessage_arena);
    }
    
  } else {
    
  }
  result_ = result;
  // @@protoc_insertion_point(field_set_allocated:User_Proto.LoginResponse.result)
}

// bool success = 2;
inline void LoginResponse::clear_success() {
  success_ = false;
}
inline bool LoginResponse::_internal_success() const {
  return success_;
}
inline bool LoginResponse::success() const {
  // @@protoc_insertion_point(field_get:User_Proto.LoginResponse.success)
  return _internal_success();
}
inline void LoginResponse::_internal_set_success(bool value) {
  
  success_ = value;
}
inline void LoginResponse::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:User_Proto.LoginResponse.success)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace User_Proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_user_2eproto
