//
// Created by Naokitsu on 3/23/2024.
//

#ifndef EMBERS_PRIMITIVES_H
#define EMBERS_PRIMITIVES_H

#include <cstdint>

// - Rust-like machine types

typedef int8_t i8;            ///< Signed integer with width of 8bit
typedef int16_t i16;          ///< Signed integer with width of 16bit
typedef int32_t i32;          ///< Signed integer with width of 32bit
typedef int64_t i64;          ///< Signed integer with width of 64bit

typedef int_fast8_t i8f;      ///< Fastest signed integer with width of at least 8bit
typedef int_fast16_t i16f;    ///< Fastest signed integer with width of at least 16bit
typedef int_fast32_t i32f;    ///< Fastest signed integer with width of at least 32bit
typedef int_fast64_t i64f;    ///< Fastest signed integer with width of at least 64bit

typedef int_least8_t i8l;     ///< Smallest signed integer with width of at least 8bit
typedef int_least16_t i16l;   ///< Smallest signed integer with width of at least 16bit
typedef int_least32_t i32l;   ///< Smallest signed integer with width of at least 32bit
typedef int_least64_t i64l;   ///< Smallest signed integer with width of at least 64bit

typedef uint8_t u8;           ///< Unsigned 8bit integer with width of at least 8bit
typedef uint16_t u16;         ///< Unsigned 16bit integer with width of at least 16bit
typedef uint32_t u32;         ///< Unsigned 32bit integer with width of at least 32bit
typedef uint64_t u64;         ///< Unsigned 64bit integer with width of at least 64bit

typedef uint_fast8_t u8f;     ///< Fastest unsigned integer with width of at least 8bit
typedef uint_fast16_t u16f;   ///< Fastest unsigned integer with width of at least 16bit
typedef uint_fast32_t u32f;   ///< Fastest unsigned integer with width of at least 32bit
typedef uint_fast64_t u64f;   ///< Fastest unsigned integer with width of at least 64bit

typedef uint_least8_t u8l;    ///< Smallest unsigned integer with width of at least 8bit
typedef uint_least16_t u16l;  ///< Smallest unsigned integer with width of at least 16bit
typedef uint_least32_t u32l;  ///< Smallest unsigned integer with width of at least 32bit
typedef uint_least64_t u64l;  ///< Smallest unsigned integer with width of at least 64bit

typedef float f32;            ///< Floating number with width of 32bits
typedef double f64;           ///< Floating number with width of 64bits

static_assert(sizeof(i8) == 1, "u8 must be 1 byte");
static_assert(sizeof(i16) == 2, "u16 must be 2 bytes");
static_assert(sizeof(i32) == 4, "u32 must be 4 bytes");
static_assert(sizeof(i64) == 8, "u64 must be 8 bytes");

static_assert(sizeof(i8f) >= 1, "u8f must be at least 1 byte");
static_assert(sizeof(i16f) >= 2, "u16f must be at least 2 bytes");
static_assert(sizeof(i32f) >= 4, "u32f must be at least 4 bytes");
static_assert(sizeof(i64f) >= 8, "u64f must be at least 8 bytes");

static_assert(sizeof(i8l) >= 1, "u8l must be 1 at least byte");
static_assert(sizeof(i16l) >= 2, "u16l must be 2 at least bytes");
static_assert(sizeof(i32l) >= 4, "u32l must be 4 at least bytes");
static_assert(sizeof(i64l) >= 8, "u64l must be 8 at least bytes");

static_assert(sizeof(u8) == 1, "u8 must be 1 byte");
static_assert(sizeof(u16) == 2, "u16 must be 2 bytes");
static_assert(sizeof(u32) == 4, "u32 must be 4 bytes");
static_assert(sizeof(u64) == 8, "u64 must be 8 bytes");

static_assert(sizeof(u8f) >= 1, "u8f must be at least 1 byte");
static_assert(sizeof(u16f) >= 2, "u16f must be at least 2 bytes");
static_assert(sizeof(u32f) >= 4, "u32f must be at least 4 bytes");
static_assert(sizeof(u64f) >= 8, "u64f must be at least 8 bytes");

static_assert(sizeof(u8l) >= 1, "u8l must be at least 1 byte");
static_assert(sizeof(u16l) >= 2, "u16l must be at least 2 bytes");
static_assert(sizeof(u32l) >= 4, "u32l must be at least 4 bytes");
static_assert(sizeof(u64l) >= 8, "u64l must be at least 8 bytes");

static_assert(sizeof(f32) == 4, "f32 must be 4 bytes");
static_assert(sizeof(f64) == 8, "f64 must be 8 bytes");

#endif //EMBERS_PRIMITIVES_H
