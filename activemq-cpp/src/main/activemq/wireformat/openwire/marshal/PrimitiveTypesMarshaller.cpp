/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "PrimitiveTypesMarshaller.h"

#include <decaf/io/ByteArrayInputStream.h>
#include <decaf/io/ByteArrayOutputStream.h>
#include <decaf/io/DataInputStream.h>
#include <decaf/io/DataOutputStream.h>
#include <activemq/wireformat/openwire/utils/OpenwireStringSupport.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/Short.h>

using namespace activemq;
using namespace activemq::util;
using namespace activemq::exceptions;
using namespace activemq::wireformat;
using namespace activemq::wireformat::openwire;
using namespace activemq::wireformat::openwire::utils;
using namespace activemq::wireformat::openwire::marshal;
using namespace decaf;
using namespace decaf::io;
using namespace decaf::lang;

///////////////////////////////////////////////////////////////////////////////
void PrimitiveTypesMarshaller::marshal( const activemq::util::PrimitiveMap* map,
                                      std::vector<unsigned char>& dest )
                                        throw ( decaf::lang::Exception ) {

    try {

        ByteArrayOutputStream bytesOut( dest );
        DataOutputStream dataOut( &bytesOut );

        if( map == NULL ) {
            dataOut.writeInt( -1 );
        } else {
            PrimitiveTypesMarshaller::marshalPrimitiveMap( dataOut, *map );
        }
    }
    AMQ_CATCH_RETHROW( decaf::lang::Exception )
    AMQ_CATCHALL_THROW( decaf::lang::Exception )
}

///////////////////////////////////////////////////////////////////////////////
void PrimitiveTypesMarshaller::unmarshal(
    activemq::util::PrimitiveMap* map,
    const std::vector<unsigned char>& src ) throw ( decaf::lang::Exception ) {

    try {

        if( map == NULL || src.empty() ) {
            return;
        }

        // Clear old data
        map->clear();

        ByteArrayInputStream bytesIn( src );
        DataInputStream dataIn( &bytesIn );
        PrimitiveTypesMarshaller::unmarshalPrimitiveMap( dataIn, *map );
    }
    AMQ_CATCH_RETHROW( decaf::lang::Exception )
    AMQ_CATCHALL_THROW( decaf::lang::Exception )
}

///////////////////////////////////////////////////////////////////////////////
void PrimitiveTypesMarshaller::marshal( const util::PrimitiveList* list,
                                        std::vector<unsigned char>& dest )
                                            throw ( decaf::lang::Exception ) {
    try {

        ByteArrayOutputStream bytesOut( dest );
        DataOutputStream dataOut( &bytesOut );

        if( list == NULL ) {
            dataOut.writeInt( -1 );
        } else {
            PrimitiveTypesMarshaller::marshalPrimitiveList( dataOut, *list );
        }
    }
    AMQ_CATCH_RETHROW( decaf::lang::Exception )
    AMQ_CATCHALL_THROW( decaf::lang::Exception )
}

///////////////////////////////////////////////////////////////////////////////
void PrimitiveTypesMarshaller::unmarshal( util::PrimitiveList* list,
                                          const std::vector<unsigned char>& src )
                                                throw ( decaf::lang::Exception ) {

    try {

        if( list == NULL || src.empty() ) {
            return;
        }

        // Clear old data
        list->clear();

        ByteArrayInputStream bytesIn( src );
        DataInputStream dataIn( &bytesIn );
        PrimitiveTypesMarshaller::unmarshalPrimitiveList( dataIn, *list );
    }
    AMQ_CATCH_RETHROW( decaf::lang::Exception )
    AMQ_CATCHALL_THROW( decaf::lang::Exception )
}

