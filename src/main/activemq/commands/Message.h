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

#ifndef _ACTIVEMQ_COMMANDS_MESSAGE_H_
#define _ACTIVEMQ_COMMANDS_MESSAGE_H_

// Turn off warning message for ignored exception specification
#ifdef _MSC_VER
#pragma warning( disable : 4290 )
#endif

#include <activemq/util/Config.h>
#include <activemq/commands/BaseCommand.h>
#include <activemq/commands/ProducerId.h>
#include <activemq/commands/ActiveMQDestination.h>
#include <activemq/commands/TransactionId.h>
#include <activemq/commands/ActiveMQDestination.h>
#include <activemq/commands/MessageId.h>
#include <activemq/commands/TransactionId.h>
#include <activemq/commands/ActiveMQDestination.h>
#include <activemq/commands/DataStructure.h>
#include <activemq/commands/ConsumerId.h>
#include <activemq/commands/BrokerId.h>
#include <activemq/commands/BrokerId.h>
#include <vector>
#include <string>

namespace activemq{
namespace commands{

    /*
     *
     *  Command and marshaling code for OpenWire format for Message
     *
     *
     *  NOTE!: This file is autogenerated - do not modify!
     *         if you need to make a change, please see the Java Classes
     *         in the activemq-openwire-generator module
     *
     */
    class AMQCPP_API Message : public BaseCommand {
    protected:

        static const unsigned int DEFAULT_MESSAGE_SIZE = 1024;

        ProducerId* producerId;
        ActiveMQDestination* destination;
        TransactionId* transactionId;
        ActiveMQDestination* originalDestination;
        MessageId* messageId;
        TransactionId* originalTransactionId;
        std::string groupID;
        int groupSequence;
        std::string correlationId;
        bool persistent;
        long long expiration;
        unsigned char priority;
        ActiveMQDestination* replyTo;
        long long timestamp;
        std::string type;
        std::vector<unsigned char> content;
        std::vector<unsigned char> marshalledProperties;
        DataStructure* dataStructure;
        ConsumerId* targetConsumerId;
        bool compressed;
        int redeliveryCounter;
        std::vector<BrokerId*> brokerPath;
        long long arrival;
        std::string userID;
        bool recievedByDFBridge;
        bool droppable;
        std::vector<BrokerId*> cluster;
        long long brokerInTime;
        long long brokerOutTime;

    public:

        const static unsigned char ID_MESSAGE = 0;

    public:

        Message();
        virtual ~Message();

        /**
         * Get the unique identifier that this object and its own
         * Marshaller share.
         * @returns new DataStructure type copy.
         */
        virtual unsigned char getDataStructureType() const;

        /**
         * Clone this object and return a new instance that the
         * caller now owns, this will be an exact copy of this one
         * @returns new copy of this object.
         */
        virtual Message* cloneDataStructure() const;

        /**
         * Copy the contents of the passed object into this object's
         * members, overwriting any existing data.
         * @param src - Source Object
         */
        virtual void copyDataStructure( const DataStructure* src );

        /**
         * Returns a string containing the information for this DataStructure
         * such as its type and value of its elements.
         * @return formatted string useful for debugging.
         */
        virtual std::string toString() const;

        /**
         * Compares the DataStructure passed in to this one, and returns if
         * they are equivalent.  Equivalent here means that they are of the
         * same type, and that each element of the objects are the same.
         * @returns true if DataStructure's are Equal.
         */
        virtual bool equals( const DataStructure* value ) const;

        /**
         * Returns the Size of this message in Bytes.
         * @returns number of bytes this message equates to.
         */
        virtual unsigned int getSize() const;

        /**
         * Allows a Visitor to visit this command and return a response to the
         * command based on the command type being visited.  The command will call
         * the proper processXXX method in the visitor.
         * 
         * @return a Response to the visitor being called or NULL if no response.
         */
        virtual commands::Command* visit( activemq::state::CommandVisitor* visitor )
            throw( exceptions::ActiveMQException );

        virtual const ProducerId* getProducerId() const;
        virtual ProducerId* getProducerId();
        virtual void setProducerId( ProducerId* producerId );

