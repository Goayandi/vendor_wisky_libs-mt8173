#ifndef __PQDCIMPL_H__
#define __PQDCIMPL_H__

/*
* header files
*/

#define ADL_ANDROID_PLATFORM



#define LUMA_BIT            9
#define LUMA_POINT_BIT      4 // For ( 17 = 2^4 + 1 ) points
#define LUMA_INTERVAL_BIT     ((LUMA_BIT)-(LUMA_POINT_BIT)) // For 17 points
#define LUMA_INTERVAL     ( 1 << ( LUMA_INTERVAL_BIT ) ) // For 17 points
#define LUMA_MAX            (1<<(LUMA_BIT))

#define LUMA_HIST_NUM           ( 1 << ( LUMA_POINT_BIT ) )
#define LUMA_HIST_NUM_WEIGHT    ( LUMA_HIST_NUM + 1 )
#define LUMA_CURVE_NUM              ( LUMA_HIST_NUM + 1 )

#define LUMA_HIST_NORM_BASE_BIT     9
#define LUMA_HIST_NORM_BASE         ( 1 << LUMA_HIST_NORM_BASE_BIT )
#define LUMA_HIST_NUM_TRUNCATE      LUMA_HIST_NUM

#define BLACK_WHITE_NUM    ( LUMA_HIST_NUM / 2 )

#define FIR_NUM             9
#define FIR_NUM_WEIGHT      8

#define Y_GAMMA_NUM     257

#define SKIN_NORM_BASE 256
#define SKIN_WGT_SLOPE_BIT      4
#define SKIN_WGT_BIT        8
#define SKIN_WGT_MAX        ( 1 << ( SKIN_WGT_BIT ) )
#define SKIN_CHANGE_WITH_LUMA_BIT 3
#define SKIN_CHANGE_WITH_LUMA_BIT_ROUND ( 1 << ( SKIN_CHANGE_WITH_LUMA_BIT - 1 ) )

enum ADLDebugFlags {
    eADLDebugDisabled          = 0x0,
    eADLDebugInput             = 0x1,
    eADLDebugOutput            = 0x2,
    eADLDebugTime              = 0x4,
    eADLDebugContent           = 0x8,
    eADLDebugAll               = 0xFF
};

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef signed int int32_t;


#ifndef ADL_ANDROID_PLATFORM
  #define ADAPTIVE_LUMA_DEBUG2_EN 1 // Debug switch for ADL FW
#endif

// Initial register values to ADL HW
struct ADLInitReg {
    uint32_t useless; // To pass compilation
};

// Initial param to ADL HW
struct ADLInitParam {
    uint32_t useless; // To pass compilation
};

// Fields collected from ADL HW
struct ADLInput {
    uint32_t LumaHist[LUMA_HIST_NUM_WEIGHT];
    uint32_t LumaSum;
    uint32_t ColorHist;
    uint32_t ImgArea;
    uint32_t LmtFullSwitch; // 0: limited, 1: full
    uint32_t VideoImgSwitch; // 0: Video, 1: Image
    uint32_t dync_cboost_yoffset;
#if DYN_CONTRAST_VERSION == 0
#else
    uint32_t tdshp_cboost_yoffset;
#endif
};

// Fields which will be set to HW registers
struct ADLOutput {
    uint32_t LumaCurve[LUMA_CURVE_NUM];
    uint32_t dync_cboost_yoffset;
    uint32_t dync_bypass;
    uint32_t new_boost_lmt_l;
#if DYN_CONTRAST_VERSION == 0
#else
    uint32_t dync_cboost_yoffset_sel;
    uint32_t dync_cboost_yconst;
    uint32_t tdshp_cboost_yoffset;
    uint32_t tdshp_cboost_yoffset_sel;
    uint32_t tdshp_cboost_yconst;
#endif
};


// ADL FW registers
struct ADLReg {
  // On & Off Switch
  uint32_t bALOnOff;
  uint32_t bBSOnOff;
  uint32_t bWSOnOff;
  uint32_t bStrongBSOffset;
  uint32_t bStrongWSOffset;
  uint32_t bBSAdaptiveLmt; // Blending with Dynamic Ratio according to BS Index
  uint32_t bWSAdaptiveLmt; // Blending with Dynamic Ratio according to WS Index

