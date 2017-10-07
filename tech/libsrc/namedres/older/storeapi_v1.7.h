//////////////////////////////////////////////////////////////////////////
//
// $Header: x:/prj/tech/libsrc/res2/RCS/storeapi.h 1.7 1998/07/08 11:03:11 JUSTIN Exp $
//
// Storage API
//
// @TBD (toml 04-20-98): we have now three competing stream APIs that are
// nearly identical (ITagFile, OLE IStream, and IStoreStream) We should consolodate, and
// make sure the implementation here is generally reusable.
//
// Description of interfaces:
// 
//  IStore
//
//    Controls access to sets of items (streams) stored in a 
//    hierarchical fashion, and provides interfaces for stream-level 
//    data extraction, which is storage-implementation-dependent. 
//    An IStore is a collection of other IStores and IStoreStreams.
//    Conceptually, an IStore is equivalent to a normal OS directory,
//    but it may be implemented as a real directory, or as some sort
//    of file. The details of all this are hidden from the client apps.
//    The IStore is responsible for providing fast answers to queries
//    about what is inside it, although no specific performance
//    guarantee is made.
//
//  IStoreHierarchy
//
//    A side-interface from IStore. This allows a controlling system to
//    help establish a hierarchy of IStores, which may be of
//    heterogeneous kinds. For example, an ordinary file system may
//    have a stream called "textures.res"; by aid of IStoreHierarchy,
//    this stream may be considered an IStore itself, and plugged in
//    as a substorage of the ordinary directory. IStoreHierarchy is not
//    normally used by user-level apps; it is intended for the utility
//    level managers.
//
//  IStoreStream
// 
//    Tied to implementation of IStore. Points at an individual 
//    stream within a structured storage unit. Conceptually, an
//    IStoreStream is like an open file; however, the item open may
//    be a real OS file, or a section of some other hierarchical
//    collection.
// 
//  IStoreFactory
// 
//    Like IResFactory, registers a set of implicit storage types by 
//    extension. Explicit assumption: we can distinguish between
//    the different storage types by their extensions.
//
//  IStoreManager
//
//    The top-level manager for a collection of IStores. Given a string,
//    one can go to the IStoreManager and ask that the storage named
//    by that string be opened. The IStoreManager keeps track of the
//    storage hierarchy insofar as is needed, so that things can be
//    found. It also allows registration of new IStoreFactories, which
//    can be used to open different types of storage.
//
//  ISearchPath
//
//    A collection of storages, which can be searched for a named
//    storage or stream. You add storages into the path, then look
//    for things in that path. An ISearchPath is conceptually similar
//    to the old Datapath mechanism, but works with arbitrary storages.
//
//    A path can have a "context", which is a higher-level storage or
//    path that contains it. For example, say that you have a large number
//    of directories, some containing textures, some sounds, some levels,
//    and so on. To make things more efficient and easier to manange, you
//    might want each of these to have a separate path -- the list of
//    texture directories, for example. But you also want a path which
//    lists the "roots" of these directories, so that you might have a
//    development root, a release root, and so on in this higher-level
//    path, so that a texture is first sought in the development area, then
//    the release area. This higher-level path is the "context" that the 
//    type-specific paths work within.
//
//    Note that, if you plan to use contexts, all of the storages in
//    this path should be relative. The results are undefined if you use
//    absolute storages in a path under a context. Contexts are strictly
//    optional; if all you want is a normal single-level path, don't
//    bother with contexts.
//
//    Set the context by calling SetContext (). After this, all Finds
//    will look through the cross-product of this path and its context,
//    searching the path under the first context root, then the second,
//    and so on. The context path is copied into this one, and that copy
//    will be freed when this one is freed.
//
//    For efficiency, paths do a considerable amount of caching. If you
//    you have reason to believe things have changed on disk, call Refresh (),
//    to force it to look up the storages anew.
//
//    Note that contexts may be nested almost arbitrarily deep -- a context
//    path may have yet higher context paths. However, since each level
//    essentially multiplies the number of directories to be searched,
//    it is advised that this capability be used with extreme caution.
//
// All of the above operate on a general abstraction of "storage", which
// is sort of like directories and files, but can also encapsulate things
// like Zip files. It is similar to IStorage, but operates at a slightly
// different level: the system is designed together so that the using
// application can essentially ignore issues of what sort of storage a
// specific level is. So long as all of the types of storage involved have
// registered factories, the system will automatically delve into any
// requested level.
//
// Some of the methods take a parameter that is the full pathname of a
// storage. This looks very much like an ordinary file pathname; however,
// the levels of the path may be files, as well as directories. When a
// file is encountered in a path, the StoreManager attempts to open that
// file using an appropriate registered StoreFactory; assuming that works,
// it just treats the file as a storage from then on. Thus, the pathname:
//
//    c:\dark\multimedia\textures.res\level1\brick.gif
//
// works perfectly fine, assuming that textures.res is, say, a Zip file,
// and the Zip factory has been registered.
//
// The explicit objective of this system is that developers should be able
// to work with all of their resources out in separate files, and then
// collect those files into a compressed format, without any code changes.
// You just change the names of the directories, and the code remains
// the same. In general, ISearchPath is intended to be the most common
// moment-to-moment interface for interacting with storage.
// 

