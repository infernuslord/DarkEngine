/////////////////////////////////////////////////////////////////////////////
// $Header: x:/prj/tech/libsrc/res2/RCS/resapi.h 1.6 1998/06/29 12:07:52 JUSTIN Exp $
//
// -------------------
// Resource System API
// -------------------
//
// Description of interfaces:
// 
// IResMan 
//    
//    Name-based resource management. Convenience interfaces for 
//    StructuredStorage creation, and LRU maintanance. Allows for 
//    "Type Sets" to be installed, defined by the client, that know 
//    how to create specific IRes implementations based on stream 
//    name (extension), and can implement optional memory and file 
//    loading abilities.
// 
//  IRes
// 
//    Typed name-based resources. Maintains lock count, provides 
//    accessors for synchronous/asynchronous loading, extraction. 
//    Talks to resource manager for named resource-raw data LRU 
//    association. A StorageFactory may create client-specific 
//    implementations to do special loading/memory management. 
//    Mutiple instances may exist for a given resource - mixed or 
//    same resource interpretation, but the Resource Manager will 
//    only keep one instance of the raw data.
// 
//  IResType
//
//    Defines a specific "type" of data. You create an IRes from an
//    IResType, and the type remains associated with the IRes.
//
//  IResMemOverride
//    
//    An optional interface that can be attached to an IRes aggregate 
//    when IResFactory creates it. Provides special memory handling 
//    abilities.
//

 
#ifndef __RESAPILG_H
#define __RESAPILG_H

#include <lg.h>
#include <comtools.h>

//
// We include the old resource system mainly due to a naming conflict;
// if res.h is to be included, it has to come before resapi.h.
// 
// @TBD: we should fix this, by removing the naming conflict. Both res and
// resapi define "sResMemStats". We should probably change the name here...
//
#include <res.h>

#pragma once
#pragma pack(4)

F_DECLARE_INTERFACE(IResMan);
F_DECLARE_INTERFACE(IRes);
F_DECLARE_INTERFACE(IResStore);
F_DECLARE_INTERFACE(IResType);
F_DECLARE_INTERFACE(IResMemOverride);
F_DECLARE_INTERFACE(IStore);
F_DECLARE_INTERFACE(IStoreHierarchy);
F_DECLARE_INTERFACE(IStoreFactory);
F_DECLARE_INTERFACE(IStoreManager);
F_DECLARE_INTERFACE(IStoreStream);
F_DECLARE_INTERFACE(ISearchPath);

// Sorry, can't mix old 16-bit Windows API and this API
#undef UnlockResource

///////////////////////////////////////////////////////////////////////////////
//
// Create the resource system and add it to the global app-object
//

#define Res2Create() \
{ \
    IUnknown * pAppUnknown = AppGetObj(IUnknown); \
    _Res2Create(IID_TO_REFIID(IID_IResMan), NULL, pAppUnknown); \
    COMRelease(pAppUnknown); \
}

//
// Creates a Resource Manager, aggregating it with specfied pOuter,
//
EXTERN tResult LGAPI
_Res2Create(REFIID, IResMan ** ppResMan, IUnknown * pOuter);


///////////////////////////////////////////////////////////////////////////////
//
// Callback types
//

///////////////////////////////////////
//
// Async lock callback
//
// When callback is called, pResource is *not* locked for client, 
// so client should not release. pResource will be AddRef'd by 
// Async system, then released after this callback is made. If an 
// Extract was requested, the buffer originally given will be 
// passed back, and size will be that passed in.
//
// @TBD (justin, 5-18-98): It would be nice to return the actual size
// of the data here, but that will take some mucking deep in
// cResARQFulfiller. At least DoFulfill needs to be changed, and it
// needs some way to find out what the actual loaded size was. For now,
// the caller should be able to find out the answer from IRes::GetSize.
// 
typedef void (*tResAsyncCallback)(IRes * pResource, 
                                  void * pData, 
                                  ulong  nBufSize, 
                                  void * pClientData);

///////////////////////////////////////
//
// Block extraction callback
//
// pResource is NOT AddRef'd. Like IStream, returns buffer, bytes, and block index
//

typedef long (*tResBlockCallback)(IRes * pResource, 
                                  void * pBuf, 
                                  long   nNumBytes, 
                                  long   nIx, 
                                  void * pClientData);

///////////////////////////////////////
//
// Resource from a storage callback.
//
// This is called by IResMan::PrepAllResources; it is called once for
// each resource found in the given storage. It is up to this callback
// to decide whether it is interested in the resource, and to Lock it
// if so.
//
typedef void (*tStoredResCallback)(IRes *pRes,
                                   IStore *pStore,
                                   void *pClientData);

