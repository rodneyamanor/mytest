//
// Generated file, do not edit! Created by nedtool 5.4 from KOPSMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "KOPSMsg_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(KDataMsg)

KDataMsg::KDataMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->msgType = 0;
    this->validUntilTime = 0;
    this->msgUniqueID = 0;
    this->initialInjectionTime = 0;
    this->realPayloadSize = 0;
    this->realPacketSize = 0;
    this->hopsTravelled = 0;
    this->destinationOriented = false;
    this->goodnessValue = 50;
    this->hopCount = 255;
    this->duplicates = 0;
    this->probabilityOfDelivery = 1.0;
}

KDataMsg::KDataMsg(const KDataMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

KDataMsg::~KDataMsg()
{
}

KDataMsg& KDataMsg::operator=(const KDataMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KDataMsg::copy(const KDataMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->dataName = other.dataName;
    this->dummyPayloadContent = other.dummyPayloadContent;
    this->msgType = other.msgType;
    this->validUntilTime = other.validUntilTime;
    this->msgUniqueID = other.msgUniqueID;
    this->initialInjectionTime = other.initialInjectionTime;
    this->realPayloadSize = other.realPayloadSize;
    this->realPacketSize = other.realPacketSize;
    this->hopsTravelled = other.hopsTravelled;
    this->initialOriginatorAddress = other.initialOriginatorAddress;
    this->finalDestinationAddress = other.finalDestinationAddress;
    this->destinationOriented = other.destinationOriented;
    this->goodnessValue = other.goodnessValue;
    this->messageID = other.messageID;
    this->hopCount = other.hopCount;
    this->duplicates = other.duplicates;
    this->probabilityOfDelivery = other.probabilityOfDelivery;
}

void KDataMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->dataName);
    doParsimPacking(b,this->dummyPayloadContent);
    doParsimPacking(b,this->msgType);
    doParsimPacking(b,this->validUntilTime);
    doParsimPacking(b,this->msgUniqueID);
    doParsimPacking(b,this->initialInjectionTime);
    doParsimPacking(b,this->realPayloadSize);
    doParsimPacking(b,this->realPacketSize);
    doParsimPacking(b,this->hopsTravelled);
    doParsimPacking(b,this->initialOriginatorAddress);
    doParsimPacking(b,this->finalDestinationAddress);
    doParsimPacking(b,this->destinationOriented);
    doParsimPacking(b,this->goodnessValue);
    doParsimPacking(b,this->messageID);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->duplicates);
    doParsimPacking(b,this->probabilityOfDelivery);
}

void KDataMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->dataName);
    doParsimUnpacking(b,this->dummyPayloadContent);
    doParsimUnpacking(b,this->msgType);
    doParsimUnpacking(b,this->validUntilTime);
    doParsimUnpacking(b,this->msgUniqueID);
    doParsimUnpacking(b,this->initialInjectionTime);
    doParsimUnpacking(b,this->realPayloadSize);
    doParsimUnpacking(b,this->realPacketSize);
    doParsimUnpacking(b,this->hopsTravelled);
    doParsimUnpacking(b,this->initialOriginatorAddress);
    doParsimUnpacking(b,this->finalDestinationAddress);
    doParsimUnpacking(b,this->destinationOriented);
    doParsimUnpacking(b,this->goodnessValue);
    doParsimUnpacking(b,this->messageID);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->duplicates);
    doParsimUnpacking(b,this->probabilityOfDelivery);
}

const char * KDataMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KDataMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KDataMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KDataMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

const char * KDataMsg::getDataName() const
{
    return this->dataName.c_str();
}

void KDataMsg::setDataName(const char * dataName)
{
    this->dataName = dataName;
}

const char * KDataMsg::getDummyPayloadContent() const
{
    return this->dummyPayloadContent.c_str();
}

void KDataMsg::setDummyPayloadContent(const char * dummyPayloadContent)
{
    this->dummyPayloadContent = dummyPayloadContent;
}

int KDataMsg::getMsgType() const
{
    return this->msgType;
}

void KDataMsg::setMsgType(int msgType)
{
    this->msgType = msgType;
}

::omnetpp::simtime_t KDataMsg::getValidUntilTime() const
{
    return this->validUntilTime;
}

void KDataMsg::setValidUntilTime(::omnetpp::simtime_t validUntilTime)
{
    this->validUntilTime = validUntilTime;
}

int KDataMsg::getMsgUniqueID() const
{
    return this->msgUniqueID;
}

void KDataMsg::setMsgUniqueID(int msgUniqueID)
{
    this->msgUniqueID = msgUniqueID;
}

::omnetpp::simtime_t KDataMsg::getInitialInjectionTime() const
{
    return this->initialInjectionTime;
}

void KDataMsg::setInitialInjectionTime(::omnetpp::simtime_t initialInjectionTime)
{
    this->initialInjectionTime = initialInjectionTime;
}

int KDataMsg::getRealPayloadSize() const
{
    return this->realPayloadSize;
}

void KDataMsg::setRealPayloadSize(int realPayloadSize)
{
    this->realPayloadSize = realPayloadSize;
}

int KDataMsg::getRealPacketSize() const
{
    return this->realPacketSize;
}

void KDataMsg::setRealPacketSize(int realPacketSize)
{
    this->realPacketSize = realPacketSize;
}