#ifndef __STOREAPI_H
#define __STOREAPI_H

#include <comtools.h>

// storcnst defines the canonical maximum lengths of things like file names
#include <storcnst.h>

#pragma once
#pragma pack(4)

F_DECLARE_INTERFACE(IStore);
F_DECLARE_INTERFACE(IStoreHierarchy);
F_DECLARE_INTERFACE(IStoreFactory);
F_DECLARE_INTERFACE(IStoreManager);
F_DECLARE_INTERFACE(IStoreStream);
F_DECLARE_INTERFACE(ISearchPath);

////////////////////////////////////////////////////////////////////////////
//
// INTERFACE: IStore
//
// @TBD: use EXTERN IAggregate *    LGAPI CreateGenericAggregate(const char * pszName, int fCreateFlags);
// from objcoll.h. Store this instance in cStorageBase, as queryable interface for IStore. Remember
// to make IStore unaggregatable - aka, not an aggregate member itself.
// Adding the IAggregate will allow the ADD_TO_AGGREGATE_1 to work (from aggmemb.h)
//

// return TRUE to let StructuredStorage store refresh data for this.
typedef BOOL(*tStoreLevelEnumCallback) (IStore *, 
                                        const char *pName, 
                                        void *pClientData);
typedef BOOL(*tStoreStreamEnumCallback) (IStore *, 
                                         const char *pName, 
                                         void *pClientData);

///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IStore