///////////////////////////////////////
//
// The callback from IResType::EnumerateExts().
//
typedef void (*tResEnumExtsCallback)(const char *pExt, 
                                     IResType *,
                                     void *pClientData);

///////////////////////////////////////////////////////////////////////////////
//
// Statistics
//

enum eResStatMode
{
   kResStats_Off,
   kResStats_On,
   kResStats_Verbose,
   
   kResStats_IntMax = 0xffffffff                 // ensure 32 bits
   
};

typedef enum eResStatMode eResStatMode;

///////////////////////////////////////
//
// This structure is also defined in "res.h", so we only bother to define
// it if it isn't already defined. Implication: res.h should be #included
// before resapi.h.
//
#ifndef __RES_H
typedef struct sResMemStats
{
   ulong reserved;

   // From Windows:
   ulong memoryLoad;                             // percent of memory in use
   ulong totalPhys;                              // bytes of physical memory
   ulong availPhys;                              // free physical memory bytes
   ulong totalPageFile;                          // bytes of paging file
   ulong availPageFile;                          // free bytes of paging file
   ulong totalVirtual;                           // user bytes of address space
   ulong availVirtual;                           // free user bytes

   // From Resource system
   ulong allocCap;
   ulong totalMalloc;
   ulong lockedMalloc;
   ulong cachedMalloc;

} sResMemStats;
#endif

///////////////////////////////////////

//
// Flags for MakeResource
//
#define RES_IS_STATIC 0x01

///////////////////////////////////////////////////////////////////////////////
//
// INTERFACE: IResMan
//
// Weakness: Association between IRes implemenations and installed types.
//
// Multiple calls to "Open" with the same file will create new 
// instances of an IStore - its up to the IStoreFactory 
// implementation to ensure this. There is transient data 
// associated with a StructuredStorage in the form of the storage 
// name and location.
//

#undef INTERFACE
#define INTERFACE IResMan

