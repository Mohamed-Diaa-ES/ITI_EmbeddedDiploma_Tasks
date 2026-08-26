/**
 * @file    STD_TYPES.h
 * @brief   Standard data types used throughout the project.
 * @details Contains the definitions for fixed-width data types to ensure they are the same size on any machine.
 *           For example, it defines u8 so you always know it is exactly 1 byte.
 * @author  Mohammed Diaa <mohammeddiaato@gmail.com>
 */
#ifndef STD_TYPES_H
#define STD_TYPES_H

/**
 * @typedef u8
 * @brief   Unsigned 8-bit integer. 
 */
typedef unsigned char u8;

/**
 * @typedef s8
 * @brief   Signed 8-bit integer. 
 */
typedef signed char s8;

/**
 * @typedef u16
 * @brief   Unsigned 16-bit integer.
 */
typedef unsigned short int u16;

/**
 * @typedef s16
 * @brief   Signed 16-bit integer.
 */
typedef signed short int s16;

/**
 * @typedef u32
 * @brief   Unsigned 32-bit integer.
 */
typedef unsigned long int u32;

/**
 * @typedef s32
 * @brief   Signed 32-bit integer.
 */
typedef signed long int s32;

/**
 * @typedef u64
 * @brief   Unsigned 64-bit integer.
 */
typedef unsigned long long int u64;

/**
 * @typedef s64
 * @brief   Signed 64-bit integer. 
 */
typedef signed long long int s64;

/**
 * @typedef f32
 * @brief   32-bit floating point number.
 */
typedef float f32;

/**
 * @typedef f64
 * @brief   64-bit floating point number.
 */
typedef double f64;

#endif