DECLARE_INTERFACE_(IStore, IUnknown)
{

   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Just the name, no path to it, or from it. The given name is semi-static,
   // and will be valid until this IStore is released.
   //
   STDMETHOD_(const char *, GetName)(THIS) PURE;

   //
   // Full Path name to this storage. As with GetName(), the string should
   // be valid until this IStore is released or refreshed.
   //
   STDMETHOD_(const char *, GetFullPathName)(THIS) PURE;

   //
   // Enumerates all of the substorages under this storage.
   //
   //   callback -- will be called once for each substorage found.
   //   bAbsolute -- iff TRUE, will give the full path for each substorage
   //       found; otherwise, will give relative paths.
   //   bRecurse -- iff TRUE, will recurse into the substorages.
   //   pClientData -- arbitrary data to pass through to the callback.
   //
   STDMETHOD_(void, EnumerateLevel)(THIS_ tStoreLevelEnumCallback, 
                                          BOOL bAbsolute, 
                                          BOOL bRecurse, 
                                          void *pClientData) PURE;

   //
   // List all of the streams (that is, contained items that don't appear
   // to be storages themselves) in this storage.
   //
   STDMETHOD_(void, EnumerateStreams)(THIS_ tStoreStreamEnumCallback, 
                                            BOOL bAbsolute, 
                                            BOOL bRecurse, 
                                            void *pClientData) PURE;

   //
   // Creates or gets an IStore corresponding to a substorage under this one.
   // If bCreate is TRUE, then this will create the substorage regardless
   // of whether it actually exists on disk.
   //
   // pSubPath may be a simple name, or a path down to a lower level.
   // If the intervening IStores do not yet exist, they will be created.
   //
   // If one of the elements in the given path exists, but is a stream
   // instead of a substorage, this will attempt to open that stream as
   // a storage, using the IStoreManager. It will fail, and return NULL,
   // if this is unsuccessful.
   //
   STDMETHOD_(IStore *, GetSubstorage)(THIS_ 
                                       const char *pSubPath,
                                       BOOL bCreate) PURE;

   //
   // Return the IStore that contains this one; returns NULL iff this is
   // the root of a hierarchy.
   //
   STDMETHOD_(IStore *, GetParent)(THIS) PURE;

   //
   // Refreshes file structure cache. For example, directory contents changed.
   // Detects newer dates, and calls RefreshStream for them. Will recursively
   // refresh anything under this IStore.
   //
   STDMETHOD_(void, Refresh)(THIS_ BOOL bRecurse) PURE;

   //
   // Returns TRUE iff this storage actually exists on disk. (It is
   // quite possible to create IStores that don't have a representation
   // on disk; they are useful data structures for some purposes.)
   //
   STDMETHOD_(BOOL, Exists)(THIS) PURE;

   //
   // Returns TRUE iff the named stream exists in this storage.
   //
   STDMETHOD_(BOOL, StreamExists)(THIS_ const char *pName) PURE;

   //
   // Open the named stream for direct I/O. The flags are currently
   // ignored; they are reserved for future extensions. (Ie, the usual
   // read/write/create open modes.) By default (if the flags are zero),
   // it opens the stream for read-only, and returns NULL if the
   // stream doesn't exist.
   //
   STDMETHOD_(IStoreStream *, OpenStream)(THIS_ const char *pName,
                                          uint fFlags) PURE;

   //
   // Get the contents of this storage iteratively. The meanings of the
   // parameters are all essentially identical to those in ISearchPath
   // (which this largely exists to serve); see there for detailed
   // documentation.
   //
   // The differences are:
   // -- BeginContents() will return NULL if this storage does not
   //    actually exist on disk;
   // -- Next() does not return an IStore (since this *is* the IStore)
   //
   STDMETHOD_(void *, BeginContents)(THIS_
                                     const char *pPattern,
                                     uint fFlags) PURE;
   STDMETHOD_(BOOL, Next)(THIS_
                          void * pCookie,
                          /* OUT */ char *foundName) PURE;
   STDMETHOD_(void, EndContents)(THIS_ void * pCookie) PURE;
};

/////////////////////////////////////////////////////////////////////////
//
// INTERFACE: IStoreHierarchy
//

#undef INTERFACE
#define INTERFACE IStoreHierarchy