DECLARE_INTERFACE_(IResMan, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Get a new, empty ISearchPath, which can be set up to look for
   // resources along.
   //
   STDMETHOD_(ISearchPath *, NewSearchPath)(THIS) PURE;

   //
   // Set the default search path to be used for opening storages.
   // This can be ignored if you always pass in explicit paths to
   // the appropriate methods. This will make a *reference* to the
   // given path; changes to the path will be immediately reflected.
   // Clear the default path by calling this with NULL.
   //
   STDMETHOD_(void, SetDefaultPath)(THIS_ ISearchPath *pPath) PURE;

   //
   // Given the name of a resource file, this loads that file in, and
   // returns the resulting resource. If a search path is specified, that
   // will be searched for the resource; otherwise, the default will be
   // used. The given name may have a directory path relative to the given
   // search path. If you know that a resource has already been found and
   // loaded (or want to test that), call PrepResource with neither a path
   // nor a default path. It will return the already-loaded resource if it
   // is found, or NULL if it hasn't been loaded.
   //
   // Prepping a resource involves two steps: getting the storage that it
   // is contained within, and binding the resource within that storage.
   // If you need finer-grained control over the process, use the GetStore
   // and MakeResource methods below. After the resource is bound, you may
   // Lock it when you actually want to get at its data.
   //
   // Note that only one resource with any given name will be found by
   // the resource system; it assumes a flat namespace.
   //
   // Returns the IRes if it could be found and loaded, or NULL if not.
   //
   STDMETHOD_(IRes *, PrepResource) (THIS_ 
                                     const char *resName,
                                     ISearchPath *pPath) PURE;

   //
   // Similar to PrepResource, but allows you to specify the type desired,
   // and does not require that the resource's extension be specified. This
   // is mostly a sop to Dark, which internally mostly doesn't have the
   // file extensions. This will try finding the named resource, using all
   // of the valid extensions for the given type. However, PrepResource is
   // probably a little faster.
   //
   STDMETHOD_(IRes *, PrepTypedResource) (THIS_
                                          const char *resName,
                                          const char *typeName,
                                          ISearchPath *pPath) PURE;

   //
   // Prepare all of the resources whose names match the given pattern,
   // found along the given path. If the pattern is NULL, then prep all
   // resources.
   //
   // For each resource found, the given callback will be called. It is
   // up to that callback to Lock the resource if it is interested in it;
   // no guarantees are made that the storage or resource will be kept
   // around afterward otherwise. Note that the resource will not necessarily
   // be loaded into memory at this point; it will be just as if PrepResource
   // had been called on it.
   //
   // pClientData is a pointer to arbitrary memory, and can be used by
   // the caller to pass information through to the callback.
   //
   STDMETHOD_(void, PrepAllResources) (THIS_
                                       const char *pPattern,
                                       ISearchPath *pPath,
                                       tStoredResCallback,
                                       void *pClientData) PURE;

   //
   // Same as PrepAllResource, but it will only find resources of the
   // specified type.
   //
   STDMETHOD_(void, PrepAllTypedResources) (THIS_
                                            const char *pPattern,
                                            ISearchPath *pPath,
                                            const char *pTypeName,
                                            tStoredResCallback,
                                            void *pClientData) PURE;

   //
   // Given a storage to look into, and the name of a stream, this will
   // get a resource corresponding to that stream. It will make a
   // best-guess of what IResType is appropriate for that resource
   // (based on its name), and create an IRes for it. Note that this
   // does not necessarily actually load the resource into memory; you
   // cannot count on having it in memory until after you Lock it.
   //
   // MakeResource can take flags controlling its behaviour. Currently,
   // the only flag allowed is RES_IS_STATIC. If this is set, then this
   // resource will be fixed to the given storage; if not, the resource
   // could be rebound to a different storage later.
   //
   // This will return an IRes, even if the named resource doesn't actually
   // exist in storage. However, in such a case, IRes->Lock will return null.
   //
   STDMETHOD_(IRes *, MakeResource) (THIS_ 
                                     IStore *pStore, 
                                     const char *pName, 
                                     const uint fBindFlags) PURE;

   //
   // This is the same as MakeResource, except that instead of simply
   // binding to the default resource type for the named stream, it will
   // bind it to the named type, assuming that that type is registered.
   // This allows a single stream to serve many different resource types.
   //
   STDMETHOD_(IRes *, MakeTypedResource) (THIS_
                                          IStore *pStore,
                                          const char *pName,
                                          const char *pTypeName,
                                          const uint fBindFlags) PURE;

   //
   // This takes an existing IRes, and creates a new one with the same
   // underlying stream, but the specified type.
   //
   STDMETHOD_(IRes *, MakeRetypedResource) (THIS_
                                            IRes *pOldRes,
                                            const char *pTypeName,
                                            const uint fBindFlags) PURE;

   // 
   // Tries to get the named storage. To get a storage along a search path,
   // use ISearchPath::Find instead. Returns NULL if this storage can't be
   // found.
   //
   // Note that this is mainly a convenience method; any IStore may be
   // used to make resources with.
   //
   STDMETHOD_(IStore *, GetStore) (THIS_ 
                                   const char *pPathName) PURE;

   ////////////////////////////////////
   //
   // IStores are created through an IStoreFactory which is registered
   // here; it decides which Factory to use based on the extension of the
   // file. Similarly, IRes are created through an IResType, which is
   // registered based on the extensions it understands.
   //
   // If multiple factories understand the same extension, the last one
   // registered will be used to create the IStore/IRes.
   //
   // There is a default "type", called "RawBinary"; if we try to open a
   // resource that has no registered type, we will use that default
   // for it. This provides only very simplistic capabilities. Similarly,
   // there is a default storage factory that deals with ordinary
   // filesystem directories.
   //
   // Returns FAILED iff the given factory is invalid or unuseable; otherwise
   // returns SUCCEEDED.
   //
   STDMETHOD_(BOOL, RegisterResType) (THIS_ IResType *) PURE;
   STDMETHOD_(BOOL, RegisterStoreFactory) (THIS_ IStoreFactory *) PURE;

   //
   // Unregister a factory. Note that storage factories cannot currently
   // be unregistered.
   //
   STDMETHOD_(void, UnregisterResType) (THIS_ IResType *) PURE;

   //////////
   //
   // Refetch methods
   //
   // These methods are intended only in cases where we believe that a
   // particular resource in memory is somehow "dirty" -- that it is no
   // longer an accurate reflection of the state of the stream on disk.
   // "Rebind" means that we should attempt to look this resource up
   // again (usually in cases where a new copy has been added earlier on
   // the path, or the one that was previously found has been deleted).
   // "Reload" means that we should use the same stream, but we should
   // load it into memory again (either because it has changed on disk,
   // or the in-memory version has been corrupted).
   //

   //
   // Notes that any version of this resource currently found in the LRU
   // is now dirty; if we need this resource again, fetch it once more
   // from storage. Useful if you have reason to believe that the resource
   // has changed in storage, or if the in-memory version has become
   // corrupt. This will mark all resources based on the named stream,
   // if there are more than one.
   //
   STDMETHOD_(void, MarkForReload) (THIS_
                                    const char *pName,
                                    ISearchPath *pPath) PURE;

   //
   // Same as MarkForReload, except that it takes the
   // actual resource itself. Will generally be faster, since less lookup
   // is needed. Only marks the given resource, though, not any others
   // from the same stream.
   //
   STDMETHOD_(void, MarkForReloadRes) (THIS_ IRes * pRes) PURE;

   //
   // Notes that any previously-found stream by this name along the path
   // should be ignored, and that we should look it up again. This will
   // not take effect until all locks are cleared; after that, the next
   // lock will cause the rebind to occur. This will rebind all
   // resources based on the named stream, if there are more than one.
   //
   STDMETHOD_(void, MarkForRebind) (THIS_
                                    const char *pName,
                                    ISearchPath *pPath) PURE;

   //
   // Same as MarkForRebind, but takes a single specific resource to
   // rebind. Will generally be faster, since less lookup is needed.
   // Takes the path, so we know where to rebind from. This will only
   // rebind the given resource (and other resources of the same type,
   // using the same data), not other resources of other types from
   // the same stream.
   //
   STDMETHOD_(void, MarkForRebindRes) (THIS_ 
                                       IRes * pRes,
                                       ISearchPath *pPath) PURE;
};

