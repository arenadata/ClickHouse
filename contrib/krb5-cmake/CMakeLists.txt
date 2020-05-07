set(KRB5_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/contrib/krb5/src/)

set(KRB5_SRC
        ${KRB5_INCLUDE_DIR}/util/support/k5buf.c
        ${KRB5_INCLUDE_DIR}/util/support/fake-addrinfo.c
        ${KRB5_INCLUDE_DIR}/util/support/hex.c
        ${KRB5_INCLUDE_DIR}/util/support/path.c
        ${KRB5_INCLUDE_DIR}/util/support/t_base64.c
        ${KRB5_INCLUDE_DIR}/util/support/t_utf16.c
        ${KRB5_INCLUDE_DIR}/util/support/base64.c
        ${KRB5_INCLUDE_DIR}/util/support/fnmatch.c
        ${KRB5_INCLUDE_DIR}/util/support/init-addrinfo.c
        ${KRB5_INCLUDE_DIR}/util/support/plugins.c
        ${KRB5_INCLUDE_DIR}/util/support/t_hashtab.c
        ${KRB5_INCLUDE_DIR}/util/support/t_utf8.c
        ${KRB5_INCLUDE_DIR}/util/support/bcmp.c
        ${KRB5_INCLUDE_DIR}/util/support/getopt.c
        ${KRB5_INCLUDE_DIR}/util/support/ipc_stream.c
        ${KRB5_INCLUDE_DIR}/util/support/printf.c
        ${KRB5_INCLUDE_DIR}/util/support/t_hex.c
        ${KRB5_INCLUDE_DIR}/util/support/threads.c
        ${KRB5_INCLUDE_DIR}/util/support/getopt_long.c
        ${KRB5_INCLUDE_DIR}/util/support/json.c
        ${KRB5_INCLUDE_DIR}/util/support/secure_getenv.c
        ${KRB5_INCLUDE_DIR}/util/support/t_json.c
        ${KRB5_INCLUDE_DIR}/util/support/utf8.c
        ${KRB5_INCLUDE_DIR}/util/support/gettimeofday.c
        ${KRB5_INCLUDE_DIR}/util/support/k5buf.c
        ${KRB5_INCLUDE_DIR}/util/support/strerror_r.c
        ${KRB5_INCLUDE_DIR}/util/support/t_k5buf.c
        ${KRB5_INCLUDE_DIR}/util/support/utf8_conv.c
        ${KRB5_INCLUDE_DIR}/util/support/dir_filenames.c
        ${KRB5_INCLUDE_DIR}/util/support/gmt_mktime.c
        ${KRB5_INCLUDE_DIR}/util/support/strlcpy.c
        ${KRB5_INCLUDE_DIR}/util/support/t_path.c
        ${KRB5_INCLUDE_DIR}/util/support/zap.c
        ${KRB5_INCLUDE_DIR}/util/support/errors.c
        ${KRB5_INCLUDE_DIR}/util/support/hashtab.c
        ${KRB5_INCLUDE_DIR}/util/support/mkstemp.c
        ${KRB5_INCLUDE_DIR}/util/support/t_unal.c
)

add_library(krb5 ${KRB5_SRC})

target_include_directories(krb5 PUBLIC ${KRB5_INCLUDE_DIR}/include/krb5)
target_include_directories(krb5 PUBLIC ${KRB5_INCLUDE_DIR}/include)
target_include_directories(krb5 PUBLIC ${KRB5_INCLUDE_DIR}/include/gssrpc)