int KDataMsg::getHopsTravelled() const
{
    return this->hopsTravelled;
}

void KDataMsg::setHopsTravelled(int hopsTravelled)
{
    this->hopsTravelled = hopsTravelled;
}

const char * KDataMsg::getInitialOriginatorAddress() const
{
    return this->initialOriginatorAddress.c_str();
}

void KDataMsg::setInitialOriginatorAddress(const char * initialOriginatorAddress)
{
    this->initialOriginatorAddress = initialOriginatorAddress;
}

const char * KDataMsg::getFinalDestinationAddress() const
{
    return this->finalDestinationAddress.c_str();
}

void KDataMsg::setFinalDestinationAddress(const char * finalDestinationAddress)
{
    this->finalDestinationAddress = finalDestinationAddress;
}

bool KDataMsg::getDestinationOriented() const
{
    return this->destinationOriented;
}

void KDataMsg::setDestinationOriented(bool destinationOriented)
{
    this->destinationOriented = destinationOriented;
}

int KDataMsg::getGoodnessValue() const
{
    return this->goodnessValue;
}

void KDataMsg::setGoodnessValue(int goodnessValue)
{
    this->goodnessValue = goodnessValue;
}

const char * KDataMsg::getMessageID() const
{
    return this->messageID.c_str();
}

void KDataMsg::setMessageID(const char * messageID)
{
    this->messageID = messageID;
}

int KDataMsg::getHopCount() const
{
    return this->hopCount;
}

void KDataMsg::setHopCount(int hopCount)
{
    this->hopCount = hopCount;
}

int KDataMsg::getDuplicates() const
{
    return this->duplicates;
}

void KDataMsg::setDuplicates(int duplicates)
{
    this->duplicates = duplicates;
}

double KDataMsg::getProbabilityOfDelivery() const
{
    return this->probabilityOfDelivery;
}

void KDataMsg::setProbabilityOfDelivery(double probabilityOfDelivery)
{
    this->probabilityOfDelivery = probabilityOfDelivery;
}

class KDataMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KDataMsgDescriptor();
    virtual ~KDataMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KDataMsgDescriptor)

KDataMsgDescriptor::KDataMsgDescriptor() : omnetpp::cClassDescriptor("KDataMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KDataMsgDescriptor::~KDataMsgDescriptor()
{
    delete[] propertynames;
}

bool KDataMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KDataMsg *>(obj)!=nullptr;
}

const char **KDataMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KDataMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KDataMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 19+basedesc->getFieldCount() : 19;
}

unsigned int KDataMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<19) ? fieldTypeFlags[field] : 0;
}

const char *KDataMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "dataName",
        "dummyPayloadContent",
        "msgType",
        "validUntilTime",
        "msgUniqueID",
        "initialInjectionTime",
        "realPayloadSize",
        "realPacketSize",
        "hopsTravelled",
        "initialOriginatorAddress",
        "finalDestinationAddress",
        "destinationOriented",
        "goodnessValue",
        "messageID",
        "hopCount",
        "duplicates",
        "probabilityOfDelivery",
    };
    return (field>=0 && field<19) ? fieldNames[field] : nullptr;
}

int KDataMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataName")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "dummyPayloadContent")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgType")==0) return base+4;
    if (fieldName[0]=='v' && strcmp(fieldName, "validUntilTime")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgUniqueID")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "initialInjectionTime")==0) return base+7;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPayloadSize")==0) return base+8;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPacketSize")==0) return base+9;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopsTravelled")==0) return base+10;
    if (fieldName[0]=='i' && strcmp(fieldName, "initialOriginatorAddress")==0) return base+11;
    if (fieldName[0]=='f' && strcmp(fieldName, "finalDestinationAddress")==0) return base+12;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationOriented")==0) return base+13;
    if (fieldName[0]=='g' && strcmp(fieldName, "goodnessValue")==0) return base+14;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageID")==0) return base+15;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+16;
    if (fieldName[0]=='d' && strcmp(fieldName, "duplicates")==0) return base+17;
    if (fieldName[0]=='p' && strcmp(fieldName, "probabilityOfDelivery")==0) return base+18;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KDataMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "string",
        "int",
        "simtime_t",
        "int",
        "simtime_t",
        "int",
        "int",
        "int",
        "string",
        "string",
        "bool",
        "int",
        "string",
        "int",
        "int",
        "double",
    };
    return (field>=0 && field<19) ? fieldTypeStrings[field] : nullptr;
}

const char **KDataMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KDataMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KDataMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *KDataMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KDataMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: return oppstring2string(pp->getDataName());
        case 3: return oppstring2string(pp->getDummyPayloadContent());
        case 4: return long2string(pp->getMsgType());
        case 5: return simtime2string(pp->getValidUntilTime());
        case 6: return long2string(pp->getMsgUniqueID());
        case 7: return simtime2string(pp->getInitialInjectionTime());
        case 8: return long2string(pp->getRealPayloadSize());
        case 9: return long2string(pp->getRealPacketSize());
        case 10: return long2string(pp->getHopsTravelled());
        case 11: return oppstring2string(pp->getInitialOriginatorAddress());
        case 12: return oppstring2string(pp->getFinalDestinationAddress());
        case 13: return bool2string(pp->getDestinationOriented());
        case 14: return long2string(pp->getGoodnessValue());
        case 15: return oppstring2string(pp->getMessageID());
        case 16: return long2string(pp->getHopCount());
        case 17: return long2string(pp->getDuplicates());
        case 18: return double2string(pp->getProbabilityOfDelivery());
        default: return "";
    }
}