//////////////////////////////////////////////////////////////////////
//
// INTERFACE: IResStats
//
// This interface is optionally available from IResMan; if available, it
// provides various statistics about the Resource Manager.
//

#undef INTERFACE
#define INTERFACE IResStats

DECLARE_INTERFACE_(IResStats, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Enable stat tracking.
   //
   STDMETHOD_(void, EnableStats) (THIS_ const eResStatMode) PURE;

   //
   // Dump stats into given file, or monolog if none.
   //
   STDMETHOD_(void, DumpStats) (THIS_ const char *pFile) PURE;
};

//////////////////////////////////////////////////////////////////////
//
// INTERFACE: IResMem
//
// This interface controls the memory-management policies of the
// Resource Manager.
//

#undef INTERFACE
#define INTERFACE IResMem

DECLARE_INTERFACE_(IResMem, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Enable paging.
   //
   STDMETHOD_(void, EnablePaging) (THIS_ BOOL) PURE;

   //
   // Flush the cache, cleanup the heap.
   //
   STDMETHOD_(void, Compact) (THIS) PURE;

   //
   // Get Resource Mem stats
   //
   STDMETHOD_(void, GetMemStats) (THIS_ sResMemStats *) PURE;
};

///////////////////////////////////////////////////////////////////////////////
//
// INTERFACE: IRes
//

#undef INTERFACE
#define INTERFACE IRes

#define NO_RES_APP_DATA -1

