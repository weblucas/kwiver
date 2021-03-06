/*ckwg +29
 * Copyright 2016 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief Interface to vital uuid
 */

#ifndef KWIVER_VITAL_TYPES_UUID_H
#define KWIVER_VITAL_TYPES_UUID_H

#include <vital/vital_config.h>
#include <vital/vital_export.h>

#include <string>
#include <cstdint>


namespace kwiver {
namespace vital {

// ----------------------------------------------------------------
/**
 * @brief Container for UUID value
 *
 * This class represents a UUID. It is a light weight container for
 * the 128 bit UUID value. The value must be generated by other means.
 */
class VITAL_EXPORT uuid
{
public:
  typedef uint8_t uuid_data_t[16];

// -- CONSTRUCTORS --
/**
 * @brief Create UUID
 *
 * @param data Byte array to be held as UUID
 */
  uuid( const uuid_data_t& data );

  virtual ~uuid() VITAL_DEFAULT_DTOR

/**
 * @brief Return uuid value
 *
 *
 * @return Value of UUID
 */
  const uuid_data_t& value() const;

/**
 * @brief Format UUID for printing
 *
 * This method formats the UUID value in a standard format (8-4-4-4-12)
 *
 * @return UUID formatted in a string
 */
  std::string format() const;

/// equality operator
  bool operator==( const uuid& other );
  bool operator!=( const uuid& other );


private:
  uuid_data_t m_uuid;
}; // end class uuid


inline std::ostream& operator<<( std::ostream& str, const uuid& obj)
{
  str << obj.format();
  return str;
}

} } // end namespace

#endif /* KWIVER_VITAL_TYPES_UUID_H */