bool KDataMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 2: pp->setDataName((value)); return true;
        case 3: pp->setDummyPayloadContent((value)); return true;
        case 4: pp->setMsgType(string2long(value)); return true;
        case 5: pp->setValidUntilTime(string2simtime(value)); return true;
        case 6: pp->setMsgUniqueID(string2long(value)); return true;
        case 7: pp->setInitialInjectionTime(string2simtime(value)); return true;
        case 8: pp->setRealPayloadSize(string2long(value)); return true;
        case 9: pp->setRealPacketSize(string2long(value)); return true;
        case 10: pp->setHopsTravelled(string2long(value)); return true;
        case 11: pp->setInitialOriginatorAddress((value)); return true;
        case 12: pp->setFinalDestinationAddress((value)); return true;
        case 13: pp->setDestinationOriented(string2bool(value)); return true;
        case 14: pp->setGoodnessValue(string2long(value)); return true;
        case 15: pp->setMessageID((value)); return true;
        case 16: pp->setHopCount(string2long(value)); return true;
        case 17: pp->setDuplicates(string2long(value)); return true;
        case 18: pp->setProbabilityOfDelivery(string2double(value)); return true;
        default: return false;
    }
}

const char *KDataMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KDataMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KDataMsg *pp = (KDataMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(KFeedbackMsg)

KFeedbackMsg::KFeedbackMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->realPacketSize = 0;
    this->goodnessValue = 0;
    this->feedbackType = 0;
}

KFeedbackMsg::KFeedbackMsg(const KFeedbackMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

KFeedbackMsg::~KFeedbackMsg()
{
}

KFeedbackMsg& KFeedbackMsg::operator=(const KFeedbackMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KFeedbackMsg::copy(const KFeedbackMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->dataName = other.dataName;
    this->realPacketSize = other.realPacketSize;
    this->goodnessValue = other.goodnessValue;
    this->feedbackType = other.feedbackType;
}

void KFeedbackMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->dataName);
    doParsimPacking(b,this->realPacketSize);
    doParsimPacking(b,this->goodnessValue);
    doParsimPacking(b,this->feedbackType);
}

void KFeedbackMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->dataName);
    doParsimUnpacking(b,this->realPacketSize);
    doParsimUnpacking(b,this->goodnessValue);
    doParsimUnpacking(b,this->feedbackType);
}

const char * KFeedbackMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KFeedbackMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KFeedbackMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KFeedbackMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

const char * KFeedbackMsg::getDataName() const
{
    return this->dataName.c_str();
}

void KFeedbackMsg::setDataName(const char * dataName)
{
    this->dataName = dataName;
}

int KFeedbackMsg::getRealPacketSize() const
{
    return this->realPacketSize;
}

void KFeedbackMsg::setRealPacketSize(int realPacketSize)
{
    this->realPacketSize = realPacketSize;
}

int KFeedbackMsg::getGoodnessValue() const
{
    return this->goodnessValue;
}

void KFeedbackMsg::setGoodnessValue(int goodnessValue)
{
    this->goodnessValue = goodnessValue;
}

int KFeedbackMsg::getFeedbackType() const
{
    return this->feedbackType;
}

void KFeedbackMsg::setFeedbackType(int feedbackType)
{
    this->feedbackType = feedbackType;
}

class KFeedbackMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KFeedbackMsgDescriptor();
    virtual ~KFeedbackMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KFeedbackMsgDescriptor)

KFeedbackMsgDescriptor::KFeedbackMsgDescriptor() : omnetpp::cClassDescriptor("KFeedbackMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KFeedbackMsgDescriptor::~KFeedbackMsgDescriptor()
{
    delete[] propertynames;
}

bool KFeedbackMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KFeedbackMsg *>(obj)!=nullptr;
}

const char **KFeedbackMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KFeedbackMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KFeedbackMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int KFeedbackMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *KFeedbackMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "dataName",
        "realPacketSize",
        "goodnessValue",
        "feedbackType",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int KFeedbackMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataName")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPacketSize")==0) return base+3;
    if (fieldName[0]=='g' && strcmp(fieldName, "goodnessValue")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "feedbackType")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KFeedbackMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **KFeedbackMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KFeedbackMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KFeedbackMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KFeedbackMsg *pp = (KFeedbackMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *KFeedbackMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KFeedbackMsg *pp = (KFeedbackMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KFeedbackMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KFeedbackMsg *pp = (KFeedbackMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: return oppstring2string(pp->getDataName());
        case 3: return long2string(pp->getRealPacketSize());
        case 4: return long2string(pp->getGoodnessValue());
        case 5: return long2string(pp->getFeedbackType());
        default: return "";
    }
}

bool KFeedbackMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KFeedbackMsg *pp = (KFeedbackMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 2: pp->setDataName((value)); return true;
        case 3: pp->setRealPacketSize(string2long(value)); return true;
        case 4: pp->setGoodnessValue(string2long(value)); return true;
        case 5: pp->setFeedbackType(string2long(value)); return true;
        default: return false;
    }
}