DECLARE_INTERFACE_(IRes, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Returns the type for this resource; use this to get the type name,
   // and translators.
   //
   STDMETHOD_(IResType *, GetType) (THIS) PURE;

   //
   // Returns resource file name only.
   //
   STDMETHOD_(const char *, GetName)(THIS) PURE;

   ////////////////////////////////////
   //
   // Raw data operations
   //

   //
   // Will look in LRU or will load. Allocates buff.
   // Returns NULL if for some reason it can't lock this resource. (Eg, it
   // doesn't exist in storage.)
   //
   STDMETHOD_(void *, Lock)(THIS) PURE;

   //
   // Decrement lock count
   //
   STDMETHOD_(void, Unlock)(THIS) PURE;

   //
   // Remove from memory. Blow LRU for this. TRUE if success.
   // FALSE if resource is locked.
   //
   STDMETHOD_(BOOL, Drop)(THIS) PURE;

   //
   // Query the size
   //
   STDMETHOD_(long, GetSize)(THIS) PURE;

   //
   // Extract into memory.
   //
   STDMETHOD_(void *, Extract)(THIS_ void * pBuf) PURE;

   //
   // Grab data, allocate, rework as needed. Will get used by resource
   // manager to load raw data.
   //
   STDMETHOD_(void *, LoadData)(THIS_ ulong *           pSize, 
                                      IResMemOverride * pResMem) PURE;

   //
   // Get data into memory (LRU). If already there, makes data 
   // most-recently-used.
   //
   STDMETHOD_(void *, PreLoad)(THIS) PURE;

   //
   // Grab data from file. If data already loaded for this resource, 
   // no file ops are done. Else, if associated stream is not already 
   // opened, then the stream is opened, data read, then stream 
   // closed. If stream is already open via 'OpenStream', then that 
   // stream is used, and not closed until explicitly closed via 
   // 'CloseStream'. Returns number of bytes extracted
   // 
   STDMETHOD_(int, ExtractPartial)(THIS_ 
                                   const long nStart, 
                                   const long nEnd, 
                                   void *pBuf)
      PURE;

   //
   // Extract this resource, one block at a time, passing each block to
   // the specified callback method. The blocks are placed in the given
   // buffer; it is the caller's responsibility to manage that buffer.
   //
   // @param pBuf A buffer in which to place each block, which will be
   //   passed to the callback.
   // @param nSize The size of that buffer, in bytes.
   // @param callback A routine to call each time a block is loaded into
   //   the buffer.
   // @param pCallbackData Some arbitrary data which will be passed to the
   //   callback, for the caller to use as it sees fit.
   //
   STDMETHOD_(void, ExtractBlocks)(THIS_ 
                                   void *pBuf, 
                                   const long nSize, 
                                   tResBlockCallback, 
                                   void *pCallbackData) 
      PURE;

   //  
   // Opens a stream using the IStore and resource name that were
   // established already.
   //
   STDMETHOD_(IStoreStream *, OpenStream)(THIS) PURE;

   ////////////////////////////////////
   //
   // Translation methods
   //
   // A resource may be able to obtain its data from other, already-loaded
   // resources based on the same underlying stream. The issue is whether
   // this type knows how to translate the data from another existing look
   // at this data, in some other type.

   //
   // Returns an array of strings, with the names of types that this one
   // knows how to translate from. Places the size of the array in
   // pnTypes.
   //
   // @NOTE: This used to be GetProxiedTypes, with a different signature.
   //
   STDMETHOD_(char **, GetTranslatableTypes)(THIS_
                                             /* OUT */ int *pnTypes) PURE;

   //
   // Load this resource from the given data block, which is from another
   // resource. Analogous to LoadData in many ways. The parameters are:
   //
   //   pOldData -- An existing block of data
   //   nOldSize -- The size of that old data block
   //   pOldTypeName -- The name of the type of that old data
   //   pAllocated -- Will return TRUE iff we allocated fresh memory for
   //       this resource, FALSE iff we are simply pointing to the old,
   //       given data block
   //   pSize -- Will return the size of the new data for this resource
   //   pResMem -- Will be used to allocate the new memory space, if
   //       any allocation is needed
   //
   // The method returns a pointer to the new data block for this resource.
   // It will return NULL if something goes wrong. (For instance, if we don't
   // know how to translate from the given data type.)
   //
   // @NOTE: This used to be LoadProxiedData, with a different signature.
   //
   STDMETHOD_(void *, LoadTranslation)(THIS_
                                       void *pOldData,
                                       long nOldSize,
                                       const char *pOldTypeName,
                                       /* OUT */ BOOL *pAllocated,
                                       /* OUT */ ulong *pSize,
                                       IResMemOverride *pResMem) PURE;

   ////////////////////////////////////
   //
   // Async operations
   //

   //
   // Lock (that is, read in and get the data for) the given resource 
   // asynchronously, calling the given callback when it is ready.
   //
   // Priority is a 'prikind.h' priority.
   //
   // pClientData is a pointer to arbitrary memory, which will be passed
   // on to the callback. It may be used as desired by the caller, and may
   // be null.
   //
   STDMETHOD_(BOOL, AsyncLock)(THIS_ 
                               const int nPriority, 
                               tResAsyncCallback Callback, 
                               void *pData) PURE;
   //
   // Similar to AsyncLock, but place the data into the given buffer.
   // Memory management on this buffer is up to the caller.
   //
   STDMETHOD_(BOOL, AsyncExtract)(THIS_ 
                                  const int nPriority, 
                                  void *pBuf, 
                                  const long bufSize, 
                                  tResAsyncCallback Callback, 
                                  void *pData) PURE;
   //
   // Similar to AsyncLock, but doesn't actually lock the Resource, just
   // loads it in on the assumption that it'll get locked Real Soon Now.
   // Assumed to be low-priority.
   //
   STDMETHOD_(BOOL, AsyncPreload)(THIS_ 
                                  tResAsyncCallback Callback, 
                                  void *pData) PURE;
   //
   // Returns TRUE if async request has been fulfilled.
   //
   STDMETHOD_(BOOL, IsAsyncFulfilled)(THIS) PURE;
   //
   // Kills async request associated with this resource.
   //
   STDMETHOD(AsyncKill)(THIS) PURE;
   // 
   // Forces synchronous completion of async request. ppResult is as
   // passed back from the ARQ fulfiller.
   //
   STDMETHOD(GetAsyncResult)(THIS_ void **ppResult) PURE;

   //
   // Application Data methods
   //
   // Sometimes, the application wants to attach a bit of data to its
   // resources; usually, but not always, this is a pointer of some sort.
   // These methods allow you to do this, giving a DWORD that will be
   // associated with this resource until further notice. (To unset this
   // data, just call SetAppData again with NO_RES_APP_DATA.) 
   //
   // Note that the resource system absolutely ignores this data. This
   // is significant, because if the IRes is completely Released, it will
   // delete itself without performing any cleanup on this data. If the
   // the data is a pointer to a structure, it is the responsibility of
   // the application to clean it up *before* completely releasing the
   // resource. (This *may* get enhanced in the future, but no promises.)
   //
   // The "empty" AppData has the value NO_RES_APP_DATA -- that is, this is
   // what GetAppData will return if SetAppData has not been called on
   // this resource.
   //
   STDMETHOD_(void, SetAppData)(THIS_ DWORD AppData) PURE;
   STDMETHOD_(DWORD, GetAppData)(THIS) PURE;

   //
   // @HACKS:
   //
   // These are methods in the interface to get Dark out the door quickly.
   // They SHOULD NOT be used by later systems. They will hopefully be removed
   // from the interface and from stdres as soon as feasible.
   //

   //
   // Get the data for this resource, without loading or locking.
   //
   // You are STRONGLY DISCOURAGED from using this method. It exists solely
   // for the use of older systems, whose designs didn't take into account the
   // Lock/Unlock model of operation. New code should always use Lock to
   // obtain the data, and should Unlock when it is done with that data.
   // This method will be removed from the API when all projects have moved
   // over to this new way of doing business.
   //
   // *If* this resource is currently loaded into memory, this returns a
   // pointer to that resource's data. This pointer can only be considered
   // valid as long as the resource is Locked; it will cease to be valid at
   // an unpredictable time after that. Do not use unless you really know
   // what you are doing.
   //
   STDMETHOD_(void *, DataPeek)(THIS) PURE;

   //
   // Assign the given data as the "real" data for this resource.
   //
   // This takes a pointer to some arbitrary memory, managed by an outside
   // module. It will use that pointer, from now on, when returning
   // information about this resource. The resource must be Unlocked when
   // this is called. Memory management on the given data is entirely the
   // responsibility of the caller. No reference counting is maintained in
   // this case.
   //
   // This particular bit of hackery is principally here to support the
   // Dark engine, which gets an image resource, then mipmaps it, and
   // "assigns" the mipmap as the new version of the resource. It is
   // intended solely for the short term; this model should NOT be emulated.
   // Instead, later systems should create custom resource types for cases
   // like this. When practicable, this method will be removed.
   //
   STDMETHOD_(void, SetData)(THIS_ void * pNewData) PURE;
   STDMETHOD_(BOOL, HasSetData)(THIS) PURE;
};

