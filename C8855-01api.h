#ifndef _C8855_API_Header
#define _C8855_API_Header
/////////////////////////////////////////////////////////////////
//
//	C8855-01api.h
//
//	  Copyright (c) 2001-, Hamamatsu Photonics K.K.
//
//    version 1.1.0 
//    version 1.2.0		C9692ReadId‚ð’Ç‰Á	2008.02.07
//    Version 1.2.1		C8855OpenM()‚ð’Ç‰Á	2008.12.12
//
/////////////////////////////////////////////////////////////////

//#define BULKOUT    1
//#define BULKIN     0

#define	C8855_GATETIME_50US         0x02
#define	C8855_GATETIME_100US        0x03
#define	C8855_GATETIME_200US        0x04
#define	C8855_GATETIME_500US        0x05
#define	C8855_GATETIME_1MS          0x06
#define	C8855_GATETIME_2MS          0x07
#define	C8855_GATETIME_5MS          0x08
#define	C8855_GATETIME_10MS         0x09
#define	C8855_GATETIME_20MS         0x0a
#define	C8855_GATETIME_50MS         0x0b
#define	C8855_GATETIME_100MS        0x0c
#define	C8855_GATETIME_200MS        0x0d
#define	C8855_GATETIME_500MS        0x0e
#define	C8855_GATETIME_1S           0x0f
#define	C8855_GATETIME_2S           0x10
#define	C8855_GATETIME_5S           0x11
#define	C8855_GATETIME_10S          0x12

#define C8855_SOFTWARE_TRIGGER      0
#define C8855_EXTERNAL_TRIGGER      1

#define	C8855_SINGLE_TRANSFER       1
#define	C8855_BLOCK_TRANSFER        2

#define C8855_PMT_POWER_OFF         0
#define C8855_PMT_POWER_ON          1
#define C8855_PMT_POWER_CHECK       2

#define C8855_ERROR_TRANSFER        0xFF

// -----------------------------------------------

#ifdef C8855API_EXPORTS
#define C8855API __declspec(dllexport)
#else
#define C8855API __declspec(dllimport)
#endif

//
// DLL Export Function
//
#ifdef __cplusplus
extern "C" {
#endif

HANDLE C8855API __stdcall C8855Open( void );

BOOL C8855API __stdcall C8855MOpen( BYTE board,
								   HANDLE *hC8855_1,
								   HANDLE *hC8855_2,
								   HANDLE *hC8855_3,
								   HANDLE *hC8855_4,
								   HANDLE *hC8855_5,
								   HANDLE *hC8855_6,
								   HANDLE *hC8855_7,
								   HANDLE *hC8855_8,
								   HANDLE *hC8855_9,
								   HANDLE *hC8855_10,
								   HANDLE *hC8855_11,
								   HANDLE *hC8855_12,
								   HANDLE *hC8855_13,
								   HANDLE *hC8855_14,
								   HANDLE *hC8855_15,
								   HANDLE *hC8855_16);

BOOL C8855API __stdcall C8855Close( HANDLE  hC8855 );

BOOL C8855API __stdcall C8855Reset( HANDLE  hC8855 );

BOOL C8855API __stdcall C8855CountStart( HANDLE  hC8855,
                                         BYTE    TriggerMode );

BOOL C8855API __stdcall C8855CountStop( HANDLE  hC8855 );


BOOL C8855API __stdcall C8855Setup( HANDLE  hC8855,
                                    BYTE    GateTime,
                                    BYTE    TransferMode,
                                    WORD    NumberOfGate);

BOOL C8855API __stdcall C8855ReadData( HANDLE  hC8855,
                                       DWORD   *DataBuffer,
                                       BYTE    *ResultReturned );

BOOL C8855API __stdcall C8855SetPmtPower(HANDLE	 hC8855,
                                         BYTE    PowerStatus );

BOOL C8855API __stdcall C8855WritePort( HANDLE  hC8855,
                                        BYTE    Data );

BOOL C8855API __stdcall C8855ReadPort( HANDLE  hC8855,
                                        BYTE   *Data );

BOOL C8855API __stdcall C8855ReadId( HANDLE  hC8855,	
                                       BYTE   *Data );

#ifdef __cplusplus
}
#endif

#endif