DECLARE_INTERFACE_(IStoreHierarchy, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Set the storage manager that is keeping track of this storage.
   //
   STDMETHOD_(void, SetStoreManager)(THIS_ IStoreManager *pManager) PURE;

   //
   // Considers the named stream to actually be a substorage from here on,
   // with the given IStore. Something that looks like a simple stream to
   // one kind of storage may actually be a storage of its own, with its
   // own internal hierarchy.
   //
   // pName should usually be the name of a stream that exists in
   // this IStore, although it could be any arbitrary name to be hooked
   // in here. From now on, that name will be treated as a substorage,
   // and point to the given one.
   //
   // This should also establish the back-link, so that this IStore is
   // registered as the substore's parent.
   //
   STDMETHOD_(void, RegisterSubstorage)(THIS_ 
                                        IStore *pSubstore,
                                        const char *pName) PURE;

   //
   // Establishes the parent of this storage; this is mostly called
   // by RegisterSubstorage ().
   //
   STDMETHOD_(void, SetParent)(THIS_ IStore *pParent) PURE;

   //
   // Establishes the stream that this storage will use for finding its
   // own data. Most substorages exist as streams in higher-level storages;
   // for example, a Zip-format storage is a stream inside an OS directory
   // (or inside a higher-level Zip file). This is the stream that the
   // storage will look for its data in.
   //
   // Storage formats that aren't streams may ignore this method.
   //
   STDMETHOD_(void, SetDataStream)(THIS_ IStoreStream *pStream) PURE;

   //
   // Tells this storage that its time is done, and that it should prepare
   // to close down. This should almost never be called by the client; it
   // is mainly used internally by the Storage Manager, to shut down. It
   // does not actually delete this storage; rather, the storage releases
   // all of its pointers to its children, so normal COM decay processes
   // can set it.
   //
   // You should always release your pointer to this storage immediately
   // after calling Close().
   //
   STDMETHOD_(void, Close)(THIS) PURE;
};

/////////////////////////////////////////////////////////////////////////
//
// INTERFACE: IStoreFactory
//

typedef void (*tStoreEnumTypeCallback) (const char *pExt, 
                                        IStoreFactory * pFactory,
                                        void *pClientData);

///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IStoreFactory

DECLARE_INTERFACE_(IStoreFactory, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // List all of the types that this factory is able to create, to the
   // given callback.
   //
   STDMETHOD_(void, EnumerateTypes) (THIS_ 
                                     tStoreEnumTypeCallback callback,
                                     void *pClientData) PURE;
   
   //
   // Create an IStore under the given parent (which may be NULL), and the
   // given name. If there is a parent, then the newly-created child store
   // will get its data from the named stream under the parent.
   //
   STDMETHOD_(IStore *, CreateStore) (THIS_ 
                                      IStore *pParent,
                                      const char *pName, 
                                      const char *pExt) PURE;
};

/////////////////////////////////////////////////////////////////////////
//
// INTERFACE: IStoreManager
//

#undef INTERFACE
#define INTERFACE IStoreManager

DECLARE_INTERFACE_(IStoreManager, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Register a factory with the manager. Storages with the extensions
   // recognized by this factory will be created by it from now on.
   //
   // There is a default factory built into the Storage Manager, which
   // expects that unknown top-level storages are just OS directories.
   // Also, most storage classes will not go through the factory to
   // create "ordinary" substorages (that is, existing homogeneous
   // storages under a storage). They will generally only use a factory
   // if they find a stream, which the caller is trying to open as a
   // storage.
   //
   // @TBD (justin 5-11-98): Currently, we don't have an unregister method.
   // Do we actually care? While purity would seem to dictate that such a
   // thing should exist, I haven't yet thought of a real-world case where
   // we're likely to want one, and it simplifies the code hugely not to.
   // (Unregistering is a pain, because it means that we have to be able to
   // backtrack through the other factories, in the order they were
   // registered, to figure out which ones should now pick up the types
   // that the now-unregistered one had.)
   //
   STDMETHOD_(void, RegisterFactory)(THIS_ IStoreFactory *pFactory) PURE;

   //
   // Try to open the named storage; the given name may be an arbitrary
   // storage path, either relative to the current directory or absolute
   // from the root directory. Iff bCreate is TRUE, then this will add
   // the given path to the tree, even if it doesn't exist on disk.
   //
   STDMETHOD_(IStore *, GetStore)(THIS_ 
                                  const char *pPathName,
                                  BOOL bCreate) PURE;

   //
   // Create the named substorage under the given storage, choosing
   // the appropriate IStoreFactory to do the creation. Most callers
   // should use IStore::GetSubstorage instead; that should in turn
   // call this if it finds something it doesn't know how to deal with.
   //
   STDMETHOD_(IStore *, CreateSubstore)(THIS_
                                        IStore *pParent,
                                        const char *pName) PURE;

   //
   // Get a new, empty ISearchPath that works with the storages kept by
   // this manager.
   //
   STDMETHOD_(ISearchPath *, NewSearchPath)(THIS) PURE;

   //
   // Tells the Storage Manager to begin to shut itself down. This will
   // not actually delete the Storage Manager, nor necessarily the storages
   // under it, but may delete some storages.
   //
   // This deals with a problem of the storage system. Since this is a
   // rich doubly-linked hierarchy, where parents point to children and
   // vice versa, ordinary COM Releases fail to properly pick up when we
   // are done with the tree. Thus, we need this pro-active call, which
   // walks down the tree, breaking enough of the links that later
   // Releases will close it down properly.
   //
   // Parts of the tree may live on, if there are outside links into it.
   // Things may continue to operate normally for those outside links;
   // however, it is strongly recommend that you not call Close until you
   // have good reason to believe that nothing else is going to use the
   // tree, because it will be in a semi-decayed state after this.
   //
   // You should Release() the Storage Manager immediately after calling
   // Close().
   //
   STDMETHOD_(void, Close)(THIS) PURE;
};