//////////////////////////////////////////////////////////////////////
//
// INTERFACE: IResStore
//
// This is a side-interface from IRes, which allows the caller to get
// and set information about the way the resource appears in storage.
// (Mainly where it is to be found.)
//

#undef INTERFACE
#define INTERFACE IResStore

DECLARE_INTERFACE_(IResStore, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Get/Set the structured storage 
   //
   STDMETHOD_(BOOL, SetStore)(THIS_ IStore *) PURE;
   STDMETHOD_(IStore *, GetStore)(THIS) PURE;

   //
   // Set the name of the resource under its storage
   //
   // @TBD (justin 5-15-98): Should we take this out? I think one can argue
   // that the name of a resource is pretty intrinsic, and shouldn't be
   // changed. As it is, this method is never called externally -- the name
   // is set at creation time. The only argument I can see for keeping it
   // external is for possible later tools...
   //
   STDMETHOD_(void, SetName)(THIS_ const char *pName) PURE;

   //
   // If FALSE, only the first call to SetStore will stick. May be useful
   // if you don't want this resource getting looked up again if the state
   // of the disk changes.
   //
   STDMETHOD_(void, AllowStorageReset)(THIS_ BOOL) PURE;

   //
   // Returns the full pathname for this resource.
   //
   STDMETHOD_(const char *, GetFullPathName)(THIS) PURE;

   //
   // Returns the *relative* pathname for this resource. This pathname is
   // relative to the storage under which the resource was created; that is,
   // it is generally equal to the name that was passed in to the Prep or
   // Make command that generated it. In general, though, you should usually
   // use GetName instead.
   //
   STDMETHOD_(void, SetRelativePathName)(THIS_ const char *pPathname) PURE;
   STDMETHOD_(const char *, GetRelativePathName)(THIS) PURE;

   //
   // @TBD (justin 5-7-98): We don't currently have a mechanism for
   // returning the pathname of this resource with the path it was
   // found along. Do we need this? If so, it'll have to be added
   // to IStoreStream. Personally, I'd rather not; it's kinda weird...
   //

   //
   // @TBD (justin 5-7-98): We will probably eventually need a bit
   // more interface here for the output side of the equation, so a
   // tool can create a resource and add it to a storage...
   //
};

