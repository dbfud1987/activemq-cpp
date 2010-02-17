/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _DECAF_UTIL_ZIP_DEFLATEROUTPUTSTREAM_H_
#define _DECAF_UTIL_ZIP_DEFLATEROUTPUTSTREAM_H_

#include <decaf/util/Config.h>

#include <decaf/io/FilterOutputStream.h>
#include <decaf/io/IOException.h>
#include <decaf/util/zip/Deflater.h>

namespace decaf {
namespace util {
namespace zip {

    /**
     *
     */
    class DECAF_API DeflaterOutputStream : public decaf::io::FilterOutputStream {
    public:

        DeflaterOutputStream( decaf::io::OutputStream* outputStream, bool own = false );

        virtual ~DeflaterOutputStream();

    };

}}}

#endif /* _DECAF_UTIL_ZIP_DEFLATEROUTPUTSTREAM_H_ */