const char *KFeedbackMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KFeedbackMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KFeedbackMsg *pp = (KFeedbackMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(KSummaryVectorMsg)

KSummaryVectorMsg::KSummaryVectorMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->realPacketSize = 0;
    messageIDHashVector_arraysize = 0;
    this->messageIDHashVector = 0;
}

KSummaryVectorMsg::KSummaryVectorMsg(const KSummaryVectorMsg& other) : ::omnetpp::cPacket(other)
{
    messageIDHashVector_arraysize = 0;
    this->messageIDHashVector = 0;
    copy(other);
}

KSummaryVectorMsg::~KSummaryVectorMsg()
{
    delete [] this->messageIDHashVector;
}

KSummaryVectorMsg& KSummaryVectorMsg::operator=(const KSummaryVectorMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KSummaryVectorMsg::copy(const KSummaryVectorMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->realPacketSize = other.realPacketSize;
    delete [] this->messageIDHashVector;
    this->messageIDHashVector = (other.messageIDHashVector_arraysize==0) ? nullptr : new ::omnetpp::opp_string[other.messageIDHashVector_arraysize];
    messageIDHashVector_arraysize = other.messageIDHashVector_arraysize;
    for (unsigned int i=0; i<messageIDHashVector_arraysize; i++)
        this->messageIDHashVector[i] = other.messageIDHashVector[i];
}

void KSummaryVectorMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->realPacketSize);
    b->pack(messageIDHashVector_arraysize);
    doParsimArrayPacking(b,this->messageIDHashVector,messageIDHashVector_arraysize);
}

void KSummaryVectorMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->realPacketSize);
    delete [] this->messageIDHashVector;
    b->unpack(messageIDHashVector_arraysize);
    if (messageIDHashVector_arraysize==0) {
        this->messageIDHashVector = 0;
    } else {
        this->messageIDHashVector = new ::omnetpp::opp_string[messageIDHashVector_arraysize];
        doParsimArrayUnpacking(b,this->messageIDHashVector,messageIDHashVector_arraysize);
    }
}

const char * KSummaryVectorMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KSummaryVectorMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KSummaryVectorMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KSummaryVectorMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

int KSummaryVectorMsg::getRealPacketSize() const
{
    return this->realPacketSize;
}

void KSummaryVectorMsg::setRealPacketSize(int realPacketSize)
{
    this->realPacketSize = realPacketSize;
}

void KSummaryVectorMsg::setMessageIDHashVectorArraySize(unsigned int size)
{
    ::omnetpp::opp_string *messageIDHashVector2 = (size==0) ? nullptr : new ::omnetpp::opp_string[size];
    unsigned int sz = messageIDHashVector_arraysize < size ? messageIDHashVector_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        messageIDHashVector2[i] = this->messageIDHashVector[i];
    for (unsigned int i=sz; i<size; i++)
        messageIDHashVector2[i] = 0;
    messageIDHashVector_arraysize = size;
    delete [] this->messageIDHashVector;
    this->messageIDHashVector = messageIDHashVector2;
}

unsigned int KSummaryVectorMsg::getMessageIDHashVectorArraySize() const
{
    return messageIDHashVector_arraysize;
}

const char * KSummaryVectorMsg::getMessageIDHashVector(unsigned int k) const
{
    if (k>=messageIDHashVector_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", messageIDHashVector_arraysize, k);
    return this->messageIDHashVector[k].c_str();
}

void KSummaryVectorMsg::setMessageIDHashVector(unsigned int k, const char * messageIDHashVector)
{
    if (k>=messageIDHashVector_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", messageIDHashVector_arraysize, k);
    this->messageIDHashVector[k] = messageIDHashVector;
}

class KSummaryVectorMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KSummaryVectorMsgDescriptor();
    virtual ~KSummaryVectorMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KSummaryVectorMsgDescriptor)

KSummaryVectorMsgDescriptor::KSummaryVectorMsgDescriptor() : omnetpp::cClassDescriptor("KSummaryVectorMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KSummaryVectorMsgDescriptor::~KSummaryVectorMsgDescriptor()
{
    delete[] propertynames;
}

bool KSummaryVectorMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KSummaryVectorMsg *>(obj)!=nullptr;
}

const char **KSummaryVectorMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KSummaryVectorMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KSummaryVectorMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int KSummaryVectorMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *KSummaryVectorMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "realPacketSize",
        "messageIDHashVector",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int KSummaryVectorMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPacketSize")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageIDHashVector")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KSummaryVectorMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
        "string",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **KSummaryVectorMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KSummaryVectorMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KSummaryVectorMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        case 3: return pp->getMessageIDHashVectorArraySize();
        default: return 0;
    }
}

const char *KSummaryVectorMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KSummaryVectorMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: return long2string(pp->getRealPacketSize());
        case 3: return oppstring2string(pp->getMessageIDHashVector(i));
        default: return "";
    }
}

bool KSummaryVectorMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 2: pp->setRealPacketSize(string2long(value)); return true;
        case 3: pp->setMessageIDHashVector(i,(value)); return true;
        default: return false;
    }
}

const char *KSummaryVectorMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KSummaryVectorMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KSummaryVectorMsg *pp = (KSummaryVectorMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(KDataRequestMsg)

KDataRequestMsg::KDataRequestMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->realPacketSize = 0;
    messageIDHashVector_arraysize = 0;
    this->messageIDHashVector = 0;
}