//////////////////////////////////////////////////////////////////////
//
// INTERFACE: IResType
//
// A "type" encapsulates a particular family of resources. It serves as
// a factory for that kind of resource -- you call CreateRes () to get
// a new resource of this type, or CreateResFromRes () to create a new
// one based on the data of an existing one.
//

#undef INTERFACE
#define INTERFACE IResType

DECLARE_INTERFACE_(IResType, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Get the name of this type. This is an arbitrary static string,
   // which should ideally be unique.
   //
   STDMETHOD_(const char *, GetName) (THIS) PURE;

   //
   // Get the extensions that this type supports. This will call the callback
   // once for each supported extension.
   //
   STDMETHOD_(void, EnumerateExts) (THIS_ 
                                    tResEnumExtsCallback callback,
                                    void *pClientData) PURE;

   //
   // Return TRUE iff the given extension is legal for this type. Arguably
   // redundant with EnumerateExts, but it is useful for efficiency reasons
   // to have both.
   //
   STDMETHOD_(BOOL, IsLegalExt) (THIS_ const char *pExt) PURE;

   //
   // Create a new resource of this type from the specified IStore, with
   // the given name. If ppResMem is non-null, it gives the memory
   // manager for this data. Returns NULL iff it can't create the IRes
   // for some reason. It should make sure that the resource knows its
   // name and storage, from the params.
   //
   // Note that this does not actually read any data in, or even open
   // up the stream in the IStore; it just sets things up so that later
   // operations can do so.
   //
   STDMETHOD_(IRes *, CreateRes) (THIS_
                                  IStore *pStore,
                                  const char *pName,
                                  const char *pExt,
                                  IResMemOverride **ppResMem) PURE;
};

///////////////////////////////////////////////////////////////////////////////
//
// INTERFACE: IResMemOverride
//

#undef INTERFACE
#define INTERFACE IResMemOverride

DECLARE_INTERFACE_(IResMemOverride, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   // @TBD (justin, 5-1-98): Is there any good reason to use special names
   // for these methods? It seems more sensible to me to just call them
   // Malloc and Free...

   //
   //
   //
   STDMETHOD_(void *, ResMalloc) (THIS_ ulong nNumBytes) PURE;

   //
   //
   //
   STDMETHOD_(void, ResFree) (THIS_ void *) PURE;

   //
   //
   //
   STDMETHOD_(ulong, GetSize) (THIS_ void *) PURE;
};

//////////////////////////////////////////////////////////////////////////
//
// C Accessor macros
//

#define IResMan_Init(p, a)                     COMCall1(p, Init, a)
#define IResMan_Cleanup(p)                     COMCall0(p, Cleanup)
#define IResMan_NewSearchPath(p)               COMCall0(p, NewSearchPath)
#define IResMan_SetDefaultPath(p, a)           COMCall1(p, SetDefaultPath, a)
#define IResMan_PrepResource(p, a, b)          COMCall2(p, PrepResource, a, b)
#define IResMan_PrepTypedResource(p, a, b, c)  COMCall3(p, PrepTypedResource, a, b, c)
#define IResMan_PrepAllResources(p, a, b, c, d) COMCall4(p, PrepAllResources, a, b, c, d)
#define IResMan_PrepAllTypedResources(p, a, b, c, d, e) COMCall5(p, PrepAllTypedResources, a, b, c, d, e)
#define IResMan_MakeResource(p, a, b, c)       COMCall3(p, MakeResource, a, b, c)
#define IResMan_MakeTypedResource(p, a, b, c, d) COMCall4(p, MakeTypedResource, a, b, c, d)
#define IResMan_MakeRetypedResource(p, a, b, c) COMCall3(p, MakeRetypedResource, a, b, c)
#define IResMan_GetStore(p, a)                 COMCall1(p, GetStore, a)
#define IResMan_RegisterResType(p, a)          COMCall1(p, RegisterResType, a)
#define IResMan_RegisterStoreFactory(p, a)     COMCall1(p, RegisterStoreFactory, a)
#define IResMan_UnregisterResType(p, a)        COMCall1(p, UnregisterResType, a)
#define IResMan_MarkForReload(p, a, b)         COMCall2(p, MarkForReload, a, b)
#define IResMan_MarkForReloadRes(p, a)         COMCall1(p, MarkForReloadRes, a)
#define IResMan_MarkForRebind(p, a, b)         COMCall2(p, MarkForRebind, a, b)
#define IResMan_MarkForRebindRes(p, a, b)      COMCall2(p, MarkForRebindRes, a, b)