///////////////////////////////////////////////////////////////////////////////
//
// INTERFACE: IStoreStream
//
// Basic interface, initially - gives us simple binary reading ability.
//
// @TBD (justin 5-7-98): This will eventually need the output side of the
// equation as well, the ability to write out a new stream. One or two
// more methods may be needed in IStore as well, to open a stream for
// creation...
//

typedef long (*tStoreStreamBlockCallback) (void *pBuf, 
                                           long nNumBytes, 
                                           long nIx, 
                                           void *pData);

///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IStoreStream

DECLARE_INTERFACE_(IStoreStream, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // This is simply a flag, which is mainly set by ISearchPath::Refresh ().
   // It means that this stream is found along that path, and any clients
   // holding pointers to this stream should consider doing a fresh lookup,
   // to see if a different stream is now more appropriate. Clients should
   // feel free to reset this flag when they feel it apt.
   //
   STDMETHOD_(BOOL, DoRelookup)(THIS) PURE;
   STDMETHOD_(void, SetRelookup)(THIS_ BOOL bLookup) PURE;

   //
   // Name may be relative to storage, or just as-is.
   //
   STDMETHOD_(void, SetName) (THIS_ const char *pName) PURE;
   STDMETHOD_(BOOL, Open) (THIS) PURE;
   STDMETHOD_(void, Close) (THIS) PURE;
   STDMETHOD_(const char *, GetName) (THIS) PURE;

   ////////////////////////////////////
   //
   // Ideally: nearly 1:1 ANSI C file operations. Stores single file pointer 
   // for each opened file.
   // @TBD: for now, just provide some basic reading/writing support. We can add stuff later.
   // @TBD: what about Writing functions in regards to "zip" implementation?
   //

   //
   // These are stream ops that ordinarily should use the Storage ops, since 
   // the storage format is important.
   //
   STDMETHOD_(BOOL, SetPos) (THIS_ long nPos) PURE;
   STDMETHOD_(long, GetPos) (THIS) PURE;
   STDMETHOD_(long, ReadAbs) (THIS_ 
                              long nStartPos, 
                              long nEndPos, 
                              char *pBuf) PURE;

   //
   //
   //
   STDMETHOD_(long, GetSize) (THIS) PURE;

   //
   // When buf is 0, just returns size.
   //
   STDMETHOD_(long, Read) (THIS_ long nNumByes, char *pBuf) PURE;

   //
   // Read in a single character, and return it in the given int16.
   // Returns -1 on failure; otherwise, the character is in the low
   // byte of the int.
   //
   // It is intended to mimic the behaviour of fgetc as closely as possible,
   // so that it can easily be dropped into old algorithms.
   //
   STDMETHOD_(int16, Getc) (THIS) PURE;

   //
   //
   //
   STDMETHOD_(void, ReadBlocks) (THIS_ void *pBuf, 
                                       long nSize, 
                                       tStoreStreamBlockCallback, 
                                       void *pData) PURE;
};

