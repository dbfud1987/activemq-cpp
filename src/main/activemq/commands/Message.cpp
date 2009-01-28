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
#include <activemq/commands/Message.h>
#include <activemq/state/CommandVisitor.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::commands;
using namespace decaf::lang::exceptions;

/*
 *
 *  Command and marshaling code for OpenWire format for Message
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
Message::Message()
{
    this->producerId = NULL;
    this->destination = NULL;
    this->transactionId = NULL;
    this->originalDestination = NULL;
    this->messageId = NULL;
    this->originalTransactionId = NULL;
    this->groupID = "";
    this->groupSequence = 0;
    this->correlationId = "";
    this->persistent = false;
    this->expiration = 0;
    this->priority = 0;
    this->replyTo = NULL;
    this->timestamp = 0;
    this->type = "";
    this->dataStructure = NULL;
    this->targetConsumerId = NULL;
    this->compressed = false;
    this->redeliveryCounter = 0;
    this->arrival = 0;
    this->userID = "";
    this->recievedByDFBridge = false;
    this->droppable = false;
    this->brokerInTime = 0;
    this->brokerOutTime = 0;
}

////////////////////////////////////////////////////////////////////////////////
Message::~Message()
{
    delete this->producerId;
    delete this->destination;
    delete this->transactionId;
    delete this->originalDestination;
    delete this->messageId;
    delete this->originalTransactionId;
    delete this->replyTo;
    delete this->dataStructure;
    delete this->targetConsumerId;
    for( size_t ibrokerPath = 0; ibrokerPath < brokerPath.size(); ++ibrokerPath ) {
        delete brokerPath[ibrokerPath];
    }
    for( size_t icluster = 0; icluster < cluster.size(); ++icluster ) {
        delete cluster[icluster];
    }
}

////////////////////////////////////////////////////////////////////////////////
Message* Message::cloneDataStructure() const {
    Message* message = new Message();

    // Copy the data from the base class or classes
    message->copyDataStructure( this );

    return message;
}

////////////////////////////////////////////////////////////////////////////////
void Message::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const Message* srcPtr = dynamic_cast<const Message*>( src );

    if( srcPtr == NULL || src == NULL ) {

        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "Message::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getProducerId() != NULL ) {
        this->setProducerId(
            dynamic_cast<ProducerId*>(
                srcPtr->getProducerId()->cloneDataStructure() ) );
    }
    if( srcPtr->getDestination() != NULL ) {
        this->setDestination(
            dynamic_cast<ActiveMQDestination*>(
                srcPtr->getDestination()->cloneDataStructure() ) );
    }
    if( srcPtr->getTransactionId() != NULL ) {
        this->setTransactionId(
            dynamic_cast<TransactionId*>(
                srcPtr->getTransactionId()->cloneDataStructure() ) );
    }
    if( srcPtr->getOriginalDestination() != NULL ) {
        this->setOriginalDestination(
            dynamic_cast<ActiveMQDestination*>(
                srcPtr->getOriginalDestination()->cloneDataStructure() ) );
    }
    if( srcPtr->getMessageId() != NULL ) {
        this->setMessageId(
            dynamic_cast<MessageId*>(
                srcPtr->getMessageId()->cloneDataStructure() ) );
    }
    if( srcPtr->getOriginalTransactionId() != NULL ) {
        this->setOriginalTransactionId(
            dynamic_cast<TransactionId*>(
                srcPtr->getOriginalTransactionId()->cloneDataStructure() ) );
    }
    this->setGroupID( srcPtr->getGroupID() );
    this->setGroupSequence( srcPtr->getGroupSequence() );
    this->setCorrelationId( srcPtr->getCorrelationId() );
    this->setPersistent( srcPtr->isPersistent() );
    this->setExpiration( srcPtr->getExpiration() );
    this->setPriority( srcPtr->getPriority() );
    if( srcPtr->getReplyTo() != NULL ) {
        this->setReplyTo(
            dynamic_cast<ActiveMQDestination*>(
                srcPtr->getReplyTo()->cloneDataStructure() ) );
    }
    this->setTimestamp( srcPtr->getTimestamp() );
    this->setType( srcPtr->getType() );
    this->setContent( srcPtr->getContent() );
    this->setMarshalledProperties( srcPtr->getMarshalledProperties() );
    if( srcPtr->getDataStructure() != NULL ) {
        this->setDataStructure(
            dynamic_cast<DataStructure*>(
                srcPtr->getDataStructure()->cloneDataStructure() ) );
    }
    if( srcPtr->getTargetConsumerId() != NULL ) {
        this->setTargetConsumerId(
            dynamic_cast<ConsumerId*>(
                srcPtr->getTargetConsumerId()->cloneDataStructure() ) );
    }
    this->setCompressed( srcPtr->isCompressed() );
    this->setRedeliveryCounter( srcPtr->getRedeliveryCounter() );
    for( size_t ibrokerPath = 0; ibrokerPath < srcPtr->getBrokerPath().size(); ++ibrokerPath ) {
        if( srcPtr->getBrokerPath()[ibrokerPath] != NULL ) {
            this->getBrokerPath().push_back(
                dynamic_cast<BrokerId*>(
                    srcPtr->getBrokerPath()[ibrokerPath]->cloneDataStructure() ) );
        } else {
            this->getBrokerPath().push_back( NULL );
        }
    }
    this->setArrival( srcPtr->getArrival() );
    this->setUserID( srcPtr->getUserID() );
    this->setRecievedByDFBridge( srcPtr->isRecievedByDFBridge() );
    this->setDroppable( srcPtr->isDroppable() );
    for( size_t icluster = 0; icluster < srcPtr->getCluster().size(); ++icluster ) {
        if( srcPtr->getCluster()[icluster] != NULL ) {
            this->getCluster().push_back(
                dynamic_cast<BrokerId*>(
                    srcPtr->getCluster()[icluster]->cloneDataStructure() ) );
        } else {
            this->getCluster().push_back( NULL );
        }
    }
    this->setBrokerInTime( srcPtr->getBrokerInTime() );
    this->setBrokerOutTime( srcPtr->getBrokerOutTime() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char Message::getDataStructureType() const {
    return Message::ID_MESSAGE;
}

////////////////////////////////////////////////////////////////////////////////
std::string Message::toString() const {

    ostringstream stream;

    stream << "Begin Class = Message" << std::endl;
    stream << " Value of Message::ID_MESSAGE = 0" << std::endl;
    stream << " Value of ProducerId is Below:" << std::endl;
    if( this->getProducerId() != NULL ) {
        stream << this->getProducerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Destination is Below:" << std::endl;
    if( this->getDestination() != NULL ) {
        stream << this->getDestination()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of TransactionId is Below:" << std::endl;
    if( this->getTransactionId() != NULL ) {
        stream << this->getTransactionId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of OriginalDestination is Below:" << std::endl;
    if( this->getOriginalDestination() != NULL ) {
        stream << this->getOriginalDestination()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of MessageId is Below:" << std::endl;
    if( this->getMessageId() != NULL ) {
        stream << this->getMessageId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of OriginalTransactionId is Below:" << std::endl;
    if( this->getOriginalTransactionId() != NULL ) {
        stream << this->getOriginalTransactionId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of GroupID = " << this->getGroupID() << std::endl;
    stream << " Value of GroupSequence = " << this->getGroupSequence() << std::endl;
    stream << " Value of CorrelationId = " << this->getCorrelationId() << std::endl;
    stream << " Value of Persistent = " << this->isPersistent() << std::endl;
    stream << " Value of Expiration = " << this->getExpiration() << std::endl;
    stream << " Value of Priority = " << (int)this->getPriority() << std::endl;
    stream << " Value of ReplyTo is Below:" << std::endl;
    if( this->getReplyTo() != NULL ) {
        stream << this->getReplyTo()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Timestamp = " << this->getTimestamp() << std::endl;
    stream << " Value of Type = " << this->getType() << std::endl;
    for( size_t icontent = 0; icontent < this->getContent().size(); ++icontent ) {
        stream << " Value of Content[" << icontent << "] = " << this->getContent()[icontent] << std::endl;
    }
    for( size_t imarshalledProperties = 0; imarshalledProperties < this->getMarshalledProperties().size(); ++imarshalledProperties ) {
        stream << " Value of MarshalledProperties[" << imarshalledProperties << "] = " << this->getMarshalledProperties()[imarshalledProperties] << std::endl;
    }
    stream << " Value of DataStructure is Below:" << std::endl;
    if( this->getDataStructure() != NULL ) {
        stream << this->getDataStructure()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of TargetConsumerId is Below:" << std::endl;
    if( this->getTargetConsumerId() != NULL ) {
        stream << this->getTargetConsumerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Compressed = " << this->isCompressed() << std::endl;
    stream << " Value of RedeliveryCounter = " << this->getRedeliveryCounter() << std::endl;
    for( size_t ibrokerPath = 0; ibrokerPath < this->getBrokerPath().size(); ++ibrokerPath ) {
        stream << " Value of BrokerPath[" << ibrokerPath << "] is Below:" << std::endl;
        if( this->getBrokerPath()[ibrokerPath] != NULL ) {
            stream << this->getBrokerPath()[ibrokerPath]->toString() << std::endl;
        } else {
            stream << "   Object is NULL" << std::endl;
        }
    }
    stream << " Value of Arrival = " << this->getArrival() << std::endl;
    stream << " Value of UserID = " << this->getUserID() << std::endl;
    stream << " Value of RecievedByDFBridge = " << this->isRecievedByDFBridge() << std::endl;
    stream << " Value of Droppable = " << this->isDroppable() << std::endl;
    for( size_t icluster = 0; icluster < this->getCluster().size(); ++icluster ) {
        stream << " Value of Cluster[" << icluster << "] is Below:" << std::endl;
        if( this->getCluster()[icluster] != NULL ) {
            stream << this->getCluster()[icluster]->toString() << std::endl;
        } else {
            stream << "   Object is NULL" << std::endl;
        }
    }
    stream << " Value of BrokerInTime = " << this->getBrokerInTime() << std::endl;
    stream << " Value of BrokerOutTime = " << this->getBrokerOutTime() << std::endl;
    stream << BaseCommand::toString();
    stream << "End Class = Message" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool Message::equals( const DataStructure* value ) const {
    const Message* valuePtr = dynamic_cast<const Message*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getProducerId() != NULL ) {
        if( !this->getProducerId()->equals( valuePtr->getProducerId() ) ) {
            return false;
        }
    } else if( valuePtr->getProducerId() != NULL ) {
        return false;
    }
    if( this->getDestination() != NULL ) {
        if( !this->getDestination()->equals( valuePtr->getDestination() ) ) {
            return false;
        }
    } else if( valuePtr->getDestination() != NULL ) {
        return false;
    }
    if( this->getTransactionId() != NULL ) {
        if( !this->getTransactionId()->equals( valuePtr->getTransactionId() ) ) {
            return false;
        }
    } else if( valuePtr->getTransactionId() != NULL ) {
        return false;
    }
    if( this->getOriginalDestination() != NULL ) {
        if( !this->getOriginalDestination()->equals( valuePtr->getOriginalDestination() ) ) {
            return false;
        }
    } else if( valuePtr->getOriginalDestination() != NULL ) {
        return false;
    }
    if( this->getMessageId() != NULL ) {
        if( !this->getMessageId()->equals( valuePtr->getMessageId() ) ) {
            return false;
        }
    } else if( valuePtr->getMessageId() != NULL ) {
        return false;
    }
    if( this->getOriginalTransactionId() != NULL ) {
        if( !this->getOriginalTransactionId()->equals( valuePtr->getOriginalTransactionId() ) ) {
            return false;
        }
    } else if( valuePtr->getOriginalTransactionId() != NULL ) {
        return false;
    }
    if( this->getGroupID() != valuePtr->getGroupID() ) {
        return false;
    }
    if( this->getGroupSequence() != valuePtr->getGroupSequence() ) {
        return false;
    }
    if( this->getCorrelationId() != valuePtr->getCorrelationId() ) {
        return false;
    }
    if( this->isPersistent() != valuePtr->isPersistent() ) {
        return false;
    }
    if( this->getExpiration() != valuePtr->getExpiration() ) {
        return false;
    }
    if( this->getPriority() != valuePtr->getPriority() ) {
        return false;
    }
    if( this->getReplyTo() != NULL ) {
        if( !this->getReplyTo()->equals( valuePtr->getReplyTo() ) ) {
            return false;
        }
    } else if( valuePtr->getReplyTo() != NULL ) {
        return false;
    }
    if( this->getTimestamp() != valuePtr->getTimestamp() ) {
        return false;
    }
    if( this->getType() != valuePtr->getType() ) {
        return false;
    }
    for( size_t icontent = 0; icontent < this->getContent().size(); ++icontent ) {
        if( this->getContent()[icontent] != valuePtr->getContent()[icontent] ) {
            return false;
        }
    }
    for( size_t imarshalledProperties = 0; imarshalledProperties < this->getMarshalledProperties().size(); ++imarshalledProperties ) {
        if( this->getMarshalledProperties()[imarshalledProperties] != valuePtr->getMarshalledProperties()[imarshalledProperties] ) {
            return false;
        }
    }
    if( this->getDataStructure() != NULL ) {
        if( !this->getDataStructure()->equals( valuePtr->getDataStructure() ) ) {
            return false;
        }
    } else if( valuePtr->getDataStructure() != NULL ) {
        return false;
    }
    if( this->getTargetConsumerId() != NULL ) {
        if( !this->getTargetConsumerId()->equals( valuePtr->getTargetConsumerId() ) ) {
            return false;
        }
    } else if( valuePtr->getTargetConsumerId() != NULL ) {
        return false;
    }
    if( this->isCompressed() != valuePtr->isCompressed() ) {
        return false;
    }
    if( this->getRedeliveryCounter() != valuePtr->getRedeliveryCounter() ) {
        return false;
    }
    for( size_t ibrokerPath = 0; ibrokerPath < this->getBrokerPath().size(); ++ibrokerPath ) {
        if( this->getBrokerPath()[ibrokerPath] != NULL ) {
            if( !this->getBrokerPath()[ibrokerPath]->equals( valuePtr->getBrokerPath()[ibrokerPath] ) ) {
                return false;
            }
        } else if( valuePtr->getBrokerPath()[ibrokerPath] != NULL ) {
            return false;
        }
    }
    if( this->getArrival() != valuePtr->getArrival() ) {
        return false;
    }
    if( this->getUserID() != valuePtr->getUserID() ) {
        return false;
    }
    if( this->isRecievedByDFBridge() != valuePtr->isRecievedByDFBridge() ) {
        return false;
    }
    if( this->isDroppable() != valuePtr->isDroppable() ) {
        return false;
    }
    for( size_t icluster = 0; icluster < this->getCluster().size(); ++icluster ) {
        if( this->getCluster()[icluster] != NULL ) {
            if( !this->getCluster()[icluster]->equals( valuePtr->getCluster()[icluster] ) ) {
                return false;
            }
        } else if( valuePtr->getCluster()[icluster] != NULL ) {
            return false;
        }
    }
    if( this->getBrokerInTime() != valuePtr->getBrokerInTime() ) {
        return false;
    }
    if( this->getBrokerOutTime() != valuePtr->getBrokerOutTime() ) {
        return false;
    }
    if( !BaseCommand::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
unsigned int Message::getSize() const {

    unsigned int size = DEFAULT_MESSAGE_SIZE;

    size += (unsigned int)this->getContent().size();
    size += (unsigned int)this->getMarshalledProperties().size();

    return size;
}

////////////////////////////////////////////////////////////////////////////////
commands::Command* Message::visit( activemq::state::CommandVisitor* visitor ) 
    throw( exceptions::ActiveMQException ) {

    return visitor->processMessage( this );
}

////////////////////////////////////////////////////////////////////////////////
const ProducerId* Message::getProducerId() const {
    return producerId;
}

////////////////////////////////////////////////////////////////////////////////
ProducerId* Message::getProducerId() {
    return producerId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setProducerId(ProducerId* producerId ) {
    this->producerId = producerId;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* Message::getDestination() const {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* Message::getDestination() {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setDestination(ActiveMQDestination* destination ) {
    this->destination = destination;
}

////////////////////////////////////////////////////////////////////////////////
const TransactionId* Message::getTransactionId() const {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionId* Message::getTransactionId() {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setTransactionId(TransactionId* transactionId ) {
    this->transactionId = transactionId;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* Message::getOriginalDestination() const {
    return originalDestination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* Message::getOriginalDestination() {
    return originalDestination;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setOriginalDestination(ActiveMQDestination* originalDestination ) {
    this->originalDestination = originalDestination;
}

////////////////////////////////////////////////////////////////////////////////
const MessageId* Message::getMessageId() const {
    return messageId;
}

////////////////////////////////////////////////////////////////////////////////
MessageId* Message::getMessageId() {
    return messageId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setMessageId(MessageId* messageId ) {
    this->messageId = messageId;
}

////////////////////////////////////////////////////////////////////////////////
const TransactionId* Message::getOriginalTransactionId() const {
    return originalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionId* Message::getOriginalTransactionId() {
    return originalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setOriginalTransactionId(TransactionId* originalTransactionId ) {
    this->originalTransactionId = originalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Message::getGroupID() const {
    return groupID;
}

////////////////////////////////////////////////////////////////////////////////
std::string& Message::getGroupID() {
    return groupID;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setGroupID(const std::string& groupID ) {
    this->groupID = groupID;
}

////////////////////////////////////////////////////////////////////////////////
int Message::getGroupSequence() const {
    return groupSequence;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setGroupSequence(int groupSequence ) {
    this->groupSequence = groupSequence;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Message::getCorrelationId() const {
    return correlationId;
}

////////////////////////////////////////////////////////////////////////////////
std::string& Message::getCorrelationId() {
    return correlationId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setCorrelationId(const std::string& correlationId ) {
    this->correlationId = correlationId;
}

////////////////////////////////////////////////////////////////////////////////
bool Message::isPersistent() const {
    return persistent;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setPersistent(bool persistent ) {
    this->persistent = persistent;
}

////////////////////////////////////////////////////////////////////////////////
long long Message::getExpiration() const {
    return expiration;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setExpiration(long long expiration ) {
    this->expiration = expiration;
}

////////////////////////////////////////////////////////////////////////////////
unsigned char Message::getPriority() const {
    return priority;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setPriority(unsigned char priority ) {
    this->priority = priority;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* Message::getReplyTo() const {
    return replyTo;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* Message::getReplyTo() {
    return replyTo;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setReplyTo(ActiveMQDestination* replyTo ) {
    this->replyTo = replyTo;
}

////////////////////////////////////////////////////////////////////////////////
long long Message::getTimestamp() const {
    return timestamp;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setTimestamp(long long timestamp ) {
    this->timestamp = timestamp;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Message::getType() const {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
std::string& Message::getType() {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setType(const std::string& type ) {
    this->type = type;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<unsigned char>& Message::getContent() const {
    return content;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char>& Message::getContent() {
    return content;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setContent(const std::vector<unsigned char>& content ) {
    this->content = content;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<unsigned char>& Message::getMarshalledProperties() const {
    return marshalledProperties;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char>& Message::getMarshalledProperties() {
    return marshalledProperties;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setMarshalledProperties(const std::vector<unsigned char>& marshalledProperties ) {
    this->marshalledProperties = marshalledProperties;
}

////////////////////////////////////////////////////////////////////////////////
const DataStructure* Message::getDataStructure() const {
    return dataStructure;
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* Message::getDataStructure() {
    return dataStructure;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setDataStructure(DataStructure* dataStructure ) {
    this->dataStructure = dataStructure;
}

////////////////////////////////////////////////////////////////////////////////
const ConsumerId* Message::getTargetConsumerId() const {
    return targetConsumerId;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerId* Message::getTargetConsumerId() {
    return targetConsumerId;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setTargetConsumerId(ConsumerId* targetConsumerId ) {
    this->targetConsumerId = targetConsumerId;
}

////////////////////////////////////////////////////////////////////////////////
bool Message::isCompressed() const {
    return compressed;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setCompressed(bool compressed ) {
    this->compressed = compressed;
}

////////////////////////////////////////////////////////////////////////////////
int Message::getRedeliveryCounter() const {
    return redeliveryCounter;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setRedeliveryCounter(int redeliveryCounter ) {
    this->redeliveryCounter = redeliveryCounter;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<BrokerId*>& Message::getBrokerPath() const {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<BrokerId*>& Message::getBrokerPath() {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setBrokerPath(const std::vector<BrokerId*>& brokerPath ) {
    this->brokerPath = brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
long long Message::getArrival() const {
    return arrival;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setArrival(long long arrival ) {
    this->arrival = arrival;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Message::getUserID() const {
    return userID;
}

////////////////////////////////////////////////////////////////////////////////
std::string& Message::getUserID() {
    return userID;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setUserID(const std::string& userID ) {
    this->userID = userID;
}

////////////////////////////////////////////////////////////////////////////////
bool Message::isRecievedByDFBridge() const {
    return recievedByDFBridge;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setRecievedByDFBridge(bool recievedByDFBridge ) {
    this->recievedByDFBridge = recievedByDFBridge;
}

////////////////////////////////////////////////////////////////////////////////
bool Message::isDroppable() const {
    return droppable;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setDroppable(bool droppable ) {
    this->droppable = droppable;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<BrokerId*>& Message::getCluster() const {
    return cluster;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<BrokerId*>& Message::getCluster() {
    return cluster;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setCluster(const std::vector<BrokerId*>& cluster ) {
    this->cluster = cluster;
}

////////////////////////////////////////////////////////////////////////////////
long long Message::getBrokerInTime() const {
    return brokerInTime;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setBrokerInTime(long long brokerInTime ) {
    this->brokerInTime = brokerInTime;
}

////////////////////////////////////////////////////////////////////////////////
long long Message::getBrokerOutTime() const {
    return brokerOutTime;
}

////////////////////////////////////////////////////////////////////////////////
void Message::setBrokerOutTime(long long brokerOutTime ) {
    this->brokerOutTime = brokerOutTime;
}