//////////

#define IResStats_EnableStats(p, a)            COMCall1(p, EnableStats, a)
#define IResStats_DumpStats(p, a)              COMCall1(p, DumpStats, a)

//////////

#define IResMem_EnablePaging(p, a)             COMCall1(p, EnablePaging, a)
#define IResMem_Compact(p)                     COMCall0(p, Compact)
#define IResMem_GetMemStats(p, a)              COMCall1(p, GetMemStats, a)

///////////////////////////////////////

#define IRes_GetType(p)                    COMCall0(p, GetType)
#define IRes_GetName(p)                    COMCall0(p, GetName)
#define IRes_Lock(p)                       COMCall0(p, Lock)
#define IRes_Unlock(p)                     COMCall0(p, Unlock)
#define IRes_Drop(p)                       COMCall0(p, Drop)
#define IRes_GetSize(p)                    COMCall0(p, GetSize)
#define IRes_Extract(p, a)                 COMCall1(p, Extract, a)
#define IRes_LoadData(p, a, b)             COMCall2(p, LoadData, a, b)
#define IRes_PreLoad(p)                    COMCall0(p, PreLoad)
#define IRes_ExtractPartial(p, a, b, c)    COMCall3(p, ExtractPartial a, b, c)
#define IRes_ExtractBlocks(p, a, b, c, d)  COMCall4(p, ExtractBlocks, a, b, c, d)
#define IRes_OpenStream(p)                 COMCall0(p, OpenStream)
#define IRes_GetTranslatableTypes(p, a)    COMCall1(p, GetTranslatableTypes, a)
#define IRes_LoadTranslation(p, a, b, c, d, e, f) COMCall6(p, LoadTranslation, a, b, c, d, e, f)
#define IRes_AsyncLock(p, a, b, c)         COMCall3(p, AsyncLock, a, b, c)
#define IRes_AsyncExtract(p, a, b, c, d, e) COMCall5(p, AsyncExtract, a, b, c, d, e)
#define IRes_AsyncPreload(p, a, b)         COMCall2(p, AsyncPreload, a, b)
#define IRes_IsAsyncFulfilled(p)           COMCall0(p, IsAsyncFulfilled)
#define IRes_AsyncKill(p)                  COMCall0(p, AsyncKill)
#define IRes_GetAsyncResult(p, a)          COMCall1(p, GetAsyncResult, a)
#define IRes_SetAppData(p, a)              COMCall1(p, SetAppData, a)
#define IRes_GetAppData(p)                 COMCall0(p, GetAppData)
#define IRes_DataPeek(p)                   COMCall0(p, DataPeek)
#define IRes_SetData(p, a)                 COMCall1(p, SetData, a)
#define IRes_HasSetData(p)                 COMCall0(p, HasSetData)

//////////

#define IResStore_SetStore(p, a)           COMCall1(p, SetStore, a)
#define IResStore_GetStore(p)              COMCall0(p, GetStore)
#define IResStore_SetName(p, a)            COMCall1(p, SetName, a)
#define IResStore_AllowStorageReset(p, a)  COMCall1(p, AllowStorageReset, a)
#define IResStore_GetFullPathName(p)       COMCall0(p, GetFullPathName)
#define IResStore_SetRelativePathName(p, a) COMCall1(p, SetRelativePathName, a)
#define IResStore_GetRelativePathName(p)   COMCall0(p, GetRelativePathName)

///////////////////////////////////////

#define IResType_GetName(p)                COMCall0(p, GetName)
#define IResType_EnumerateExts(p, a, b)    COMCall2(p, EnumerateExts, a, b)
#define IResType_IsLegalExt(p, a)          COMCall1(p, IsLegalExt, a)
#define IResType_CreateRes(p, a, b, c, d)  COMCall4(p, CreateRes, a, b, c, d)

///////////////////////////////////////

#define IResMemOverride_ResMalloc(p, a)  COMCall1(p, ResMalloc, a)
#define IResMemOverride_ResFree(p, a)    COMCall1(p, ResFree, a)
#define IResMemOverride_ResGetSize(p, a) COMCall1(p, ResGetSize, a)

///////////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__RESAPILG_H */