///////////////////////////////////////////////////////////////////////////////
void PrimitiveTypesMarshaller::marshalPrimitiveMap(
    decaf::io::DataOutputStream& dataOut,
    const decaf::util::Map<std::string, PrimitiveValueNode>& map )
        throw ( decaf::io::IOException ) {

    try{

        dataOut.writeInt( (int)map.size() );

        std::vector<std::string> keys = map.keySet();
        std::vector<std::string>::const_iterator iter = keys.begin();

        for(; iter != keys.end(); ++iter ) {

            dataOut.writeUTF( *iter );
            PrimitiveValueNode value = map.get( *iter );
            marshalPrimitive( dataOut, value );
        }
    }
    AMQ_CATCH_RETHROW( io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( Exception, io::IOException )
    AMQ_CATCHALL_THROW( io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void PrimitiveTypesMarshaller::marshalPrimitiveList(
    decaf::io::DataOutputStream& dataOut,
    const decaf::util::List<PrimitiveValueNode>& list )
        throw ( decaf::io::IOException ) {

    try{
        dataOut.writeInt( (int)list.size() );

        for( std::size_t ix = 0; ix < list.size(); ++ix ) {
            marshalPrimitive( dataOut, list.get( ix ) );
        }
    }
    AMQ_CATCH_RETHROW( io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( Exception, io::IOException )
    AMQ_CATCHALL_THROW( io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void PrimitiveTypesMarshaller::marshalPrimitive( io::DataOutputStream& dataOut,
                                               const activemq::util::PrimitiveValueNode& value )
                                                    throw ( decaf::io::IOException ) {

    try {

        if( value.getType() == PrimitiveValueNode::BOOLEAN_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::BOOLEAN_TYPE );
            dataOut.writeBoolean( value.getBool() );

        } else if( value.getType() == PrimitiveValueNode::BYTE_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::BYTE_TYPE );
            dataOut.writeByte( value.getByte() );

        } else if( value.getType() == PrimitiveValueNode::CHAR_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::CHAR_TYPE );
            dataOut.writeChar( value.getChar() );

        } else if( value.getType() == PrimitiveValueNode::SHORT_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::SHORT_TYPE );
            dataOut.writeShort( value.getShort() );

        } else if( value.getType() == PrimitiveValueNode::INTEGER_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::INTEGER_TYPE );
            dataOut.writeInt( value.getInt() );

        } else if( value.getType() == PrimitiveValueNode::LONG_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::LONG_TYPE );
            dataOut.writeLong( value.getLong() );

        } else if( value.getType() == PrimitiveValueNode::FLOAT_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::FLOAT_TYPE );
            dataOut.writeFloat( value.getFloat() );

        } else if( value.getType() == PrimitiveValueNode::DOUBLE_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::DOUBLE_TYPE );
            dataOut.writeDouble( value.getDouble() );

        } else if( value.getType() == PrimitiveValueNode::BYTE_ARRAY_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::BYTE_ARRAY_TYPE );

            std::vector<unsigned char> data = value.getByteArray();

            dataOut.writeInt( (int)data.size() );
            dataOut.write( data );

        } else if( value.getType() == PrimitiveValueNode::STRING_TYPE ) {

            std::string data = value.getString();

            // is the string big??
            if( data.size() > Short::MAX_VALUE / 4 ) {
                dataOut.writeByte( PrimitiveValueNode::BIG_STRING_TYPE );
                OpenwireStringSupport::writeString( dataOut, &data );
            } else {
                dataOut.writeByte( PrimitiveValueNode::STRING_TYPE );
                dataOut.writeUTF( data );
            }

        } else if( value.getType() == PrimitiveValueNode::LIST_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::LIST_TYPE );
            marshalPrimitiveList( dataOut, value.getList() );

        } else if( value.getType() == PrimitiveValueNode::MAP_TYPE ) {

            dataOut.writeByte( PrimitiveValueNode::MAP_TYPE );
            marshalPrimitiveMap( dataOut, value.getMap() );

        } else {
            throw IOException(
                __FILE__,
                __LINE__,
                "Object is not a primitive: ");
        }
    }
    AMQ_CATCH_RETHROW( io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( Exception, io::IOException )
    AMQ_CATCHALL_THROW( io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void PrimitiveTypesMarshaller::unmarshalPrimitiveMap(
    decaf::io::DataInputStream& dataIn, PrimitiveMap& map )
        throw ( decaf::io::IOException ) {

    try{

        int size = dataIn.readInt();

        if( size > 0 ) {
            for( int i=0; i < size; i++ ) {
                std::string key = dataIn.readUTF();
                map.put( key, unmarshalPrimitive( dataIn ) );
            }
        }
    }
    AMQ_CATCH_RETHROW( io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( Exception, io::IOException )
    AMQ_CATCHALL_THROW( io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void PrimitiveTypesMarshaller::unmarshalPrimitiveList(
    decaf::io::DataInputStream& dataIn,
    decaf::util::StlList<PrimitiveValueNode>& list )
        throw ( decaf::io::IOException ) {

    try{

        int size = dataIn.readInt();
        while( size-- > 0 ) {
            list.add( unmarshalPrimitive( dataIn ) );
        }
    }
    AMQ_CATCH_RETHROW( io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( Exception, io::IOException )
    AMQ_CATCHALL_THROW( io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
PrimitiveValueNode PrimitiveTypesMarshaller::unmarshalPrimitive(
    io::DataInputStream& dataIn ) throw ( decaf::io::IOException ) {

    try {

        unsigned char type = dataIn.readByte();

        PrimitiveValueNode value;

        switch( type ) {

            case PrimitiveValueNode::NULL_TYPE:
                value.clear();
                break;
            case PrimitiveValueNode::BYTE_TYPE:
                value.setByte( dataIn.readByte() );
                break;
            case PrimitiveValueNode::BOOLEAN_TYPE:
                value.setBool( dataIn.readBoolean() );
                break;
            case PrimitiveValueNode::CHAR_TYPE:
                value.setChar( dataIn.readChar() );
                break;
            case PrimitiveValueNode::SHORT_TYPE:
                value.setShort( dataIn.readShort() );
                break;
            case PrimitiveValueNode::INTEGER_TYPE:
                value.setInt( dataIn.readInt() );
                break;
            case PrimitiveValueNode::LONG_TYPE:
                value.setLong( dataIn.readLong() );
                break;
            case PrimitiveValueNode::FLOAT_TYPE:
                value.setFloat( dataIn.readFloat() );
                break;
            case PrimitiveValueNode::DOUBLE_TYPE:
                value.setDouble( dataIn.readDouble() );
                break;
            case PrimitiveValueNode::BYTE_ARRAY_TYPE:
            {
                int size = dataIn.readInt();
                std::vector<unsigned char> data;
                data.resize( size );
                dataIn.readFully( data );
                value.setByteArray( data );
                break;
            }
            case PrimitiveValueNode::STRING_TYPE:
                value.setString( dataIn.readUTF() );
                break;
            case PrimitiveValueNode::BIG_STRING_TYPE:
                value.setString( OpenwireStringSupport::readString( dataIn ) );
                break;
            case PrimitiveValueNode::LIST_TYPE:
            {
                PrimitiveList list;
                PrimitiveTypesMarshaller::unmarshalPrimitiveList( dataIn, list );
                value.setList( list );
                break;
            }
            case PrimitiveValueNode::MAP_TYPE:
            {
                PrimitiveMap map;
                PrimitiveTypesMarshaller::unmarshalPrimitiveMap( dataIn, map );
                value.setMap( map );
                break;
            }
            default:
                throw IOException(
                    __FILE__,
                    __LINE__,
                    "PrimitiveTypesMarshaller::unmarshalPrimitive - "
                    "Unsupported data type: ");
        }

        return value;
    }
    AMQ_CATCH_RETHROW( io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( Exception, io::IOException )
    AMQ_CATCHALL_THROW( io::IOException )
}