KDataRequestMsg::KDataRequestMsg(const KDataRequestMsg& other) : ::omnetpp::cPacket(other)
{
    messageIDHashVector_arraysize = 0;
    this->messageIDHashVector = 0;
    copy(other);
}

KDataRequestMsg::~KDataRequestMsg()
{
    delete [] this->messageIDHashVector;
}

KDataRequestMsg& KDataRequestMsg::operator=(const KDataRequestMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KDataRequestMsg::copy(const KDataRequestMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->realPacketSize = other.realPacketSize;
    delete [] this->messageIDHashVector;
    this->messageIDHashVector = (other.messageIDHashVector_arraysize==0) ? nullptr : new ::omnetpp::opp_string[other.messageIDHashVector_arraysize];
    messageIDHashVector_arraysize = other.messageIDHashVector_arraysize;
    for (unsigned int i=0; i<messageIDHashVector_arraysize; i++)
        this->messageIDHashVector[i] = other.messageIDHashVector[i];
    this->initialOriginatorAddress = other.initialOriginatorAddress;
}

void KDataRequestMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->realPacketSize);
    b->pack(messageIDHashVector_arraysize);
    doParsimArrayPacking(b,this->messageIDHashVector,messageIDHashVector_arraysize);
    doParsimPacking(b,this->initialOriginatorAddress);
}

void KDataRequestMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->realPacketSize);
    delete [] this->messageIDHashVector;
    b->unpack(messageIDHashVector_arraysize);
    if (messageIDHashVector_arraysize==0) {
        this->messageIDHashVector = 0;
    } else {
        this->messageIDHashVector = new ::omnetpp::opp_string[messageIDHashVector_arraysize];
        doParsimArrayUnpacking(b,this->messageIDHashVector,messageIDHashVector_arraysize);
    }
    doParsimUnpacking(b,this->initialOriginatorAddress);
}

const char * KDataRequestMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KDataRequestMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KDataRequestMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KDataRequestMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

int KDataRequestMsg::getRealPacketSize() const
{
    return this->realPacketSize;
}

void KDataRequestMsg::setRealPacketSize(int realPacketSize)
{
    this->realPacketSize = realPacketSize;
}

void KDataRequestMsg::setMessageIDHashVectorArraySize(unsigned int size)
{
    ::omnetpp::opp_string *messageIDHashVector2 = (size==0) ? nullptr : new ::omnetpp::opp_string[size];
    unsigned int sz = messageIDHashVector_arraysize < size ? messageIDHashVector_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        messageIDHashVector2[i] = this->messageIDHashVector[i];
    for (unsigned int i=sz; i<size; i++)
        messageIDHashVector2[i] = 0;
    messageIDHashVector_arraysize = size;
    delete [] this->messageIDHashVector;
    this->messageIDHashVector = messageIDHashVector2;
}

unsigned int KDataRequestMsg::getMessageIDHashVectorArraySize() const
{
    return messageIDHashVector_arraysize;
}

const char * KDataRequestMsg::getMessageIDHashVector(unsigned int k) const
{
    if (k>=messageIDHashVector_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", messageIDHashVector_arraysize, k);
    return this->messageIDHashVector[k].c_str();
}

void KDataRequestMsg::setMessageIDHashVector(unsigned int k, const char * messageIDHashVector)
{
    if (k>=messageIDHashVector_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", messageIDHashVector_arraysize, k);
    this->messageIDHashVector[k] = messageIDHashVector;
}

const char * KDataRequestMsg::getInitialOriginatorAddress() const
{
    return this->initialOriginatorAddress.c_str();
}

void KDataRequestMsg::setInitialOriginatorAddress(const char * initialOriginatorAddress)
{
    this->initialOriginatorAddress = initialOriginatorAddress;
}

class KDataRequestMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KDataRequestMsgDescriptor();
    virtual ~KDataRequestMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KDataRequestMsgDescriptor)

KDataRequestMsgDescriptor::KDataRequestMsgDescriptor() : omnetpp::cClassDescriptor("KDataRequestMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KDataRequestMsgDescriptor::~KDataRequestMsgDescriptor()
{
    delete[] propertynames;
}

bool KDataRequestMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KDataRequestMsg *>(obj)!=nullptr;
}

const char **KDataRequestMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KDataRequestMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KDataRequestMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int KDataRequestMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *KDataRequestMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "realPacketSize",
        "messageIDHashVector",
        "initialOriginatorAddress",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int KDataRequestMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPacketSize")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageIDHashVector")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "initialOriginatorAddress")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KDataRequestMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
        "string",
        "string",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **KDataRequestMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KDataRequestMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KDataRequestMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        case 3: return pp->getMessageIDHashVectorArraySize();
        default: return 0;
    }
}

const char *KDataRequestMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KDataRequestMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: return long2string(pp->getRealPacketSize());
        case 3: return oppstring2string(pp->getMessageIDHashVector(i));
        case 4: return oppstring2string(pp->getInitialOriginatorAddress());
        default: return "";
    }
}

bool KDataRequestMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 2: pp->setRealPacketSize(string2long(value)); return true;
        case 3: pp->setMessageIDHashVector(i,(value)); return true;
        case 4: pp->setInitialOriginatorAddress((value)); return true;
        default: return false;
    }
}

