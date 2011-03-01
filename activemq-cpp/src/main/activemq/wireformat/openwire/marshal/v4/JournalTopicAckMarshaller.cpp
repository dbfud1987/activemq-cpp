/*
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

#include <activemq/wireformat/openwire/marshal/v4/JournalTopicAckMarshaller.h>

#include <activemq/commands/JournalTopicAck.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/Pointer.h>

//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::commands;
using namespace activemq::wireformat;
using namespace activemq::wireformat::openwire;
using namespace activemq::wireformat::openwire::marshal;
using namespace activemq::wireformat::openwire::utils;
using namespace activemq::wireformat::openwire::marshal::v4;
using namespace decaf;
using namespace decaf::io;
using namespace decaf::lang;

///////////////////////////////////////////////////////////////////////////////
DataStructure* JournalTopicAckMarshaller::createObject() const {
    return new JournalTopicAck();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char JournalTopicAckMarshaller::getDataStructureType() const {
    return JournalTopicAck::ID_JOURNALTOPICACK;
}

///////////////////////////////////////////////////////////////////////////////
void JournalTopicAckMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

        JournalTopicAck* info =
            dynamic_cast<JournalTopicAck*>( dataStructure );
        info->setDestination( Pointer<ActiveMQDestination>( dynamic_cast< ActiveMQDestination* >(
            tightUnmarshalNestedObject( wireFormat, dataIn, bs ) ) ) );
        info->setMessageId( Pointer<MessageId>( dynamic_cast< MessageId* >(
            tightUnmarshalNestedObject( wireFormat, dataIn, bs ) ) ) );
        info->setMessageSequenceId( tightUnmarshalLong( wireFormat, dataIn, bs ) );
        info->setSubscritionName( tightUnmarshalString( dataIn, bs ) );
        info->setClientId( tightUnmarshalString( dataIn, bs ) );
        info->setTransactionId( Pointer<TransactionId>( dynamic_cast< TransactionId* >(
            tightUnmarshalNestedObject( wireFormat, dataIn, bs ) ) ) );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
int JournalTopicAckMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        JournalTopicAck* info =
            dynamic_cast<JournalTopicAck*>( dataStructure );

        int rc = BaseDataStreamMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
        rc += tightMarshalNestedObject1( wireFormat, info->getDestination().get(), bs );
        rc += tightMarshalNestedObject1( wireFormat, info->getMessageId().get(), bs );
        rc += tightMarshalLong1( wireFormat, info->getMessageSequenceId(), bs );
        rc += tightMarshalString1( info->getSubscritionName(), bs );
        rc += tightMarshalString1( info->getClientId(), bs );
        rc += tightMarshalNestedObject1( wireFormat, info->getTransactionId().get(), bs );

        return rc + 0;
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void JournalTopicAckMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

        JournalTopicAck* info =
            dynamic_cast<JournalTopicAck*>( dataStructure );
        tightMarshalNestedObject2( wireFormat, info->getDestination().get(), dataOut, bs );
        tightMarshalNestedObject2( wireFormat, info->getMessageId().get(), dataOut, bs );
        tightMarshalLong2( wireFormat, info->getMessageSequenceId(), dataOut, bs );
        tightMarshalString2( info->getSubscritionName(), dataOut, bs );
        tightMarshalString2( info->getClientId(), dataOut, bs );
        tightMarshalNestedObject2( wireFormat, info->getTransactionId().get(), dataOut, bs );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void JournalTopicAckMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
        JournalTopicAck* info =
            dynamic_cast<JournalTopicAck*>( dataStructure );
        info->setDestination( Pointer<ActiveMQDestination>( dynamic_cast< ActiveMQDestination* >( 
            looseUnmarshalNestedObject( wireFormat, dataIn ) ) ) );
        info->setMessageId( Pointer<MessageId>( dynamic_cast< MessageId* >( 
            looseUnmarshalNestedObject( wireFormat, dataIn ) ) ) );
        info->setMessageSequenceId( looseUnmarshalLong( wireFormat, dataIn ) );
        info->setSubscritionName( looseUnmarshalString( dataIn ) );
        info->setClientId( looseUnmarshalString( dataIn ) );
        info->setTransactionId( Pointer<TransactionId>( dynamic_cast< TransactionId* >( 
            looseUnmarshalNestedObject( wireFormat, dataIn ) ) ) );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void JournalTopicAckMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( decaf::io::IOException ) {

    try {

        JournalTopicAck* info =
            dynamic_cast<JournalTopicAck*>( dataStructure );
        BaseDataStreamMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

        looseMarshalNestedObject( wireFormat, info->getDestination().get(), dataOut );
        looseMarshalNestedObject( wireFormat, info->getMessageId().get(), dataOut );
        looseMarshalLong( wireFormat, info->getMessageSequenceId(), dataOut );
        looseMarshalString( info->getSubscritionName(), dataOut );
        looseMarshalString( info->getClientId(), dataOut );
        looseMarshalNestedObject( wireFormat, info->getTransactionId().get(), dataOut );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