        virtual const ActiveMQDestination* getDestination() const;
        virtual ActiveMQDestination* getDestination();
        virtual void setDestination( ActiveMQDestination* destination );

        virtual const TransactionId* getTransactionId() const;
        virtual TransactionId* getTransactionId();
        virtual void setTransactionId( TransactionId* transactionId );

        virtual const ActiveMQDestination* getOriginalDestination() const;
        virtual ActiveMQDestination* getOriginalDestination();
        virtual void setOriginalDestination( ActiveMQDestination* originalDestination );

        virtual const MessageId* getMessageId() const;
        virtual MessageId* getMessageId();
        virtual void setMessageId( MessageId* messageId );

        virtual const TransactionId* getOriginalTransactionId() const;
        virtual TransactionId* getOriginalTransactionId();
        virtual void setOriginalTransactionId( TransactionId* originalTransactionId );

        virtual const std::string& getGroupID() const;
        virtual std::string& getGroupID();
        virtual void setGroupID( const std::string& groupID );

        virtual int getGroupSequence() const;
        virtual void setGroupSequence( int groupSequence );

        virtual const std::string& getCorrelationId() const;
        virtual std::string& getCorrelationId();
        virtual void setCorrelationId( const std::string& correlationId );

        virtual bool isPersistent() const;
        virtual void setPersistent( bool persistent );

        virtual long long getExpiration() const;
        virtual void setExpiration( long long expiration );

        virtual unsigned char getPriority() const;
        virtual void setPriority( unsigned char priority );

        virtual const ActiveMQDestination* getReplyTo() const;
        virtual ActiveMQDestination* getReplyTo();
        virtual void setReplyTo( ActiveMQDestination* replyTo );

        virtual long long getTimestamp() const;
        virtual void setTimestamp( long long timestamp );

        virtual const std::string& getType() const;
        virtual std::string& getType();
        virtual void setType( const std::string& type );

        virtual const std::vector<unsigned char>& getContent() const;
        virtual std::vector<unsigned char>& getContent();
        virtual void setContent( const std::vector<unsigned char>& content );

        virtual const std::vector<unsigned char>& getMarshalledProperties() const;
        virtual std::vector<unsigned char>& getMarshalledProperties();
        virtual void setMarshalledProperties( const std::vector<unsigned char>& marshalledProperties );

        virtual const DataStructure* getDataStructure() const;
        virtual DataStructure* getDataStructure();
        virtual void setDataStructure( DataStructure* dataStructure );

        virtual const ConsumerId* getTargetConsumerId() const;
        virtual ConsumerId* getTargetConsumerId();
        virtual void setTargetConsumerId( ConsumerId* targetConsumerId );

        virtual bool isCompressed() const;
        virtual void setCompressed( bool compressed );

        virtual int getRedeliveryCounter() const;
        virtual void setRedeliveryCounter( int redeliveryCounter );

        virtual const std::vector<BrokerId*>& getBrokerPath() const;
        virtual std::vector<BrokerId*>& getBrokerPath();
        virtual void setBrokerPath( const std::vector<BrokerId*>& brokerPath );

        virtual long long getArrival() const;
        virtual void setArrival( long long arrival );

        virtual const std::string& getUserID() const;
        virtual std::string& getUserID();
        virtual void setUserID( const std::string& userID );

        virtual bool isRecievedByDFBridge() const;
        virtual void setRecievedByDFBridge( bool recievedByDFBridge );

        virtual bool isDroppable() const;
        virtual void setDroppable( bool droppable );

        virtual const std::vector<BrokerId*>& getCluster() const;
        virtual std::vector<BrokerId*>& getCluster();
        virtual void setCluster( const std::vector<BrokerId*>& cluster );

        virtual long long getBrokerInTime() const;
        virtual void setBrokerInTime( long long brokerInTime );

        virtual long long getBrokerOutTime() const;
        virtual void setBrokerOutTime( long long brokerOutTime );

    };

}}

#endif /*_ACTIVEMQ_COMMANDS_MESSAGE_H_*/