const char *KDataRequestMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KDataRequestMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KDataRequestMsg *pp = (KDataRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("reactionType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("reactionType"));
    e->insert(ignore, "ignore");
    e->insert(comment, "comment");
    e->insert(save, "save");
)

Register_Class(KReactionMsg)

KReactionMsg::KReactionMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->reaction = 0;
}

KReactionMsg::KReactionMsg(const KReactionMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

KReactionMsg::~KReactionMsg()
{
}

KReactionMsg& KReactionMsg::operator=(const KReactionMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KReactionMsg::copy(const KReactionMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->dataName = other.dataName;
    this->reaction = other.reaction;
}

void KReactionMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->dataName);
    doParsimPacking(b,this->reaction);
}

void KReactionMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->dataName);
    doParsimUnpacking(b,this->reaction);
}

const char * KReactionMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KReactionMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KReactionMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KReactionMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

const char * KReactionMsg::getDataName() const
{
    return this->dataName.c_str();
}

void KReactionMsg::setDataName(const char * dataName)
{
    this->dataName = dataName;
}

int KReactionMsg::getReaction() const
{
    return this->reaction;
}

void KReactionMsg::setReaction(int reaction)
{
    this->reaction = reaction;
}

class KReactionMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KReactionMsgDescriptor();
    virtual ~KReactionMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KReactionMsgDescriptor)

KReactionMsgDescriptor::KReactionMsgDescriptor() : omnetpp::cClassDescriptor("KReactionMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KReactionMsgDescriptor::~KReactionMsgDescriptor()
{
    delete[] propertynames;
}

bool KReactionMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KReactionMsg *>(obj)!=nullptr;
}

const char **KReactionMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KReactionMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KReactionMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int KReactionMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *KReactionMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "dataName",
        "reaction",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int KReactionMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataName")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "reaction")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KReactionMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **KReactionMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *KReactionMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3:
            if (!strcmp(propertyname,"enum")) return "reactionType";
            return nullptr;
        default: return nullptr;
    }
}

int KReactionMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KReactionMsg *pp = (KReactionMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *KReactionMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KReactionMsg *pp = (KReactionMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KReactionMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KReactionMsg *pp = (KReactionMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: return oppstring2string(pp->getDataName());
        case 3: return enum2string(pp->getReaction(), "reactionType");
        default: return "";
    }
}

bool KReactionMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KReactionMsg *pp = (KReactionMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 2: pp->setDataName((value)); return true;
        case 3: pp->setReaction((reactionType)string2enum(value, "reactionType")); return true;
        default: return false;
    }
}

const char *KReactionMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KReactionMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KReactionMsg *pp = (KReactionMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(KDPtableRequestMsg)

KDPtableRequestMsg::KDPtableRequestMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->realPacketSize = 0;
}

KDPtableRequestMsg::KDPtableRequestMsg(const KDPtableRequestMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

KDPtableRequestMsg::~KDPtableRequestMsg()
{
}

KDPtableRequestMsg& KDPtableRequestMsg::operator=(const KDPtableRequestMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KDPtableRequestMsg::copy(const KDPtableRequestMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    this->realPacketSize = other.realPacketSize;
}

void KDPtableRequestMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->realPacketSize);
}

void KDPtableRequestMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->realPacketSize);
}

const char * KDPtableRequestMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KDPtableRequestMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KDPtableRequestMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KDPtableRequestMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

int KDPtableRequestMsg::getRealPacketSize() const
{
    return this->realPacketSize;
}

void KDPtableRequestMsg::setRealPacketSize(int realPacketSize)
{
    this->realPacketSize = realPacketSize;
}

class KDPtableRequestMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KDPtableRequestMsgDescriptor();
    virtual ~KDPtableRequestMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KDPtableRequestMsgDescriptor)

KDPtableRequestMsgDescriptor::KDPtableRequestMsgDescriptor() : omnetpp::cClassDescriptor("KDPtableRequestMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KDPtableRequestMsgDescriptor::~KDPtableRequestMsgDescriptor()
{
    delete[] propertynames;
}

bool KDPtableRequestMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KDPtableRequestMsg *>(obj)!=nullptr;
}

const char **KDPtableRequestMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KDPtableRequestMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KDPtableRequestMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int KDPtableRequestMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *KDPtableRequestMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "realPacketSize",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int KDPtableRequestMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPacketSize")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KDPtableRequestMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **KDPtableRequestMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KDPtableRequestMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KDPtableRequestMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KDPtableRequestMsg *pp = (KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *KDPtableRequestMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDPtableRequestMsg *pp = (KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KDPtableRequestMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDPtableRequestMsg *pp = (KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: return long2string(pp->getRealPacketSize());
        default: return "";
    }
}

bool KDPtableRequestMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KDPtableRequestMsg *pp = (KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 2: pp->setRealPacketSize(string2long(value)); return true;
        default: return false;
    }
}