  // Full Range Setup
  uint32_t bLevelLowBnd;
  uint32_t bLevelHighBnd;

  // Scene Change Param
  uint32_t bADLSceneChange;
  uint32_t bForceScenceChangeEn; // For debug
  uint32_t bForceScenceChange2En; // To control scene change
  uint32_t bForceScenceChange2; // Scene change type
  uint32_t bMaxDiffThreshold;
  uint32_t bTotalDiffThreshold;
  uint32_t bAPLDiffThreshold;

  // Histogram FIR Weight
  uint32_t bADLWeight1;
  uint32_t bADLWeight2;
  uint32_t bADLWeight3;

  // Mid Param
  uint32_t bMIDACGain;
  uint32_t bMIDDCGain;

  // BS Basic Param
  uint32_t bBSDCGain;
  uint32_t bBSACGain;
  uint32_t bBSLevel;
  uint32_t bBSRatio;

  // BS Offset Param
  uint32_t bBSOffsetThL; // Input threshold
  uint32_t bBSOffsetThH; // Input threshold
  uint32_t bBSOffsetL; // Output threshold
  uint32_t bBSOffsetH; // Output threshold

  // WS Basic Param
  uint32_t bWSDCGain;
  uint32_t bWSACGain;
  uint32_t bWSLevel;
  uint32_t bWSRatio;

  // WS Offset Param
  uint32_t bWSOffsetThL; // Input threshold
  uint32_t bWSOffsetThH; // Input threshold
  uint32_t bWSOffsetL; // Output threshold
  uint32_t bWSOffsetH; // Output threshold

  // YGamma
  uint32_t bYGammaIdx1;
  uint32_t bYGammaIdx2;

  // IIR
  uint32_t bIIRStrength;

  // Spike Fallback Protection
  uint32_t bSpikeWeightLowBnd;
  uint32_t bSpikeThLow;
  uint32_t bSpikeThHigh;
  uint32_t bSpikeBlendmethod;
  uint32_t bIIRStrengthSpike;

  // Skin processing
  uint32_t bSkinBlendmethod;
  uint32_t bIIRStrengthSkin;
  uint32_t bSkinWgtSlope;
};


///////////////////////////////////////////////////////////////////////////////
// ADL FW Processing class
///////////////////////////////////////////////////////////////////////////////
class CPQDCFW
{
    /* ........Adaptive Luma Process, functions......... */
public:

    CPQDCFW();
    ~CPQDCFW();
#ifdef ADL_ANDROID_PLATFORM
    void onCalculate(const ADLInput &input, ADLOutput *output);
    void onInitPlatform(const ADLInitParam &initParam, ADLInitReg *initReg);
#else
    void vDrvADLProc_int( const ADLInput &input, ADLOutput * output);
#endif