/////////////////////////////////////////////////////////////////////////
//
// INTERFACE: ISearchPath
//

#undef INTERFACE
#define INTERFACE ISearchPath

//
// The signature of the callbacks for Iterate:
//
//      pPath -- The ISearchPath being iterated over.
//      pStore -- The name of a storage, as it was added.
//      pClientData -- The opaque pointer that was given to Iterate.
//
typedef void (*tSearchPathIterateCallback) (ISearchPath *pPath,
                                            const char *pStore,
                                            void *pClientData);

#define SEARCH_TRY_CURRENT 0x01
#define SEARCH_STORAGES 0x02
#define SEARCH_STREAMS 0x00

DECLARE_INTERFACE_(ISearchPath, IUnknown)
{
   //
   // IUnknown methods
   //
   DECLARE_UNKNOWN_PURE();

   //
   // Clear this path.
   //
   STDMETHOD_(void, Clear)(THIS) PURE;

   //
   // Return a copy of this path.
   //
   STDMETHOD_(ISearchPath *, Copy)(THIS) PURE;

   //
   // Add a named storage to this path. The storage will be added to the
   // end of the path. No guarantee is made that this storage is actually
   // valid; it will not actually be searched unless it really exists on
   // disk.
   //
   STDMETHOD_(void, AddStore)(THIS_ const char *pStoreName) PURE;

   //
   // Add a path (in string format) to this path. All of the storages
   // on the given path will be appended to this one. The path should be
   // delimited by semicolons.
   //
   STDMETHOD_(void, AddPath)(THIS_ const char *pPath) PURE;

   //
   // Add a storage *and* the entire hierarchy under it to this path. This
   // is like AddStore, but it will walk down through the tree, and add all
   // of the substorages as well.
   //
   STDMETHOD_(void, AddStoreTree)(THIS_ const char *pStoreName) PURE;

   //
   // Add all of the trees on the given path. This will call AddStoreTree
   // for each storage on the given path. The path should be in the same
   // semicolon-delimited format as AddPath.
   //
   STDMETHOD_(void, AddPathTrees)(THIS_ const char *pPath) PURE;
                                  
   //
   // Call this when the client has reason to believe that things have
   // changed on disk. This clears all cached data along this path.
   //
   // @NOTE: (to me): This needs, among other things, to mark all streams
   // that have real IStoreStreams along the path as "dirty", so that the
   // ResMan can detect that it may need to rebind the resources
   // corresponding to those streams. This essentially replaces MarkForRebind,
   // on the theory that we're usually going to consider the whole path
   // suspect, not just a single named resource.
   //
   STDMETHOD_(void, Refresh)(THIS) PURE;

   //
   // Set the context for this path. Henceforth, the specified context
   // path will be used to set the "roots" for searching in this path.
   // You can clear an existing context by calling this with NULL. Note
   // that the context path is used by copy, not by reference; if the
   // context is changed, you will need to call SetContext () again.
   //
   // @TBD (justin 5-12-98): Is this actually the semantic we want? Since
   // ISearchPath is now a proper COM thingy, with reference counting, it
   // is rather safer to have paths refer to each other instead. It would
   // be slightly more efficient, and would make it much more feasible
   // to change the whole application context on the fly. Worth thinking
   // about. It would be a fairly small change to the implementation to
   // to simply AddRef pContext instead of copying it.
   //
   STDMETHOD_(void, SetContext)(THIS_ ISearchPath *pContext) PURE;

   //
   // Find a named storage or stream within this path. The flags control
   // exactly how the find works:
   //
   //    SEARCH_TRY_CURRENT -- if set, the null storage (ie, the current
   //      directory) will be tried before searching the path.
   //    SEARCH_STORAGES -- if set, Find will only look for a storage with
   //      the given name, and will return that storage if found.
   //    SEARCH_STREAMS -- (default) if set, Find will only look for a
   //      stream with the given name, and will return its containing IStore
   //      if it is found.
   //
   // Note that SEARCH_STREAMS and SEARCH_STORAGES are mutually exclusive,
   // and one will always be set. SEARCH_STREAMS is set by default; thus,
   // it serves only as a useful comment in code.
   //
   // Returns NULL if the named item could not be found along the path.
   //
   STDMETHOD_(IStore *, Find)(THIS_
                              const char *pRelativePathname,
                              uint fFlags) PURE;

   //
   // Begin iterating over a path, returning all of the items that match
   // the given pattern in any of the storages on the path. If the pattern
   // is NULL, then all items found will be returned. The flags control
   // exactly what gets returned:
   //
   //    SEARCH_TRY_CURRENT -- if set, the null storage (ie, the current
   //      directory) will have its contents returned first.
   //    SEARCH_IGNORE_STORAGES -- if set, then no substorages will be
   //      returned.
   //    SEARCH_IGNORE_STREAMS -- if set, then no streams will be returned.
   //
   // This will return a magic cookie, which should be passed through to
   // Next() and EndContents(). If that cookie is NULL, then something has
   // gone wrong, and you should not continue this search.
   //
   // After calling this, call Next() repeatedly until it returns FALSE.
   // When you are finished iterating (either because Next() returns FALSE,
   // or because you have decided not to continue), call EndContents() to
   // clean up.
   //
   // Do *not* change the path between BeginContents() and EndContents()!
   // The results are undefined if you do so.
   //
   STDMETHOD_(void *, BeginContents)(THIS_
                                     const char *pPattern,
                                     uint fFlags) PURE;

   //
   // Get the next item along the path, as constrained by BeginContents ().
   // Returns TRUE iff something was found, FALSE otherwise. Returns the
   // name of the next item found, and the IStore that it was found in, in
   // the OUT params. foundName should be a buffer large enough for the 
   // largest object names. The contents of foundName are undefined when
   // Next() returns FALSE; do *not* count on it being unchanged.
   //
   // pCookie is the magic value returned from BeginContents.
   //
   STDMETHOD_(BOOL, Next)(THIS_
                          void * pCookie,
                          /* OUT */ IStore **foundStore,
                          /* OUT */ char *foundName) PURE;

   //
   // Finish a listing of the contents of this path, and do any necessary
   // cleanup.
   //
   // pCookie is the magic value returned from BeginContents.
   //
   STDMETHOD_(void, EndContents)(THIS_ void * pCookie) PURE;

   //
   // Iterate over this path, calling the given callback with each element
   // in it. The callback will be called with the path, the name of a
   // storage in the path (exactly as specified by AddStore), and the
   // given opaque data. This will be called with all elements specified
   // in the path, whether they actually exist in storage or not.
   //
   // If bUseContext is TRUE, then it will call the callback will be called
   // once for each instance of the path in each context, and the path that
   // gets passed in will be the context, plus the lower-level path.
   //
   STDMETHOD_(void, Iterate)(THIS_ 
                             tSearchPathIterateCallback callback,
                             BOOL bUseContext,
                             void *pClientData) PURE;
};

