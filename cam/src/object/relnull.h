// $Header: r:/t2repos/thief2/src/object/relnull.h,v 1.4 2000/01/29 13:24:55 adurant Exp $
#pragma once

#ifndef __RELNULL_H
#define __RELNULL_H
#include <relation.h>

/////////////////////////////////////////////////////////////
// THE NULL RELATION
//
// Contains no links.
//

class cNullRelation : public IRelation
{
public:
   DECLARE_UNAGGREGATABLE();
   
   STDMETHOD_(const sRelationDesc*, Describe)() const;
   STDMETHOD_(RelationID,GetID)() const; 
   STDMETHOD(SetID)(RelationID ) ; 

   STDMETHOD_(const sRelationDataDesc*, DescribeData)() const;
   STDMETHOD_(IRelation*, Inverse)();
   STDMETHOD_(LinkID, Add)(ObjID source, ObjID dest);
   STDMETHOD_(LinkID, AddFull)(ObjID source, ObjID desc, void* data);
   STDMETHOD(Remove)(LinkID id); 
   STDMETHOD_(BOOL,Get)(LinkID id, sLink* out) const; 
   STDMETHOD(SetData)(LinkID id, void* data);
   STDMETHOD_(void*,GetData)(LinkID id);
   STDMETHOD_(ILinkQuery*,Query)(ObjID source, ObjID dest) const;
   STDMETHOD(Notify)(eRelationNotifyMsg msg, RelationNotifyData data);
   STDMETHOD(Listen)(RelationListenMsgSet interests, RelationListenFunc func, RelationListenerData data);   
   STDMETHOD_(LinkID, GetSingleLink)(ObjID source, ObjID dest);
   STDMETHOD_(BOOL, AnyLinks)(ObjID source, ObjID dest);
   
};

#endif // __RELNULL_H
