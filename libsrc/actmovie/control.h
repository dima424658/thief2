/* This header file machine-generated by mktyplib.exe */
/* Interface to type library: QuartzTypeLib */

#ifndef _QuartzTypeLib_H_
#define _QuartzTypeLib_H_

DEFINE_GUID(LIBID_QuartzTypeLib,0x56A868B0L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

typedef double REFTIME;

typedef long OAEVENT;

typedef long OAHWND;

typedef long OAFilterState;

DEFINE_GUID(IID_IAMCollection,0x56A868B9L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IAMCollection */
#undef INTERFACE
#define INTERFACE IAMCollection

DECLARE_INTERFACE_(IAMCollection, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IAMCollection methods */
    STDMETHOD(get_Count)(THIS_ long FAR* plCount) PURE;
    STDMETHOD(Item)(THIS_ long lItem, IUnknown * FAR* ppUnk) PURE;
    STDMETHOD(get__NewEnum)(THIS_ IUnknown * FAR* ppUnk) PURE;
};

DEFINE_GUID(IID_IMediaControl,0x56A868B1L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IMediaControl */
#undef INTERFACE
#define INTERFACE IMediaControl

DECLARE_INTERFACE_(IMediaControl, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IMediaControl methods */
    STDMETHOD(Run)(THIS) PURE;
    STDMETHOD(Pause)(THIS) PURE;
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(GetState)(THIS_ long msTimeout, OAFilterState FAR* pfs) PURE;
    STDMETHOD(RenderFile)(THIS_ BSTR strFilename) PURE;
    STDMETHOD(AddSourceFilter)(THIS_ BSTR strFilename, IDispatch * FAR* ppUnk) PURE;
    STDMETHOD(get_FilterCollection)(THIS_ IDispatch * FAR* ppUnk) PURE;
    STDMETHOD(get_RegFilterCollection)(THIS_ IDispatch * FAR* ppUnk) PURE;
};

DEFINE_GUID(IID_IMediaEvent,0x56A868B6L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IMediaEvent */
#undef INTERFACE
#define INTERFACE IMediaEvent

DECLARE_INTERFACE_(IMediaEvent, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IMediaEvent methods */
    STDMETHOD(GetEventHandle)(THIS_ OAEVENT FAR* hEvent) PURE;
    STDMETHOD(GetEvent)(THIS_ long FAR* lEventCode, long FAR* lParam1, long FAR* lParam2, long msTimeout) PURE;
    STDMETHOD(WaitForCompletion)(THIS_ long msTimeout, long FAR* pEvCode) PURE;
    STDMETHOD(CancelDefaultHandling)(THIS_ long lEvCode) PURE;
    STDMETHOD(RestoreDefaultHandling)(THIS_ long lEvCode) PURE;
    STDMETHOD(FreeEventParams)(THIS_ long lEvCode, long lParam1, long lParam2) PURE;
};

DEFINE_GUID(IID_IMediaPosition,0x56A868B2L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IMediaPosition */
#undef INTERFACE
#define INTERFACE IMediaPosition

DECLARE_INTERFACE_(IMediaPosition, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IMediaPosition methods */
    STDMETHOD(get_Duration)(THIS_ REFTIME FAR* plength) PURE;
    STDMETHOD(put_CurrentPosition)(THIS_ REFTIME llTime) PURE;
    STDMETHOD(get_CurrentPosition)(THIS_ REFTIME FAR* pllTime) PURE;
    STDMETHOD(get_StopTime)(THIS_ REFTIME FAR* pllTime) PURE;
    STDMETHOD(put_StopTime)(THIS_ REFTIME llTime) PURE;
    STDMETHOD(get_PrerollTime)(THIS_ REFTIME FAR* pllTime) PURE;
    STDMETHOD(put_PrerollTime)(THIS_ REFTIME llTime) PURE;
    STDMETHOD(put_Rate)(THIS_ double dRate) PURE;
    STDMETHOD(get_Rate)(THIS_ double FAR* pdRate) PURE;
    STDMETHOD(CanSeekForward)(THIS_ long FAR* pCanSeekForward) PURE;
    STDMETHOD(CanSeekBackward)(THIS_ long FAR* pCanSeekBackward) PURE;
};

DEFINE_GUID(IID_IBasicAudio,0x56A868B3L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IBasicAudio */
#undef INTERFACE
#define INTERFACE IBasicAudio

DECLARE_INTERFACE_(IBasicAudio, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IBasicAudio methods */
    STDMETHOD(put_Volume)(THIS_ long lVolume) PURE;
    STDMETHOD(get_Volume)(THIS_ long FAR* plVolume) PURE;
    STDMETHOD(put_Balance)(THIS_ long lBalance) PURE;
    STDMETHOD(get_Balance)(THIS_ long FAR* plBalance) PURE;
};

DEFINE_GUID(IID_IVideoWindow,0x56A868B4L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IVideoWindow */
#undef INTERFACE
#define INTERFACE IVideoWindow

DECLARE_INTERFACE_(IVideoWindow, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IVideoWindow methods */
    STDMETHOD(put_Caption)(THIS_ BSTR strCaption) PURE;
    STDMETHOD(get_Caption)(THIS_ BSTR FAR* strCaption) PURE;
    STDMETHOD(put_WindowStyle)(THIS_ long WindowStyle) PURE;
    STDMETHOD(get_WindowStyle)(THIS_ long FAR* WindowStyle) PURE;
    STDMETHOD(put_WindowStyleEx)(THIS_ long WindowStyleEx) PURE;
    STDMETHOD(get_WindowStyleEx)(THIS_ long FAR* WindowStyleEx) PURE;
    STDMETHOD(put_AutoShow)(THIS_ long AutoShow) PURE;
    STDMETHOD(get_AutoShow)(THIS_ long FAR* AutoShow) PURE;
    STDMETHOD(put_WindowState)(THIS_ long WindowState) PURE;
    STDMETHOD(get_WindowState)(THIS_ long FAR* WindowState) PURE;
    STDMETHOD(put_BackgroundPalette)(THIS_ long BackgroundPalette) PURE;
    STDMETHOD(get_BackgroundPalette)(THIS_ long FAR* pBackgroundPalette) PURE;
    STDMETHOD(put_Visible)(THIS_ long Visible) PURE;
    STDMETHOD(get_Visible)(THIS_ long FAR* pVisible) PURE;
    STDMETHOD(put_Left)(THIS_ long Left) PURE;
    STDMETHOD(get_Left)(THIS_ long FAR* pLeft) PURE;
    STDMETHOD(put_Width)(THIS_ long Width) PURE;
    STDMETHOD(get_Width)(THIS_ long FAR* pWidth) PURE;
    STDMETHOD(put_Top)(THIS_ long Top) PURE;
    STDMETHOD(get_Top)(THIS_ long FAR* pTop) PURE;
    STDMETHOD(put_Height)(THIS_ long Height) PURE;
    STDMETHOD(get_Height)(THIS_ long FAR* pHeight) PURE;
    STDMETHOD(put_Owner)(THIS_ OAHWND Owner) PURE;
    STDMETHOD(get_Owner)(THIS_ OAHWND FAR* Owner) PURE;
    STDMETHOD(put_MessageDrain)(THIS_ OAHWND Drain) PURE;
    STDMETHOD(get_MessageDrain)(THIS_ OAHWND FAR* Drain) PURE;
    STDMETHOD(get_BorderColor)(THIS_ long FAR* Color) PURE;
    STDMETHOD(put_BorderColor)(THIS_ long Color) PURE;
    STDMETHOD(get_FullScreenMode)(THIS_ long FAR* FullScreenMode) PURE;
    STDMETHOD(put_FullScreenMode)(THIS_ long FullScreenMode) PURE;
    STDMETHOD(SetWindowForeground)(THIS_ long Focus) PURE;
    STDMETHOD(NotifyOwnerMessage)(THIS_ long hwnd, long uMsg, long wParam, long lParam) PURE;
    STDMETHOD(SetWindowPosition)(THIS_ long Left, long Top, long Width, long Height) PURE;
    STDMETHOD(GetWindowPosition)(THIS_ long FAR* pLeft, long FAR* pTop, long FAR* pWidth, long FAR* pHeight) PURE;
    STDMETHOD(GetMinIdealImageSize)(THIS_ long FAR* pWidth, long FAR* pHeight) PURE;
    STDMETHOD(GetMaxIdealImageSize)(THIS_ long FAR* pWidth, long FAR* pHeight) PURE;
    STDMETHOD(GetRestorePosition)(THIS_ long FAR* pLeft, long FAR* pTop, long FAR* pWidth, long FAR* pHeight) PURE;
    STDMETHOD(HideCursor)(THIS_ long HideCursor) PURE;
    STDMETHOD(IsCursorHidden)(THIS_ long FAR* CursorHidden) PURE;
};

DEFINE_GUID(IID_IBasicVideo,0x56A868B5L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IBasicVideo */
#undef INTERFACE
#define INTERFACE IBasicVideo

DECLARE_INTERFACE_(IBasicVideo, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IBasicVideo methods */
    STDMETHOD(get_AvgTimePerFrame)(THIS_ REFTIME FAR* pAvgTimePerFrame) PURE;
    STDMETHOD(get_BitRate)(THIS_ long FAR* pBitRate) PURE;
    STDMETHOD(get_BitErrorRate)(THIS_ long FAR* pBitErrorRate) PURE;
    STDMETHOD(get_VideoWidth)(THIS_ long FAR* pVideoWidth) PURE;
    STDMETHOD(get_VideoHeight)(THIS_ long FAR* pVideoHeight) PURE;
    STDMETHOD(put_SourceLeft)(THIS_ long SourceLeft) PURE;
    STDMETHOD(get_SourceLeft)(THIS_ long FAR* pSourceLeft) PURE;
    STDMETHOD(put_SourceWidth)(THIS_ long SourceWidth) PURE;
    STDMETHOD(get_SourceWidth)(THIS_ long FAR* pSourceWidth) PURE;
    STDMETHOD(put_SourceTop)(THIS_ long SourceTop) PURE;
    STDMETHOD(get_SourceTop)(THIS_ long FAR* pSourceTop) PURE;
    STDMETHOD(put_SourceHeight)(THIS_ long SourceHeight) PURE;
    STDMETHOD(get_SourceHeight)(THIS_ long FAR* pSourceHeight) PURE;
    STDMETHOD(put_DestinationLeft)(THIS_ long DestinationLeft) PURE;
    STDMETHOD(get_DestinationLeft)(THIS_ long FAR* pDestinationLeft) PURE;
    STDMETHOD(put_DestinationWidth)(THIS_ long DestinationWidth) PURE;
    STDMETHOD(get_DestinationWidth)(THIS_ long FAR* pDestinationWidth) PURE;
    STDMETHOD(put_DestinationTop)(THIS_ long DestinationTop) PURE;
    STDMETHOD(get_DestinationTop)(THIS_ long FAR* pDestinationTop) PURE;
    STDMETHOD(put_DestinationHeight)(THIS_ long DestinationHeight) PURE;
    STDMETHOD(get_DestinationHeight)(THIS_ long FAR* pDestinationHeight) PURE;
    STDMETHOD(SetSourcePosition)(THIS_ long Left, long Top, long Width, long Height) PURE;
    STDMETHOD(GetSourcePosition)(THIS_ long FAR* pLeft, long FAR* pTop, long FAR* pWidth, long FAR* pHeight) PURE;
    STDMETHOD(SetDefaultSourcePosition)(THIS) PURE;
    STDMETHOD(SetDestinationPosition)(THIS_ long Left, long Top, long Width, long Height) PURE;
    STDMETHOD(GetDestinationPosition)(THIS_ long FAR* pLeft, long FAR* pTop, long FAR* pWidth, long FAR* pHeight) PURE;
    STDMETHOD(SetDefaultDestinationPosition)(THIS) PURE;
    STDMETHOD(GetVideoSize)(THIS_ long FAR* pWidth, long FAR* pHeight) PURE;
    STDMETHOD(GetVideoPaletteEntries)(THIS_ long StartIndex, long Entries, long FAR* pRetrieved, long FAR* pPalette) PURE;
    STDMETHOD(GetCurrentImage)(THIS_ long FAR* pBufferSize, long FAR* pDIBImage) PURE;
    STDMETHOD(IsUsingDefaultSource)(THIS) PURE;
    STDMETHOD(IsUsingDefaultDestination)(THIS) PURE;
};

DEFINE_GUID(IID_IDeferredCommand,0x56A868B8L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IDeferredCommand */
#undef INTERFACE
#define INTERFACE IDeferredCommand

DECLARE_INTERFACE_(IDeferredCommand, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IDeferredCommand methods */
    STDMETHOD(Cancel)(THIS) PURE;
    STDMETHOD(Confidence)(THIS_ long FAR* pConfidence) PURE;
    STDMETHOD(Postpone)(THIS_ REFTIME newtime) PURE;
    STDMETHOD(GetHResult)(THIS_ HRESULT FAR* phrResult) PURE;
};

DEFINE_GUID(IID_IQueueCommand,0x56A868B7L,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IQueueCommand */
#undef INTERFACE
#define INTERFACE IQueueCommand

DECLARE_INTERFACE_(IQueueCommand, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IQueueCommand methods */
    STDMETHOD(InvokeAtStreamTime)(THIS_ IDeferredCommand FAR* FAR* pCmd, REFTIME time, GUID FAR* iid, long dispidMethod, short wFlags, long cArgs, VARIANT FAR* pDispParams, VARIANT FAR* pvarResult, short FAR* puArgErr) PURE;
    STDMETHOD(InvokeAtPresentationTime)(THIS_ IDeferredCommand FAR* FAR* pCmd, REFTIME time, GUID FAR* iid, long dispidMethod, short wFlags, long cArgs, VARIANT FAR* pDispParams, VARIANT FAR* pvarResult, short FAR* puArgErr) PURE;
};

DEFINE_GUID(CLSID_FilgraphManager,0xE436EBB3L,0x524F,0x11CE,0x9F,0x53,0x00,0x20,0xAF,0x0B,0xA7,0x70);

#ifdef __cplusplus
class FilgraphManager;
#endif

DEFINE_GUID(IID_IFilterInfo,0x56A868BAL,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IFilterInfo */
#undef INTERFACE
#define INTERFACE IFilterInfo

DECLARE_INTERFACE_(IFilterInfo, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IFilterInfo methods */
    STDMETHOD(FindPin)(THIS_ BSTR strPinID, IDispatch * FAR* ppUnk) PURE;
    STDMETHOD(get_Name)(THIS_ BSTR FAR* strName) PURE;
    STDMETHOD(get_VendorInfo)(THIS_ BSTR FAR* strVendorInfo) PURE;
    STDMETHOD(get_Filter)(THIS_ IUnknown * FAR* ppUnk) PURE;
    STDMETHOD(get_Pins)(THIS_ IDispatch * FAR* ppUnk) PURE;
    STDMETHOD(get_IsFileSource)(THIS_ long FAR* pbIsSource) PURE;
    STDMETHOD(get_Filename)(THIS_ BSTR FAR* pstrFilename) PURE;
    STDMETHOD(put_Filename)(THIS_ BSTR strFilename) PURE;
};

DEFINE_GUID(IID_IRegFilterInfo,0x56A868BBL,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IRegFilterInfo */
#undef INTERFACE
#define INTERFACE IRegFilterInfo

DECLARE_INTERFACE_(IRegFilterInfo, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IRegFilterInfo methods */
    STDMETHOD(get_Name)(THIS_ BSTR FAR* strName) PURE;
    STDMETHOD(Filter)(THIS_ IDispatch * FAR* ppUnk) PURE;
};

DEFINE_GUID(IID_IMediaTypeInfo,0x56A868BCL,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IMediaTypeInfo */
#undef INTERFACE
#define INTERFACE IMediaTypeInfo

DECLARE_INTERFACE_(IMediaTypeInfo, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IMediaTypeInfo methods */
    STDMETHOD(get_Type)(THIS_ BSTR FAR* strType) PURE;
    STDMETHOD(get_Subtype)(THIS_ BSTR FAR* strType) PURE;
};

DEFINE_GUID(IID_IPinInfo,0x56A868BDL,0x0AD4,0x11CE,0xB0,0x3A,0x00,0x20,0xAF,0x0B,0xA7,0x70);

/* Definition of interface: IPinInfo */
#undef INTERFACE
#define INTERFACE IPinInfo

DECLARE_INTERFACE_(IPinInfo, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IPinInfo methods */
    STDMETHOD(get_Pin)(THIS_ IUnknown * FAR* ppUnk) PURE;
    STDMETHOD(get_ConnectedTo)(THIS_ IDispatch * FAR* ppUnk) PURE;
    STDMETHOD(get_ConnectionMediaType)(THIS_ IDispatch * FAR* ppUnk) PURE;
    STDMETHOD(get_FilterInfo)(THIS_ IDispatch * FAR* ppUnk) PURE;
    STDMETHOD(get_Name)(THIS_ BSTR FAR* ppUnk) PURE;
    STDMETHOD(get_Direction)(THIS_ long FAR* ppDirection) PURE;
    STDMETHOD(get_PinID)(THIS_ BSTR FAR* strPinID) PURE;
    STDMETHOD(get_MediaTypes)(THIS_ IDispatch * FAR* ppUnk) PURE;
    STDMETHOD(Connect)(THIS_ IUnknown * pPin) PURE;
    STDMETHOD(ConnectDirect)(THIS_ IUnknown * pPin) PURE;
    STDMETHOD(ConnectWithType)(THIS_ IUnknown * pPin, IDispatch * pMediaType) PURE;
    STDMETHOD(Disconnect)(THIS) PURE;
    STDMETHOD(Render)(THIS) PURE;
};

#endif