//////////////////////////////////////////////////////////////////////////
//
// C Accessor macros
//

#define IStore_GetName(p)                       COMCall0(p, GetName)
#define IStore_GetFullPathName(p)               COMCall0(p, GetFullPathName)
#define IStore_EnumerateLevel(p, a, b, c, d)    COMCall4(p, EnumerateLevel, a, b, c, d)
#define IStore_EnumerateStreams(p, a, b, c, d)  COMCall4(p, EnumerateStreams, a, b, c, d)
#define IStore_GetSubstorage(p, a, b)           COMCall2(p, GetSubstorage, a, b)
#define IStore_GetParent(p)                     COMCall0(p, GetParent)
#define IStore_Refresh(p, a)                    COMCall1(p, Refresh, a)
#define IStore_Exists(p)                        COMCall0(p, Exists)
#define IStore_StreamExists(p, a)               COMCall1(p, StreamExists, a)
#define IStore_OpenStream(p, a, b)              COMCall2(p, OpenStream, a, b)
#define IStore_BeginContents(p, a, b)           COMCall2(p, BeginContents, a, b)
#define IStore_Next(p, a, b)                    COMCall2(p, Next, a, b)
#define IStore_EndContents(p, a)                COMCall1(p, EndContents, a)

//////////

#define IStoreHierarchy_SetStoreManager(p, a)   COMCall1(p, SetStoreManager, a)
#define IStoreHierarchy_RegisterSubstorage(p, a, b) COMCall2(p, RegisterSubstorage, a, b)
#define IStoreHierarchy_SetParent(p, a)         COMCall1(p, SetParent, a)
#define IStoreHierarchy_SetDataStream(p, a)     COMCall1(p, SetDataStream, a)