const char *KDPtableRequestMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KDPtableRequestMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KDPtableRequestMsg *pp = (KDPtableRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

MsgDelivPredictability::MsgDelivPredictability()
{
    this->nodeDP = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const MsgDelivPredictability& a)
{
    doParsimPacking(b,a.nodeMACAddress);
    doParsimPacking(b,a.nodeDP);
}

void __doUnpacking(omnetpp::cCommBuffer *b, MsgDelivPredictability& a)
{
    doParsimUnpacking(b,a.nodeMACAddress);
    doParsimUnpacking(b,a.nodeDP);
}

class MsgDelivPredictabilityDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    MsgDelivPredictabilityDescriptor();
    virtual ~MsgDelivPredictabilityDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MsgDelivPredictabilityDescriptor)

MsgDelivPredictabilityDescriptor::MsgDelivPredictabilityDescriptor() : omnetpp::cClassDescriptor("MsgDelivPredictability", "")
{
    propertynames = nullptr;
}

MsgDelivPredictabilityDescriptor::~MsgDelivPredictabilityDescriptor()
{
    delete[] propertynames;
}

bool MsgDelivPredictabilityDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MsgDelivPredictability *>(obj)!=nullptr;
}

const char **MsgDelivPredictabilityDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MsgDelivPredictabilityDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MsgDelivPredictabilityDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int MsgDelivPredictabilityDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *MsgDelivPredictabilityDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nodeMACAddress",
        "nodeDP",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int MsgDelivPredictabilityDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeMACAddress")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeDP")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MsgDelivPredictabilityDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **MsgDelivPredictabilityDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MsgDelivPredictabilityDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MsgDelivPredictabilityDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MsgDelivPredictability *pp = (MsgDelivPredictability *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MsgDelivPredictabilityDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MsgDelivPredictability *pp = (MsgDelivPredictability *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MsgDelivPredictabilityDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MsgDelivPredictability *pp = (MsgDelivPredictability *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->nodeMACAddress);
        case 1: return double2string(pp->nodeDP);
        default: return "";
    }
}

bool MsgDelivPredictabilityDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MsgDelivPredictability *pp = (MsgDelivPredictability *)object; (void)pp;
    switch (field) {
        case 0: pp->nodeMACAddress = (value); return true;
        case 1: pp->nodeDP = string2double(value); return true;
        default: return false;
    }
}

const char *MsgDelivPredictabilityDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *MsgDelivPredictabilityDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MsgDelivPredictability *pp = (MsgDelivPredictability *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(KDPtableDataMsg)

KDPtableDataMsg::KDPtableDataMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    dpList_arraysize = 0;
    this->dpList = 0;
    this->realPacketSize = 0;
}

KDPtableDataMsg::KDPtableDataMsg(const KDPtableDataMsg& other) : ::omnetpp::cPacket(other)
{
    dpList_arraysize = 0;
    this->dpList = 0;
    copy(other);
}

KDPtableDataMsg::~KDPtableDataMsg()
{
    delete [] this->dpList;
}

KDPtableDataMsg& KDPtableDataMsg::operator=(const KDPtableDataMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KDPtableDataMsg::copy(const KDPtableDataMsg& other)
{
    this->sourceAddress = other.sourceAddress;
    this->destinationAddress = other.destinationAddress;
    delete [] this->dpList;
    this->dpList = (other.dpList_arraysize==0) ? nullptr : new MsgDelivPredictability[other.dpList_arraysize];
    dpList_arraysize = other.dpList_arraysize;
    for (unsigned int i=0; i<dpList_arraysize; i++)
        this->dpList[i] = other.dpList[i];
    this->realPacketSize = other.realPacketSize;
}

void KDPtableDataMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->destinationAddress);
    b->pack(dpList_arraysize);
    doParsimArrayPacking(b,this->dpList,dpList_arraysize);
    doParsimPacking(b,this->realPacketSize);
}

void KDPtableDataMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->destinationAddress);
    delete [] this->dpList;
    b->unpack(dpList_arraysize);
    if (dpList_arraysize==0) {
        this->dpList = 0;
    } else {
        this->dpList = new MsgDelivPredictability[dpList_arraysize];
        doParsimArrayUnpacking(b,this->dpList,dpList_arraysize);
    }
    doParsimUnpacking(b,this->realPacketSize);
}

const char * KDPtableDataMsg::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void KDPtableDataMsg::setSourceAddress(const char * sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

const char * KDPtableDataMsg::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void KDPtableDataMsg::setDestinationAddress(const char * destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

void KDPtableDataMsg::setDpListArraySize(unsigned int size)
{
    MsgDelivPredictability *dpList2 = (size==0) ? nullptr : new MsgDelivPredictability[size];
    unsigned int sz = dpList_arraysize < size ? dpList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        dpList2[i] = this->dpList[i];
    dpList_arraysize = size;
    delete [] this->dpList;
    this->dpList = dpList2;
}

unsigned int KDPtableDataMsg::getDpListArraySize() const
{
    return dpList_arraysize;
}

MsgDelivPredictability& KDPtableDataMsg::getDpList(unsigned int k)
{
    if (k>=dpList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", dpList_arraysize, k);
    return this->dpList[k];
}

void KDPtableDataMsg::setDpList(unsigned int k, const MsgDelivPredictability& dpList)
{
    if (k>=dpList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", dpList_arraysize, k);
    this->dpList[k] = dpList;
}

int KDPtableDataMsg::getRealPacketSize() const
{
    return this->realPacketSize;
}

void KDPtableDataMsg::setRealPacketSize(int realPacketSize)
{
    this->realPacketSize = realPacketSize;
}

class KDPtableDataMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KDPtableDataMsgDescriptor();
    virtual ~KDPtableDataMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KDPtableDataMsgDescriptor)

KDPtableDataMsgDescriptor::KDPtableDataMsgDescriptor() : omnetpp::cClassDescriptor("KDPtableDataMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KDPtableDataMsgDescriptor::~KDPtableDataMsgDescriptor()
{
    delete[] propertynames;
}

bool KDPtableDataMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KDPtableDataMsg *>(obj)!=nullptr;
}

const char **KDPtableDataMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KDPtableDataMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KDPtableDataMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int KDPtableDataMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *KDPtableDataMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceAddress",
        "destinationAddress",
        "dpList",
        "realPacketSize",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int KDPtableDataMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "dpList")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "realPacketSize")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KDPtableDataMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "MsgDelivPredictability",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **KDPtableDataMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KDPtableDataMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KDPtableDataMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KDPtableDataMsg *pp = (KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        case 2: return pp->getDpListArraySize();
        default: return 0;
    }
}