    void setDebugFlags(unsigned int debug) {
        DebugFlags = debug;
    }

private:
  void ADLInitialize(void);
  void LmtFullSettings1(uint8_t LmtFullSwitch, const uint32_t wHist[LUMA_HIST_NUM_WEIGHT], uint32_t waHistCur[LUMA_HIST_NUM_WEIGHT], ADLOutput * output); //
  void HistLmt2Full( const uint32_t wHist[LUMA_HIST_NUM_WEIGHT], uint32_t waHistCur[LUMA_HIST_NUM_WEIGHT] ); //
  void BasicInfoCal( uint32_t LumaSum, uint32_t ImgArea, uint32_t ColorHist, uint32_t * u4APL, uint32_t * u4SkinRatio );
  void u1DrvGetLumaHistWeight(const uint32_t wHist[LUMA_HIST_NUM_WEIGHT], uint16_t waHistCur[LUMA_HIST_NUM_WEIGHT], uint16_t u2NormBase);
  void bHistogramNormalization(const uint32_t wHist[LUMA_HIST_NUM_WEIGHT], uint16_t waHistCur[LUMA_HIST_NUM_WEIGHT], uint8_t bDim, uint16_t wBase);
  uint8_t bDrvADLDetectSceneChanged(const uint16_t wHistCur[LUMA_HIST_NUM_WEIGHT], uint32_t u4APL, uint8_t VideoImgSwitch);
  void vDrvGetBlackWhiteIndex(const uint16_t waHistCur[LUMA_HIST_NUM_WEIGHT]);
  void LocalHistEqualized(const uint16_t waHist[LUMA_HIST_NUM_WEIGHT], uint16_t waLumaCurve[LUMA_CURVE_NUM]);
  void vDrvDynamicADLPara(void);
  void vDrvDynamicBSOffset(void);
  void vDrvDynamicWSOffset(void);
  void vDrvADLBuildDefault(uint16_t wCurve[LUMA_CURVE_NUM]);
  void LowPassFilter(uint32_t u4FIR[FIR_NUM]);
  void HistFIR(const uint16_t waHistCur[LUMA_HIST_NUM_WEIGHT], uint16_t waLowPass[LUMA_HIST_NUM], uint32_t u4FIR[FIR_NUM] );
  void vDrvApplyUserCurve1(uint16_t* waFinalCurve, uint8_t bSel);
  void vDrvApplyUserCurve2(uint16_t* waFinalCurve, uint8_t bSel);
  void vDrvADLLumaCurveLowPass(const uint16_t waCurCurve[LUMA_CURVE_NUM], uint32_t waLumaCurve[LUMA_CURVE_NUM]);

  void vBuildSecondLumaCurve(const uint16_t waCurCurve[LUMA_CURVE_NUM], uint16_t waLumaCurve[LUMA_CURVE_NUM], uint32_t u4SkinRatio);
  uint32_t vAdapSecondLumaWeight( uint32_t u4SkinRatio );
  void vSpikeLumaCurve(const uint16_t waCurCurve[LUMA_CURVE_NUM], uint16_t waLumaCurve[LUMA_CURVE_NUM], const uint16_t waHist[LUMA_HIST_NUM_WEIGHT]);
  uint32_t vSpikeLumaWeight(const uint16_t waHist[LUMA_HIST_NUM_WEIGHT]);
  void LmtFullSettings2(uint32_t LmtFullSwitch, uint32_t waCurCurve[LUMA_CURVE_NUM]); //
  void CurveFull2Lmt(uint32_t waCurCurve[LUMA_CURVE_NUM]); //

    /* ........Adaptive Luma Process, variables......... */
public:
    ADLReg * pADLReg;

#ifndef ADL_ANDROID_PLATFORM
    FILE * ifp1;
    FILE * ifp2; // wenwen
#endif

private:

    uint32_t DebugFlags;

    uint32_t fullHist[LUMA_HIST_NUM_WEIGHT]; //
    uint16_t waHist[LUMA_HIST_NUM_WEIGHT];
    uint16_t waCurCurve[LUMA_CURVE_NUM];
    uint16_t waLumaArray[LUMA_CURVE_NUM];
    uint16_t waLumaArray2[LUMA_CURVE_NUM];
    uint32_t u4APL;
    uint32_t u4SkinRatio;

    // Histogram FIR Weight
    uint8_t bParamChange;

    // BS_WS Index Param
    uint8_t bBlackIndex;
    uint8_t bWhiteIndex;

    // BS Offset Param
    uint8_t bBSOffset; // Output result

    // WS Offset Param
    uint8_t bWSOffset; // Output result

    // Previous luma curve : Add bits to prevent quantization error
    uint32_t waTCurvePre[LUMA_CURVE_NUM];

    // Previous average pixel level
    uint32_t u4PreAPL;

    // Previous histogram
    uint16_t wHistPre[LUMA_HIST_NUM_WEIGHT];

    // previous skin ratio: Add bits to prevent quantization error
    uint32_t u4SkinRatioPre;
    // previous spike weight: Add bits to prevent quantization error
    uint32_t u4SpikeWeightPre;
};

#endif //__PQDCIMPL_H__
