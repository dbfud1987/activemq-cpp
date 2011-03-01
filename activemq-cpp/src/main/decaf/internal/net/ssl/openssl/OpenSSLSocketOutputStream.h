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

#ifndef _DECAF_INTERNAL_NET_SSL_OPENSSL_OPENSSLSOCKETOUTPUTSTREAM_H_
#define _DECAF_INTERNAL_NET_SSL_OPENSSL_OPENSSLSOCKETOUTPUTSTREAM_H_

#include <decaf/util/Config.h>

#include <decaf/io/OutputStream.h>

namespace decaf {
namespace internal {
namespace net {
namespace ssl {
namespace openssl {

    class OpenSSLSocket;

    /**
     * OutputStream implementation used to write data to an OpenSSLSocket instance.
     *
     * @since 1.0
     */
    class DECAF_API OpenSSLSocketOutputStream : public decaf::io::OutputStream {
    private:

        OpenSSLSocket* socket;
        volatile bool closed;

    public:

        OpenSSLSocketOutputStream( OpenSSLSocket* socket );

        virtual ~OpenSSLSocketOutputStream();

        virtual void close() throw( decaf::io::IOException );

    protected:

        virtual void doWriteByte( unsigned char c ) throw ( decaf::io::IOException );

        virtual void doWriteArrayBounded( const unsigned char* buffer, int size, int offset, int length )
            throw ( decaf::io::IOException,
                    decaf::lang::exceptions::NullPointerException,
                    decaf::lang::exceptions::IndexOutOfBoundsException );

    };

}}}}}

#endif /* _DECAF_INTERNAL_NET_SSL_OPENSSL_OPENSSLSOCKETOUTPUTSTREAM_H_ */