const char *KDPtableDataMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDPtableDataMsg *pp = (KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KDPtableDataMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KDPtableDataMsg *pp = (KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSourceAddress());
        case 1: return oppstring2string(pp->getDestinationAddress());
        case 2: {std::stringstream out; out << pp->getDpList(i); return out.str();}
        case 3: return long2string(pp->getRealPacketSize());
        default: return "";
    }
}

bool KDPtableDataMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KDPtableDataMsg *pp = (KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceAddress((value)); return true;
        case 1: pp->setDestinationAddress((value)); return true;
        case 3: pp->setRealPacketSize(string2long(value)); return true;
        default: return false;
    }
}

const char *KDPtableDataMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(MsgDelivPredictability));
        default: return nullptr;
    };
}

void *KDPtableDataMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KDPtableDataMsg *pp = (KDPtableDataMsg *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getDpList(i)); break;
        default: return nullptr;
    }
}

Register_Class(KStatisticsMsg)

KStatisticsMsg::KStatisticsMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->likedData = false;
    this->dataCountReceivable = 0;
    this->dataBytesReceivable = 0;
}

KStatisticsMsg::KStatisticsMsg(const KStatisticsMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

KStatisticsMsg::~KStatisticsMsg()
{
}

KStatisticsMsg& KStatisticsMsg::operator=(const KStatisticsMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void KStatisticsMsg::copy(const KStatisticsMsg& other)
{
    this->likedData = other.likedData;
    this->dataCountReceivable = other.dataCountReceivable;
    this->dataBytesReceivable = other.dataBytesReceivable;
}

void KStatisticsMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->likedData);
    doParsimPacking(b,this->dataCountReceivable);
    doParsimPacking(b,this->dataBytesReceivable);
}

void KStatisticsMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->likedData);
    doParsimUnpacking(b,this->dataCountReceivable);
    doParsimUnpacking(b,this->dataBytesReceivable);
}

bool KStatisticsMsg::getLikedData() const
{
    return this->likedData;
}

void KStatisticsMsg::setLikedData(bool likedData)
{
    this->likedData = likedData;
}

int KStatisticsMsg::getDataCountReceivable() const
{
    return this->dataCountReceivable;
}

void KStatisticsMsg::setDataCountReceivable(int dataCountReceivable)
{
    this->dataCountReceivable = dataCountReceivable;
}

int KStatisticsMsg::getDataBytesReceivable() const
{
    return this->dataBytesReceivable;
}

void KStatisticsMsg::setDataBytesReceivable(int dataBytesReceivable)
{
    this->dataBytesReceivable = dataBytesReceivable;
}

class KStatisticsMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    KStatisticsMsgDescriptor();
    virtual ~KStatisticsMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(KStatisticsMsgDescriptor)

KStatisticsMsgDescriptor::KStatisticsMsgDescriptor() : omnetpp::cClassDescriptor("KStatisticsMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

KStatisticsMsgDescriptor::~KStatisticsMsgDescriptor()
{
    delete[] propertynames;
}

bool KStatisticsMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<KStatisticsMsg *>(obj)!=nullptr;
}

const char **KStatisticsMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *KStatisticsMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int KStatisticsMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int KStatisticsMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *KStatisticsMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "likedData",
        "dataCountReceivable",
        "dataBytesReceivable",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int KStatisticsMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "likedData")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataCountReceivable")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataBytesReceivable")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *KStatisticsMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **KStatisticsMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *KStatisticsMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int KStatisticsMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    KStatisticsMsg *pp = (KStatisticsMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *KStatisticsMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KStatisticsMsg *pp = (KStatisticsMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string KStatisticsMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    KStatisticsMsg *pp = (KStatisticsMsg *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getLikedData());
        case 1: return long2string(pp->getDataCountReceivable());
        case 2: return long2string(pp->getDataBytesReceivable());
        default: return "";
    }
}

bool KStatisticsMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    KStatisticsMsg *pp = (KStatisticsMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setLikedData(string2bool(value)); return true;
        case 1: pp->setDataCountReceivable(string2long(value)); return true;
        case 2: pp->setDataBytesReceivable(string2long(value)); return true;
        default: return false;
    }
}

const char *KStatisticsMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *KStatisticsMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    KStatisticsMsg *pp = (KStatisticsMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