///////////////////////////////////////

#define IStoreFactory_EnumerateTypes(p, a, b)   COMCall2(p, EnumerateTypes, a, b)
#define IStoreFactory_CreateStore(p, a, b, c)   COMCall3(p, CreateStore, a, b, c)

///////////////////////////////////////

#define IStoreManager_RegisterFactory(p, a)     COMCall1(p, RegisterFactory, a)
#define IStoreManager_GetStore(p, a, b)         COMCall2(p, GetStore, a, b)
#define IStoreManager_CreateSubstore(p, a, b)   COMCall2(p, CreateSubstore, a, b)
#define IStoreManager_NewSearchPath(p)          COMCall0(p, NewSearchPath)

///////////////////////////////////////

#define IStoreStream_DoRelookup(p)              COMCall0(p, DoRelookup)
#define IStoreStream_SetRelookup(p, a)          COMCall1(p, SetRelookup, a)
#define IStoreStream_SetName(p, a)              COMCall1(p, SetName, a)
#define IStoreStream_Open(p)                    COMCall0(p, Open)
#define IStoreStream_Close(p)                   COMCall0(p, Close)
#define IStoreStream_GetName(p)                 COMCall0(p, GetName)
#define IStoreStream_SetPos(p, a)               COMCall1(p, SetPos, a)
#define IStoreStream_GetPos(p)                  COMCall0(p, GetPos)
#define IStoreStream_ReadAbs(p, a, b, c)        COMCall3(p, ReadAbs, a, b, c)
#define IStoreStream_GetSize(p)                 COMCall0(p, GetSize)
#define IStoreStream_Read(p, a, b)              COMCall2(p, Read, a, b)
#define IStoreStream_Getc(p)                    COMCall0(p, Getc)
#define IStoreStream_ReadBlocks(p, a, b, c, d)  COMCall4(p, ReadBlocks, a, b, c, d)

///////////////////////////////////////

#define ISearchPath_Clear(p)                 COMCall0(p, Clear)
#define ISearchPath_Copy(p)                  COMCall0(p, Copy)
#define ISearchPath_AddStore(p, a)           COMCall1(p, AddStore, a)
#define ISearchPath_AddPath(p, a)            COMCall1(p, AddPath, a)
#define ISearchPath_Refresh(p)               COMCall0(p, Refresh)
#define ISearchPath_SetContext(p, a)         COMCall1(p, SetContext, a)
#define ISearchPath_Find(p, a, b)            COMCall2(p, Find, a, b)
#define ISearchPath_BeginContents(p, a, b)   COMCall2(p, BeginContents, a, b)
#define ISearchPath_Next(p, a, b, c)         COMCall3(p, Next, a, b, c)
#define ISearchPath_EndContents(p, a)        COMCall1(p, EndContents, a)
#define ISearchPath_Iterate(p, a, b, c)      COMCall3(p, Iterate, a, b, c)

//////////////////////////////////////////////////////////////////////////

#pragma pack()

#endif /* !__STOREAPI_H */
